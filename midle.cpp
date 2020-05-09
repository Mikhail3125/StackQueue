#include "Stdafx.h"
#include "midle.h"
using namespace std;

/*
������� ������� ��������� ��������, ��� ���������� ��������� ����������� ������. ����������� ��������
���������� (enqueue) � �������� (dequeue) �������� �� �������. �������� � ������� ������ �one�,
�two�, �three�, �four� � ������������ ���������� �������. ������� 1 ������� �� �������, ����� 
�������� � ������� ������ �five� � ������������ ������� ��� ���. * ������� ��������� ����� �����,
������������� �������
*/
void midle()
{
	system("cls");
	cout << "\nMidle level task: \n";
	queue* q;
	q = (queue*)malloc(sizeof(queue*));
	enequeue(q);
	string mas_str[4] = { "one", "two", "three", "four" };
	for (size_t i = 0; i < 4; i++)
	{
		insert(q, mas_str[i]);
	}
	cout << "\n���������� ������� �� ��������� ���������: \n";
	show(q);
	cout << "\n���������� ������� ����� ��������� ���������: \n";
	remove(q);
	insert(q, "five");
	show(q);
	cout << "\n��������� ����� �����,������������� �������: ";  int len = length(q); cout << len << endl;
	cout << "\n������� Enter ��� ����������...";
	while (getchar() != '\n')
		continue;
}

struct queue
{
	list* front, * tail;
};

struct list
{
	string strvar;
	list* next;
};

int length(queue* q)
{
	int len = 0;
	list* lst;
	if (isEmpty(q) == 1) {
		printf("������� �����!\n");
		return -1;
	}
	for (lst = q->front; lst != nullptr; lst = lst->next)
		len += lst->strvar.length();
	return len;
}

string remove(queue* q)
{
	struct list* temp;
	string strvar;
	if (isEmpty(q) == 1) {
		printf("������� �����!\n");
		return 0;
	}
	strvar = q->front->strvar;
	temp = q->front;
	q->front = q->front->next;
	free(temp);
	return strvar;
}

void show(queue* q)
{
	list* h;
	if (isEmpty(q) == 1) {
		printf("������� �����!\n");
		return;
	}
	for (h = q->front; h != nullptr; h = h->next)
		printf("%s ", h->strvar.c_str());
	return;
}


void enequeue(queue* q)
{
	q->front = nullptr;
	q->tail = nullptr;
}

int isEmpty(queue* q)
{
	if (q->front == nullptr)
		return 1;
	return 0;
}

void insert(queue* q, string strvar)
{
	if ((q->tail == nullptr) && (q->front == nullptr))
	{
		q->tail = push_back(strvar);
		q->front = q->tail;
	}
	else
	{

		q->tail = addelem(q->tail, strvar);
	}
}

list* addelem(list* lst, string strvar)
{
	list* temp, * p;
	temp = new list;
	p = lst->next; // ���������� ��������� �� ��������� ����
	lst->next = temp; // ���������� ���� ��������� �� �����������
	temp->strvar = strvar; // ���������� ���� ������ ������������ ����
	temp->next = p; // ��������� ���� ��������� �� ��������� �������
	return(temp);
}

list* push_back(string strvar)
{
	list* lst;
	// ��������� ������ ��� ������ ������
	lst = new list;
	lst->strvar = strvar;
	lst->next = nullptr; // ��� ��������� ���� ������
	return lst;
}

