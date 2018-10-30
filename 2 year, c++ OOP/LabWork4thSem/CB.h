#pragma once

#include "stdafx.h"
#include "classes.h"
#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 20



/* ��� ��������, ��������� � ������ */
typedef coord ElemType;
 
/* ��� ����� */
class CircularBuffer
 { 
    int         size;   // ����� ���������          
    int         start;  // ������ ������� ��������              
    int         end;    // ������ �����, ��� �� ����� ���������  
    ElemType   *elems;  // ��������� �� ������ ���������                 
 public:
	CircularBuffer(int size = BUF_SIZE);
	CircularBuffer(const CircularBuffer &a);
	~CircularBuffer();

	int IsFull();
	int IsEmpty();

	void PushFront(ElemType *elem);	//� �����
	void PushBack(ElemType *elem); //� ������


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

  
 