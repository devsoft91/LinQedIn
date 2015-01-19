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
