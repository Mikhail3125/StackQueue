#pragma once
#include <string>
struct list;
struct queue;
void enequeue(queue* q);
int  isEmpty(queue* q);
void insert(queue* q, std::string strvar);
list* addelem(list* lst, std::string strvar);
list* push_back(std::string strvar);
void show(queue* q);
std::string remove(queue* q);
int length(queue* q);

void midle();