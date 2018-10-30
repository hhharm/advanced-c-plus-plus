#include "stdafx.h"
#include "Polynom.h"

Polynom::Polynom()
{
	head = new Node;
	head->next = head;
}

void Polynom::PushMonom(Monom &monom)
{
	Node *i = head->next, *prev = head;
	int curHash, monHash = monom.GetHash();
	while (i != head)
	{
		curHash = i->value.GetHash();
		if (curHash == monHash)
		{
			i->value.SetCoef(i->value.GetCoef() + monom.GetCoef());
			if (abs(i->value.GetCoef()) < 0.0001) 
			{
				prev->next = i->next;
				delete i;			
			}
			return;
		}
		else 
			if (curHash > monHash) break;
		prev = i;
		i = i->next;
	}
		Node *n = new Node;
		n->value = monom;
		prev->next = n;
		n->next = i;
}

double Polynom::Calc(double x, double y, double t)
{
	Iterator it = this->iterator();
	double res = 0.0;
	while (it.HasNext())
	{
		res += it.Next().Calc(x,y,t);
	}
	return res;
}

bool Iterator::HasNext() 
{
	if (cur == first) return false;
	return true;
}

Monom& Iterator::Next()
{
	
	Monom *res = &(cur->value);
	cur = cur->next;
	return (*res);
}