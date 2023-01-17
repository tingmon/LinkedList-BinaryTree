//#include <stdio.h>
//#include <string.h>
//#include <malloc.h>
//
//typedef struct NODE
//{
//	char data[64]; // data to be managed
//	struct NODE* next; // pointer for data management
//} NODE;
//
//NODE g_Head = { 0 };
//NODE* g_pTail = 0;
//
//int IsEmpty()
//{
//	if (g_Head.next == NULL) {
//		return 1;
//	}
//	return 0;
//}
//
//void PrintList()
//{
//	NODE* pHead = g_Head.next;
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
//		g_Head.next = pNewNode;
//		g_pTail = pNewNode;
//	}
//	else {
//		pNewNode->next = g_Head.next;
//		g_Head.next = pNewNode;
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
//	NODE* pTemp = &g_Head;
//
//	if (IsEmpty()) {
//		g_Head.next = pNewNode;
//		g_pTail = pNewNode;
//	}
//	else {
//		//while (pTemp->next != NULL) { -> Tail pointer can substitute this code block.  
//		//	pTemp = pTemp->next;
//		//}
//		//pTemp->next = pNewNode;
//
//		g_pTail->next = pNewNode;
//		g_pTail = pNewNode;
//	}
//
//	return 0;
//}
//
//void DropList()
//{
//	NODE* pTemp = g_Head.next;
//	while (pTemp != NULL) {
//		NODE* pDelete = pTemp;
//		pTemp = pTemp->next;
//
//		printf("DropList: [%p] %s\n", pDelete, pDelete->data);
//		free(pDelete);
//	}
//	g_Head.next = NULL;
//	g_pTail = NULL;
//}
//
//NODE* FindNodeByData(char* pData)
//{
//	NODE* pTemp = g_Head.next;
//	while (pTemp != NULL)
//	{
//		if (strcmp(pTemp->data, pData) == 0) {
//			return pTemp;
//		}
//		pTemp = pTemp->next;
//	}
//	return 0;
//}
//
//NODE* FindPrevNodeForDeletion(char* pData) {
//	NODE* pTemp = g_Head.next;
//	NODE* pPrev = &g_Head;
//	while (pTemp != NULL)
//	{
//		if (strcmp(pTemp->data, pData) == 0) {
//			return pPrev; // return previous node of target node
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
//		//if (deleteNode == g_pTail)
//		//	g_pTail = NULL;
//		free(deleteNode);
//		return 1;
//	}
//	return 0;
//}
//
//int DeleteNodeByData(char* pData)
//{
//	NODE* pTemp = g_Head.next;
//	NODE* pPrev = NULL;
//	while (pTemp != NULL)
//	{
//		if (strcmp(pTemp->data, pData) == 0) {
//			if (pPrev != NULL) {
//				pPrev->next = pTemp->next; // link node to node before erase pTemp
//			}
//			else { // target node is on the head
//				g_Head.next = pTemp->next; // link rest nodes
//			}
//			printf("DeleteNodeByData: [%p] %s\n", pTemp, pTemp->data);
//			//if (pTemp == g_pTail)
//			//	g_pTail = NULL;
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
//	NODE* pPrev = &g_Head;
//	NODE* pTemp = g_Head.next;
//	pPrev->next = pTemp->next;
//	//if (pTemp == g_pTail)
//	//	g_pTail = NULL;
//	free(pTemp);
//}
//
//void PopUntilFindData(char* pData) {
//	NODE* pTemp = g_Head.next;
//	NODE* pPrev = &g_Head;
//	while (pTemp != 0) {
//		if (strcmp(pTemp->data, pData) != 0) { // not equal == pop
//			pPrev->next = pTemp->next;
//			//if (pTemp == g_pTail)
//			//	g_pTail = NULL;
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
//	NODE* sp = g_Head.next;
//	if (IsEmpty()) {
//		return 0;
//	}
//	NODE* pPopNode = (NODE*)malloc(sizeof(NODE));
//	memset(pPopNode, 0, sizeof(NODE));
//	strcpy_s(pPopNode->data, sizeof(pPopNode->data), sp->data);
//	pPopNode->next = sp->next;
//
//
//	g_Head.next = sp->next;
//	//if (sp == g_pTail)
//	//	g_pTail = NULL;
//	free(sp);
//	return pPopNode;
//}
//
//int PopAndReturnNodeInfo(NODE* pPopNode) {
//	NODE* sp = g_Head.next;
//	if (IsEmpty()) {
//		return 0;
//	}
//	memcpy(pPopNode, sp, sizeof(NODE));
//	g_Head.next = sp->next;
//	//if (sp == g_pTail)
//	//	g_pTail = NULL;
//	free(sp);
//	return 1;
//}
//
//int Enqueue(char* pData) {
//	AttachTailNode(pData);
//}
//
//int Dequeue(NODE* pNode) {
//	return PopAndReturnNodeInfo(pNode);
//}
//
//int main()
//{
//	Enqueue("1");
//	Enqueue("2");
//	Enqueue("3");
//	PrintList();
//
//	NODE node = { 0 };
//
//	Dequeue(&node);
//	printf("Deleted node info - data: %s, next: %p\n", node.data, node.next);
//	Dequeue(&node);
//	printf("Deleted node info - data: %s, next: %p\n", node.data, node.next);
//	Dequeue(&node);
//	printf("Deleted node info - data: %s, next: %p\n", node.data, node.next);
//	PrintList();
//
//	DropList();
//
//	Enqueue("1");
//	Enqueue("2");
//	Enqueue("3");
//	PrintList();
//
//	DropList();
//
//	return 0;
//}