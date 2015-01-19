#ifndef ES_IOS_H
#define ES_IOS_H

class D:public ios{};

int F(ios& ref){
    if( dynamic_cast<istream*>(&ref)  //TD(ref) <= istream
    &&
    !dynamic_cast<ostream*>(&ref)  //TD(ref) </= ostream
            ) return -1;

    //TD(ref) non è una classe di input

    if( dynamic_cast<ostream*>(&ref)  //TD(ref) <= istream
    &&
    !dynamic_cast<istream*>(&ref)  //TD(ref) </= ostream
            ) return 1;

    //TD(ref) non è una classe di input e non è una classe di output

    if(dynamic_cast<istream*>(&ref) && dynamic_cast<ostream*>(&ref)) return 0;

    //TD(ref) non è ne input output inputoutput

    return 9;

}

#endif // ES_IOS_H
//---------------------------------------------------------------------------------------------------------------------------------------------

//T1 e T2 tipi polimorfi (ok RTTI)
template<class T1, class T2>
bool fun(T1* p,T2& r){
    return typeid(T1) == typeid(T2) && typeid(*p) == typeid(r) && dynamic_cast<ios*>(p);
}
