/*
输入一个链表的头结点，从尾到头反过来打印每个节点的值
*/

#include<iostream>
#include<stack>
using namespace std;

struct ListNode
{
	int m_nKey;
	ListNode* m_pNext;
};

/*递归实现*/
void PrintList(ListNode* Head);

/*重载非递归实现*/
void PrintList(ListNode* Head, int a);

/*测试*/
void test1();
void test2();

/*创建链表*/
ListNode* CreateList(int* a, int size);

int main()
{
	test1();
	test2();
	return 0;
}

void PrintListReversingly(ListNode* Head)
{
	if (Head == nullptr)
	{
		cout << "空串！" << endl;
		return;
	}

	if (Head->m_pNext != nullptr)
		PrintListReversingly(Head->m_pNext);
	cout << Head->m_nKey << " ";
}

void PrintListRversingly(ListNode * Head, int)
{
	if (Head == nullptr)
	{
		cout << "空串!" << endl;
		return;
	}

	stack<ListNode*> s;
	ListNode* L = Head;
	while (L != nullptr)
	{
		s.push(L);
		L=L->m_pNext;
	}
	while (!s.empty())
	{
		cout << s.top()->m_nKey << " ";
		s.pop();
	}
}

void test1()
{
	int a[] = { 1,2,3,4,5,6 };
	ListNode* Head = nullptr;
	Head = CreateList(a, 6);
	cout << "递归逆置：";
	PrintListReversingly(Head);
	cout << endl;
	cout << "非递归逆置：";
	PrintListRversingly(Head, 1);
	cout << endl;
	delete Head;
}

void test2()
{
	int* a = nullptr;
	ListNode* Head = nullptr;
	Head = CreateList(a, 0);
	cout << "递归逆置：";
	PrintListReversingly(Head);
	cout << endl;
	cout << "非递归逆置：";
	PrintListRversingly(Head, 1);
	cout << endl;
}

ListNode * CreateList(int * a, int size)
{
	if (a == nullptr || size <= 0)
		return nullptr;

	ListNode* node = new ListNode();
	ListNode* head = new ListNode();
	head->m_nKey = a[0];
	head->m_pNext = nullptr;
	ListNode* p = head;
	int i = 1;
	while (i < size)
	{
		node->m_nKey = a[i++];
		p->m_pNext = node;
		p = node;
		p->m_pNext = nullptr;
	}
	return head;
}