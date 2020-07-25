#ifndef SBG_LIST_TAIL_H
#define SBG_LIST_TAIL_H

#include <stdio.h>
/*
    实现基本的头插法和尾插入法，长度，反转功能 的单向连表
*/
namespace sbg_tail {
template <typename T>
struct _Node
{
    T    val;
    _Node * next;
} ;

template<typename T>
class sbg_list
{
public:
    sbg_list():_head(nullptr),_tail(nullptr)
    {
        _head = new _Node<T>;
        _head->next = nullptr;
    }
    ~sbg_list()
    {
        _Node<T> * index = _head;
        while(index != nullptr)
        {
            _Node<T>* next = index->next;
            delete index;
            index = next;
        }
    }
    int length()
    {
        _Node<T> *cur = _head;
        int len = 0;
        while (cur->next)
        {
            len ++;
            cur = cur->next;
        }
        return len;
    }
    void show_list()
    {
        _Node<T> * cur = _head->next;
        while(cur != nullptr)
        {
            printf("%d ",cur->val);
            cur = cur->next;
        }
         printf("\n");
    }
    void reverse()
    {
        _Node<T> * newList = _head->next;
        _tail = _head->next;
        _head->next = nullptr;
        while(newList != nullptr)
        {
            _Node<T>* next = newList->next;
            newList->next = _head->next;
            _head->next = newList;
            newList = next;
        }
    }

    void push(T val){
        _Node<T>* newVal = new _Node<T>;
        newVal->val = val;
        newVal->next = _head->next;
        _head->next = newVal;
        if (_tail == nullptr)
        {
            _tail = newVal;
        }
    }

    void push_back(T val){
         _Node<T>* newVal = new _Node<T>;
         newVal->val = val;
         newVal->next = nullptr;

        if (_tail == nullptr)
        {
            _tail = newVal;
        }else{
            _tail->next = newVal;
            _tail = newVal;
        }
        if (_head->next == nullptr)
        {
            _head->next = newVal;
        }
    }

    void pop()
    {
       _Node<T> * node = _head->next;
       _head->next = node->next;
       delete node;
    }

private:
    _Node<T> * _head;
    _Node<T> * _tail;
};
}

#endif // SBG_LIST_H
