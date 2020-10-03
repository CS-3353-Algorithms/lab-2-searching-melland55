#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

template <typename T>
struct Node{
    T data;
    Node* next;
    Node* prev;
    Node(){ next = nullptr;prev = nullptr;}
    Node(T t){data = t; next = nullptr; prev = nullptr;}
    ~Node(){next = nullptr; prev = nullptr; delete next; delete prev;}
};




template <typename T>
class LinkedList
{
public:
    LinkedList();
    LinkedList(const LinkedList<T> &list);
    ~LinkedList();
    void insert(T, int);
    void prepend(T);
    void append(T);
    void remove(T);
    T pop();
    T prepop();
    int getSize();
	void display();
    LinkedList<T>& operator=(const LinkedList<T>&);
    bool operator==(const LinkedList<T>&);
	Node<T>* head;
    Node<T>* tail;
private:
    int length;
};

#endif