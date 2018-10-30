#pragma once
#include "CB.h"

class StackIsEmpty{};
class StackIsFull{};

class MyStack
{
	CircularBuffer *buf;
	int size;
public:
	MyStack(int size = 10);
	~MyStack();
	MyStack(const MyStack &a);
	void operator=(MyStack a);

	ElemType& ReadEl(int i);
	void Push(ElemType *a);
	ElemType Pop();

	bool IsFull();
	bool IsEmpty();

	int GetSize();
	int GetStart();
	int GetEnd();
	void Clean();
};