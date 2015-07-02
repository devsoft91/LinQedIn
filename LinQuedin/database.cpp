#include "database.h"
#include "qstringlist.h"
#include "ubasic.h"
#include "ubusiness.h"
#include "uexecutive.h"

Database::Database(){}

void Database::load(){
    QString nome,cognome,email,luogonascita,luogoresidenza,nomediploma,nomelaurea,azienda, titolo,citta,user,users,userA,userB,tipo;
    QDate datanascita,inizio, fine;
    QStringList coppia;
    int annod, annol, stresstest = 0;
    bool wellformedDB = false;

    Utente* utente;
    Utente* utenteA;
    Utente* utenteB;

    path = "/home/giacomo/Scrivania/P2/PROGETTO/LinQuedin/database.xml";
    QFile file(path);
    while(!wellformedDB){
        while(!file.open(QIODevice::ReadOnly)){
            QMessageBox box;
            box.setWindowTitle("Attention");
            box.setText("Database not found. Choose one from your files.");
            box.setIcon(QMessageBox::Warning);
            box.setStandardButtons(QMessageBox::Ok);
            int choose = box.exec();
            switch(choose){
                case QMessageBox::Ok:
                    path = QFileDialog::getOpenFileName(0,"Open File","/home","Xml (*.xml)");
                    file.setFileName(path);
            }
        }
        QXmlStreamReader test_reader(&file);
        test_reader.readNextStartElement();
        if(test_reader.name()=="LinQedInDatabase") wellformedDB = true;
        else{
            file.setFileName("/home/giacomo/Scrivania/P2/PROGETTO/LinQuedin/database.xml");
            QMessageBox box;
            box.setWindowTitle("Warning");
            box.setText("The file doesn't contain any valid database!");
            box.setIcon(QMessageBox::Critical);
            box.setStandardButtons(QMessageBox::Close);
            box.exec();
        }
    }

    QFile filek(path);
    filek.open(QIODevice::ReadOnly);
    QXmlStreamReader reader(&filek);
    reader.readNextStartElement();
    while(!(reader.name()=="LinQedInDatabase" && reader.tokenType() == QXmlStreamReader::EndElement)){
        if(reader.name()=="Utenti" && reader.tokenType() == QXmlStreamReader::StartElement){
            while(!(reader.name()=="Utenti" && reader.tokenType() == QXmlStreamReader::EndElement)){
                Profilo profile;
                while(!(reader.name()=="Utente" && reader.tokenType() == QXmlStreamReader::EndElement)){
                    if(reader.name()=="Utente" && reader.tokenType() == QXmlStreamReader::StartElement){
                        tipo = reader.attributes().value("type").toString();
                    }
                    if(reader.name()=="Dati_Anagrafici" && reader.tokenType() == QXmlStreamReader::StartElement){
                        while(!(reader.name() == "Dati_Anagrafici" && reader.tokenType() == QXmlStreamReader::EndElement)) {

                            if(reader.name() == "Nome") {
                                nome = reader.readElementText();
                            }

                            if(reader.name() == "Cognome") {
                                cognome = reader.readElementText();
                            }

                            if(reader.name() == "Email") {
                                email = reader.readElementText();
                            }

                            if(reader.name() == "Data_Nascita") {
                                datanascita = QDate::fromString(reader.readElementText(),"dd MM yyyy");
                            }

                            if(reader.name() == "Luogo_Nascita") {
                                luogonascita = reader.readElementText();
                            }

                            if(reader.name() == "Luogo_Residenza") {
                                luogoresidenza = reader.readElementText();
                            }

                            reader.readNextStartElement();
                        }
                        DAnagrafici dati(nome,cognome,email,datanascita,luogonascita,luogoresidenza);
                        profile.setDati(dati);
                    }

                    if(reader.name()=="Diploma" && reader.tokenType() == QXmlStreamReader::StartElement){
                        while(!(reader.name() == "Diploma" && reader.tokenType() == QXmlStreamReader::EndElement)){
                            if(reader.name() == "NomeDiploma") {
                                nomediploma = reader.readElementText();
                            }

                            if(reader.name() == "AnnoDiploma") {
                                annod = reader.readElementText().toInt();
                            }
                            reader.readNextStartElement();
                        }
                        TitoliStudio titoli(nomediploma,annod);

                        while(!(reader.name() == "Titoli_Studio" && reader.tokenType() == QXmlStreamReader::EndElement)){
                            if(reader.name() == "Laurea" && reader.tokenType() == QXmlStreamReader::StartElement){
                                while(!(reader.name() == "Laurea" && reader.tokenType() == QXmlStreamReader::EndElement)){

                                    if(reader.name() == "NomeLaurea") {
                                        nomelaurea = reader.readElementText();
                                    }

                                    if(reader.name() == "AnnoLaurea") {
                                        annol = reader.readElementText().toInt();
                                    }
                                    reader.readNextStartElement();
                                }
                                Laurea laurea(nomelaurea,annol);
                                titoli.addLaurea(laurea);
                            }
                            reader.readNextStartElement();
                        }
                        profile.setTitoli(titoli);
                    }

                    if(reader.name()=="Lavoro" && reader.tokenType() == QXmlStreamReader::StartElement){
                        Impieghi impieghi;
                        while(!(reader.name() == "Impieghi" && reader.tokenType() == QXmlStreamReader::EndElement)){
                            while(!(reader.name() == "Lavoro" && reader.tokenType() == QXmlStreamReader::EndElement)){

                                if(reader.name() == "Titolo") {
                                    titolo = reader.readElementText();
                                }

                                if(reader.name() == "Azienda") {
                                    azienda = reader.readElementText();
                                }

                                if(reader.name() == "Citta") {
                                    citta = reader.readElementText();
                                }

                                if(reader.name() == "Inizio") {
                                    inizio = QDate::fromString(reader.readElementText(),"dd MM yyyy");
                                }

                                if(reader.name() == "Fine") {
                                    fine = QDate::fromString(reader.readElementText(),"dd MM yyyy");
                                }

                                reader.readNextStartElement();
                            }
                            Lavoro lavoro(titolo,azienda,citta,inizio,fine);
                            impieghi.addLavoro(lavoro);
                            reader.readNextStartElement();
                        }
                        profile.setImpieghi(impieghi);
                    }

                    if(reader.name()=="Username" && reader.tokenType() == QXmlStreamReader::StartElement){
                        user = reader.readElementText();
                    }

                    reader.readNextStartElement();
                }

                if(tipo == "Basic")
                    utente = new UBasic(profile,user);
                if(tipo == "Business")
                    utente = new UBusiness(profile,user);
                if(tipo == "Executive")
                    utente = new UExecutive(profile,user);
                Aggiungi(user,utente);
                reader.readNextStartElement();

            }
        }

        if(reader.name()=="Reti" && reader.tokenType() == QXmlStreamReader::StartElement){
            reader.readNextStartElement();
            while(!(reader.name() == "Reti" && reader.tokenType() == QXmlStreamReader::EndElement)){
                users = reader.readElementText();
                coppia = users.split("-");
                userA = coppia.at(0);
                userB = coppia.at(1);
                utenteA = getUtente(userA);
                utenteB = getUtente(userB);
                utenteA->add(utenteB);

                reader.readNextStartElement();
            }
        }

        reader.readNextStartElement();
        stresstest++;
    }

    file.close();

}

void Database::save() const{
    QFile file(path);
    file.open(QIODevice::WriteOnly);
    QXmlStreamWriter writer(&file);
    std::map<QString,Utente*>::const_iterator it = db.begin();
    writer.setAutoFormatting(true);
    writer.writeStartDocument();
    writer.writeStartElement("LinQedInDatabase");
        writer.writeStartElement("Utenti");
        int dbsize = db.size();
        for(int i=0;i<dbsize;++i){
            writer.writeStartElement("Utente");
            QString tipo = typeid(*(*it).second).name();
            if(tipo.contains("Basic"))
              writer.writeAttribute("type","Basic");
            if(tipo.contains("Business"))
              writer.writeAttribute("type","Business");
            if(tipo.contains("Executive"))
              writer.writeAttribute("type","Executive");
                writer.writeStartElement("Profilo");
                    writer.writeStartElement("Dati_Anagrafici");
                        writer.writeTextElement("Nome",(*it).second->getProfilo().getDati().getNome());
                        writer.writeTextElement("Cognome",(*it).second->getProfilo().getDati().getCognome());
                        writer.writeTextElement("Email",(*it).second->getProfilo().getDati().getEmail());
                        writer.writeTextElement("Data_Nascita",(*it).second->getProfilo().getDati().getData_nascita().toString("dd MM yyyy"));
                        writer.writeTextElement("Luogo_Nascita",(*it).second->getProfilo().getDati().getLuogo_nascita());
                        writer.writeTextElement("Luogo_Residenza",(*it).second->getProfilo().getDati().getLuogo_residenza());
                    writer.writeEndElement();
                    writer.writeStartElement("Titoli_Studio");
                        writer.writeStartElement("Diploma");
                            writer.writeTextElement("NomeDiploma",(*it).second->getProfilo().getTitoli().getDiploma());
                            writer.writeTextElement("AnnoDiploma",QString::number((*it).second->getProfilo().getTitoli().getAnno()));
                        writer.writeEndElement();
                    int vsize = (*it).second->getProfilo().getTitoli().getLauree().size();
                        for (int i=0;i<vsize;++i) {
                        writer.writeStartElement("Laurea");
                            writer.writeTextElement("NomeLaurea",(*it).second->getProfilo().getTitoli().getLauree()[i].getNome());
                            writer.writeTextElement("AnnoLaurea",QString::number((*it).second->getProfilo().getTitoli().getLauree()[i].getAnno()));
                        writer.writeEndElement();
                        }
                    writer.writeEndElement();
                    list<Lavoro> lista_lavori = (*it).second->getProfilo().getImpieghi().getLavori();
                    vsize = lista_lavori.size();
                    if(vsize!=0){
                        list<Lavoro>::const_iterator it = lista_lavori.begin();
                        writer.writeStartElement("Impieghi");
                        for (int i=0;i<vsize;++i){
                            writer.writeStartElement("Lavoro");
                            writer.writeTextElement("Titolo",(*it).getTitolo());
                            writer.writeTextElement("Azienda",(*it).getAzienda());
                            writer.writeTextElement("Citta",(*it).getCitta());
                            writer.writeTextElement("Inizio",(*it).getInizio().toString("dd MM yyyy"));
                            writer.writeTextElement("Fine",(*it).getFine().toString("dd MM yyyy"));
                            writer.writeEndElement();
                            ++it;
                        }
                        writer.writeEndElement(); //impieghi
                    }
                writer.writeEndElement();  //profilo
                writer.writeTextElement("Username",(*it).second->getUsername());
            writer.writeEndElement();  //utente
            it++;
        }
        writer.writeEndElement();  //utenti

        writer.writeStartElement("Reti");
        it = db.begin();
        for(int i=0;i<dbsize;++i){
            if((*it).second->getRete() != NULL){
                std::map<QString,Nodo>::const_iterator iter = (*it).second->getRete()->rete.begin();
                int netsize = (*it).second->getRete()->rete.size();
                for(int j=0;j<netsize;j++){
                    if((*iter).second.getFlag()){
                        QString a,b;
                        a = (*it).second->getUsername();
                        a.append("-");
                        b = (*iter).first;
                        a.append(b);
                        writer.writeTextElement("Link",a);
                    }
                    iter++;
                }
            }
            it++;
        }

    writer.writeEndDocument();  //LinQedInDatabase
    file.close();
}

void Database::Aggiungi(const QString& us,Utente* ut){
    db.insert(std::pair<QString,Utente*>(us,ut));
}

void Database::Elimina(const QString& ut){
    Utente* tmp = db.find(ut)->second;
    db.erase(ut);
    delete tmp;
}

Utente* Database::getUtente(const QString& u) const{
    map<QString,Utente*>::const_iterator it = db.find(u);
    if(it!=db.end())
        return it->second;
    return 0;
}

map<QString,Utente*> Database::find(const QString& s) const{
    if(s=="")
        return db;
    else{
        map<QString,Utente*> datatmp;
        map<QString,Utente*>::const_iterator it = db.find(s);
        if(it!=db.end())
            datatmp.insert(std::pair<QString,Utente*>((*it).first,(*it).second));
        return datatmp;
    }

}
