#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef enum { false, true } bool;

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

void DropTree(NODE* pParent)
{
	//printf("g_nSize[%d], pData[%p]\n", g_nSize, pParent->pData);
	
	if (pParent == NULL) {
		return;
	}

	DropTree(pParent->left);
	DropTree(pParent->right);
	printf("free(): %p, %s\n", pParent, pParent->pData);
	free(pParent);
	g_nSize--;

	
}

void PrintTree(NODE* pParent) // pParent is likely a root node
{
	if (g_nSize == 0)
	{
		printf("Nothing to Print, List is Empty.\n");
		return;
	}
	if (pParent == NULL) 
		return;

	PrintTree(pParent->left); // print this.left node

	printf("left[%p], this[%p], right[%p], data: %s\n", // print this node
		pParent->left, pParent, pParent->right, pParent->pData);

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
		g_nSize++;
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

NODE* GetNodeByData(const NODE* pParent, const char* data, const bool isPrevReturn)
{
	if (pParent == NULL)
		return NULL;
	if (data == NULL)
		return NULL;
	NODE* pTemp = pParent;
	NODE* pPrev = NULL;
	while (pTemp != NULL)
	{
		if (strcmp(pTemp->pData, data) == 0)
		{
			if (isPrevReturn)
				return pPrev;
			return pTemp;
		}
		if (strcmp(pTemp->pData, data) > 0)
		{
			if (pTemp->left != NULL)
			{
				pPrev = pTemp;
				pTemp = pTemp->left;
				continue;
			}
		}
		else 
		{
			if (pTemp->right != NULL)
			{
				pPrev = pTemp;
				pTemp = pTemp->right;
				continue;
			}
		}
	}
	return NULL;
}

// delete all nodes below pDelNode
int DeleteNodeInclusive(const NODE* pParent, const char* data)
{
	NODE* pDelNode = GetNodeByData(pParent, data, false);
	NODE* pPrev = GetNodeByData(pParent, data, true);
	if (pDelNode == NULL)
		return 0;

	if (strcmp(pPrev->pData, pDelNode->pData) > 0)
		pPrev->left = NULL;
	else
		pPrev->right = NULL;
	
	printf("delete[%p], val[%s]\n", pDelNode, pDelNode->pData);

	if (pDelNode->left->pData != NULL)
		DeleteNodeInclusive(pDelNode, pDelNode->left->pData);
	if (pDelNode->right->pData != NULL)
		DeleteNodeInclusive(pDelNode, pDelNode->right->pData);

	free(pDelNode);  
	g_nSize--;
	return g_nSize;
}

// delete target node only, structure arrangement required
int DeleteNodeExclusive(const NODE* pParent, const char* data)
{
	NODE* pDelNode = GetNodeByData(pParent, data, false);
	if (pDelNode == g_pRoot) // not sure what to do...
		return 0;
	if (pDelNode == NULL)
		return 0;
	NODE* pPrev = GetNodeByData(pParent, data, true);
	if (pPrev == NULL)
		return 0;

	printf("delete[%p], val[%s]\n", pDelNode, pDelNode->pData);

	if (strcmp(pPrev->pData, pDelNode->pData) > 0)
	{
		// delnode is left of parent node
		pPrev->left = pDelNode->right;
		while (pDelNode != NULL)
		{
			if (pDelNode->right != NULL)
			{
			}
			if (pDelNode->right != NULL && pDelNode->left != NULL)
			{
				pDelNode->right->left = pDelNode->left;
			}
			pDelNode = pDelNode->right;
		}
	} 
	else
	{
		// delnode is right of parent node
		pPrev->right = pDelNode->left;
		while (pDelNode != NULL)
		{
			if (pDelNode->left != NULL && pDelNode->right != NULL)
			{
				pDelNode->left->right = pDelNode->right;
			}
			pDelNode = pDelNode->left;
		}
	}
	free(pDelNode);
	g_nSize--;
	return 0;
}

void UpdateNode(const NODE* pParent, char* prevData, const char* newData)
{
	NODE* targetNode = GetNodeByData(pParent, prevData, false);
	strcpy_s(targetNode->pData, sizeof(targetNode->pData), newData);
	// re-arrange again? hell no..
}

int main() 
{
	InsertNode("5");
	InsertNode("4");
	InsertNode("7");
	InsertNode("6");
	InsertNode("8");
	//InsertNode("68");
	//InsertNode("94");
	//InsertNode("31");
	//InsertNode("18");
	//InsertNode("46");
	//InsertNode("33");
	//InsertNode("57");
	//InsertNode("63");
	//InsertNode("11");
	//InsertNode("24");

	PrintTree(g_pRoot);


	//DeleteNodeInclusive(g_pRoot, "7");
	DeleteNodeExclusive(g_pRoot, "7");
	//DropTree(g_pRoot);
	UpdateNode(g_pRoot, "4", "10");
	PrintTree(g_pRoot);
	return 0;
}