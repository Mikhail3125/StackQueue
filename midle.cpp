#include "Stdafx.h"
#include "midle.h"
using namespace std;

/*
Создать очередь строковых значений, для реализации используя односвязные списки. Реализовать операции
добавления (enqueue) и удаления (dequeue) элемента из очереди. Добавьте в очередь строки «one»,
«two», «three», «four» и распечатайте содержимое очереди. Удалите 1 элемент из очереди, затем 
добавьте в очередь строку «five» и распечатайте очередь еще раз. * Найдите суммарную длину строк,
принадлежащих очереди
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
	cout << "\nСодержимое очереди до внесенных изминений: \n";
	show(q);
	cout << "\nСодержимое очереди после внесенных изминений: \n";
	remove(q);
	insert(q, "five");
	show(q);
	cout << "\nСуммарная длина строк,принадлежащих очереди: ";  int len = length(q); cout << len << endl;
	cout << "\nНажмите Enter для завершения...";
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
		printf("Очередь пуста!\n");
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
		printf("Очередь пуста!\n");
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
		printf("Очередь пуста!\n");
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
	p = lst->next; // сохранение указателя на следующий узел
	lst->next = temp; // предыдущий узел указывает на создаваемый
	temp->strvar = strvar; // сохранение поля данных добавляемого узла
	temp->next = p; // созданный узел указывает на следующий элемент
	return(temp);
}

list* push_back(string strvar)
{
	list* lst;
	// выделение памяти под корень списка
	lst = new list;
	lst->strvar = strvar;
	lst->next = nullptr; // это последний узел списка
	return lst;
}

