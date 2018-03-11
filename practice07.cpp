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

//�㷨
BinaryTreeNode* Construct(int* preorder, int* inorder, int length);
BinaryTreeNode* ConstructCore(int* stratPreorder, int* endPrereder,int* startInorder, int* endInorder);

//���ԣ�ǰ���������{1,2,4,7,3,5,6,8}�������������{4,7,2,1,5,3,8,6}
void test1();

//ǰ�����������
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
	//��ʼ�����ڵ�
	BinaryTreeNode* node = new BinaryTreeNode();
	node->m_nValue = *startPreorder;
	node->m_pLeft = node->m_pRight = nullptr;

	//���ڵ�����������е�λ�ã������������������������У��ұ����������������������
	int *valueInInorder = startInorder;
	//���ڼ�¼���ڵ�������������е�λ�ã�Ҳ�����������ж��ٽڵ�
	int count = 0;
	while (valueInInorder<= endInorder)
	{
		if (*valueInInorder == *startPreorder)
			break;
		++valueInInorder;
		++count;
	}
	//���ڵ���������������в�����
	if (valueInInorder > endInorder)
		throw exception("invalued input!");
	//��¼����������и��ڵ�����λ�ö�Ӧ��ǰ��������е�λ�ã����ڷֿ�����������ǰ��������У��������������ǰ��������У��ұ�����������ǰ���������
	int *addrInPreorder = startPreorder + count;

	//����������
	if (startPreorder < addrInPreorder)
		node->m_pLeft = ConstructCore(startPreorder + 1, addrInPreorder, startInorder, valueInInorder - 1);
	
	//����������
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