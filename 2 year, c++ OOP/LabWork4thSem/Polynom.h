#pragma once
#include "stdafx.h"
#include "Monom.h"

struct Node
{
	Monom value;
	Node *next;
};



class Iterator
{
	Node *cur, *first;
public:
	Iterator(Node* _first): first(_first), cur(_first->next) {}
	Monom& Next();
	bool HasNext();
};


class Polynom
{
	Node *head;

public:	
	Polynom();
	~Polynom();
	void PushMonom(Monom &monom);
	Polynom& operator+(Polynom &b){return *this;}
	double Calc(double x, double y, double t);
	Iterator iterator() {return *(new Iterator(head));}
	void Clear() {
		Node *i = head->next, *cur;
		while (i != head)
		{
			cur = i;
			i = i->next;
			delete cur;			
		}
		head->next = head;
	}
	
};
