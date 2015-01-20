#ifndef PRIMOAPPELLO1314_H
#define PRIMOAPPELLO1314_H

class Z{
private:
    int x;
};

class B{
private:
    Z x;
};

class D : public B{
private:
    Z y;
public:
    //ridefinizione operator=
    D& operator=(const D& d){
        this->B::operator=(d);
        y=d.y;
        return *this;
    }
};

#endif // PRIMOAPPELLO1314_H

//-----------------------------------------------------------------------------------------------------------------------------------------------
//Capo astratta
class Capo{
private:
    string brand;
    int taglia;
public:
    Capo(string b = "nobrand", int t = 40) : brand(b),taglia(t){}
    virtual ~Capo(){}
    virtual bool operator==(const Capo& c) const{
        return brand==c.brand && taglia==c.taglia;
    }

};

class Tshirt : public Capo{
private:
    bool corta;
public:
    Tshirt(string b = "nobrand", int t=40, bool c = true) : Capo(b,t),corta(c){}
    virtual bool operator==(const Capo& c) const{
        return typeid(const Tshirt&)==typeid(c) && Capo::operator ==(c) && corta == static_cast<const Tshirt&>(c).corta;
    }
};

class Jeans : public Capo{
private:
    int fondo; //in cm
public:
    Jeans(string b = "nobrand", int t=40, int f = 20) : Capo(b,t),fondo(f){}
    virtual bool operator==(const Capo& c) const{
        return typeid(const Jeans&)==typeid(c) && Capo::operator ==(c) && fondo == static_cast<const Jeans&>(c).fondo;
    }
};

class Articolo{
    friend class Zoox;
private:
    Capo* c; //puntatore polimorfo
    int q;  //quantita articoli
public:
    Articolo(Capo* p,int x=1): c(p),q(x){}
    int getQuantita() const {return q;}
    void setQuantita(int x=1) {q=0;} //da sostituire col metodo scarica
    bool uguale(const Capo& c) const{
        return *this == c;
    }
    int getFondo() const{ return fondo;}
};

class Exception{  //da completare
public:

};

class Zoox{
private:
    list<Articoli> mag;
public:
    int giacenza(const Capo& c) const{
        list<Articolo>::const_iterator it = mag.begin();
        for(;it != mag.end();++it)
            if(it->uguale(c)) return it->getQuantita();
        return 0;
    }
    vector<Jeans> getJeans(string m, int s, int f) const{
        vector<Jeans> v;
        list<Articolo>::const_iterator it = mag.begin();
        for(;it != mag.end();++it){
            Jeans* p = dynamic_cast<Jeans*>(it->c);
            if(p && Jeans(m,s).Capo::operator ==(*(it->c) && p->getFondo() >= f))
                v.push_back(*p);
        }
        return v;
    }
    void scarica(const Tshirt* pt) throw(Exception){
        list<Articolo>::const_iterator it = mag.begin();
        for(;it != mag.end();++it) {it->scarica(); return;}
        if(it==mag.end()) throw Exception("assente");
    }
    void insert(const Tshirt& t, int x){

    }

};
