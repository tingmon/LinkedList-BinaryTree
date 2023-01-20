//#include <stdio.h>
//#include <string.h>
//#include <malloc.h>
//#include "myList.h"
//
//void InitList(LIST_INFO* pListData) {
//	pListData->pHead = (NODE*)malloc(sizeof(NODE));
//	pListData->pTail = (NODE*)malloc(sizeof(NODE));
//	pListData->nSize = 0;
//
//	memset(pListData->pHead, 0, sizeof(NODE));
//	memset(pListData->pTail, 0, sizeof(NODE));
//
//	pListData->pHead->next = pListData->pTail;
//	pListData->pTail->prev = pListData->pHead;
//}
//
//void DropList(LIST_INFO* pListData)
//{
//	printf("g_nSize[%d], g_pHead[%p], g_pTail[%p]\n", pListData->nSize, pListData->pHead, pListData->pTail);
//	NODE* pTemp = pListData->pHead;
//	while (pTemp->next != pListData->pTail) {
//		NODE* pDelNode = pTemp;
//		pTemp = pTemp->next;
//		free(pDelNode->pData);
//		free(pDelNode);
//	}
//
//	pListData->pHead = NULL;
//	pListData->pTail = NULL;
//	pListData->nSize = 0;
//	// InitList();
//}
//
//int GetLength(LIST_INFO* pListData)
//{
//	return pListData->nSize;
//}
//
//int IsEmpty(LIST_INFO* pListData)
//{
//	if (pListData->pHead->next == pListData->pTail)
//		return 1;
//	return 0;
//}
//
//NODE* NodeInit(LIST_INFO* pListData, const void* data)
//{
//	// allocation, initialization, substitution
//	NODE* pNewNode = malloc(sizeof(NODE));
//	memset(pNewNode, 0, sizeof(NODE));
//	pNewNode->pData = data;
//
//	return pNewNode;
//}
//
//NODE* GetNodeByIndex(LIST_INFO* pListData, const int index)
//{
//	int length = GetLength(pListData);
//	int counter = 0;
//	if (index > length || index < 0)
//		return NULL;
//	if (length - index > length / 2)
//	{
//		NODE* pTemp = pListData->pHead->next;
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
//			return pListData->pTail;
//		}
//		NODE* pTemp = pListData->pTail->prev;
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
//NODE* GetNodeByKey(LIST_INFO* pListData, const char* key)
//{
//	NODE* pTemp = pListData->pHead->next;
//	const char* (*pfGetKey)(void*) = NULL;
//	while (pTemp != NULL)
//	{
//		pfGetKey = pTemp->pData; // assuming first member of pData is GetKey function
//		if (strcmp(pfGetKey(pTemp->pData), key) == 0)
//		{
//			return pTemp;
//		}
//		pTemp = pTemp->next;
//	}
//	return NULL;
//}
//
//int InsertAfter(LIST_INFO* pListData, NODE* pDstNode, NODE* pNewNode)
//{
//	NODE* pNext = pDstNode->next;
//	pNewNode->prev = pDstNode;
//	pNewNode->next = pDstNode->next;
//	pDstNode->next = pNewNode;
//	pNext->prev = pNewNode;
//
//	pListData->nSize++;
//	return pListData->nSize;
//}
//
//// setting node connection for InsertTail
//int InsertBefore(LIST_INFO* pListData, NODE* pDstNode, NODE* pNewNode)
//{
//	NODE* pPrev = pDstNode->prev;
//	pNewNode->prev = pDstNode->prev;
//	pNewNode->next = pDstNode;
//	pDstNode->prev = pNewNode;
//	pPrev->next = pNewNode;
//
//	pListData->nSize++;
//	return pListData->nSize;
//}
//
//int InsertHead(LIST_INFO* pListData, const void* data)
//{
//	NODE* pNewNode = NodeInit(pListData, data);
//
//	InsertAfter(pListData, pListData->pHead, pNewNode);
//
//	return pListData->nSize;
//}
//
//int InsertTail(LIST_INFO* pListData, const void* data)
//{
//	NODE* pNewNode = NodeInit(pListData, data);
//
//	InsertBefore(pListData, pListData->pTail, pNewNode);
//
//	return pListData->nSize;
//}
//
//int InsertMiddle(LIST_INFO* pListData, const int index, const void* data)
//{
//	if (index > GetLength(pListData) || index < 0)
//		//printf("[InsertMiddle] index out of bound, index: %d length: %d\n", index, GetLength(pListData));
//		return 0;
//	NODE* pNewNode = NodeInit(pListData, data);
//	NODE* target = GetNodeByIndex(pListData, index);
//
//	InsertBefore(pListData, target, pNewNode);
//
//	return pListData->nSize;
//}
//
//int DeleteNodeByKey(LIST_INFO* pListData, const char* key)
//{
//	NODE* pDelNode = GetNodeByKey(pListData, key);
//	if (pDelNode == NULL)
//		return 0;
//	pDelNode->prev->next = pDelNode->next;
//	pDelNode->next->prev = pDelNode->prev;
//
//	free(pDelNode->pData);
//	free(pDelNode);
//	pListData->nSize--;
//
//	return 0;
//}
//
//int DeleteNodeByIndex(LIST_INFO* pListData, const int index)
//{
//	if (IsEmpty(pListData) || GetLength(pListData) == 0 || index < 0 || index >= GetLength(pListData))
//		return 0;
//	NODE* pDelNode = GetNodeByIndex(pListData, index);
//	pDelNode->prev->next = pDelNode->next;
//	pDelNode->next->prev = pDelNode->prev;
//
//	free(pDelNode->pData);
//	free(pDelNode);
//	pListData->nSize--;
//
//	return 0;
//}