/*用两个栈实现一个队列.队列的声明如下，请实现它的两个函数appendTail和deleteHead,
分别完成在队列尾部插入节点和在队列头部删除节点*/

#include<iostream>
#include<stack>
using namespace std;

template<class T>
class CQueue 
{
private:
	stack<T> stack1, stack2;
public:
	CQueue(void) {};
	~CQueue(void) {};
	void appendTail(const T& data);
	T deleteHead();
};

template<class T>
void CQueue<T>::appendTail(const T & data)
{
	stack1.push(data);
}

template<class T>
T CQueue<T>::deleteHead()
{
	if (stack2.size() > 0)
	{
		T popData = stack2.top();
		stack2.pop();
		return popData;
	}
	else if (stack1.size() > 0)
	{
		while (stack1.size() > 0)
		{
			T popData = stack1.top();
			stack1.pop();
			stack2.push(popData);
		}
		T popData = stack2.top();
		stack2.pop();
		return popData;
	}
	else
		throw new exception("Empty Queue!");
	return T();
}

void Test(char actual, char expected)
{
	if (actual == expected)
		printf("Test passed.\n");
	else
		printf("Test failed.\n");
}

int main(int argc, char* argv[])
{
	CQueue<char> queue;

	queue.appendTail('a');
	queue.appendTail('b');
	queue.appendTail('c');

	char head = queue.deleteHead();
	Test(head, 'a');

	head = queue.deleteHead();
	Test(head, 'b');

	queue.appendTail('d');
	head = queue.deleteHead();
	Test(head, 'c');

	queue.appendTail('e');
	head = queue.deleteHead();
	Test(head, 'd');

	head = queue.deleteHead();
	Test(head, 'e');

	return 0;
}