#pragma once
#include <exception>
#include <string>
#include <iostream>

// TODO:
// define here the exception classes, also wrap
// this around WeirdMemoryAllocator namespace
// also implement the exception throws to the restrictedPtr class below
#define MAXREFCOUNT 3
namespace  WeirdMemoryAllocator
{
class restrictedPtrEx: public std::exception
{
public:
    restrictedPtrEx(){}
    virtual std::string getError() const throw()
    {
        std::string str = ": Exception throwed!";
        return str;
    }
};

class restrcitedCopyException: public restrictedPtrEx
{
public:
    restrcitedCopyException(const std::string& use):restrictedPtrEx(),s(use){}

    std::string getError() const throw()
    {
        std::string str= s +": Too many copies of restrictedPtr!";
	    return str;
    }
private:
    std::string s;
};

class restrictedNullException: public restrictedPtrEx
{
public:
    restrictedNullException(const std::string& use):restrictedPtrEx(),s(use){}
    std::string getError() const throw()
    {
	    std::string str= s +": nullptr exception!";
	    return str;
    }
private:
    std::string s;
};

class restrictedRefCounter
{
public:
	restrictedRefCounter() : refCount(0) {}
	bool addReference()
	{
		if(refCount < MAXREFCOUNT)
		{
			refCount++;
			return true;
		}
		return false;

	}
	int removeReference()
	{
		refCount--;
		return refCount;
	}

	int getRefCount()
	{
		return refCount;
	}

private:
	int refCount;
};


template<typename T> class restrictedPtr
{
public:

	// empty constructor
	restrictedPtr() : rawPointer(nullptr), refCounter(new restrictedRefCounter()), use("nullptr")
	{
		refCounter->addReference();
	}

	// constructor when it is called with a pointer
	restrictedPtr(T* pointerVal, const std::string w_use) : rawPointer(pointerVal), refCounter(nullptr), use(w_use)
	{
		refCounter = new restrictedRefCounter();
		refCounter->addReference();
	}

	// copy constructor
	restrictedPtr(const restrictedPtr<T>& restrPtr)
	{
		// TODO: throw copy exception if ref count exceeds 3!

		if(restrPtr.refCounter->addReference())
		{
			// only one ref addition is needed, as all restrictedPtr instances (that point to the same pointer) share the same refCounter
			rawPointer = restrPtr.rawPointer;
			refCounter = restrPtr.refCounter;
			use = restrPtr.use;
		}
		else
            throw restrcitedCopyException(restrPtr.use);
	}

	// destructor, only delete the object if the reference count drops to zero
	~restrictedPtr()
	{
		if(refCounter)
		{
			if(refCounter->removeReference() == 0)
			{
				if(rawPointer != nullptr)
				{
					delete rawPointer;
				}
				delete refCounter;
				refCounter = nullptr;
			}
		}
	}

	// copy assignment
	restrictedPtr<T>& operator = (const restrictedPtr<T>& restrPtr)
	{
		// don't assign to the same object!
		if(&restrPtr != this)
		{
			// remove one reference from this old pointer
			if(refCounter)
			{
				if(refCounter->removeReference() == 0)
				{
					if(rawPointer != nullptr)
					{
						delete rawPointer;
					}
					delete refCounter;
					refCounter = nullptr;
				}
			}
			// do copy
			// also check addRef return val
			// TODO: Throw copy exception if reference count exceeds 3!


			if(restrPtr.refCounter->addReference())
			{
				rawPointer = restrPtr.rawPointer;
				refCounter = restrPtr.refCounter;
				use = restrPtr.use;
			}
            else
                throw  restrcitedCopyException(use);
			//refCounter->addReference();
		}
		return *this;
	}

	// member function to get the data from pointer
	// this is given as a reference, so it can be modified
	T& getData()
	{
		// TODO: throw null exception if rawPointer is null!
		if(rawPointer==nullptr)
        {
            throw restrictedNullException(use);
        }
		return *rawPointer;
	}

	// member function to get the pointer address
	T* getPointer()
	{
		return rawPointer;
	}

	// get ref count
	int getRefCount()
	{
		// TODO: throw null exception if refCounter is null!
		if(refCounter==nullptr)
        {
            throw restrictedNullException(use);
        }
		return refCounter->getRefCount();
	}

	// get the use for this pointer allocation
	std::string getUse()
	{
		return use;
	}


private:
	T* rawPointer;
	restrictedRefCounter* refCounter;
	std::string use;
}; // class restrictedPtr






}
