#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct USERDATA
{
	char name[64]; // key
	char phone[64];
} USERDATA;

const char* GetKeyFromUserData(USERDATA* pUser)
{
	return pUser->name;
}

typedef struct NODE
{
	// Manageable Data
	void* pData;

	// Member Function Pointer
	const char* (*GetKey)(void*);

	// Data Structure
	struct NODE* prev;
	struct NODE* next;
} NODE;

NODE* g_pHead; // Head dummy node
NODE* g_pTail; // Tail dummy node
int g_nSize;

void InitList()
{
	// memory allocation
	g_pHead = (NODE*)malloc(sizeof(NODE));
	g_pTail = (NODE*)malloc(sizeof(NODE));
	g_nSize = 0;

	// memory initialization
	memset(g_pHead, 0, sizeof(NODE));
	memset(g_pTail, 0, sizeof(NODE));

	g_pHead->next = g_pTail;
	g_pTail->prev = g_pHead;
}

void DropList()
{
	printf("g_nSize[%d], g_pHead[%p], g_pTail[%p]\n", g_nSize, g_pHead, g_pTail);
	NODE* pTemp = g_pHead;
	while (pTemp->next != g_pTail) {
		NODE* pDelNode = pTemp;
		pTemp = pTemp->next;
		free(pDelNode->pData);
		free(pDelNode);
	}

	g_pHead = NULL;
	g_pHead = NULL;
	g_nSize = 0;
	// InitList();
}

void PrintList()
{
	int counter = 0;
	NODE* pTemp = g_pHead;
	while (pTemp != NULL) { 
		if (pTemp == g_pHead || pTemp == g_pTail) {
			printf("prev: [%p], address: [%p], next: [%p], DUMMY\n", pTemp->prev, pTemp, pTemp->next);
		}
		else {
			printf("prev: [%p], address: [%p], next: [%p], name(key): %s\n", pTemp->prev, pTemp, pTemp->next, pTemp->GetKey(pTemp->pData));
		}
		pTemp = pTemp->next;
		counter++;
	}
	if (counter == 0)
	{
		printf("List is Empty.\n");
	}
	printf("\n");
}

int GetLength()
{
	return g_nSize;
}

int IsEmpty()
{
	if (g_pHead->next == g_pTail)
		return 1;
	return 0;
}

NODE* NodeInit(const void* data, const char* (*pfParam)(void*))
{
	// allocation, initialization, substitution
	NODE* pNewNode = malloc(sizeof(NODE));
	memset(pNewNode, 0, sizeof(NODE));
	pNewNode->pData = (USERDATA*)data;
	pNewNode->GetKey = pfParam;

	return pNewNode;
}

NODE* GetNodeByIndex(const int index)
{
	int length = GetLength();
	int counter = 0;
	if (index > length || index < 0)
		return NULL;
	if (length - index > length / 2)
	{
		NODE* pTemp = g_pHead->next;
		while (pTemp != NULL)
		{
			if (counter == index)
			{
				return pTemp;
			}
			pTemp = pTemp->next;
			counter++;
		}
	}
	else
	{
		if (length - index == 0)
		{
			return g_pTail;
		}
		NODE* pTemp = g_pTail->prev;
		while (pTemp != NULL)
		{
			if (counter == length - index - 1)
			{
				return pTemp;
			}
			pTemp = pTemp->prev;
			counter++;
		}
	}
	return NULL;
}

NODE* GetNodeByKey(const char* key)
{
	NODE* pTemp = g_pHead->next;
	while (pTemp != NULL)
	{
		if (strcmp(pTemp->GetKey(pTemp->pData), key) == 0)
		{
			return pTemp;
		}
		pTemp = pTemp->next;
	}
	return NULL;
}

int InsertAfter(NODE* pDstNode, NODE* pNewNode)
{
	NODE* pNext = pDstNode->next;
	pNewNode->prev = g_pHead;
	pNewNode->next = g_pHead->next;
	g_pHead->next = pNewNode;
	pNext->prev = pNewNode;

	g_nSize++;
	return g_nSize;
}

int InsertBefore(NODE* pDstNode, NODE* pNewNode)
{
	NODE* pPrev = pDstNode->prev;
	pNewNode->prev = pDstNode->prev;
	pNewNode->next = pDstNode;
	pDstNode->prev = pNewNode;
	pPrev->next = pNewNode;

	g_nSize++;
	return g_nSize;
}

int InsertHead(const void* data, const char* (*pfParam)(void*))
{
	NODE* pNewNode = NodeInit(data, pfParam);

	InsertAfter(g_pHead, pNewNode);

	return g_nSize;
}

int InsertTail(const void* data, const char* (*pfParam)(void*))
{
	NODE* pNewNode = NodeInit(data, pfParam);

	InsertBefore(g_pTail, pNewNode);

	return g_nSize;
}

int InsertMiddle(const int index, const void* data, const char* (*pfParam)(void*))
{
	if (index > GetLength() || index < 0)
		return 0;
	NODE* pNewNode = NodeInit(data, pfParam);
	NODE* target = GetNodeByIndex(index);

	InsertBefore(target, pNewNode);

	return g_nSize;
}

int DeleteNodeByKey(const char* key)
{
	NODE* pDelNode = GetNodeByKey(key);
	if (pDelNode == NULL)
		return 0;
	pDelNode->prev->next = pDelNode->next;
	pDelNode->next->prev = pDelNode->prev;

	free(pDelNode->pData);
	free(pDelNode);
	g_nSize--;

	return 0;
}

int DeleteNodeByIndex(const int index)
{
	if (IsEmpty() || GetLength() == 0 || index < 0 || index >= GetLength())
		return 0;
	NODE* pDelNode = GetNodeByIndex(index);
	pDelNode->prev->next = pDelNode->next;
	pDelNode->next->prev = pDelNode->prev;

	free(pDelNode->pData);
	free(pDelNode);
	g_nSize--;

	return 0;
}

int main()
{
	InitList();

	USERDATA* pNewData = (USERDATA*)malloc(sizeof(USERDATA));
	memset(pNewData, 0, sizeof(USERDATA));
	strcpy_s(pNewData->name, sizeof(pNewData->name), "tj");
	strcpy_s(pNewData->phone, sizeof(pNewData->phone), "1234");

	InsertTail(pNewData, GetKeyFromUserData);


	PrintList();
	DropList();
	return 0;
}