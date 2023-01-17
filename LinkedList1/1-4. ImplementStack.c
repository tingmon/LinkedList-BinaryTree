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
//void Push(char* pData) {
//	AttachHeadNode(pData);
//}
//
//void Pop() {
//	NODE* pPrev = &g_pHead;
//	NODE* pTemp = g_pHead.next;
//	pPrev->next = pTemp->next;
//	free(pTemp);
//}
//
//void PopUntilFindData(char* pData) {
//	NODE* pTemp = g_pHead.next;
//	NODE* pPrev = &g_pHead;
//	while (pTemp != 0) {
//		if (strcmp(pTemp->data, pData) != 0) { // not equal == pop
//			pPrev->next = pTemp->next;
//			free(pTemp);
//			pTemp = pPrev->next;
//		}
//		else {
//			break;
//		}
//	}
//}
//
//NODE* PopAndReturnNewNode() {
//	NODE* sp = g_pHead.next;
//	if (IsEmpty()) {
//		return 0;
//	}
//	NODE* pPopNode = (NODE*)malloc(sizeof(NODE));
//	memset(pPopNode, 0, sizeof(NODE));
//	strcpy_s(pPopNode->data, sizeof(pPopNode->data) , sp->data);
//	pPopNode->next = sp->next;
//
//	
//	g_pHead.next = sp->next;
//	free(sp);
//	return pPopNode;
//}
//
//int PopAndReturnNode(NODE* pPopNode) {
//	NODE* sp = g_pHead.next;
//	if (IsEmpty()) {
//		return 0;
//	}
//	memcpy(pPopNode, sp, sizeof(NODE));
//	g_pHead.next = sp->next;
//	free(sp);
//	return 1;
//}
//
//
//int main()
//{
//	Push("1");
//	Push("2");
//	Push("3");
//	Push("4");
//	Push("5");
//	Push("6");
//	Push("7");
//	Push("8");
//	Push("9");
//	Push("10");
//	PrintList();
//	NODE node = { 0 };
//	NODE* result = PopAndReturnNewNode();
//	if (result) {
//		printf("Node found [%p] data: %s, next: %p\n", result, result->data, result->next); // address cannot be same, this is a new node
//	}
//	PrintList();
//
//	PopUntilFindData("6");
//	PrintList();
//
//	Pop();
//	Pop();
//
//	PopAndReturnNode(&node);
//	printf("Deleted node info - data: %s, next: %p\n", node.data, node.next);
//	PrintList();
//
//	DropList();
//	return 0;
//}