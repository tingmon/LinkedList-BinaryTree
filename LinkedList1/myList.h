#pragma once

typedef struct NODE
{
	// Manageable Data
	void* pData;

	// Data Structure
	struct NODE* prev;
	struct NODE* next;
} NODE;

typedef struct LIST_INFO
{
	NODE* pHead;
	NODE* pTail;
	int nSize;
} LIST_INFO;