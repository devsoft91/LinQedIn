#include "mainwindow.h"
#include <QApplication>
#include <QString>
#include <string>
#include <QDate>
#include <iostream>

#include "database.h"

using namespace std;

int main()
{/*
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
    DAnagrafici dati;
    QString a,b,c,e,f;
    QDate d(1995,6,1);

    a="Giacomo";
    b="Beltrame";
    c="cicccio@email.com";
    e="porcodio";
    f="madonna puttana";

    dati.setNome(a);
    dati.setCognome(b);
    dati.setEmail(c);
    dati.setData_nascita(d);
    dati.setLuogo_nascita(e);
    dati.setLuogo_residenza(f);

    cout<<endl;
    cout<<dati.getNome().toStdString()<<endl;
    cout<<dati.getCognome().toStdString()<<endl;
    cout<<dati.getEmail().toStdString()<<endl;
    cout<<dati.getData_nascita().toString("dd.MM.yyyy").toStdString()<<endl;
    cout<<dati.getLuogo_nascita().toStdString()<<endl;
    cout<<dati.getLuogo_residenza().toStdString()<<endl;*/

/*
    //PROVA SCRITTURA SU FILE XML
    QString nome,cognome,email,lnascita,residenza;
    QDate dnascita(1992,2,1);
    nome="Enrico";
    cognome="Infinity";
    email="einfinity@houncazzoenorme.com";
    lnascita="TrevisoLammoda";
    residenza="CazzoVoglio";
    DAnagrafici a(nome,cognome,email,dnascita,lnascita,residenza);

    QString diploma,nomelaurea;
    diploma="infinito";
    int anno1=2010;
    nomelaurea="informatica";
    int anno2=2015;
    Laurea laurea(nomelaurea,anno2);
    TitoliStudio b(diploma,anno1);
    b.addLaurea(laurea);

    QString azienda,titolo,citta;
    QDate inizio(2012,1,1);
    QDate fine(2012,1,2);
    azienda="infinitech";
    titolo="CEO";
    citta="Treviso";
    Lavoro l(azienda,titolo,citta,inizio,fine);
    Impieghi c(l);
    c.addLavoro(l);
    Profilo p(a,b,c);

    QString user1,user2;
    user1="b";
    user2="a";

    Utente u(p,user1);
    Utente ut(p,user2);

    Utente* punt=&u;
    Utente* puntatore=&ut;
*/
    //SCRIVO NEL DB
    Database db;
    db.load();
    Utente* utente1 = db.getUtente("a");
    utente1->add("b",db);
    //db.Aggiungi(u.username,punt);
    //db.Aggiungi(ut.username,puntatore);
    db.save();
    return 0;
}
