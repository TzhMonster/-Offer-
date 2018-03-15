/*
请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
路径可以从矩阵中的任意一个开始，每一步可以在矩阵中向左、右、上、下移动一格。
如果一条路径经过了矩阵的某一格，那么该路径不能再次进入该各自。
*/
#include <iostream>
using namespace std;

bool hasPath(const char* matrix, int rows, int cols,const char * str);
bool hasPathCore(const char * matrix,
	int row, int col, int rows, int cols,
	bool * visited, const char * str, int& length);



bool hasPath(const char* matrix, int rows, int cols,const char * str)
{
	//判空
	if (matrix == nullptr || rows < 1 || cols < 1 || str==nullptr)
		return false;

	//创建并初始化布尔矩阵
	bool* visited = new bool[rows*cols];
	memset(visited, 0, rows*cols);
	/*for (int i = 0; i != rows; ++i)
		for (int j = 0; j != cols; ++j)
			visited[i*cols + j] = false;*/

	int length = 0;
	//查找到第一个节点并判断是否存在通路
	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < cols; ++j)
			if (hasPathCore(matrix, i, j, rows, cols, visited, str, length))
			{
				delete[] visited;
				return true;
			}
	//else情况为还没有找到这个节点或者该节点不存在通路

	delete[] visited;
	return false;
}


bool hasPathCore(const char * matrix, 
	int row, int col, int rows, int cols,
	bool * visited, const char * str,int& length)
{
	//路径查找完毕
	if (str[length] == '\0')
		return true;

	bool hasPath = false;
	//判断是否为矩阵内未被访问的元素
	if (matrix[row*cols + col] == str[length]
		&& row < rows && col < cols
		&& row >= 0 && col >= 0
		&& !visited [row*cols + col])
	{
		visited [row*cols + col] = true;
		++length;
		//判断在上下左右为路径下一个字符
		hasPath = hasPathCore(matrix, row + 1, col, rows, cols, visited, str, length)
			|| hasPathCore(matrix, row - 1, col, rows, cols, visited, str, length)
			|| hasPathCore(matrix, row, col + 1, rows, cols, visited, str, length)
			|| hasPathCore(matrix, row, col - 1, rows, cols, visited, str, length);
		//此路不同，回溯
		if (!hasPath)
		{
			--length;
			visited [row*cols + col] = false;
		}
	}
	return hasPath;
}


// ====================测试代码====================
void Test(const char* testName, const char* matrix, int rows, int cols, const char* str, bool expected)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	if (hasPath(matrix, rows, cols, str) == expected)
		printf("Passed.\n");
	else
		printf("FAILED.\n");
}

//ABTG
//CFCS
//JDEH

//BFCE
void Test1()
{
	const char* matrix = "ABTGCFCSJDEH";
	const char* str = "BFCE";

	Test("Test1", (const char*)matrix, 3, 4, str, true);
}

//ABCE
//SFCS
//ADEE

//SEE
void Test2()
{
	const char* matrix = "ABCESFCSADEE";
	const char* str = "SEE";

	Test("Test2", (const char*)matrix, 3, 4, str, true);
}

//ABTG
//CFCS
//JDEH

//ABFB
void Test3()
{
	const char* matrix = "ABTGCFCSJDEH";
	const char* str = "ABFB";

	Test("Test3", (const char*)matrix, 3, 4, str, false);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SLHECCEIDEJFGGFIE
void Test4()
{
	const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
	const char* str = "SLHECCEIDEJFGGFIE";

	Test("Test4", (const char*)matrix, 5, 8, str, true);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SGGFIECVAASABCEHJIGQEM
void Test5()
{
	const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
	const char* str = "SGGFIECVAASABCEHJIGQEM";

	Test("Test5", (const char*)matrix, 5, 8, str, true);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SGGFIECVAASABCEEJIGOEM
void Test6()
{
	const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
	const char* str = "SGGFIECVAASABCEEJIGOEM";

	Test("Test6", (const char*)matrix, 5, 8, str, false);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SGGFIECVAASABCEHJIGQEMS
void Test7()
{
	const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
	const char* str = "SGGFIECVAASABCEHJIGQEMS";

	Test("Test7", (const char*)matrix, 5, 8, str, false);
}

//AAAA
//AAAA
//AAAA

//AAAAAAAAAAAA
void Test8()
{
	const char* matrix = "AAAAAAAAAAAA";
	const char* str = "AAAAAAAAAAAA";

	Test("Test8", (const char*)matrix, 3, 4, str, true);
}

//AAAA
//AAAA
//AAAA

//AAAAAAAAAAAAA
void Test9()
{
	const char* matrix = "AAAAAAAAAAAA";
	const char* str = "AAAAAAAAAAAAA";

	Test("Test9", (const char*)matrix, 3, 4, str, false);
}

//A

//A
void Test10()
{
	const char* matrix = "A";
	const char* str = "A";

	Test("Test10", (const char*)matrix, 1, 1, str, true);
}

//A

//B
void Test11()
{
	const char* matrix = "A";
	const char* str = "B";

	Test("Test11", (const char*)matrix, 1, 1, str, false);
}

void Test12()
{
	Test("Test12", nullptr, 0, 0, nullptr, false);
}

int main(int argc, char* argv[])
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();
	Test7();
	Test8();
	Test9();
	Test10();
	Test11();
	Test12();

	return 0;
}