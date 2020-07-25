#ifndef SBG_LIST_DOUBLE_H
#define SBG_LIST_DOUBLE_H
#include <stdio.h>
namespace sbg_dlist {


template <typename T>
struct _DNode
{
    typedef _DNode<T>*  NodePrt;
    T    val;
    NodePrt * next;
    NodePrt * pre;
} ;

template<typename T>
class sbg_db_list
{
public:


};

}
#endif // SBG_LIST_H
