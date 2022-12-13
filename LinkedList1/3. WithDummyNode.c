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
//NODE g_pHead = { 0 };
//
//int IsEmpty() 
//{
//	if (g_pHead.next == NULL) {
//		return 1;
//	}
//	return 0;
//}
//
//void PrintList()
//{
//	NODE* pHead = g_pHead.next;
//	while (pHead != NULL) {
//		printf("current[%p], %s, next[%p]\n", pHead, pHead->data, pHead->next);
//		pHead = pHead->next;
//	}
//	printf("\n");
//}
//
//int AttachHeadNode(char* pData) // head
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
//	if (IsEmpty()) {
//		g_pHead.next = pNewNode;
//	}
//	else {
//		pNewNode->next = g_pHead.next;
//		g_pHead.next = pNewNode;
//	}
//
//	return 0;
//}
//
//int AttachTailNode(char* pData) // tail
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
//	//NODE* pTemp = g_pHead.next;
//	NODE* pTemp = &g_pHead;
//
//	if (IsEmpty()) {
//		g_pHead.next = pNewNode;
//	}
//	else {
//		while (pTemp->next != NULL) {
//			pTemp = pTemp->next;
//		}
//		pTemp->next = pNewNode;
//	}
//
//	return 0;
//}
//
//void DropList() 
//{
//	NODE* pTemp = g_pHead.next;
//	while (pTemp != NULL) {
//		NODE* pDelete = pTemp;
//		pTemp = pTemp->next;
//
//		printf("DropList: [%p] %s\n", pDelete, pDelete->data);
//		free(pDelete);
//	}
//	g_pHead.next = NULL;
//}
//
//NODE* FindNodeByData(char* pData)
//{
//	NODE* pTemp = g_pHead.next;
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
//NODE* FindPrevNodeForDeletion(char* pData) {
//	NODE* pTemp = g_pHead.next;
//	NODE* pPrev = &g_pHead;
//	while (pTemp != NULL)
//	{
//		if (strcmp(pTemp->data, pData) == 0) {
//			return pPrev; // intentionally return previous node
//		}
//		pTemp = pTemp->next;
//		pPrev = pPrev->next;
//	}
//	return 0;
//}
//
//int DeleteNodeBySearch(char* pData) {
//	NODE* prevNode = FindPrevNodeForDeletion(pData);
//	if (prevNode != NULL) {
//		NODE* deleteNode = prevNode->next;
//		prevNode->next = deleteNode->next;
//		printf("DeleteNodeBySearch: [%p] %s\n", deleteNode, deleteNode->data);
//		free(deleteNode);
//		return 1;
//	}
//	return 0;
//}
//
//int DeleteNodeByData(char* pData)
//{
//	NODE* pTemp = g_pHead.next;
//	NODE* pPrev = NULL;
//	while (pTemp != NULL) 
//	{
//		if (strcmp(pTemp->data, pData) == 0) {
//			if (pPrev != NULL) {
//				pPrev->next = pTemp->next; // link node to node before erase pTemp
//			}
//			else { // target node was on the head
//				g_pHead.next = pTemp->next; // link rest nodes
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
//	AttachTailNode("Test01");
//	PrintList();
//	AttachTailNode("Test02");
//	PrintList();
//
//	AttachHeadNode("Test03");
//	PrintList();
//	AttachHeadNode("Test04");
//	PrintList();
//
//	AttachTailNode("Test05");
//	PrintList();
//
//	NODE* found = FindNodeByData("Test02");
//	if (found) {
//		printf("Node found [%p] %s\n", found, found->data);
//	}
//
//	DeleteNodeBySearch("Test04");
//	DeleteNodeBySearch("Test01");
//	DeleteNodeBySearch("Test05");
//
//	DropList();
//
//	AttachTailNode("Test01");
//	AttachHeadNode("Test02");
//	PrintList();
//
//	DropList();
//
//	return 0;
//}