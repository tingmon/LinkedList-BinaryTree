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

int GetLength()
{
	return g_nSize;
}

int IsEmpty()
{
	if (g_pRoot == NULL)
		return 1;
	return 0;
}

//void DropTree()
//{
//	printf("g_nSize[%d], g_pRoot[%p]\n", g_nSize, g_pRoot);
//	NODE* pTemp = g_pRoot;
//	while (pTemp->next != g_pTail) {
//		NODE* pDelNode = pTemp;
//		pTemp = pTemp->next;
//		free(pDelNode);
//	}
//
//	g_pRoot = NULL;
//	g_nSize = 0;
//}

void PrintTree(NODE* pParent) // pParent is likely a root node
{
	if (g_nSize == 0)
	{
		printf("List is Empty.\n");
		return;
	}
	if (pParent == NULL) 
		return;

	PrintTree(pParent->left); // print this.left node

	printf("this[%p], left[%p], right[%p], data: %s\n", // print this node
		pParent, pParent->left, pParent->right, pParent->pData);

	PrintTree(pParent->right); // print this.right node
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
	while (pTemp != NULL)
	{
		if (strcmp(pTemp->pData, pNewNode->pData) > 0) // strcmp(criterion, value) -> criterion - value > 0 == criterion is bigger than value
		{
			// left
			if (pTemp->left == NULL)
			{
				pTemp->left = pNewNode;
				g_nSize++;
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
				g_nSize++;
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

//NODE* GetNodeByData(const char* data)
//{
//	NODE* pTemp = g_pHead->next;
//	while (pTemp != NULL)
//	{
//		if (strcmp(pTemp->pData, data) == 0)
//		{
//			return pTemp;
//		}
//		pTemp = pTemp->next;
//	}
//	return NULL;
//}
//
//int DeleteNodeByData(const char* data)
//{
//	NODE* pDelNode = GetNodeByData(data);
//	if (pDelNode == NULL)
//		return 0;
//	pDelNode->prev->next = pDelNode->next;
//	pDelNode->next->prev = pDelNode->prev;
//	free(pDelNode);
//	g_nSize--;
//	return 0;
//}

int main() 
{
	InsertNode("5");
	InsertNode("2");
	InsertNode("6");
	InsertNode("56");
	InsertNode("13");
	InsertNode("68");
	InsertNode("94");
	InsertNode("31");
	InsertNode("18");
	InsertNode("46");
	InsertNode("33");
	InsertNode("57");
	InsertNode("63");
	InsertNode("11");
	InsertNode("24");

	PrintTree(g_pRoot);
	return 0;
}