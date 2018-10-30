#pragma once
#include "CB.h"

void CircularBuffer::Copy(CurrentField &a, CurrentField &b)
{
	for (int i = 0; i < a.Field->Row();i++)
	 for (int j = 0; j<a.Field->Colmns(); j++)
		{
			a.Field->SetEl(i,j,b.Field->GetEl(i,j));
		}

	 for (int i = 0; i < a.Res->Row();i++)
	 for (int j = 0; j<a.Res->Colmns(); j++)
		{
			a.Res->SetEl(i,j,b.Res->GetEl(i,j));
		}

	 for (int i = 0; i < a.Temp->Row();i++)
	 for (int j = 0; j<a.Temp->Colmns(); j++)
		{
			a.Temp->SetEl(i,j,b.Temp->GetEl(i,j));
		}
}

CircularBuffer::CircularBuffer(int size) 
{
	this->size  = size + 1; /* include empty elem */
    end   = size;
	start = 0;
	elems = new ElemType[this->size];
}

CircularBuffer::CircularBuffer(const CircularBuffer &a)
{
	 this->size = a.size;           
     this->start = a.start;                
     this->end = a.end;  
	 this->elems = new ElemType[size];
	 for (int i = 0; i < size; i++) Copy(elems[i], a.elems[i]);
}
 
CircularBuffer::~CircularBuffer() {
	
	delete [] elems; 
}
 
int CircularBuffer::IsFull() {
    return (end + 2) % size == start;
}
 
int CircularBuffer::IsEmpty() {
    return (end + 1) % size == start;
}

void CircularBuffer::PushFront(ElemType *elem) {
	if (!IsFull()){
    end = (end + 1) % size;

    Copy(elems[end], *elem);
	}
	else throw "CB is Full";
}
 void CircularBuffer::PushBack(ElemType *elem) {
	if (!IsFull()){
    start = (start + size - 1 ) % size;
	Copy(elems[start],*elem);
	}
	else throw "CB is Full";
}
/* Read last element. App must ensure !cbIsEmpty() first. */
ElemType CircularBuffer::PopFront() 
{
	if (!IsEmpty())
	{
	int old_end = end;
   end = (end - 1 + size) % size;
   return elems[old_end];
	}
	else throw "CB is empty";
}

ElemType CircularBuffer::PopBack() 
{
	if (!IsEmpty())
	{
	int old_start = start;
   start = (start + 1) % size;
   return elems[old_start];
	}
	else throw "CB is empty";
}



void CircularBuffer::operator=(CircularBuffer b)
{
	if (&b != this)
	{
		delete this;
		this->size = b.size;
		this->start = b.start;
		this->end = b.end;
		elems = new ElemType[size];
		int i = start;
		while (i != end)
		{
			Copy(elems[i],b.elems[i]);
			i=(i+1)%size;
		}
	}
}

ElemType& CircularBuffer::Read(int i)
{
	return this->elems[i];
}

int CircularBuffer::Size(){return size;}
int CircularBuffer::Start(){return start;}
int CircularBuffer::End(){return end;}
