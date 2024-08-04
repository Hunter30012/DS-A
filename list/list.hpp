#ifndef _LIST_H_
#define _LIST_H_

#include <iostream>

namespace mine
{
    template <typename T> class List_iterator;
    template <typename T> class Node;
    template <typename T>
    class List
    {
        friend class List_iterator<T>;
        friend class Node<T>;
    protected:
        Node<T> *head;
        Node<T> *tail;
        unsigned int size;
    public:
        typedef List_iterator<T> iterator;

        List();
        ~List();
        List(const List<T> &rhs);
        void push_back(const T &x);
        void push_front(const T &x);
        void pop_back();
        void pop_front();
        T & back() const;
        T & front() const;
        iterator begin();
        iterator end();
        List<T> & operator=(const List<T> & rhs);
    };

    template <typename T> 
    class Node
    {
        friend class List_iterator<T>;
        friend class List<T>;
    private:
        T value;
        Node<T> * next;
        Node<T> * prev;
        Node(const T &x);
    };

    template <class T> class List_iterator
    {
    protected:
        Node<T> * cur_node;
        friend class List<T>;

    public:
        typedef List_iterator<T> iterator;

        List_iterator(Node<T> * source): cur_node{source} { }
        List_iterator(): cur_node{nullptr} { }
        List_iterator(List_iterator<T> * source_iterator): cur_node{source_iterator.cur_node} { }

        T & operator*();  // dereferencing operator
        iterator & operator=(const iterator & rhs);
        bool operator==(const iterator & rhs);
        bool operator!=(const iterator & rhs);
        iterator & operator++(); 
        iterator & operator--();  
    };
    
}

#include "list.cpp"
#endif