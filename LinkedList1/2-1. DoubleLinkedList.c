//#include <stdio.h>
//#include <string.h>
//#include <malloc.h>
//
//typedef struct NODE
//{
//	char pData[64];
//	struct NODE* prev;
//	struct NODE* next;
//} NODE;
//
//NODE* g_pHead; // Head dummy node
//NODE* g_pTail; // Tail dummy node
//int g_nSize;
//
//void InitList()
//{
//	// memory allocation
//	g_pHead = (NODE*)malloc(sizeof(NODE));
//	g_pTail = (NODE*)malloc(sizeof(NODE));
//	g_nSize = 0;
//
//	// memory initialization
//	memset(g_pHead, 0, sizeof(NODE));
//	memset(g_pTail, 0, sizeof(NODE));
//
//	strcpy_s(g_pHead->pData, sizeof(g_pHead->pData), "Dummy Head");
//	strcpy_s(g_pTail->pData, sizeof(g_pTail->pData), "Dummy Tail");
//
//	g_pHead->next = g_pTail;
//	g_pTail->prev = g_pHead;
//}
//
//void DropList()
//{
//	printf("g_nSize[%d], g_pHead[%p], g_pTail[%p]\n", g_nSize, g_pHead, g_pTail);
//	NODE* pTemp = g_pHead;
//	while (pTemp->next != g_pTail) {
//		NODE* pDelNode = pTemp;
//		pTemp = pTemp->next;
//		free(pDelNode);
//	}
//
//	g_pHead = NULL;
//	g_pHead = NULL;
//	g_nSize = 0;
//	// InitList();
//}
//
//void PrintList()
//{
//	int counter = 0;
//	NODE* pTemp = g_pHead;
//	while (pTemp != NULL) {
//		printf("prev: [%p], address: [%p], next: [%p], data: %s\n", pTemp->prev, pTemp, pTemp->next, pTemp->pData);
//		pTemp = pTemp->next;
//		counter++;
//	}
//	if (counter == 0) 
//	{
//		printf("List is Empty.\n");
//	}
//}
//
//int GetLength()
//{
//	return g_nSize;
//}
//
//int IsEmpty()
//{
//	if (g_pHead->next == g_pTail)
//		return 1;
//	return 0;
//}
//
//NODE* NodeInit(const char* data)
//{
//	// allocation, initialization, substitution
//	NODE* pNewNode = malloc(sizeof(NODE));
//	memset(pNewNode, 0, sizeof(NODE));
//	strcpy_s(pNewNode->pData, sizeof(pNewNode->pData), data);
//	
//	return pNewNode;
//}
//
//NODE* GetNodeByIndex(const int index)
//{
//	int length = GetLength();
//	int counter = 0;
//	if (index > length || index < 0)
//		return NULL;
//	if (length - index > length / 2)
//	{
//		NODE* pTemp = g_pHead->next;
//		while (pTemp != NULL)
//		{
//			if (counter == index)
//			{
//				return pTemp;
//			}
//			pTemp = pTemp->next;
//			counter++;
//		}
//	}
//	else
//	{
//		if (length - index == 0)
//		{
//			return g_pTail;
//		}
//		NODE* pTemp = g_pTail->prev;
//		while (pTemp != NULL)
//		{
//			if (counter == length - index - 1)
//			{
//				return pTemp;
//			}
//			pTemp = pTemp->prev;
//			counter++;
//		}
//	}
//	return NULL;
//}
//
//NODE* GetNodeByData(const char* data)
//{
//	NODE* pTemp = g_pHead->next;
//	while (pTemp != NULL)
//	{
//		if (strcmp(pTemp->pData, data) == 0)
//		{
//			return pTemp;
//		}
//		pTemp = pTemp->next;
//	}
//	return NULL;
//}
//
//int InsertHead(const char* data)
//{
//	NODE* pNewNode = NodeInit(data);
//
//	InsertAfter(g_pHead, pNewNode);
//
//	return g_nSize;
//}
//
//int InsertAfter(NODE* pDstNode, NODE* pNewNode)
//{
//	NODE* pNext = pDstNode->next;
//	pNewNode->prev = g_pHead;
//	pNewNode->next = g_pHead->next;
//	g_pHead->next = pNewNode;
//	pNext->prev = pNewNode;
//
//	g_nSize++;
//	return g_nSize;
//}
//
//int InsertTail(const char* data)
//{
//	NODE* pNewNode = NodeInit(data);
//
//	InsertBefore(g_pTail, pNewNode);
//
//	return g_nSize;
//}
//
//int InsertBefore(NODE* pDstNode, NODE* pNewNode) 
//{
//	NODE* pPrev = pDstNode->prev;
//	pNewNode->prev = pDstNode->prev;
//	pNewNode->next = pDstNode;
//	pDstNode->prev = pNewNode;
//	pPrev->next = pNewNode;
//
//	g_nSize++;
//	return g_nSize;
//}
//
//int InsertMiddle(const int index, const char* data)
//{
//	if (index > GetLength() || index < 0)
//		return 0;
//	NODE* pNewNode = NodeInit(data);
//	NODE* target = GetNodeByIndex(index);
//
//	InsertBefore(target, pNewNode);
//
//	return g_nSize;
//}
//
//int DeleteNodeByData(const char* data)
//{
//	NODE* pDelNode = GetNodeByData(data);
//	if (pDelNode == NULL)
//		return 0;
//	pDelNode->prev->next = pDelNode->next;
//	pDelNode->next->prev = pDelNode->prev;
//	free(pDelNode);
//	g_nSize--;
//	return 0;
//}
//
//int DeleteNodeByIndex(const int index)
//{
//	if (IsEmpty() || GetLength() == 0 || index < 0 || index >= GetLength())
//		return 0;
//	NODE* pDelNode = GetNodeByIndex(index);
//	pDelNode->prev->next = pDelNode->next;
//	pDelNode->next->prev = pDelNode->prev;
//	free(pDelNode);
//	g_nSize--;
//	return 0;
//}
//
//int main() 
//{
//	InitList();
//
//	InsertMiddle(0, "TestMiddle1");
//
//	InsertHead("TestHead1");
//	InsertHead("TestHead2");
//	InsertHead("TestHead3");
//
//	PrintList();
//	printf("\n");
//
//	InsertTail("TestTail1");
//	InsertTail("TestTail2");
//	InsertTail("TestTail3");
//
//	PrintList();
//	printf("\n");
//
//	InsertMiddle(0, "TestMiddle2");
//	InsertMiddle(8, "TestMiddle3");
//
//	PrintList();
//	printf("\n");
//
//	DeleteNodeByData("TestTail2");
//	DeleteNodeByIndex(6);
//
//	PrintList();
//	printf("\n");
//
//	DropList();
//	return 0;
//}