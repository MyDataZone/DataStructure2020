#pragma once
#include "head.h"

void reverseArray(int *a, int left, int right, int k)
{
	int temp = 0;
	for (int i = left, j = right; i < j && i < left + k; i++, j--)
	{
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
}

void reverseArrayInSequence(int *a, int n, int k)
{
	reverseArray(a, 0, k - 1, k);
	reverseArray(a, n - k, n - 1, k);
	reverseArray(a, 0, n - 1, n);
}

void rotateArray(int *a, int n, int r)
{
	reverseArray(a, 0, r - 1, r);
	reverseArray(a, r, n - 1, n - r);
	reverseArray(a, 0, n - 1, n);
}

int* mergeArray(int *a, int m, int *b, int n)
{
	int *c = new int[m + n];
	int i, j, k;
	i = j = k = 0;
	while (i < m && j < n)
	{
		if (a[i] < b[j])
			c[k++] = a[i++];
		else
			c[k++] = b[j++];
	}
	while (i < m)
		c[k++] = a[i++];
	while (j < n)
		c[k++] = b[j++];
	return c;
}

void mergeList(Node *a, Node *b, Node *&c)
{
	Node *p = a->next;
	Node *q = b->next;
	c = a;
	delete b;
	Node *r;
	r = c;
	c->next = nullptr;
	while (p != nullptr && q != nullptr)
	{
		if (p->elem <= q->elem)
		{
			r->next = p;
			p = p->next;
		}
		else
		{
			r->next = q;
			q = q->next;
		}
		r = r->next;
	}
	if (p != nullptr)
		r->next = p;
	if (q != nullptr)
		r->next = q;
}

void partition(int *arr, int n)
{
	int i, j;
	int tmp = 0;
	i = 0, j = n - 1;
	tmp = arr[i];
	while (i < j)
	{
		while (i<j&&arr[j]>tmp)
			j--;
		if (i < j)
			arr[i++] = arr[j];
		while (i < j&&arr[i] <= tmp)
			i++;
		if (i < j)
			arr[j--] = arr[i];
		arr[i] = tmp;
	}
}

void partitionCmp(int *arr, int n, int cmp)
{
	int i = 0, j = n - 1;
	int tmp = arr[i];
	while (i < j)
	{
		while (i<j&&arr[j]>cmp)
			j--;
		if (i < j)
			arr[i++] = arr[j];
		while (i < j&&arr[i] <= cmp)
			i++;
		if (i < j)
			arr[j--] = arr[i];
		arr[i] = tmp;
	}
}

void partitionRAny(int *arr, int n, int k)
{
	int i = 0, j = n - 1;
	int tmp = arr[i];
	arr[i] = arr[k];
	arr[k] = tmp;
	while (i < j)
	{
		while (i<j&&arr[j]<tmp)
			j--;
		if (i < j)
			arr[i++] = arr[j];
		while (i < j&&arr[i] >= tmp)
			i++;
		if (i < j)
			arr[j--] = arr[i];
		arr[i] = tmp;
	}
}