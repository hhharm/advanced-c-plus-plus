
#include "stdafx.h"
#include "Stack.h"

MyStack::MyStack(int size)
{
		this->size = size;
		buf = new CircularBuffer(size);
}
MyStack::~MyStack()
{
	delete buf;
}

MyStack::MyStack(const MyStack &b)
{
	*this->buf = *b.buf;
	size = b.size;
}

void MyStack::operator= (MyStack a)
{
	*buf = *a.buf;
	size = a.size;
}

void MyStack::Push(ElemType *a)
{
	if(buf->IsFull()) buf->PopBack();
	buf->PushFront(a);	
}

ElemType MyStack::Pop()
{
	if(!buf->IsEmpty())
		return buf->PopFront();
	else
		throw StackIsEmpty();
}

bool MyStack::IsFull(){return buf->IsFull();}
bool MyStack::IsEmpty(){return buf->IsEmpty();}


ElemType& MyStack::ReadEl(int i)
{
	if (!IsEmpty())
	return buf->Read(i);
	else throw StackIsEmpty();
}
int MyStack::GetSize(){return buf->Size();}
int MyStack::GetStart(){return buf->Start();}
int MyStack::GetEnd(){return buf->End();}


void MyStack::Clean(){
	while (!IsEmpty()) Pop();
}

