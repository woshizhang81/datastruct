#ifndef SBG_TREE_TRAVERSE_HPP
#define SBG_TREE_TRAVERSE_HPP
#include <stdio.h>
#include <functional>
#include "sbg_queue_list.hpp"
#include "sbg_stack_list.hpp"
#include <unordered_map>
typedef enum{
    PRE_TRAVERSE,
    MID_TRAVERSE,
    BACK_TRAVERSE,
    BROADCAST_TRAVERSE
} TRAVERSE_TYPE;


template<typename T>
struct TNode{
    T value;
    TNode<T> * _left;
    TNode<T> * _right;
};

template<typename T>
class sbg_tree_traverse
{
public:
    sbg_tree_traverse()
    {
        _root = nullptr;
    }
    void set_callback(std::function<void(TRAVERSE_TYPE , T) >  cb)
    {
         _callback = cb;
    }
    void insert(T value ) //创建一个
    {
        pri_insert(_root,value);
    }

private:
    int get_height(TNode<T>* node)
    {
        if (!node)
        {
            return 0;
        }else {
            int lh = get_height(node->_left);
            int rh = get_height(node->_right);
            return lh > rh ? lh :rh + 1;
        }
    }

    int get_height_circle(TNode<T>* node)
    {
        if (!node)
        {
            return 0;
        }else {
            int lh = get_height(node->_left);
            int rh = get_height(node->_right);
            return lh > rh ? lh :rh + 1;
        }
    }

public:
    int height()
    {
        return get_height(_root);
    }

// 循环方式先序列遍历
    void for_pre_trav()
    {
        sbg_stack_list<TNode<T>*>  stack;
        stack.push(this->_root);
        while(!stack.is_empty()){
            TNode<T>* t;
            stack.pop(t);
            _callback(TRAVERSE_TYPE::PRE_TRAVERSE,t->value);
            if (t->_right)
                stack.push(t->_right);
            if (t->_left)
                stack.push(t->_left);
        }
    }
    void for_pre_trav_2()
    {
        sbg_stack_list<TNode<T>*>  stack;
        TNode<T>* cur = _root;
        //先把左节点全部压栈
        while(cur || !stack.is_empty())
        {
            if (cur)
            {
                _callback(TRAVERSE_TYPE::PRE_TRAVERSE,cur->value);
                stack.push(cur);
                cur = cur->_left;
            }else {
                stack.pop(cur);
                cur = cur->_right;
            }
        }
    }

    void for_mid_trav2()
    {
        sbg_stack_list<TNode<T>*>  stack;
        TNode<T>* cur = _root;
        //先把左节点全部压栈
        while(cur || !stack.is_empty())
        {
            if (cur)
            {
                stack.push(cur);
                cur = cur->_left;
            }else {
                stack.pop(cur);
                _callback(TRAVERSE_TYPE::PRE_TRAVERSE,cur->value);
                cur = cur->_right;
            }
        }
    }

    void for_mid_trav()
    {
        sbg_stack_list<TNode<T>*>  stack;
        TNode<T>* cur = _root;
        //先把左节点全部压栈
        while(cur)
        {
            stack.push(cur);
            cur = cur->_left;
        }
        //出战时判断右节点
        while(!stack.is_empty())
        {
            TNode<T>* t;
            stack.pop(t);
            _callback(TRAVERSE_TYPE::PRE_TRAVERSE,t->value);
            TNode<T> *r = t->_right;
            while(r)
            {
                stack.push(r);
                r = r->_left;
            }
        }
    }

    void for_back_trav()
    {
        std::unordered_map<TNode<T>*, bool> tmap;
        sbg_stack_list<TNode<T>*>  stack;
        TNode<T>* cur = _root;
        //先把左节点全部压栈
        while(cur || !stack.is_empty())
        {
            if (cur)
            {
                stack.push(cur);
                tmap.insert(std::pair<TNode<T>*, bool>(cur,false));
                cur = cur->_left;
            }else {
                //不出栈，但需要找到栈顶的右 先压一次
                cur = stack.top();
                if (!tmap[cur])
                {
                    tmap[cur] = true;  //修改状态，后直接出栈
                    cur = cur->_right;
                }else
                {
                     stack.pop(cur);
                     _callback(TRAVERSE_TYPE::BACK_TRAVERSE,cur->value);
                     cur = nullptr;
                }
            }
        }
    }

/***********************************************/
    void trav_totol()
    {
        traverse_totol(this->_root);
    }

    void pre_trav()
    {
        pre_traverse(this->_root);
    }

    void mid_trav()
    {
        mid_traverse(this->_root);
    }

    void back_trav()
    {
        back_traverse(this->_root);
    }

    //广度遍历 借助队列
    void broadcast_trav()
    {
        sbg_queue_list<TNode<T> *> queue;
        queue.enqueue(this->_root);
        while(!queue.is_empty())
        {
           TNode<T> * node =  queue.dequeue();
           _callback(BROADCAST_TRAVERSE,node->value);
           if (node->_left)
                queue.enqueue(node->_left);
           if (node->_right)
                queue.enqueue(node->_right);
        }
    }

private:
    void pri_insert(TNode<T> * &rnode ,T value ) //创建一个
    {
        TNode<T> * node = new TNode<T>;
        node->value = value;
        node->_left = node->_right = nullptr;
        if(rnode == nullptr)
        {
            rnode = node;
            return ;
        }
        if(node->value < rnode->value)
        {
            pri_insert(rnode->_left  , value);//第归到最后将new插入到左结点，第归到最后返回new
        }
        else
        {
            pri_insert(rnode->_right , value);
        }
    }

    void traverse_totol(TNode<T> * node)
    {
        if (!node)
        {
            return ;
        }
        _callback(TRAVERSE_TYPE::PRE_TRAVERSE,node->value);
        traverse_totol (node->_left);
        _callback(TRAVERSE_TYPE::MID_TRAVERSE,node->value);
        traverse_totol (node->_right);
        _callback(TRAVERSE_TYPE::BACK_TRAVERSE,node->value);
    }
    void pre_traverse(TNode<T> * node)
    {
        if (!node)
        {
            return ;
        }
        _callback(TRAVERSE_TYPE::PRE_TRAVERSE,node->value);
        pre_traverse (node->_left);
        pre_traverse (node->_right);
    }
    void mid_traverse(TNode<T> * node)
    {
        if (!node)
        {
            return ;
        }
        mid_traverse (node->_left);
        _callback(TRAVERSE_TYPE::MID_TRAVERSE,node->value);
        mid_traverse (node->_right);
    }
    void back_traverse(TNode<T> * node)
    {
        if (!node)
        {
            return ;
        }
        back_traverse (node->_left);
        back_traverse (node->_right);
        _callback(TRAVERSE_TYPE::BACK_TRAVERSE,node->value);
    }
private:
    std::function<void(TRAVERSE_TYPE , T)> _callback;
    TNode<T> * _root;
};

#endif // SBG_TREE_TRAVERSE_H
