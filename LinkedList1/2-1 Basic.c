#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct NODE
{
	char* pData;
	struct NODE* prev;
	struct NODE* next;
} NODE;

NODE* g_pHead; // Head dummy node
NODE* g_pTail; // Tail dummy node
int g_nSize;

void InitList()
{
	g_pHead = (NODE*)malloc(sizeof(NODE));
	g_pTail = (NODE*)malloc(sizeof(NODE));
	g_nSize = 0;
}

void DropList()
{

}

void PrintList()
{

}

int GetLength()
{
	return g_nSize;
}

void IsEmpty()
{

}

int InsertHead(const char* data)
{
	return 0;
}

int InsertTail(const char* data)
{
	return 0;
}

int InsertMiddle(const char* data)
{
	return 0;
}

NODE* GetNode(const char* data)
{
	return NULL;
}

int DeleteNode(const char* data)
{
	NODE* pDelNode = GetNode(data);
	return 0;
}

int main(void) 
{
	return 0;
}