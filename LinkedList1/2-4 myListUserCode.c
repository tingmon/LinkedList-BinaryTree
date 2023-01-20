//#include <stdio.h>
//#include <string.h>
//#include <malloc.h>
//#include "myList.h"
//
//typedef struct USERDATA
//{
//	// Member Function Pointer
//	const char* (*GetKey)(void*);
//
//	char name[64]; // key
//	char phone[64];
//} USERDATA;
//
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
//void PrintList(LIST_INFO* pListData)
//{
//	int counter = 0;
//	NODE* pTemp = pListData->pHead;
//	while (pTemp != NULL) {
//		if (pTemp == pListData->pHead || pTemp == pListData->pTail) {
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
//int main()
//{
//	LIST_INFO userList01 = { 0 };
//	InitList(&userList01);
//
//	USERDATA* pNewData = ConstructUserData("aaa", "123");
//	InsertHead(&userList01, pNewData);
//
//	pNewData = ConstructUserData("bbb", "123");
//	InsertHead(&userList01, pNewData);
//
//	pNewData = ConstructUserData("ccc", "123");
//	InsertHead(&userList01, pNewData);
//
//	pNewData = ConstructUserData("ddd", "123");
//	InsertTail(&userList01, pNewData);
//
//	pNewData = ConstructUserData("fff", "123");
//	InsertTail(&userList01, pNewData);
//
//	pNewData = ConstructUserData("eee", "123");
//	InsertTail(&userList01, pNewData);
//
//	pNewData = ConstructUserData("ggg", "123");
//	InsertMiddle(&userList01, 0, pNewData);
//
//	pNewData = ConstructUserData("hhh", "123");
//	InsertMiddle(&userList01, 7, pNewData);
//
//	pNewData = ConstructUserData("iii", "123");
//	InsertMiddle(&userList01, 1, pNewData);
//
//	PrintList(&userList01);
//
//	DeleteNodeByIndex(&userList01, 7);
//	DeleteNodeByKey(&userList01, "ccc");
//
//	PrintList(&userList01);
//
//	return 0;
//}