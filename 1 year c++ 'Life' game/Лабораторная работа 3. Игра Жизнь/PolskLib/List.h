#pragma once
#pragma once
#include <stdlib.h>

class WrongIndexExp{};

template <class ElemType>
struct Node
{
	ElemType val;
	Node *Next;
};



template <class ElemType>
class List
{
	Node <ElemType> *head;
	Node <ElemType> *tail;
public:
	List()
	 {
		head = NULL;
		tail = NULL;
	 }

	~List()
	{
		Clean();
		delete head;
	}

	void Clean()
	{
		Node <ElemType> *t;
		while (head != NULL)
		 {
			t = head;
			head = head->Next;
			delete t;
		 }
	}

	//узнать, сколько элементов в списке
	int Count()
	{
		int c = 0;
		Node <ElemType> *cur = head;
		while (cur != NULL)
		 {
			c++;
			cur = cur->Next;
		 }
		return c;
	}

	//добавить элемент в начало
	void PushBegin(ElemType a)
	{
		Node <ElemType> *n;
		n = new Node <ElemType>;
		n->val = a;
		n->Next = head;
		head = n;
		if (tail == NULL) tail = head;
	}
	////добавить элемент a на i-ое место
	void Push(ElemType a, int i)
	{
		int c = Count();
		if (c < i) throw WrongIndexExp();
		if (i == 0) PushBegin(a);
		else if (i == c) PushLast(a);
		else
		 {
			int j;
			Node <ElemType> *t = head,  *n;
			for (j = 0; j < i; j++) t = t->Next;
			n = new Node <ElemType>;
			n->val = a;
			n->Next = t->Next->Next;
			t->Next = n;
		 }
	}

	//добавить элемент в конец
	void PushLast(ElemType a)
	{
		Node <ElemType> *n;
		n = new Node <ElemType>;
		n->val = a;
		n->Next = NULL;
		if (head != NULL)
		{
			tail->Next = n;	
			tail = n;	
			if (head->Next == NULL) head->Next = tail;
		}
		else
		{
			head = n;
			tail = n;
		}
	}
	
	//удалить первый эл
	void RemoveBegin()
	{
		if (head != NULL)
		{
			Node <ElemType> *n = head;
			if (tail == head) tail = head->Next;
			head = head->Next;	
			delete n;	
		}
	}	
	////удалить элемент на i-ом месте
	void Remove(int i)
	{
		int c = Count();
		if (c < i) throw WrongIndexExp();
		if (i == 0) RemoveBegin();
		else if (i == c) RemoveLast();
		else
		{
			int j;
			Node <ElemType> *t = head, *n;
			for (j = 0; j < i-1; j++) t = t->Next;
			n = t->Next;
			t->Next = t->Next->Next;
			delete n;
		}
	}
	//удалить последний элемент
	void RemoveLast()
	{
		if (head != NULL)
		{
			if (head != tail)
			 {
				Node <ElemType> *n = head, *t;
				int c = Count();
				for (int i = 0; i < c-2; i++) n = n->Next;
				t = n->Next;
				n->Next = NULL;
				tail = n;
				delete t;
			 }
			else {delete head; head = tail = NULL;  }
		}
	}


	ElemType ReadFirst(){return head->val;}
	ElemType ReadLast(){return tail->val;}

	//прочитать i-ый элемент
	ElemType operator[](int i)	
	{
		if (i > Count() || IsEmpty() || i < 0) throw "EX";
		int j;
		Node <ElemType> *t = head;
		for (j = 0; j < i; j++) t = t->Next;
		return t->val;
	}


	bool IsEmpty(){return head == NULL;}

};