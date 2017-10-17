#include <memory>
#include<iostream>
class RC
{
private:
    int count;
public:
    int get_count()
    {
        return count;
    }
    void add()
    {
        count++;
    }
    void decrease()
    {
        count--;
    }
    void reset()
    {
        count =1;
    }
};
template<typename T>
class restrictedPtr
{
public:
    restrictedPtr():pointer(0),rc(0){
    rc = new RC();
    rc->add();
    };
    restrictedPtr(T* a):pointer(a),rc(0)
    {
        rc= new RC();
        rc->add();
    }
    restrictedPtr<T>(restrictedPtr<T>& a)
    {
        std::cout<<a.getRC()->get_count()<<std::endl;

        if(a.getRC()->get_count()<3)
        {
            pointer = a.getPointer();
            rc = a.getRC();
            rc->add();
        }
        else
        {
            this->getPointer()=nullptr;
            rc = new RC;
            this->getRC()->reset();
        }
        std::cout<<a.getRC()->get_count()<<std::endl;

    }

    restrictedPtr<T>& operator=(restrictedPtr<T>& b)
    {
        std::cout<<b.getRC()->get_count()<<std::endl;

         if(getRC()->get_count()==1)
         {
             delete(pointer);
             delete(rc);
         }
        if(b.getRC()->get_count()<3)
        {
            pointer = b.getPointer();
            rc = b.getRC();
            rc->add();
        }
        else
        {
            this->getPointer()=nullptr;
            rc = new RC;
            this->getRC()->reset();
        }
        std::cout<<b.getRC()->get_count()<<std::endl;
        return *this;
    }

    ~restrictedPtr()
    {
       // std::cout<<rc->get_count()<<std::endl;
        rc->decrease();
        if(rc->get_count()==0)
        {
            delete(pointer);
            delete(rc);
        }
        std::cout<<rc->get_count()<<std::endl;
    }

    T& getData()
    {
        return *pointer;
    }

    T*& getPointer()
    {
        return pointer;
    }
    RC*& getRC()
    {
        return rc;
    }
private:
    T* pointer;
    RC* rc;
};

