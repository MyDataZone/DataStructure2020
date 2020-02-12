#include "head.h"
#include <iostream>
#include <cstdio>
#include <ctime>
#include <iterator>
#include <algorithm>

#define maxSize 10

#pragma warning(disable:4996)

using namespace std;

int createList(int *A, int &length)
{
	printf("please input your array's length in \n");
	scanf("%d", &length);
	if (length<0 || length>maxSize)
		return 0;
	for (int i = 0; i < length; i++)
		scanf("%d", A + i);
	return 1;
}

void PrintOne(int x)
{
	printf("%d ", x);
}

void createDbLinkListR(Node* &head)
{
	head = new Node;
	head->next = nullptr;
	head->prior = nullptr;
	int n = 0;
	scanf("%d", &n);
	if (n < 0)
		return;
	Node *p, *q;
	q = head;
	for (int i = 0; i < n; i++)
	{
		p = new Node;
		p->next = nullptr;
		p->prior = nullptr;
		scanf("%d", &(p->elem));
		q->next = p;
		p->prior = q;
		q = p;
	}
}

void createCDbLinkListL(Node* &head)
{
	head = new Node;
	head->next = head;
	head->prior = head;
	int n = 0;
	scanf("%d", &n);
	if (n < 0)
		return;
	Node *temp = nullptr;
	for (int i = 0; i < n; i++)
	{
		temp = new Node;
		temp->next = temp;
		temp->prior = temp;
		scanf("%d", &(temp->elem));
		temp->next = head->next;
		head->next->prior = temp;
		head->next = temp;
		temp->prior = head;
	}
}

int main()
{
	int A[maxSize] = { 0 };
	int length = 0;
	int flag = createList(A, length);
	if (flag != 0)
	{
		printf("Length = %d \n", length);
		for_each(begin(A), begin(A) + length, PrintOne);
		printf("\n");
	}
	Node* head;
	createCDbLinkListL(head);
	if (head != nullptr)
	{
		Node* tmp = head->next;
		while (tmp != head)
		{
			printf("%d ", tmp->elem);
			tmp = tmp->next;
		}
		tmp = tmp->prior;
		printf("\n");
		while (tmp != head)
		{
			printf("%d ", tmp->elem);
			tmp = tmp->prior;
		}
	}
	printf("\n end \n");
	system("pause");
	return 0;
}