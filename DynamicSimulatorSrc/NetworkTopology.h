#pragma once
//Keep Track of any change in network to modify the knowledge graph for routing.
#include<iostream>
#include "containerFile.h"
#define PATH "parseFile.txt"
#define MAX 9999
#pragma warning(disable:4996)
using namespace std;
struct node {
	struct node *link;
	int data;
};

int **getKnowledgeGraph()//creats adjacency matrix and keep ready the nodeStatus[] array  
{

	char arr[100],c; int rs = 0, i = 0, j, k, n1, i1, l, **arrr1; FILE *ptr;
	ptr = fopen(PATH, "r");
	// Reading  the total no of vertex
	fgets(arr, 80, ptr);
	i = 0; n = 0;
	while (arr[i] != '\n')	{
		k = arr[i] - '0';
		n = (n * 10) + k;
		i++;
	}
	arrr1 = (int **)malloc(sizeof(int *)*n);
	for (i = 0; i<n; i++)
		arrr1[i] = (int *)malloc(sizeof(int)*n);
	n1 = 0; i = 0; j = 0; k = 0;
	for (i = 0; i<n; i++, j = 0)
	{
		fgets(arr, 80, ptr); i1 = 0;
		l = strlen(arr) - 1;
		for (i1 = 0; i1 <= l; i1++)
		{
			if (isdigit(arr[i1]))
			{
				k = 0;
				k = arr[i1] - '0';
				n1 = n1 * 10 + k;
				if ((i == n - 1) && (j == n - 1))
					arrr1[i][j] = n1;
			}
			else
			{
				arrr1[i][j] = n1;
				n1 = 0; j++;
			}
		}
	}
	n1 = 0;
	// Reading the wireless node id 
	fgets(arr, 80, ptr);
	l = strlen(arr) - 1;
	int *RS1 = new int[n];
	for (i1 = 0; i1 <= l; i1++)
	{
		if (isdigit(arr[i1]))
		{
			k = 0;
			k = arr[i1] - '0';
			n1 = n1 * 10 + k;
		}
		else
		{
			RS1[rs++] = n1;
			n1 = 0;
		}
	}
	nodeStatus = new int[n];
	for (int k = 0; k<n; k++)
		nodeStatus[k] = 0;
	for (int k = 0; k<rs; k++)
		nodeStatus[RS1[k]] = 1;
	n1 = 0; rs = 0;
	// Reading the base Station  node id 
	fgets(arr, 80, ptr);
	l = strlen(arr) - 1;
	for (i1 = 0; i1 <= l; i1++)
	{
		if (isdigit(arr[i1]))
		{
			k = 0;
			k = arr[i1] - '0';
			n1 = n1 * 10 + k;
		}
		else
		{
			RS1[rs++] = n1;
			n1 = 0;
		}
	}
	for (int k = 0; k<rs; k++)
		nodeStatus[RS1[k]] = 2;
	fclose(ptr);
	return arrr1;
}
