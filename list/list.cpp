#ifndef _LIST_CPP_
#define _LIST_CPP_

#include "list.hpp"

template<typename T>
mine::List<T>::List()
    : head {nullptr}, tail {nullptr}, size {0}
{
}

template<typename T>
mine::Node<T>::Node(const T &x)
    : value {x}, next {nullptr}, prev {nullptr}
{
}

template<typename T>
mine::List<T>::List(const List<T> &rhs)
    : head {nullptr}, tail {nullptr}, size {rhs.size}
{
    for (Node<T>* cur = rhs.head; cur != nullptr; cur = cur->next)
    {
        push_back(cur->value);
    }
}

template<typename T>
mine::List<T>::~List()
{
    Node<T> *temp = head;
    while (temp != nullptr)
    {
        Node<T> *cur = temp->next;
        delete temp;
        temp = cur;
    } 
}

template<typename T>
void mine::List<T>::push_back(const T &x)
{
    Node<T>* newNode = new Node<T> (x);
    if(head == nullptr)
    {
        head = tail = newNode;
        newNode->next = nullptr;
        newNode->prev = nullptr;
    }
    else
    {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

template<typename T>
void mine::List<T>::push_front(const T &x)
{
    Node<T>* newNode = new Node<T>(x);
    if(head == nullptr)
    {
        head = tail = newNode;
        newNode->next = nullptr;
        newNode->prev = nullptr;
    }
    else
    {
        newNode->prev = nullptr;
        newNode->next = head;
        head = newNode;
    }
}

template <typename T>
void mine::List<T>::pop_back()
{
    if(head == nullptr)
    {
        return;
    }
    else
    {
        Node<T> * temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
    }
}

template <typename T>
void mine::List<T>::pop_front()
{
    if(head == nullptr)
    {
        return;
    }
    else
    {
        Node<T> *temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;
    }    
}

template <typename T>
T& mine::List<T>::back() const
{
    return tail->value;
}

template <typename T>
T& mine::List<T>::front() const
{
    return head->value;
}

template <typename T>
typename mine::List<T>::iterator mine::List<T>::begin()
{
    return iterator(head);
}

template <typename T>
typename mine::List<T>::iterator mine::List<T>::end()
{
    return iterator();
}

template<class T>
mine::List<T> &mine::List<T>::operator=(const mine::List<T> &rhs)
{
    if(this == &rhs)
    {
        return *this;
    }
    Node<T> *temp = head;
    while (temp != nullptr)
    {
        Node<T> *cur = temp->next;
        delete temp;
        temp = cur;
    }
    for (Node<T>* cur = rhs.head; cur != nullptr; cur = cur->next)
    {
        push_back(cur->value);
    } 
}

template<class T>
T &mine::List_iterator<T>::operator*()
{
    return cur_node->value;
}

template<class T>
mine::List_iterator<T>& mine::List_iterator<T>::operator=(const mine::List_iterator<T> &rhs)
{
    return List_iterator(rhs.cur_node);
}

template<class T> 
bool mine::List_iterator<T>::operator==(const mine::List_iterator<T> &rhs)
{
    return (this->cur_node == rhs.cur_node);
}

template<class T> 
bool mine::List_iterator<T>::operator!=(const mine::List_iterator<T> &rhs)
{
    return (this->cur_node != rhs.cur_node);
}

template<class T>
mine::List_iterator<T> &mine::List_iterator<T>::operator++()
{
    cur_node = cur_node->next;
    return *this;
}

template<class T>
mine::List_iterator<T> &mine::List_iterator<T>::operator--()
{
    cur_node = cur_node->prev;
    return *this;
}

#endif
