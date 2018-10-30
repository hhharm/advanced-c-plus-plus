#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "Field.h"
#include "Fill.h"

 
/* ��� ��������, ��������� � ������ */
typedef CurrentField ElemType;
 
/* ��� ����� */
class CircularBuffer
 { 
    int         size;   // ����� ���������          
    int         start;  // ������ ������� ��������              
    int         end;    // ������ �����, ��� �� ����� ���������  
    ElemType   *elems;  // ��������� �� ������ ���������                 
 public:
	CircularBuffer(int size = 20);
	CircularBuffer(const CircularBuffer &a);
	~CircularBuffer();
	int IsFull();
	int IsEmpty();

	void PushFront(ElemType *elem);
	void PushBack(ElemType *elem);


	void operator =(CircularBuffer b);

	/* ����������� ���������. ����� ������ ��������� !cbIsEmpty(). */
	ElemType PopFront();
	/* ����������� ������. ����� ������ ��������� !cbIsEmpty(). */
	ElemType PopBack();

	ElemType& Read(int i);
	//������ ������ ��� ������� ����� (����� �� ��� ����� ���� ����������)
	

	int Size();
	int Start();
	int End();
};

  
 