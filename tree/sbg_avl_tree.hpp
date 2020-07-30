#ifndef SBG_AVL_TREE_H
#define SBG_AVL_TREE_H
#include <assert.h>
#include <functional>
#include <stdio.h>
#include <queue>
typedef enum{RECURSION,NONE_RECURSION} VER_MODE;  //递归版本和非递归版本和
template<typename T>
struct AVLNode{
    AVLNode() {
        _height  = 0    ;
        _balance = 0    ;
        _parent  = nullptr;
        _left    = nullptr;
        _right   = nullptr;
    }
    T _value;
    int _height;
    int _balance;
    AVLNode<T>* _parent;
    AVLNode<T>* _left;
    AVLNode<T>* _right;
};
template<typename T>
class sbg_avl_tree
{
public:
   // typedef enum{RECURSION,NORMAL} VER_TYPE;
    typedef std::function<void (void * , T val)> cb_fun;
    typedef void * cb_handle;
    sbg_avl_tree(cb_fun cbfun = sbg_avl_tree<T>::show ,
             cb_handle handle = nullptr,
             VER_MODE type = VER_MODE::RECURSION); //默认递归版本
    ~sbg_avl_tree();
    void insert(T v);
    void pre_traverse();
    void mid_traverse();
    void post_traverse();
    void traverse_layer();
    AVLNode<T> * get_parent(AVLNode<T> * child);
    AVLNode<T> * get_min_node();
    AVLNode<T> * get_max_node();
    AVLNode<T> * find(T v);
    void del_node(AVLNode<T> * v);
    void del_value(T v);
    void destrory();


private:
    AVLNode<T> *    get_min_node_c(AVLNode<T> * root);
    AVLNode<T> *    get_max_node_c(AVLNode<T> * root);
    void destrory_c(AVLNode<T> * troot);
    AVLNode<T> * find_c(AVLNode<T> * troot ,T v);
    AVLNode<T> * find_n(AVLNode<T> * troot ,T v);
    void del_node_c(AVLNode<T> * troot ,AVLNode<T> * v);
    void del_value_c(AVLNode<T> * troot  ,T v);
    void insert_c(AVLNode<T> * troot ,AVLNode<T> * newnode);
    void pre_traverse_c(AVLNode<T>* troot);
    void mid_traverse_c(AVLNode<T>* troot);
    void post_traverse_c(AVLNode<T>* troot);
private:
    VER_MODE _mode;
    AVLNode<T> * _root;
    cb_fun _traverse_callback;
    cb_handle _cb_handle;
    static void show (void * handle, T v);
};

template<typename T>
void sbg_avl_tree<T>::show(void * handle ,T val)
{
    printf("%d ",val);
}

template<typename T>
sbg_avl_tree<T>::sbg_avl_tree(cb_fun cfun,cb_handle handle,VER_MODE mode )
    :_root(nullptr),
      _traverse_callback(cfun),
      _cb_handle(handle),
      _mode(mode)
{
    if (nullptr == _cb_handle)
    {
        _cb_handle = this;
    }
}

template<typename T>
sbg_avl_tree<T>::~sbg_avl_tree()
{
    destrory();
}

template<typename T>
void sbg_avl_tree<T>::pre_traverse_c(AVLNode<T>* troot)
{
    if (!troot)
        return;
    _traverse_callback(_cb_handle,  troot->_value);
    pre_traverse_c(troot->_left);
    pre_traverse_c(troot->_right);
}
template<typename T>
void sbg_avl_tree<T>::mid_traverse_c(AVLNode<T>* troot)
{
    if (!troot)
        return;
    mid_traverse_c(troot->_left);
    _traverse_callback(_cb_handle , troot->_value);
    mid_traverse_c(troot->_right);
}

template<typename T>
void sbg_avl_tree<T>::post_traverse_c(AVLNode<T>* troot)
{
    if (!troot)
        return;
    post_traverse_c(troot->_left);
    post_traverse_c(troot->_right);
    _traverse_callback(_cb_handle , troot->_value);
}

template<typename T>
void sbg_avl_tree<T>::insert_c(AVLNode<T> * node, AVLNode<T> * new_node)
{
    if (nullptr == node)
    {
        return;
    }
    if (new_node->_value <= node->_value)
    {
        if (node->_left == nullptr)
        {
            node->_left = new_node;
        }else {
            insert_c(node->_left,new_node);
        }
    }else {
        if (node->_right == nullptr)
        {
            node->_right = new_node;
        }else {
            insert_c(node->_right,new_node);
        }
    }
}

template<typename T>
void sbg_avl_tree<T>::pre_traverse()
{
    if (_mode == VER_MODE::RECURSION)
        pre_traverse_c(_root);
    else
        return ;
}

template<typename T>
void sbg_avl_tree<T>::mid_traverse()
{
    if (_mode == VER_MODE::RECURSION)
        mid_traverse_c(_root);
    else
        return ;
}

template<typename T>
void sbg_avl_tree<T>::post_traverse()
{
    if (_mode == VER_MODE::RECURSION)
        post_traverse_c(_root);
    else
        return ;
}

template<typename T>
void sbg_avl_tree<T>::traverse_layer()
{
    std::queue<AVLNode<T>* > qu;
    qu.push(_root);
    while (!qu.empty())
    {
        AVLNode<T>* cur = qu.front();
        qu.pop();
        this->_traverse_callback(_cb_handle, cur->_value);

        if (cur->_left)
                qu.push(cur->_left);
        if (cur->_right)
                qu.push(cur->_right);
    }
}

template<typename T>
void sbg_avl_tree<T>::insert(T v)
{
    AVLNode<T> * new_node = new AVLNode<T> ;
    new_node->_value = v;
    new_node->_left = new_node->_right = nullptr;
    if (!_root)
    {
        _root = new_node;
    }else {
        insert_c(_root,new_node);
    }
}

template<typename T>
AVLNode<T> * sbg_avl_tree<T>::find_c(AVLNode<T> * pnode ,T v)
{
    if (!pnode)
        return nullptr;

    if (pnode->_value == v)
    {
        return pnode;
    }else if(pnode->_value > v)
    {
        return find_c(pnode->_left  ,v);
    }else {
        return find_c(pnode->_right ,v);
    }
}

template<typename T>
AVLNode<T> * sbg_avl_tree<T>::find_n(AVLNode<T> * pnode ,T v)
{
    while(pnode)
    {
        if (pnode->_value == v)
        {
            return pnode;
        }else if(pnode->_value > v)
        {
            pnode = pnode->_left;
        }else {
            pnode = pnode->_right;
        }
    }
    return nullptr;
}


template<typename T>
void sbg_avl_tree<T>::del_node_c(AVLNode<T> * proot , AVLNode<T> * pdel)
{


}

template<typename T>
void sbg_avl_tree<T>::del_value_c(AVLNode<T> * pnode , T v)
{

}

template<typename T>
AVLNode<T> * sbg_avl_tree<T>::get_parent(AVLNode<T> * child)
{
    std::queue<AVLNode<T>*> qu;
    qu.push(_root);
    while (!qu.empty())
    {
        AVLNode<T>* p = qu.front();
        qu.pop();
        if (p->_left == child || p->_right == child)
        {
            return p;
        }
        if (p->_left)
            qu.push(p->_left);
        if (p->_right)
            qu.push(p->_right);
    }
    return nullptr;
}

template<typename T>
AVLNode<T> * sbg_avl_tree<T>::get_min_node()
{
    AVLNode<T> * cur = _root;
    while(cur->_left)
    {
        cur = cur->_left;
    }
    return cur;
}

template<typename T>
AVLNode<T> * sbg_avl_tree<T>::get_max_node()
{
    AVLNode<T> * cur = _root;
    while(cur->_right)
    {
        cur = cur->_right;
    }
    return cur;
}
template<typename T>
AVLNode<T> * sbg_avl_tree<T>::get_min_node_c(AVLNode<T> * root)
{
    AVLNode<T> * cur = root;
    while(cur->_left)
    {
        cur = cur->_left;
    }
    return cur;
}

template<typename T>
AVLNode<T> * sbg_avl_tree<T>::get_max_node_c(AVLNode<T> * root)
{
    AVLNode<T> * cur = root;
    while(cur->_right)
    {
        cur = cur->_right;
    }
    return cur;
}

template<typename T>
AVLNode<T> * sbg_avl_tree<T>::find(T v)
{
    if (_mode == VER_MODE::RECURSION)
        return find_c(_root,v);
    else
        return find_n(_root,v);
}

template<typename T>
void sbg_avl_tree<T>::del_node(AVLNode<T> * pdel)
{
    /*
    if (_mode == VER_MODE::RECURSION)
        del_node_c(_root,pnode);
    */
    assert(pdel);
    AVLNode<T> * proot = _root;
    AVLNode<T> * parent = get_parent(pdel);
    assert(parent || pdel == _root);
    if (nullptr == pdel->_left && nullptr == pdel->_right)
    {
        if (pdel == _root)
        {
            delete _root;
            _root = nullptr;
        }else {
            if (parent->_left == pdel)
            {
                parent->_left = nullptr;
            }else {
                parent->_right = nullptr;
            }
            delete pdel;
        }
    }else if ( nullptr != pdel->_left && nullptr == pdel->_right) {
        if (pdel == _root)
        {
            AVLNode<T> * t = pdel;
            _root = pdel->_left;
            delete t;
        } else {
            if (parent->_left == pdel)
            {
                parent->_left  = pdel->_left;
            }else {
                parent->_right = pdel->_left;
            }
            delete pdel;
        }
    }else if ( nullptr == pdel->_left && nullptr != pdel->_right) {
        if (pdel == _root)
        {
            AVLNode<T> * t = pdel;
            _root = pdel->_right;
            delete t;
        }else {
            if (parent->_left == pdel)
            {
                parent->_left  = pdel->_right;
            }else {
                parent->_right = pdel->_right;
            }
            delete pdel;
        }
    } else {
        AVLNode<T> * min_right = get_min_node_c(pdel->_right);
        pdel->_value = min_right->_value;
        if (pdel->_right == min_right) //又子数连续
        {
            pdel->_right = min_right->_right;
        }else {
            AVLNode<T> * pnt = get_parent(min_right);
            //此时min_right 必然没有左子数，
            pnt->_left = min_right->_right;
        }
        delete min_right;
    }

}

template<typename T>
void sbg_avl_tree<T>::del_value(T v)
{
    if (_mode == VER_MODE::RECURSION)
        del_value_c(_root,v);
}

template<typename T>
void sbg_avl_tree<T>::destrory()
{
    destrory_c(_root);
    _root = nullptr;
}

template<typename T>
void sbg_avl_tree<T>::destrory_c(AVLNode<T> * troot)
{
    if (!troot)
        return ;
    destrory_c(troot->_left);
    destrory_c(troot->_right);
    delete troot;
}





#endif // sbg_avl_tree_H

