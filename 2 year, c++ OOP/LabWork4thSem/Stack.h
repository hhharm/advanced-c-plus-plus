#pragma once

#include "stdafx.h"
#include "CB.h"

class StackIsEmpty{};
class StackIsFull{};
#define STACK_SIZE 20

class MyStack
{
	CircularBuffer *buf;
	int size;
public:
	MyStack(int size = STACK_SIZE);
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