/*
 * =====================================================================================
 *
 *       Filename:  Trie_UniqueRows.cpp
 *
 *    Description:  Problem: http://www.geeksforgeeks.org/print-unique-rows/
 *
 *        Version:  1.0
 *        Created:  11/20/2016 7:20:25 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  YOUR NAME (Adwait R Sambare), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

using namespace std;

#define MAX_BIN 2
#define MAX_CHARS 26

#define ARRAY_TO_LEN(array) sizeof(array)/sizeof(array[0])
#define BIN_CHAR_TO_INDEX(a) (int)a - (int)'0'

struct TNode
{
	struct TNode *children[MAX_BIN];

	bool isLeaf;

};


struct TNode * getNode()
{
	struct TNode *newNode = (struct TNode*)malloc(sizeof(struct TNode));

	for(int i=0; i < MAX_BIN ; i++)
	{
		newNode->children[i] = 0;
		newNode->isLeaf = false;
	}

	return newNode;
}

void insert(TNode *root, char *str)
{
	int length = strlen(str);
	int index;

	for(int i=0; i < length; i++)
	{
		index = BIN_CHAR_TO_INDEX(str[i]);

		if(!root->children[index])
			root->children[index] = getNode();
		root = root->children[index];
	}

	root->isLeaf = true;
}

bool search(TNode *root, char *str)
{
	int length = strlen(str);
	int index;

	for(int i=0; i < length; i++)
	{
		index = BIN_CHAR_TO_INDEX(str[i]);

		if(!root->children[i])
			return false;
		root = root->children[index];
	}

	return (root != NULL && root->isLeaf);
}

bool hasChildren(TNode *root)
{
	TNode *pCrawl = root;

	for(int i = 0; i < MAX_BIN ; i++)
	{
		if(pCrawl->children[i])
			return true;
	}

	return false;
}

bool deleteUtil(TNode *root, char *str, int count, int length)
{
	int index = BIN_CHAR_TO_INDEX(str[count]);
	TNode *pCrawl = root;
	
	if(root)
	{
		if(count == length)
		{
			if(pCrawl->isLeaf)
			{
				pCrawl->isLeaf = false;

				return !hasChildren(pCrawl);	
			}
		}
		else if(deleteUtil(pCrawl->children[index], str, count+1, length))
		{

			free(pCrawl->children[index]);
			pCrawl->children[index] = NULL;

			return (!hasChildren(pCrawl) && !pCrawl->isLeaf);
			
		}
	
	}	return false;
	
}



int main()
{

	char keys[][8] = {"010101", "111010", "101000", "010101", "110001", "101000", "000011"};
	
	TNode *root = new TNode;
		     
	for(int i = 0; i < ARRAY_TO_LEN(keys); i++)
	{
		(root, keys[i]);
	}
			 
	deleteUtil(root, keys[0], 0, strlen("010101"));
			     
	printf("%s %d\n", "010101", search(root, (char*)"010101"));
				   

	return 0;
}
