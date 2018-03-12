/*
两个队列实现栈
*/

#include<iostream>
#include<queue>
using namespace std;

template<class T>
class Stack 
{
private:
	queue<T> queue1, queue2;
public:
	Stack(void) {};
	~Stack(void) {};
	void push(const T& data);
	T pop();
};

template<class T>
void Stack<T>::push(const T& data)
{
	if (!queue1.empty())
		queue1.push(data);
	else if (!queue2.empty())
		queue2.push(data);
	else
		queue1.push(data);
}

template<class T>
T Stack<T>::pop()
{
	if (!queue1.empty())
	{
		while (queue1.size() > 1)
		{
			queue2.push(queue1.front());
			queue1.pop();
		}
		T popData = queue1.front();
		queue1.pop();
		return popData;
	}
	else if (!queue2.empty())
	{
		while (queue2.size() > 1)
		{
			queue1.push(queue2.front());
			queue2.pop();
		}
		T popData = queue2.front();
		queue2.pop();
		return popData;
	}
	else
		throw new exception("empty queue!");
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
	Stack<char> stack;

	stack.push('a');
	stack.push('b');
	stack.push('c');

	char head = stack.pop();
	Test(head, 'c');

	head = stack.pop();
	Test(head, 'b');

	stack.push('d');
	head = stack.pop();
	Test(head, 'd');

	stack.push('e');
	head = stack.pop();
	Test(head, 'e');

	head = stack.pop();
	Test(head, 'a');

	return 0;
}