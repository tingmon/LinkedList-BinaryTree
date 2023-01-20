#pragma once
// Uncomment codes inside 2-3 and 2-4 files for testing.

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

// function declare code here

void InitList(LIST_INFO* pListData);
void DropList(LIST_INFO* pListData);
void PrintList(LIST_INFO* pListData);
int GetLength(LIST_INFO* pListData);
int IsEmpty(LIST_INFO* pListData);
NODE* NodeInit(LIST_INFO* pListData, const void* data);
NODE* GetNodeByIndex(LIST_INFO* pListData, const int index);
NODE* GetNodeByKey(LIST_INFO* pListData, const char* key);
int InsertAfter(LIST_INFO* pListData, NODE* pDstNode, NODE* pNewNode);
int InsertBefore(LIST_INFO* pListData, NODE* pDstNode, NODE* pNewNode);
int InsertHead(LIST_INFO* pListData, const void* data);
int InsertTail(LIST_INFO* pListData, const void* data);
int InsertMiddle(LIST_INFO* pListData, const int index, const void* data);
int DeleteNodeByKey(LIST_INFO* pListData, const char* key);
int DeleteNodeByIndex(LIST_INFO* pListData, const int index);

