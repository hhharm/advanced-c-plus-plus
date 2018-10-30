#pragma once 
#include "List.h"


template <class ElemType>
class StackList
{
	List <ElemType>  *list;
public:
	class StackIsEmpty{};
	class StackIsFull{};

	StackList(){		list = new List <ElemType>;}

	~StackList() {	delete list;}

	StackList(const StackList &a) 
	{throw "Dont!";
		for (int i = a.GetStart(); a < a.GetSize(); a++)
			Push(a.ReadEl(i));
	}

	void operator = (StackList a)
	{throw "Dont!";
		Clean();
		for (int i = a.GetStart(); a < a.GetSize(); a++)
			Push(a.ReadEl(i));
	}

	ElemType ReadEl(int i)		
	{
		if (!IsEmpty())
			return list->operator[](i);
		else throw StackIsEmpty();
	}

	void Push(ElemType a)
	{
		list->PushLast(a);	
	}

	ElemType Pop()
	{
		if(!IsEmpty())
		 {
			ElemType t = list->ReadLast();

			list->RemoveLast();
			return t;

		 }
		else
			throw StackIsEmpty();
	}

	bool IsEmpty(){return list->IsEmpty();}

	int GetSize() {return list->Count();}

	int GetStart() {return 0;}

	int GetEnd() {return list->Count()-1;}

	void Clean() {	list->Clean();}
};



const int SIZE_STACK = 10;

template <class ElemType>
class ArrStack
{
	int *mem;
	int size;
	int end;
public:
	ArrStack(int _size = SIZE_STACK)
	{
	mem = new ElemType[_size];
	if (_size == 0) mem = NULL;
	size = _size;
	end = -1;
	}

	ArrStack(const ArrStack &a)
	{
	this->mem = new  ElemType[a.size];
	this->size = a.size;
	for (int i = 0; i < size; i++)
		mem[i] = a.mem[i];
	end = a.end;
	}
	~ArrStack() {	if (mem != NULL) delete [] mem;}

	class FullStackExp{};
	class EmptyStackExp{};

	bool IsEmpty() const { return (end == -1);	  }
	bool IsFull() const  { return end == size - 1;}
	void Push(ElemType Val)
	{
		if (IsFull()) throw FullStackExp();
		end++;
		mem[end] = Val;
	}

	ElemType Pop()		
	{
		if (IsEmpty()) throw EmptyStackExp();
		return mem[end--];
	}
	
	int NumOfElem() {return end;}

	ElemType ReadHead() {return mem[end];}

};