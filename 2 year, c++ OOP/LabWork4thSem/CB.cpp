#pragma once

#include "stdafx.h"
#include "CB.h"


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
	 for (int i = 0; i < size; i++) this->elems[i] = a.elems[i];
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

    elems[end] = *elem;
	}
	else throw "CB is Full";
}
 void CircularBuffer::PushBack(ElemType *elem) {
	if (!IsFull()){
    start = (start + size - 1 ) % size;
	elems[start] = *elem;
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
			this->elems[i] = b.elems[i];
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
