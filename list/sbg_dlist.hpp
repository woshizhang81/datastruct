#ifndef SBG_LIST_DOUBLE_H
#define SBG_LIST_DOUBLE_H
#include <stdio.h>
// 实现双向循环列表
template <typename T>
struct _DNode
{
 //   typedef _DNode<T>*  NodePrt;
    T    val;
    _DNode<T> * next;
    _DNode<T> * pre;
} ;

template<typename T>
class sbg_dlist
{
public:
    sbg_dlist():_head(nullptr)
    {
        _head = new _DNode<T>;
        //都指向自己
        _head->pre = _head->next = _head;
    }
    ~sbg_dlist()
    {
        //最后一个节点next 置为null 转化为单链表
        _head->pre->next = nullptr;
        _DNode<T> * cur = _head;
        while (cur){
            auto nxt = cur->next;
            delete cur;
            cur = nxt;
        }
    }
    //头插法
    void insert_node(const T v)
    {
        _DNode<T> * cur = new _DNode<T>;
        cur->val = v ;
        cur->next = _head->next;
        cur->pre = _head;
        _head->next->pre = cur;
        _head->next = cur;
    }
    //尾插法
    void push_back(const T v)
    {
        _DNode<T> * cur = new _DNode<T>;
        _DNode<T> * tail = _head->pre;
        cur->val = v ;
        cur->next = tail->next;
        cur->pre = tail;
        tail->next->pre = cur;
        tail->next = cur;
    }
    int length()
    {
        _DNode<T> * cur = _head->next;
        int len = 0;
        while(_head != cur)
        {
            len  ++;
            cur = cur->next;
        }
        return len;
    }

    void delete_dnode(_DNode<T> * val)
    {
        _DNode<T> *pre = val->pre;
        _DNode<T> *next = val->next;

        pre->next = next;
        next->pre = pre;
        delete val;
    }

    bool is_empty()
    {
       return (_head->next == _head->next && _head->next == _head)? true:false;
    }

    bool front(T & val)
    {
        if (!is_empty())
        {
            _DNode<T> *first = _head->next;
            val = first->val;
            return true;
        }
        return false;
    }

    bool back(T & val)
    {
        if (!is_empty())
        {
            _DNode<T> *tail = _head->pre;
            val = tail->val;
            return true;
        }
        return false;
    }

    void pop_front()
    {
        _DNode<T> *first = _head->next;
        first->pre->next = first->next;
        first->next->pre = first->pre;
        delete first;
    }

    void pop_back ()
    {
        _DNode<T> *tail = _head->pre;
        tail->pre->next = tail->next;
        tail->next->pre = tail->pre;
        delete tail;
    }

    //双向寻找法
    _DNode<T>*  find_dnode(T v)
    {
        _DNode<T> * l, *r, *bfind;
        l = _head->next;
        r = _head->pre;
        while (1){
            if (l->val == v)
            {
                bfind = l;
                break;
            }
            if (r->val == v)
            {
                bfind = r;
                break;
            }
            if (l->pre == r && r->next == l) //交错了
            {
                break;
            }
            l = l->next;
            r = r->pre;
        }
        return bfind;
    }


    void sort_dlist()
    {
        int len = length();
        for (int i=0 ;i < len - 1 ;i ++) {
            _DNode<T> *p = _head->next;
            _DNode<T> *q = p->next;
            for (int j = 0 ;j <len -i -1;j++) {
                if (p->val > q->val)
                {
                    //先拿出p
                    p->pre->next = p->next;
                    p->next->pre = p->pre;
                    //再把p 放到q后面
                    p->next = q->next;
                    p->pre  = q;
                    q->next->pre = p;
                    q->next = p;

                    q = p->next;
                    continue;
                }
                p = p->next;
                q = p->next;
            }
        }
    }

    void print_list()
    {
        _DNode<T> * cur = _head->next;
        while (_head != cur)
        {
            printf("%d ",cur->val);
            cur = cur->next;
        }
        printf("\n");
    }

private:
    _DNode<T> * _head;

};


#endif // SBG_LIST_H
