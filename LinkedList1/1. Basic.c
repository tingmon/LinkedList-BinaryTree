//#include <stdio.h>
//
//typedef struct NODE {
//	// data to be managed
//	int data;
//
//	// pointer for data management
//	struct NODE* next;
//} NODE;
//
//int main()
//{
//	NODE list[5] = { 0 };
//
//	// store value of each list element
//	list[0].data = 100;
//	list[1].data = 101;
//	list[2].data = 102;
//	list[3].data = 103;
//	list[4].data = 104;
//
//	// store address of next list element
//	list[0].next = &list[3]; // 0 - 3 - 2 - 1 - 4 - null
//	list[1].next = &list[4];
//	list[2].next = &list[1];
//	list[3].next = &list[2];
//	list[4].next = 0; // equivalent with NULL
//
//	for (int i = 0; i < 5; ++i) {
//		printf("list[%d]: %d\n", i, list[i].data);
//	}
//
//	NODE* pHead = &list[0];
//	while (pHead != NULL) {
//		// '->' allows to access elements in Structures == get the value of pointed address
//		printf("%p: %d\n", pHead, pHead->data);
//		pHead = pHead->next;
//	}
//
//	return 0;
//}