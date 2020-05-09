#pragma once
struct list;
struct queue;
void enq(queue* q);
int  IsEmpty(queue* q);
void push(queue* q, double digit);
list* addnode(list* lst, double digit);
list* push_list(double strvar);
void Show(queue* q);
int pop(queue* q);
void FillQueue(queue* q, int count);
void move(queue* q1, queue* q2, int N);//ф-ия пер-ия элементов 1-ой очереди
void clear(queue* q, int count_del);


void hard();