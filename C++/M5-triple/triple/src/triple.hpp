#ifndef TRIPLE_HH
#define TRIPLE_HH
/* Add include guards here */
#include <string>
#include <list>
#include <vector>
#include<typeinfo>
using namespace std;

template <typename T1, typename T2, typename T3>
class Triple
{
public:
    Triple(T1 t1,T2 t2,T3 t3):First(t1),Second(t2),Third(t3){}
    const T1& first() const  {return First;}
    const T2& second() const {return Second;}
    const T3& third()  const {return Third;}
    const Triple<T1,T2,T3>& operator=(Triple<T1,T2,T3>& b)
    {
     First = b.first();
     Second= b.second();
     Third = b.third();
     return *this;
    }
private:
    T1 First;
    T2 Second;
    T3 Third;
};

template<typename T1, typename T2, typename T3>
bool isHomogenous(const Triple<T1,T2,T3>& t)
{
    if(typeid(t.first())==typeid(t.second()))
       {
            if(typeid(t.first())==typeid(t.third()))
                return true;
       }

   return false;
}

template<typename T1, typename T2, typename T3>
Triple<T1,T2,T3>& makeTriple(T1 t1, T2 t2, T3 t3)
{
    Triple<T1,T2,T3>* new_triple;
    new_triple = new Triple<T1,T2,T3>(t1, t2, t3);
    return *new_triple;
}

 template <typename T1,typename T2,typename T3>
 bool operator==(const Triple<T1,T2,T3>& a,const Triple<T1,T2,T3>& b)
 {
     T1 x1 = a.first();
     T1 x2 = b.first();
     T2 y1 = a.second();
     T2 y2 = b.second();
     T3 z1 = a.third();
     T3 z2 = b.third();
     if(x1 == x2&& y1==y2 && z1==z2)
        return true;
     else
        return false;
 }

 template <typename T1, typename T2, typename T3>
  bool operator!=(const Triple<T1,T2,T3>& a,const Triple<T1,T2,T3>& b)
 {
     if(a.first()!=b.first() || a.second()!=b.second() || a.third()!=b.third())
        return true;
     else
        return false;
 }


template<typename T1,typename T2,typename T3>
ostream& operator<<(ostream& os,const Triple<T1,T2,T3>& t)
{

    os<< "[" << t.first() << ", " << t.second() << ", " << t.third() << "]";
    return os;
}

#endif
