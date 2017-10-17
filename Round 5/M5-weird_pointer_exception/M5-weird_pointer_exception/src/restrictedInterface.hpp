#pragma once
#include "restrictedPtrEx.hpp"
#include <iostream>

template<typename T>
WeirdMemoryAllocator::restrictedPtr<T> makeRestricted(T* ptr)
{
	// implement the makeRestricted interface here
	try
	{
        WeirdMemoryAllocator::restrictedPtr<T> new_rp(ptr,"restrictedptr instance");
        return new_rp;

	}catch(WeirdMemoryAllocator::restrictedPtrEx& ex)
	{
        WeirdMemoryAllocator::restrictedPtr<T> nullPtr;
        return nullPtr;
	}
}

template<typename T>
WeirdMemoryAllocator::restrictedPtr<T> copyRestricted(WeirdMemoryAllocator::restrictedPtr<T>& w_restrPtr)
{
	// implement the copyRestricted interface here

	try
	{
        WeirdMemoryAllocator::restrictedPtr<T> rp = w_restrPtr;
        return  rp;
	}catch(WeirdMemoryAllocator::restrictedPtrEx& ex)
	{
	    std::cout<<ex.getError()<<std::endl;
        WeirdMemoryAllocator::restrictedPtr<T> nullPtr;
        return nullPtr;
	}

}

template<typename T>
void printRestricted(WeirdMemoryAllocator::restrictedPtr<T>& w_restrPtr)
{
	// implement the printRestricted interface here
	// both exception and value printing should end in newline
	try{
	    std::cout<<w_restrPtr.getData()<<std::endl;
	}catch(WeirdMemoryAllocator::restrictedPtrEx& e)
	{
        std::cout<<e.getError()<<std::endl;
	}

}
