#ifndef SBG_LIST_H
#define SBG_LIST_H
#include <stdio.h>
/*
    实现头插法的单向连表
*/
template <typename T>
struct _Node
{
    typedef _Node<T>*  NodePrt;
    T    val;
    _Node<T> * next;
} ;

template<typename T>
class sbg_list
{
public:
    sbg_list():_head(nullptr)
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
        _head->next = nullptr;
        while(newList != nullptr)
        {
            _Node<T>* next = newList->next;
            newList->next = _head->next;
            _head->next = newList;
            newList = next;
        }
    }

    _Node<T>* find(T val)
    {
        _Node<T> *p = _head->next;
        while(p)
        {
            if (p->val == val)
            {
                return p;
            }
            p = p->next;
        }
        return nullptr;
    }

    void delete_node(_Node<T> * dnode)
    {
        _Node<T> * cur = _head;
        while (cur)
        {
            if (cur->next == dnode)
            {
                cur->next = dnode->next;
                delete dnode;
            }
            cur = cur->next;
        }
    }
    /*交换数据 排序 冒泡思想*/
    void sort_changevalue()
    {
        _Node<T> * cl,*cr;
        int listLen = length();
        for (int i = 0; i <listLen -1 ;i++) {
            cl = _head->next;
            cr = cl->next;
            for (int j = 0; j < listLen -i -1;j++) {
                if (cl->val > cr->val)
                {
                    cl->val = cl->val ^ cr->val;
                    cr->val = cl->val ^ cr->val;
                    cl->val = cl->val ^ cr->val;
                }
                cl = cl->next;
                cr = cr->next;
            }
        }
    }

    /*交换节点 排序 冒泡思想
    todo: 需要继续加深理解
    */
    void sort_changenode()
    {
       _Node<T> *pre,*cl,*cr;
       int listLen = length();
       for (int i = 0; i < listLen -1; i++) {
           pre = _head;
           cl = _head->next;
           cr = cl->next;
           for (int j = 0 ;j < listLen -i -1; j++) {
               if (cl->val > cr->val)
               {
                   pre->next = cr;
                   cl->next = cr->next;
                   cr->next = cl;

                   pre = cr;
                   cr = cl->next;
                   continue;
               }
               pre = pre->next;
               cl = cl->next;
               cr = cr->next;
           }
       }
    }

    void push(T val){
        _Node<T>* newVal = new _Node<T>;
        newVal->val = val;
        newVal->next = _head->next;
        _head->next = newVal;
    }

    void pop()
    {
       _Node<T> * node = _head->next;
       _head->next = node->next;
       delete node;
    }

private:
    _Node<T> * _head;
};

#endif // SBG_LIST_H
