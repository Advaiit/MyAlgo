#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

using namespace std;

#define MAX_CHAR 26
#define ARRAY_TO_SIZE(array) sizeof(array)/sizeof(array[0])
#define CHAR_TO_INDEX(a) ((int)a - (int)'a')
#define FREE(x) free(x);x = NULL;

struct TNode
{
	struct TNode *nodes[26];

	bool isLeaf;
};


struct TNode * getNode()
{
	TNode *node = NULL;

	node = (struct TNode*)malloc(sizeof(struct TNode));

	if(node)
	{
		for(int i=0;i<MAX_CHAR;i++)
		{
			node->nodes[i] = NULL;
		}

		node->isLeaf = false;
	}

	return node;
}


void insertTrie(TNode *root, const char *str)
{
	if(!root)
	{
		root = getNode();
	}
	
	TNode *pCrawl = root;

	int length = strlen(str);
	int index;

	for(int level = 0; level < length; level++)
	{
		index = CHAR_TO_INDEX(str[level]);

		if(!pCrawl->nodes[index])
			pCrawl->nodes[index] = getNode();
		pCrawl = pCrawl->nodes[index];
	}	

	pCrawl->isLeaf = true;
}

bool searchTrie(TNode *root, const char *str)
{
	if(!root)
	{
		cout<<"searchTrie:root is NULL"<<endl;
		return false;
	}

	int length = strlen(str);
	int index;
	TNode *pCrawl = root;

	for(int level = 0; level < length; level++)
	{
		index = CHAR_TO_INDEX(str[level]);

		if(!pCrawl->nodes[index])
			return false;
		pCrawl = pCrawl->nodes[index];
	}

	
	return (pCrawl != NULL && pCrawl->isLeaf);
}

bool IsFreeNode(TNode *root)
{
	for(int i = 0 ; i < MAX_CHAR ; i++)
	{
		if(root->nodes[i])
			return false;
	}

	return true;
}


bool deleteUtilTrie(TNode *root, const char *str, int count, int len)
{
	if(root)
	{
		if(count == len)
		{
			root->isLeaf = false;

			if(IsFreeNode(root))
				return true;
			return true;
		}
		else
		{
			int index = CHAR_TO_INDEX(str[count]);

			if(deleteUtilTrie(root->nodes[index], str, count+1, len))
			{
				FREE(root->nodes[index]);

				return (!(root->isLeaf) && IsFreeNode(root));
			}
		}
	}
}


int main()
{
	char keys[][8] = {"hello", "how", "are", "you", "these", "are", "some", "keys"};

	TNode *root = getNode();

	int arraysize = ARRAY_TO_SIZE(keys);

	for(int i=0; i < arraysize; i++)
	{
		insertTrie(root, keys[i]);
	}


	cout<<"Search for hello: "<<searchTrie(root,"hello");

	cout<<"Search for hola: "<<searchTrie(root, "hola");

	deleteUtilTrie(root, "hello", 0, 5);

	cout<<"Search for hello: "<<searchTrie(root,"hello");
	
	return 0;
}
