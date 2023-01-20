//#include <stdio.h>
//#include <string.h>
//#include <malloc.h>
//
//int InsertHead(const void* data);
//int InsertTail(const void* data);
//int InsertMiddle(const int index, const void* data);
//
//// NODE must be detached from data characteristics and operations.(Reusability)
//typedef struct NODE
//{
//	// Manageable Data
//	void* pData;
//
//	// Data Structure
//	struct NODE* prev;
//	struct NODE* next;
//} NODE;
//
//// characteristics
//typedef struct USERDATA // how to remove USERDATA* declaration in code?
//{	
//	// Member Function Pointer
//	const char* (*GetKey)(void*);
//
//	char name[64]; // key
//	char phone[64];
//} USERDATA;
//
//// operation
//const char* GetKeyFromUserData(USERDATA* pUser)
//{
//	return pUser->name;
//}
//
//USERDATA* ConstructUserData(const char* name, const char* phone)
//{
//	USERDATA* pNewData = (USERDATA*)malloc(sizeof(USERDATA));
//	memset(pNewData, 0, sizeof(USERDATA));
//	strcpy_s(pNewData->name, sizeof(pNewData->name), name);
//	strcpy_s(pNewData->phone, sizeof(pNewData->phone), phone);
//
//	// structure member function initializing
//	pNewData->GetKey = GetKeyFromUserData;
//
//	return pNewData;
//}
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
//		free(pDelNode->pData);
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
//		if (pTemp == g_pHead || pTemp == g_pTail) {
//			printf("prev: [%p], address: [%p], next: [%p], DUMMY\n", pTemp->prev, pTemp, pTemp->next);
//		}
//		else {
//			USERDATA* pUser = pTemp->pData; // not a good code for the sake of reusability
//			printf("prev: [%p], address: [%p], next: [%p], name(key): %s\n", pTemp->prev, pTemp, pTemp->next, pUser->GetKey(pUser));
//		}
//		pTemp = pTemp->next;
//		counter++;
//	}
//	if (counter == 0)
//	{
//		printf("List is Empty.\n");
//	}
//	printf("\n");
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
//NODE* NodeInit(const void* data)
//{
//	// allocation, initialization, substitution
//	NODE* pNewNode = malloc(sizeof(NODE));
//	memset(pNewNode, 0, sizeof(NODE));
//	pNewNode->pData = (USERDATA*)data;
//
//	// structure member function initializing
//	USERDATA* pUser = pNewNode->pData;
//	pUser->GetKey = GetKeyFromUserData;
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
//NODE* GetNodeByKey(const char* key)
//{
//	NODE* pTemp = g_pHead->next;
//	while (pTemp != NULL)
//	{
//		USERDATA* pfGetKey = pTemp->pData; // assuming first member of pData is GetKey function
//		if (strcmp(pfGetKey->GetKey(pTemp->pData), key) == 0)
//		{
//			return pTemp;
//		}
//		pTemp = pTemp->next;
//	}
//	return NULL;
//}
//
//// setting node connection for InsertHead
//int InsertAfter(NODE* pDstNode, NODE* pNewNode)
//{
//	NODE* pNext = pDstNode->next;
//	pNewNode->prev = pDstNode;
//	pNewNode->next = pDstNode->next;
//	pDstNode->next = pNewNode;
//	pNext->prev = pNewNode;
//
//	g_nSize++;
//	return g_nSize;
//}
//
//// setting node connection for InsertTail
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
//int InsertHead(const void* data)
//{
//	NODE* pNewNode = NodeInit(data);
//
//	InsertAfter(g_pHead, pNewNode);
//
//	return g_nSize;
//}
//
//int InsertTail(const void* data)
//{
//	NODE* pNewNode = NodeInit(data);
//
//	InsertBefore(g_pTail, pNewNode);
//
//	return g_nSize;
//}
//
//int InsertMiddle(const int index, const void* data)
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
//int DeleteNodeByKey(const char* key)
//{
//	NODE* pDelNode = GetNodeByKey(key);
//	if (pDelNode == NULL)
//		return 0;
//	pDelNode->prev->next = pDelNode->next;
//	pDelNode->next->prev = pDelNode->prev;
//
//	free(pDelNode->pData);
//	free(pDelNode);
//	g_nSize--;
//
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
//
//	free(pDelNode->pData);
//	free(pDelNode);
//	g_nSize--;
//
//	return 0;
//}
//
//int main()
//{
//	InitList();
//
//	USERDATA* pNewData = NULL;
//	pNewData = ConstructUserData("oihn", "125125");
//	InsertTail(pNewData);
//
//	pNewData = (USERDATA*)malloc(sizeof(USERDATA));
//	memset(pNewData, 0, sizeof(USERDATA));
//	strcpy_s(pNewData->name, sizeof(pNewData->name), "tj");
//	strcpy_s(pNewData->phone, sizeof(pNewData->phone), "1234");
//	InsertTail(pNewData);
//
//	pNewData = (USERDATA*)malloc(sizeof(USERDATA));
//	memset(pNewData, 0, sizeof(USERDATA));
//	strcpy_s(pNewData->name, sizeof(pNewData->name), "asdf");
//	strcpy_s(pNewData->phone, sizeof(pNewData->phone), "1234");
//	InsertTail(pNewData);
//
//	pNewData = (USERDATA*)malloc(sizeof(USERDATA));
//	memset(pNewData, 0, sizeof(USERDATA));
//	strcpy_s(pNewData->name, sizeof(pNewData->name), "qwer");
//	strcpy_s(pNewData->phone, sizeof(pNewData->phone), "1234");
//	InsertHead(pNewData);
//
//	pNewData = (USERDATA*)malloc(sizeof(USERDATA));
//	memset(pNewData, 0, sizeof(USERDATA));
//	strcpy_s(pNewData->name, sizeof(pNewData->name), "zxcv");
//	strcpy_s(pNewData->phone, sizeof(pNewData->phone), "1234");
//	InsertMiddle(2, pNewData);
//
//	PrintList();
//
//	DeleteNodeByIndex(2);
//	DeleteNodeByKey("qwer");
//
//
//	PrintList();
//	DropList();
//	return 0;
//}