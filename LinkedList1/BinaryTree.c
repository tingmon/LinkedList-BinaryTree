#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct NODE
{
	char pData[64];
	struct NODE* left;
	struct NODE* right;
} NODE;

NODE* g_pRoot; 
int g_nSize;

void DropTree()
{
	printf("g_nSize[%d], g_pRoot[%p]\n", g_nSize, g_pRoot);
	NODE* pTemp = g_pRoot;
	while (pTemp->next != g_pTail) {
		NODE* pDelNode = pTemp;
		pTemp = pTemp->next;
		free(pDelNode);
	}

	g_pRoot = NULL;
	g_nSize = 0;
	// InitList();
}

void PrintTree()
{
	int counter = 0;
	NODE* pTemp = g_pHead;
	while (pTemp != NULL) {
		printf("prev: [%p], address: [%p], next: [%p], data: %s\n", pTemp->prev, pTemp, pTemp->next, pTemp->pData);
		pTemp = pTemp->next;
		counter++;
	}
	if (counter == 0) 
	{
		printf("List is Empty.\n");
	}
}

int GetLength()
{
	return g_nSize;
}

int IsEmpty()
{
	if (g_pHead->next == g_pTail)
		return 1;
	return 0;
}

NODE* NodeInit(const char* data)
{
	// allocation, initialization, substitution
	NODE* pNewNode = malloc(sizeof(NODE));
	memset(pNewNode, 0, sizeof(NODE));
	strcpy_s(pNewNode->pData, sizeof(pNewNode->pData), data);
	
	return pNewNode;
}

int InsertNode(const char* data)
{
	NODE* pNewNode = NodeInit(data);
	if (g_pRoot == NULL) {
		g_pRoot = pNewNode;
		return 1;
	}

	NODE* pTemp = g_pRoot;
	while (1) 
	{
		if (strcmp(pTemp->pData, pNewNode->pData) < 0)
		{
			// left
			if (pTemp->left == NULL)
			{
				pTemp->left = pNewNode;
				break;
			}
			else
			{
				pTemp = pTemp->left;
				continue;
			}
		}
		else
		{
			// right
			if (pTemp->right == NULL)
			{
				pTemp->right = pNewNode;
				break;
			}
			else
			{
				pTemp = pTemp->right;
				continue;
			}
		}
	}
	return g_nSize;
}

NODE* GetNodeByData(const char* data)
{
	NODE* pTemp = g_pHead->next;
	while (pTemp != NULL)
	{
		if (strcmp(pTemp->pData, data) == 0)
		{
			return pTemp;
		}
		pTemp = pTemp->next;
	}
	return NULL;
}

int DeleteNodeByData(const char* data)
{
	NODE* pDelNode = GetNodeByData(data);
	if (pDelNode == NULL)
		return 0;
	pDelNode->prev->next = pDelNode->next;
	pDelNode->next->prev = pDelNode->prev;
	free(pDelNode);
	g_nSize--;
	return 0;
}

int main() 
{
	return 0;
}