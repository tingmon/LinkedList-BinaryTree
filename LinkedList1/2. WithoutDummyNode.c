//#include <stdio.h>
//#include <string.h>
//#include <malloc.h>
//
//typedef struct NODE
//{
//	// data to be managed
//	char data[64];
//
//	// pointer for data management
//	struct NODE* next;
//} NODE;
//
//NODE* g_pHead;
//
//void PrintList()
//{
//	NODE* pHead = g_pHead;
//	while (pHead != NULL) {
//		printf("current[%p], %s, next[%p]\n", pHead, pHead->data, pHead->next);
//		pHead = pHead->next;
//	}
//	printf("\n");
//}
//
//int InsertNode(char* pData)
//{
//	// malloc function allocate the requested size of bytes and 
//	// it returns a pointer to the first byte of allocated memory.
//	NODE* pNewNode = (NODE*)malloc(sizeof(NODE));
//
//	// initialise from start to end of new pointer memory value to 0. 
//	memset(pNewNode, 0, sizeof(NODE));
//
//	strcpy_s(pNewNode->data, sizeof(pNewNode->data), pData);
//
//	if (g_pHead == NULL) {
//		g_pHead = pNewNode;
//	}
//	else {
//		pNewNode->next = g_pHead;
//		g_pHead = pNewNode;
//	}
//
//	return 0;
//}
//
//void DropList()
//{
//	NODE* pTemp = g_pHead;
//	while (pTemp != NULL) {
//		NODE* pDelete = pTemp;
//		pTemp = pTemp->next;
//
//		printf("DropList: [%p] %s\n", pDelete, pDelete->data);
//		free(pDelete);
//	}
//}
//
//NODE* FindNodeByData(char* pData)
//{
//	NODE* pTemp = g_pHead;
//	while (pTemp != NULL)
//	{
//		if (strcmp(pTemp->data, pData) == 0) {
//			return pTemp;
//		}
//		pTemp = pTemp->next;
//
//	}
//	return 0;
//}
//
//int DeleteNodeByData(char* pData)
//{
//	NODE* pTemp = g_pHead;
//	NODE* pPrev = NULL;
//	while (pTemp != NULL)
//	{
//		if (strcmp(pTemp->data, pData) == 0) {
//			if (pPrev != NULL) {
//				pPrev->next = pTemp->next;
//			}
//			else {
//				g_pHead = pTemp->next;
//			}
//			printf("DeleteNodeByData: [%p] %s\n", pTemp, pTemp->data);
//			free(pTemp);
//			return 1;
//		}
//		pPrev = pTemp;
//		pTemp = pTemp->next;
//	}
//	return 0;
//}
//
//
//int main()
//{
//	InsertNode("Test01");
//	PrintList();
//	InsertNode("Test02");
//	PrintList();
//	InsertNode("Test03");
//	PrintList();
//	InsertNode("Test04");
//	PrintList();
//	InsertNode("Test05");
//	PrintList();
//
//	NODE* found = FindNodeByData("Test02");
//	if (found) {
//		printf("Node found [%p] %s\n", found, found->data);
//	}
//
//	printf("\n");
//
//	DeleteNodeByData("Test01");
//	DeleteNodeByData("Test03");
//
//	printf("\n");
//
//	DropList();
//
//	printf("\n");
//
//	printf("g_pHead: [%p], %s, [%p]\n", g_pHead, g_pHead->data, g_pHead->next);
//	return 0;
//}