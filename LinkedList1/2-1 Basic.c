#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct NODE
{
	char* pData;
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
		free(pDelNode);
	}
}

void PrintList()
{
	int counter = 0;
	NODE* pTemp = g_pHead;
	while (pTemp != NULL) {
		printf("prev: [%p] | data: %s | next: [%p]\n", pTemp->prev, pTemp->pData, pTemp->next);
		pTemp = pTemp->next;
		counter++;
	}
	if (counter == 0) 
	{
		printf("List is Empty.\n");
	}
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

int InsertHead(const char* data)
{
	// allocation, initialization, substitution
	NODE* pNewNode = malloc(sizeof(NODE));
	memset(pNewNode, 0, sizeof(NODE));
	strcpy_s(pNewNode->pData, sizeof(NODE), data);
	//if (g_nSize == 0) 
	//{
	//	g_pTail->prev = pNewNode;
	//}
	//else 
	//{
	//	NODE* pTemp = g_pHead->next;
	//	pTemp->prev = pNewNode;
	//}
	pNewNode->prev = g_pHead;
	pNewNode->next = g_pHead->next;
	g_pHead->next = pNewNode;
	pNewNode->next->prev = pNewNode;

	g_nSize++;

	return g_nSize;
}

int InsertTail(const char* data)
{
	// allocation, initialization, substitution
	NODE* pNewNode = malloc(sizeof(NODE));
	memset(pNewNode, 0, sizeof(NODE));
	strcpy_s(pNewNode->pData, sizeof(NODE), data);
	//if (g_nSize == 0)
	//{
	//	g_pHead->next = pNewNode;
	//}
	//else
	//{
	//	NODE* pTemp = g_pTail->prev;
	//	pTemp->next = pNewNode;
	//}
	pNewNode->prev = g_pTail->prev;
	pNewNode->next = g_pTail;
	g_pTail->prev = pNewNode;
	pNewNode->prev->next = pNewNode;

	g_nSize++;

	return g_nSize;
}

int InsertMiddle(const int index, const char* data)
{
	if (GetLength() == 0 || index > GetLength() || index < 0)
		return 0;
	// allocation, initialization, substitution
	NODE* pNewNode = malloc(sizeof(NODE));
	memset(pNewNode, 0, sizeof(NODE));
	strcpy_s(pNewNode->pData, sizeof(NODE), data);

	NODE* front = GetNode(index - 1);
	NODE* rear = GetNode(index);

	pNewNode->prev = front;
	pNewNode->next = rear;
	front->next = pNewNode;
	rear->prev = pNewNode;

	g_nSize++;

	return g_nSize;
}

NODE* GetNode(const int index)
{
	int length = GetLength();
	int counter = 0;
	if (index > length || index < 0)
		return NULL;
	if (length - index > length / 2)
	{
		if (index == 0)
		{
			return g_pHead;
		}

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
			if (counter == length - index)
			{
				return pTemp;
			}
			pTemp = pTemp->prev;
			counter++;
		}
	}
	return NULL;
}

NODE* GetNode(const char* data)
{
	return NULL;
}

int DeleteNode(const char* data)
{
	NODE* pDelNode = GetNode(data);
	return 0;
}

int main(void) 
{
	InitList();

	InsertHead("TestHead1");
	InsertHead("TestHead2");
	InsertHead("TestHead3");

	PrintList();

	InsertTail("TestTail1");
	InsertTail("TestTail2");
	InsertTail("TestTail3");

	PrintList();

	InsertMiddle(3, "TestMiddle1");
	InsertMiddle(7, "TestMiddle2");

	PrintList();

	DropList();
	PrintList();
	return 0;
}