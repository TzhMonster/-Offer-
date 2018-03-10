/*
����ĳ��������ǰ���������������Ľ�������ؽ��ö����������������ǰ�����
����������Ľ���ж������ظ������֡����磬����ǰ���������{1,2,3,7,3,5,6,8}
�������������{4,7,2,1,5,3,8,6}�����ؽ���ͼ2.6��ʾ�Ķ��������������ͷ��㡣
*/
#include<iostream>
using namespace std;

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

BinaryTreeNode* Construct(int* preorder, int* inorder, int length);
BinaryTreeNode* ConstruceCore(int* stratPreorder, int* endPrereder,
	int* startInorder, int* endInorder);

void test1();
void test2();

int main()
{
	test1();
	test2();
	return 0;
}

BinaryTreeNode * Construct(int * preorder, int * inorder, int length)
{
	if (preorder == nullptr || inorder == nullptr || length <= 0)
		return nullptr;
	return ConstruceCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
}

BinaryTreeNode * ConstruceCore(int * stratPreorder, int * endPrereder, int * startInorder, int * endInorder)
{
	int* sP = startInorder, *eP = endPrereder, *sI = startInorder, *eI = endInorder;
	BinaryTreeNode* node = new BinaryTreeNode();
	node->m_nValue = *sP;
	while (*sP == *sI)
	{
		if (sI > eI)
			return nullptr;
		++sI;
	}
	return nullptr;
}


