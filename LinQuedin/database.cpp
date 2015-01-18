#include "database.h"
#include "qstringlist.h"

void Database::load(){
    QString nome,cognome,email,luogonascita,luogoresidenza,nomediploma,nomelaurea,azienda, titolo,citta,user,users,userA,userB;
    QDate datanascita,inizio, fine;
    QStringList coppia;
    int annod, annol;

    Utente* utente;

    QString path("/home/giacomo/Scrivania/P2/PROGETTO/LinQuedin/input.xml");
    QFile file(path);
    file.open(QIODevice::ReadOnly);
    QXmlStreamReader reader(&file);
    reader.readNextStartElement();
    std::cout<<reader.name().toString().toStdString();


    while(!(reader.name()=="Database" && reader.tokenType() == QXmlStreamReader::EndElement)){
        if(reader.name()=="Utenti" && reader.tokenType() == QXmlStreamReader::StartElement){
            while(!(reader.name()=="Utenti" && reader.tokenType() == QXmlStreamReader::EndElement)){
                Profilo profile;
                while(!(reader.name()=="Utente" && reader.tokenType() == QXmlStreamReader::EndElement)){
                    std::cout<<reader.name().toString().toStdString()<<std::endl;

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
                        profile.setDati(dati); //fase 1
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
                        profile.setTitoli(titoli); //fase 2
                    }

                    if(reader.name()=="Lavoro" && reader.tokenType() == QXmlStreamReader::StartElement){
                        Impieghi impieghi;
                        while(!(reader.name() == "Impieghi" && reader.tokenType() == QXmlStreamReader::EndElement)){
                            while(!(reader.name() == "Lavoro" && reader.tokenType() == QXmlStreamReader::EndElement)){
                                if(reader.name() == "Azienda") {
                                    azienda = reader.readElementText();
                                }

                                if(reader.name() == "Titolo") {
                                    titolo = reader.readElementText();
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
                            Lavoro lavoro(azienda,titolo,citta,inizio,fine);
                            impieghi.addLavoro(lavoro);
                            reader.readNextStartElement();
                        }
                        profile.setImpieghi(impieghi);  //fase 3
                    }

                    if(reader.name()=="Username" && reader.tokenType() == QXmlStreamReader::StartElement){
                        user = reader.readElementText();
                    }

                    reader.readNextStartElement();
                }

                utente = new Utente(profile,user);  //costruisco l'utente  DA MODIFICARE
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
                utente = db.find(userA)->second;
                utente->add(userB,*this);

                reader.readNextStartElement();
            }
        }

        reader.readNextStartElement();
    }

    file.close();
    std::cout<<std::endl;
}

void Database::save() const{
    QString path("/home/giacomo/Scrivania/P2/PROGETTO/LinQuedin/output.xml");
    QFile file(path);
    file.open(QIODevice::WriteOnly);
    QXmlStreamWriter writer(&file);
    std::map<QString,Utente*>::const_iterator it = db.begin();
    writer.setAutoFormatting(true);
    writer.writeStartDocument();
    writer.writeStartElement("Database");
        writer.writeStartElement("Utenti");
        int dbsize = db.size();
        for(int i=0;i<dbsize;++i){
            writer.writeStartElement("Utente");
                writer.writeStartElement("Profilo");
                    writer.writeStartElement("Dati_Anagrafici");
                        writer.writeTextElement("Nome",(*it).second->profile.getDati().getNome());
                        writer.writeTextElement("Cognome",(*it).second->profile.getDati().getCognome());
                        writer.writeTextElement("Email",(*it).second->profile.getDati().getEmail());
                        writer.writeTextElement("Data_Nascita",(*it).second->profile.getDati().getData_nascita().toString("dd MM yyyy"));
                        writer.writeTextElement("Luogo_Nascita",(*it).second->profile.getDati().getLuogo_nascita());
                        writer.writeTextElement("Luogo_Residenza",(*it).second->profile.getDati().getLuogo_residenza());
                    writer.writeEndElement();
                    writer.writeStartElement("Titoli_Studio");
                        writer.writeStartElement("Diploma");
                            writer.writeTextElement("NomeDiploma",(*it).second->profile.getTitoli().getDiploma());
                            writer.writeTextElement("AnnoDiploma",QString::number((*it).second->profile.getTitoli().getAnno()));
                        writer.writeEndElement();
                    int vsize = (*it).second->profile.getTitoli().getLaurea().size();
                        for (int i=0;i<vsize;++i) {
                        writer.writeStartElement("Laurea");
                            writer.writeTextElement("NomeLaurea",(*it).second->profile.getTitoli().getLaurea()[i].getNome());
                            writer.writeTextElement("AnnoLaurea",QString::number((*it).second->profile.getTitoli().getLaurea()[i].getAnno()));
                        writer.writeEndElement();
                        }
                    writer.writeEndElement();
                    vsize = (*it).second->profile.getImpieghi().getLavoro().size();
                    if(vsize!=0){
                        writer.writeStartElement("Impieghi");
                        for (int i=0;i<vsize;++i){
                            writer.writeStartElement("Lavoro");
                            writer.writeTextElement("Azienda",(*it).second->profile.getImpieghi().getLavoro()[i].getAzienda());
                            writer.writeTextElement("Titolo",(*it).second->profile.getImpieghi().getLavoro()[i].getTitolo());
                            writer.writeTextElement("Citta",(*it).second->profile.getImpieghi().getLavoro()[i].getCitta());
                            writer.writeTextElement("Inizio",(*it).second->profile.getImpieghi().getLavoro()[i].getInizio().toString("dd MM yyyy"));
                            writer.writeTextElement("Fine",(*it).second->profile.getImpieghi().getLavoro()[i].getFine().toString("dd MM yyyy"));
                            writer.writeEndElement();
                        }
                        writer.writeEndElement(); //impieghi
                    }
                writer.writeEndElement();  //profilo
                writer.writeTextElement("Username",(*it).second->username);
            writer.writeEndElement();  //utente
            it++;
        }
        writer.writeEndElement();  //utenti

        writer.writeStartElement("Reti");
        it = db.begin();
        for(int i=0;i<dbsize;++i){
            if((*it).second->net != NULL){
                std::map<QString,Nodo>::const_iterator iter = (*it).second->net->rete.begin();
                int netsize = (*it).second->net->rete.size();
                for(int j=0;j<netsize;j++){
                    if((*iter).second.flag){
                        QString a,b;
                        a = (*it).second->username.append("-");
                        //a.append("-");
                        b = (*iter).first;
                        a.append(b);
                        writer.writeTextElement("Link",a);
                    }
                    iter++;
                }
            }
            it++;
        }

    writer.writeEndDocument();  //Database
    file.close();
}

void Database::Aggiungi(const QString& us,Utente* ut){
    db.insert(std::pair<QString,Utente*>(us,ut));
}

void Database::Elimina(const QString& ut){
    db.erase(ut);
    //da completare
}

Utente* Database::getUtente(const QString& u) const{
    return db.find(u)->second;
}

void Database::checkflag() const{

}

