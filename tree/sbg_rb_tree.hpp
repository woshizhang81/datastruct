#ifndef SBG_RB_TREE_H
#define SBG_RB_TREE_H
#include <assert.h>
#include <functional>
#include <stdio.h>
#include <queue>
#include <iomanip>
#include <iostream>
using namespace std;

typedef enum{COLOR_RED,COLOR_BLACK} NODE_COLOR;

template<typename T>
struct RBNode{
    RBNode() {
        _color  = NODE_COLOR::COLOR_RED  ; //全部初始化为红树
        _parent  = nullptr;
        _left    = nullptr;
        _right   = nullptr;
    }
    RBNode(T v) {
        _value = v;
        _color  = NODE_COLOR::COLOR_RED  ; //全部初始化为红树
        _parent  = nullptr;
        _left    = nullptr;
        _right   = nullptr;
    }
    T _value;
    NODE_COLOR _color;
    RBNode<T>* _parent;
    RBNode<T>* _left;
    RBNode<T>* _right;
};

template<typename T>
class sbg_rb_tree
{
public:
    sbg_rb_tree():_root(nullptr){
      //  _root = new RBNode<T>(v);
    } //默认递归版本
    ~sbg_rb_tree() {}
    void insert(T data)
    {
        if (!_root)
        {
            _root = new RBNode<T>(data);
            _root->_color = NODE_COLOR::COLOR_BLACK;
        }else {
            RBNode<T> * insert_node = insert(_root,data);
            assert(insert_node);
            insert_fix_up( _root,insert_node);
            _root->_color = NODE_COLOR::COLOR_BLACK;
        }
    }

    void mid_traverse()
    {
        mid_traverse(_root);
    }

    void print()
    {
        if (_root != NULL)
            print(_root, _root->_value, 0);
    }

    RBNode<T>* search( T v) {
        return search(_root,v);
    }

    RBNode<T>* remove( T v) {
        RBNode<T>* finded = search (v) ;
        if (finded)
        {
            remove(_root,finded);
        }
    }

private:
    RBNode<T>* remove(RBNode<T>* &root, RBNode<T>* find)
    {
        if (find->_left == nullptr && find->_right == nullptr)
        {
            if (find->_parent == nullptr) { 
                root = nullptr;
            }else{ 
                if (rb_parent(find)->_left == find)
                    rb_parent(find)->_left = nullptr;
                else 
                    rb_parent(find)->_right = nullptr;
                //当前节点为叶子节点
            }
        } else if (find->_left != nullptr && find->_right == nullptr) {
            if (find->_parent == nullptr)
            {
                _root = find->_left;
            }else{
                if (rb_parent(find)->_left == find)
                    rb_parent(find)->_left  = find->_left;
                else
                    rb_parent(find)->_right = find->_left;
            }
        }else if (find->_left == nullptr && find->_right != nullptr) {
            if (find->_parent == nullptr)
            {
                _root = find->_right;
            }else{
                if (rb_parent(find)->_left == find)
                    rb_parent(find)->_left = find->_right; 
                else
                    rb_parent(find)->_right = find->_right;
            }
        }else{
            RBNode<T>* replace = find;
            replace = replace->_right;
            while(replace)
            {
                replace = replace->_left;
            }
            //找到最小节点 取代find 的value ，把replace当作要删除的节点
            find->_value = replace->_value;
            if (find->_right == replace)
            {
                find->_right = replace->_right;
            }else{
                //此时被删除节点没有左子树 最多只有又子树
                rb_parent(replace)->_left = replace->_right;
            }
            //用replace 代替 find
            find  = replace;
        }

        delete find;
    }

    RBNode<T>* remove_fix_up(RBNode<T>* &root, RBNode<T>* bdeleted,RBNode<T>* parent)
    {
        
    }

    RBNode<T>* search(RBNode<T>* node, T v)
    {
        if(node->_value == v || node == nullptr)
        {
            return node;
        }

        if (node->_value > v)
        {
           return search(node->_left);
        } else {
           return search(node->_right);
        }
    }

    void mid_traverse(RBNode<T>* node)
    {
        if (!node)
            return ;
        mid_traverse(node->_left);
        printf("(%d,%s) ",node->_value ,node->_color == COLOR_RED ? "red":"black");
        mid_traverse(node->_right);
    }
#define rb_parent(r)        ((r)->_parent)
#define rb_color(r)         ((r)->_color)
#define rb_is_red(r)        ((r)->_color == COLOR_RED)
#define rb_is_black(r)      ((r)->_color == COLOR_BLACK)
#define rb_set_black(r)     do { (r)->_color = COLOR_BLACK; } while (0)
#define rb_set_red(r)       do { (r)->_color = COLOR_RED; } while (0)
#define rb_set_parent(r,p)  do { (r)->_parent = (p); } while (0)
#define rb_set_color(r,c)   do { (r)->_color = (c); } while (0)
private:
    //插入修正函数，满足红黑树特性
    RBNode<T> * insert_fix_up(RBNode<T> * &root ,RBNode<T> *cur_node)
    {
        RBNode<T> * parent , *gparent ;
        parent = rb_parent(cur_node);
        while( parent  && rb_is_red(parent)) //父节点为red
        {
            gparent = rb_parent(parent);
            if (gparent->_left == parent) //在祖父亲的左节点
            {
                RBNode<T> * uncle = gparent->_right; //找到叔叔节点
                if (uncle && rb_is_red(uncle)) //叔叔节点也为red //没有叔叔就是null 也为黑
                {
                    rb_set_black(parent);
                    rb_set_black(uncle);
                    rb_set_red(gparent);
                    cur_node = gparent;
                }else { //叔叔为黑节点
                    if (cur_node == parent->_left) //外插
                    {
                        //父节点和爷爷节点颜色互换 /再右旋
                        rb_set_black(parent);
                        rb_set_red(gparent);
                        right_rotate(root,gparent);
                    }else {  //内插
                        //先按父亲左旋
                        RBNode<T> * temp = parent;
                        left_rotate(root,parent);
                        //左旋转后 调整父节点和当前节点。
                        parent = cur_node;
                        cur_node = temp;

                        rb_set_black(parent);
                        rb_set_red(gparent);
                        right_rotate(root,gparent);
                        //再按gparent 右旋转，并交换父亲和爷爷节点颜色
                    }
                }
            }else {
                RBNode<T> * uncle = gparent->_left;
                if (uncle && rb_is_red(uncle))
                {
                    rb_set_black(parent);
                    rb_set_black(uncle);
                    rb_set_red(gparent);
                    cur_node = gparent;
                }else {
                    //叔叔为黑
                    if (parent->_left == cur_node)//内插法
                    {
                        RBNode<T> * tmp = parent;
                        right_rotate(root,parent);

                        parent = cur_node;
                        cur_node = tmp;
                    }
                    //无论如何都要左旋转
                    rb_set_black(parent);
                    rb_set_red(gparent);
                    left_rotate(root , gparent);
                }
            }
        }
    }

    RBNode<T> * insert(RBNode<T> * root ,T v)
    {
        RBNode<T> *  new_node = nullptr;
        if (root->_value <= v) //红黑树允许节点重复
        {
            if (!root->_right)
            {
                new_node = new RBNode<T>(v);
                root->_right = new_node;
                new_node->_parent = root;
                return new_node;
            }
            else
            {
                return insert(root->_right,v);
            }
        } else {
            if (!root->_left)
            {
                new_node = new RBNode<T>(v);
                root->_left = new_node;
                new_node->_parent = root;
                return new_node;
            }
            else
            {
                return insert(root->_left,v);
            }
        }
    }

    //左旋转
    void left_rotate(RBNode<T> *  & proot  , RBNode<T> *  pnode) {

        RBNode<T> *x ,*y ,*px;
        x = pnode;
        y = x->_right;

        x->_right = y->_left;
        if (y->_left)
            y->_left->_parent = x;
    //    y->_left = x;
        y->_parent = x->_parent;
        if ( !x->_parent )
        {//根节点
            proot = y;
        }else {
            if (x->_parent->_left == x)
                x->_parent->_left = y;
            else
                x->_parent->_right = y;
        }
        y->_left = x;
        x->_parent = y;

    }

    //右旋转
    void right_rotate(RBNode<T> * & proot , RBNode<T> *  pnode){
        // 设置x是当前节点的左孩子。
        RBNode<T> *x ,*y ,*px;
        x = pnode;
        y = x->_left;

        x->_left = y->_right;
        if (y->_right)
            y->_right->_parent = x;

        y->_parent = x->_parent;
        if (!x->_parent)
        {
            proot = y;
        }else {
            if (x->_parent->_left == x)
                x->_parent->_left = y;
            else
                x->_parent->_right = y;
        }
        y->_right = x;
        x->_parent = y;
    }

    void print(RBNode<T>* tree, T key, int direction)
    {
        if(tree != NULL)
        {
            if(direction==0)    // tree是根节点
                cout << setw(2) << tree->_value << "(B) is root" << endl;
            else                // tree是分支节点
                cout << setw(2) << tree->_value <<  (rb_is_red(tree)?"(R)":"(B)") << " is " << setw(2) << key << "'s "  << setw(12) << (direction==1?"right child" : "left child") << endl;

            print(tree->_left, tree->_value, -1);
            print(tree->_right,tree->_value,  1);
        }
    }
private:

    RBNode<T> * _root;
};






#endif // sbg_rb_tree_H

