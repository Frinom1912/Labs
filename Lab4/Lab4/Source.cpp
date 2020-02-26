#include <iostream>
//��������� ����� ListNode (���� ������������ ������)
template <class INF, class FRIEND>
class ListNode				//���� ������
{
private:
	INF d;             			//�������������� ����� ����
	ListNode* next;   		 //��������� �� ��������� ���� ������
	ListNode() { next = NULL; } //����������� 
	friend FRIEND;
};

//��������� ����� MyStack �� ������ ������������ ������.
template <class INF >
class MyStack
{
	typedef class ListNode < INF, MyStack <INF> > Node;
	Node* top;
public:
	MyStack();		// �����������
	~MyStack();         	// ���������� ������������ ������
	bool empty();		// ���� ������?
	bool push(INF n);		// �������� ���� � ������� �����
	bool pop();		// ������� ���� �� ������� �����
	INF top_inf();		//������� ���������� �� ������� �����
};

template<class INF>
MyStack<INF>::MyStack()
{
	top = NULL;
}

template<class INF>
MyStack<INF>::~MyStack()
{
	delete[] top;
}

template<class INF>
bool MyStack<INF>::empty()
{
	return top == NULL ? true : false;
}

template<class INF>
bool MyStack<INF>::push(INF n)
{
	Node* temp = new Node;
	temp->next = top;
	temp->d = n;
	
	top = temp;

	return true;
}

template<class INF>
bool MyStack<INF>::pop()
{
	if (!empty())
	{
		top = top->next;
		return true;
	}
	else
		return false;
}

template<class INF>
INF MyStack<INF>::top_inf()
{
	return (top->d);
}


int main()
{
	MyStack<int> a;
	MyStack<int> b;

	int N;

	std::cin >> N;
	
	int original = N;
	int del = 2;

	while (N != 1)
	{
		while (N % del == 0)
		{
			a.push(del);
			N /= del;
		}
		if (del >= 3)
			del += 2;
		else
			del++;
	}


	std::cout << original << " = ";
	for (; !a.empty();)
	{
		std::cout << a.top_inf();
		b.push(a.top_inf());
		a.pop();
		if (!a.empty())
			std::cout << " * ";
	}
	std::cout << "\n";
	std::cout << original << " = ";
	for (; !b.empty();)
	{
		std::cout << b.top_inf();
		b.pop();
		if (!b.empty())
			std::cout << " * ";
	}
	std::cout << '\n';

	system("pause");
	return 0;
}