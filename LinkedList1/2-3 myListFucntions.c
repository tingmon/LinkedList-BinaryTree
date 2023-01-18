#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "myList.h"

void InitList(LIST_INFO* pListData) {
	pListData->pHead = (NODE*)malloc(sizeof(NODE));
	pListData->pTail = (NODE*)malloc(sizeof(NODE));
	pListData->nSize = 0;

	memset(pListData->pHead, 0, sizeof(NODE));
	memset(pListData->pTail, 0, sizeof(NODE));

	pListData->pHead->next = pListData->pTail;
	pListData->pTail->prev = pListData->pHead;
}