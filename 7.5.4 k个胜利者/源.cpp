#include <iostream>
using namespace std;

typedef struct ListNode {
	int val;
	ListNode* next;
};

ListNode* createNode(int n)//建立一个循环链表
{
	ListNode* child = new ListNode();
	child->val = 1;
	child->next = NULL;
	ListNode* p = child;
	for (int i = 2; i <= n; i++)
	{
		ListNode* newNode = new ListNode();
		newNode->val = i;
		p->next = newNode;
		p = p->next;
	}

	p->next = child;

	return child;
}

void gaming(int n, int m, int k,ListNode*& child)
{
	ListNode* now = child;
	ListNode* prev = child;
	int i = 1;
	for(int remain = n; remain != k;)
	{
		if (i == m)
		{
			prev->next = now->next;
			now = now->next;
			child = now;
			i = 1;
			remain--;
		}
		else
		{
			prev = now;
			now = now->next;
			i++;
		}
	}
}

void output(ListNode* child,int k)
{
	ListNode* p = child->next;
	for (int i = 1; i <= k; i++)
	{
		cout << p->val << " ";
		p = p->next;
	}
}

int main()
{
	int i;
	cin >> i;
	for (int j = 1; j <= i; j++)
	{
		int n, m, k;
		cin >> n >> m >> k;
		ListNode* child = createNode(n);
		gaming(n, m, k, child);
		output(child, k);
	}
}