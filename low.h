#pragma once


void low();

struct list;
struct queue;
void init(queue* q);
int  isempty(queue* q);
void insert(queue* q, double digit);
list* addelem(list* lst, double digit);
list* push_back(double strvar);
void print(queue* q);
double remove(queue* q);
double min_elem(queue* q);
