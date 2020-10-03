#include "LinkedList.h"

using namespace std;

template <typename T>
LinkedList<T>::LinkedList(){
    head = nullptr;
    tail = nullptr;
    length = 0;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &list){
    Node<T>* temp;
    head = nullptr;
    tail = nullptr;
    length = 0;
    for(Node<T>* i = list.head; i != nullptr; i = i->next){
        Node<T>* node = new Node<T>(i->data);
        if(length == 0){
            head = node;
            head->prev = nullptr;
            temp = head;
        }else{
            node->prev = temp;
            temp->next = node;
            temp = node;
            tail = node;
        }
        length++;
    }
}

template <typename T>
LinkedList<T>::~LinkedList(){
    Node<T>* node = head;
    while(node != nullptr){
        Node<T>* temp = node;
        node = node->next;
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
}

template <typename T>
void LinkedList<T>::insert(T data, int index){
    if(index > length || index < 0){throw ("Index out of bounds");}

    if(index == 0){
        this->prepend(data);
        return;
    }else if(index == length){
        this->postpend(data);
        return;
    }
    Node<T>* dataNode = new Node<T>(data);
    Node<T>* temp = head;

    for(int i = 0; i < index; i++){
        temp = temp->next;
    }

    temp->prev->next = dataNode;
    temp->prev = dataNode;

    length++;
}

template <typename T>
void LinkedList<T>::prepend(T data){
    Node<T>* temp = new Node<T>(data);

    if(length == 0){
        head = temp;
        tail = temp;
    }else{
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    length++;
}

template <typename T>
void LinkedList<T>::append(T data){
    Node<T>* temp = new Node<T>(data);

    if(length == 0){
        head = temp;
        tail = temp;
    }else{
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
    length++;
}

template <typename T>
void LinkedList<T>::remove(T data){
    if(length == 0){
        return;
    }


}

template <typename T>
T LinkedList<T>::pop(){
    if(length <= 0)
        throw ("List is empty");
    else if(length == 1){
        T temp = tail->data;
        delete tail;
        tail = nullptr;
        head = nullptr;
        length = 0;
        return temp;
    }else{
        T temp = tail->data;
        tail = tail->prev;
        delete tail->next;
        tail->next = nullptr;
        length -= 1;
        return temp;
    }
}

template <typename T>
T LinkedList<T>::prepop(){
    if(length <= 0)
        throw("Empty List");
    else if(length == 1){
        T temp = head->data;
        delete head;
        head = nullptr;
        tail = nullptr;
        length = 0;
        return temp;
    } else {
        T temp = head->data;
        head = head->next;
        delete head->prev;
        head->prev = nullptr;
        length -= 1;
        return temp;
    }
}

template <typename T>
int LinkedList<T>::getSize(){
    return length;
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& list){
    Node<T>* temp = new Node<T>;
    head = nullptr;
    tail = nullptr;
    length = 0;

    for(Node<T>* i = list.head; i != nullptr; i = i->next){
        Node<T>* newNodePointer = new Node<T>(i->data);

        if(length == 0){
            head = newNodePointer;
        }

        temp->next = newNodePointer;
        temp = temp->next;
        length++;
    }
    this->tail = temp;
    return *this;
}

template <typename T>
bool LinkedList<T>::operator==(const LinkedList<T>& list){
    if((this->getSize() != list.getSize())){
        return false;
    } else if(this->getSize() == 0 && list.getSize() == 0){
        return true;
    }
    Node<T>* temp1 = head;
    Node<T>* temp2 = list.head;

    while(temp1 != nullptr){
        if(temp1->data != temp2->data)
            return false;
    }
    return true;
}