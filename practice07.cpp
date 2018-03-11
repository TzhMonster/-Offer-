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

//算法
BinaryTreeNode* Construct(int* preorder, int* inorder, int length);
BinaryTreeNode* ConstructCore(int* stratPreorder, int* endPrereder,int* startInorder, int* endInorder);

//测试，前序遍历序列{1,2,4,7,3,5,6,8}，中序遍历序列{4,7,2,1,5,3,8,6}
void test1();

//前序遍历二叉树
void Preorder(BinaryTreeNode* BiTree);

int main()
{
	test1();
	return 0;
}

BinaryTreeNode * Construct(int * preorder, int * inorder, int length)
{
	if (preorder == nullptr || inorder == nullptr || length <= 0)
		return nullptr;
	return ConstructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
}

BinaryTreeNode * ConstructCore(int * startPreorder, int * endPrereder, int * startInorder, int * endInorder)
{
	//初始化根节点
	BinaryTreeNode* node = new BinaryTreeNode();
	node->m_nValue = *startPreorder;
	node->m_pLeft = node->m_pRight = nullptr;

	//根节点在中序遍历中的位置，左边是左子树的中序遍历序列，右边是右子树的中序遍历序列
	int *valueInInorder = startInorder;
	//用于记录根节点在中序遍历序列的位置，也就是左子树有多少节点
	int count = 0;
	while (valueInInorder<= endInorder)
	{
		if (*valueInInorder == *startPreorder)
			break;
		++valueInInorder;
		++count;
	}
	//根节点在中序遍历序列中不存在
	if (valueInInorder > endInorder)
		throw exception("invalued input!");
	//记录中序遍历序列根节点所在位置对应的前序遍历序列的位置，用于分开左右子树的前序遍历序列，左边是左子树的前序遍历序列，右边是右子树的前序遍历序列
	int *addrInPreorder = startPreorder + count;

	//建立左子树
	if (startPreorder < addrInPreorder)
		node->m_pLeft = ConstructCore(startPreorder + 1, addrInPreorder, startInorder, valueInInorder - 1);
	
	//建立右子树
	if (valueInInorder < endInorder)
		node->m_pRight = ConstructCore(addrInPreorder + 1, endPrereder, valueInInorder + 1, endInorder);

	return node;
}

void test1()
{
	int Pre[] = { 1,2,4,7,3,5,6,8 };
	int In[] = { 4,7,2,1,5,3,8,6 };
	BinaryTreeNode *BiTree;
	BiTree = Construct(Pre, In, 8);
	Preorder(BiTree);
	cout << endl;
}

void Preorder(BinaryTreeNode * BiTree)
{
	if (BiTree == nullptr)
		return;
	if(BiTree->m_pLeft)
		Preorder(BiTree->m_pLeft);
	cout << BiTree->m_nValue << " ";
	if(BiTree->m_pRight)
		Preorder(BiTree->m_pRight);
}