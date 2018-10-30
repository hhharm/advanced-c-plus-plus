#pragma once
#include "List.h"


class QueueIsEmpty{};
class QueueIsFull{};

template <class ElemType>
class QueueList
{
	List <ElemType> *list;
public:
	QueueList()	{list = new List <IToken*>;}

	~QueueList(){delete list;	 }

	QueueList(const QueueList &a) 
	{
		list = new List <IToken*>;
		int n = a.list->Count();
		for (int i = 0; i < n; i++)
			Push(a.list->operator[](i));
	}

	void operator=(QueueList a)		
	{
		Clean();
		int n = a.list->Count();
		for (int i = 0; i < n; i++)
			Push(a.list->operator[](i));
	}

	ElemType ReadEl(int i) 
		{
		if (!IsEmpty())
			return list->operator[](i);
		else throw QueueIsEmpty();
	}

	void Push(ElemType a)
	{
		list->PushLast(a);	
	}
	ElemType Pop()		
	{

		if(!IsEmpty())
		{
			ElemType t = list->ReadFirst();
			list->RemoveBegin();
			return t;
		}
		else
			throw QueueIsEmpty();
	} 

	bool IsEmpty() {return list->IsEmpty();}

	int GetSize() {return list->Count();}

	int GetStart() {return 0;}

	int GetEnd() {return list->Count()-1;}

	ElemType ReadHead() {return list->ReadLast();}

	void Clean(){list->Clean();}

};

