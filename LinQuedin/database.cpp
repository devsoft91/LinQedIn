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
    int annod, annol;

    Utente* utente;
    Utente* utenteA;
    Utente* utenteB;

    QString path("/home/giacomo/Scrivania/P2/PROGETTO/LinQuedin/database.xml");
    QFile file(path);
    file.open(QIODevice::ReadOnly);
    QXmlStreamReader reader(&file);
    reader.readNextStartElement();

    while(!(reader.name()=="Database" && reader.tokenType() == QXmlStreamReader::EndElement)){
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
                        profile.setImpieghi(impieghi);  //fase 3
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
                utenteB = getUtente(userB);//attenzione core dump se non esiste utente A
                utenteA->add(utenteB);

                reader.readNextStartElement();
            }
        }

        reader.readNextStartElement();
    }

    file.close();

}

void Database::save() const{
    QString path("/home/giacomo/Scrivania/P2/PROGETTO/LinQuedin/database.xml");
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
            QString tipo = typeid(*(*it).second).name();
            if(tipo.contains("Basic"))
              writer.writeAttribute("type","Basic");
            if(tipo.contains("Business"))
              writer.writeAttribute("type","Business");
            if(tipo.contains("Executive"))
              writer.writeAttribute("type","Executive");
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
                    list<Lavoro> lista_lavori = (*it).second->profile.getImpieghi().getLavori();
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
                        a = (*it).second->username;
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

    writer.writeEndDocument();  //Database
    file.close();
}

void Database::Aggiungi(const QString& us,Utente* ut){
    db.insert(std::pair<QString,Utente*>(us,ut));
}

void Database::Elimina(const QString& ut){
    Utente* tmp = db.find(ut)->second;
    db.erase(ut);
    std::cout<<"Elimina\n";
    delete tmp;
}

Utente* Database::getUtente(const QString& u) const{
    std::map<QString,Utente*>::const_iterator it = db.find(u);
    if(it!=db.end())
        return it->second;
    return 0;
}

void Database::checkflag() const{

}

