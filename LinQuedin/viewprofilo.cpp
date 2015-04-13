#include "viewprofilo.h"

ViewProfilo::ViewProfilo(QWidget *parent,const QString& s,Controller* c) : QWidget(parent){

    tmp = c;
    username = s;

    box = new QDialog();
    box->resize(500,400);
    box->setWindowTitle("LinQedIn - Visualizza Profilo");
    layout = new QVBoxLayout();
    view = new QTreeWidget();
    QStringList list;
    list << "Nome" << "Valore";
    view->setHeaderLabels(list);
    view->setColumnWidth(0,200);

    if(typeid(*tmp)==typeid(Client)){
        if(tmp->returnUserType()==0)
            viewBasic();
        if(tmp->returnUserType()==1)
            viewBusiness();
        if(tmp->returnUserType()==2)
            viewExecutive();
    }
    if(typeid(*tmp)==typeid(Admin))
        viewAdmin();

    layout->addWidget(view);
    box->setLayout(layout);
    box->exec();
}

void ViewProfilo::viewBasic(){

    DAnagrafici dati;
    Client* client = dynamic_cast<Client*>(tmp);
    if(client){
        dati = client->data_->getUtente(username)->getProfilo().getDati();
        controllertype = 0;
    }
    else{
        Admin* admin = dynamic_cast<Admin*>(tmp);
        dati = admin->data_->getUtente(username)->getProfilo().getDati();
        controllertype = 1;
    }
    QStringList label;
    label << "Nome" << "Cognome" << "Email" << "Data di Nascita" << "Luogo di Nascita" << "Luogo di Residenza";
    QStringList value;
    value << dati.getNome() << dati.getCognome() << dati.getEmail() << dati.getData_nascita().toString("dd/MM/yyyy") << dati.getLuogo_nascita() << dati.getLuogo_residenza();
    QList<QTreeWidgetItem*> items;
    QTreeWidgetItem* dati_anagrafici = new QTreeWidgetItem((QTreeWidget*)0, QStringList(QString("Dati Anagrafici")));
    for(int i=0;i<6;++i){
        QTreeWidgetItem* child = new QTreeWidgetItem();
        QVariant variant1(label.at(i));
        QVariant variant2(value.at(i));
        child->setData(0,Qt::DisplayRole,variant1);
        child->setData(1,Qt::DisplayRole,variant2);
        dati_anagrafici->addChild(child);
    }
    items.append(dati_anagrafici);
    if(controllertype==0)
        view->insertTopLevelItems(0,items);
    else view->insertTopLevelItems(1,items);
    dati_anagrafici->setExpanded(true);

}

void ViewProfilo::viewBusiness(){

    viewBasic();

    TitoliStudio titoli;
    Client* client = dynamic_cast<Client*>(tmp);
    if(client){
        titoli = client->data_->getUtente(username)->getProfilo().getTitoli();
        controllertype = 0;
    }
    else{
        Admin* admin = dynamic_cast<Admin*>(tmp);
        titoli = admin->data_->getUtente(username)->getProfilo().getTitoli();
        controllertype = 1;
    }
    vector<Laurea> v = titoli.getLauree();

    QStringList label;
    label << "Nome Diploma" << "Anno Diploma" << "Nome Laurea" << "Anno Laurea";
    QStringList value;
    value << titoli.getDiploma() << QString::number(titoli.getAnno());
    QList<QTreeWidgetItem *> items;
    QList<QTreeWidgetItem *> children;
    QTreeWidgetItem* titoli_studio = new QTreeWidgetItem((QTreeWidget*)0, QStringList(QString("Titoli di Studio")));
    QTreeWidgetItem* diploma = new QTreeWidgetItem((QTreeWidget*)0, QStringList(QString("Diploma")));
    QTreeWidgetItem* nome = new QTreeWidgetItem();
    QVariant v1(label.at(0));
    QVariant v2(value.at(0));
    nome->setData(0,Qt::DisplayRole,v1);
    nome->setData(1,Qt::DisplayRole,v2);
    diploma->addChild(nome);
    QTreeWidgetItem* anno = new QTreeWidgetItem();
    QVariant var1(label.at(1));
    QVariant var2(value.at(1));
    anno->setData(0,Qt::DisplayRole,var1);
    anno->setData(1,Qt::DisplayRole,var2);
    diploma->addChild(anno);
    children.append(diploma);
    vector<Laurea>::const_iterator it = v.begin();
    for(;it!=v.end();++it){
        QTreeWidgetItem* laurea = new QTreeWidgetItem((QTreeWidget*)0, QStringList(QString("Laurea")));
        QTreeWidgetItem* nome = new QTreeWidgetItem();
        QVariant variant1(label.at(2));
        QVariant variant2((*it).getNome());
        nome->setData(0,Qt::DisplayRole,variant1);
        nome->setData(1,Qt::DisplayRole,variant2);
        laurea->addChild(nome);
        QTreeWidgetItem* anno = new QTreeWidgetItem();
        QVariant variant3(label.at(3));
        QVariant variant4((*it).getAnno());
        anno->setData(0,Qt::DisplayRole,variant3);
        anno->setData(1,Qt::DisplayRole,variant4);
        laurea->addChild(anno);
        children.append(laurea);
    }
    titoli_studio->addChildren(children);
    items.append(titoli_studio);
    if(controllertype==0)
        view->insertTopLevelItems(1,items);
    else view->insertTopLevelItems(2,items);
    QList<QTreeWidgetItem*>::iterator iter = children.begin();
    for(;iter!=children.end();++iter)
        (*iter)->setExpanded(true);
    titoli_studio->setExpanded(true);

}

void ViewProfilo::viewExecutive(){

    viewBusiness();

    Impieghi lavori;
    Client* client = dynamic_cast<Client*>(tmp);
    if(client){
        lavori = client->data_->getUtente(username)->getProfilo().getImpieghi();
        controllertype = 0;
    }
    else{
        Admin* admin = dynamic_cast<Admin*>(tmp);
        lavori = admin->data_->getUtente(username)->getProfilo().getImpieghi();
        controllertype = 1;
    }
    list<Lavoro> l = lavori.getLavori();
    if(l.size()!=0){
        QStringList label;
        label << "Titolo" << "Azienda" << "Città" << "Data Inizio" << "Data Fine";
        QList<QTreeWidgetItem *> items;
        QList<QTreeWidgetItem *> children;
        QTreeWidgetItem* impieghi = new QTreeWidgetItem((QTreeWidget*)0, QStringList(QString("Impieghi")));
        list<Lavoro>::const_iterator it = l.begin();
        for(;it!=l.end();++it){
            QStringList value;
            value << (*it).getTitolo() << (*it).getAzienda() << (*it).getCitta() << (*it).getInizio().toString("dd/MM/yyyy") << (*it).getFine().toString("dd/MM/yyyy");
            QTreeWidgetItem* lavoro = new QTreeWidgetItem((QTreeWidget*)0, QStringList(QString("Lavoro")));
            for(int i=0;i<5;++i){
                QTreeWidgetItem* child = new QTreeWidgetItem();
                QVariant variant1(label.at(i));
                QVariant variant2(value.at(i));
                child->setData(0,Qt::DisplayRole,variant1);
                child->setData(1,Qt::DisplayRole,variant2);
                lavoro->addChild(child);
            }
            children.append(lavoro);
            impieghi->addChildren(children);
        }
        items.append(impieghi);
        if(controllertype==0)
            view->insertTopLevelItems(2,items);
        else view->insertTopLevelItems(3,items);
        QList<QTreeWidgetItem*>::iterator iter = children.begin();
        for(;iter!=children.end();++iter)
            (*iter)->setExpanded(true);
        impieghi->setExpanded(true);
    }

}

void ViewProfilo::viewAdmin(){

    Admin* admin = dynamic_cast<Admin*>(tmp);

    QTreeWidgetItem* tipo = new QTreeWidgetItem();
    QVariant variant1("Tipo Account");
    tipo->setData(0,Qt::DisplayRole,variant1);
    int usertype = admin->typeOf(username);
    if(usertype==0){
        QVariant variant2("Basic");
        tipo->setData(1,Qt::DisplayRole,variant2);
    }
    if(usertype==1){
        QVariant variant2("Business");
        tipo->setData(1,Qt::DisplayRole,variant2);
    }
    if(usertype==2){
        QVariant variant2("Executive");
        tipo->setData(1,Qt::DisplayRole,variant2);
    }
    view->insertTopLevelItem(0,tipo);

    viewExecutive();

    map<QString,Nodo> m = admin->data_->getUtente(username)->getRete()->rete;
    if(m.size()!=0){
        QString label = "Rete (" + QString::number(m.size()) + ")";
        map<QString,Nodo>::const_iterator it = m.begin();
        QList<QTreeWidgetItem *> items;
        QTreeWidgetItem* rete = new QTreeWidgetItem((QTreeWidget*)0, QStringList(QString(label)));
        for(;it!=m.end();++it){
            QString nc = (*it).second.utente->getProfilo().getDati().getNome();
            nc = nc + " " + (*it).second.utente->getProfilo().getDati().getCognome();
            QTreeWidgetItem* child = new QTreeWidgetItem();
            QVariant variant1("Utente");
            QVariant variant2(nc);
            child->setData(0,Qt::DisplayRole,variant1);
            child->setData(1,Qt::DisplayRole,variant2);
            rete->addChild(child);
        }
        items.append(rete);
        view->insertTopLevelItems(4,items);
        rete->setExpanded(true);
    }
}
