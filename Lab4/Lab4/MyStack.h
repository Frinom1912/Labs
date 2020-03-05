#pragma once
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
	delete top;
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