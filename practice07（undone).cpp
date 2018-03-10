/*
输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历
和中序遍历的结果中都不含重复的数字。例如，输入前序遍历序列{1,2,3,7,3,5,6,8}
和中序遍历序列{4,7,2,1,5,3,8,6}，则重建如图2.6所示的二叉树并输出它的头结点。
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


