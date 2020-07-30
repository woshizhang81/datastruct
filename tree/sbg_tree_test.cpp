#include "sbg_tree_test.h"
#include "sbg_tree.hpp"
//#include "sbg_avl_tree.hpp"
void test_case_1()
{
    /*
                  33
             24         39
               28     34  46
    */
    sbg_tree<int> stree;
    stree.insert(33);
    stree.insert(24);
    stree.insert(39);
    stree.insert(28);
    stree.insert(34);
    stree.insert(46);

    stree.pre_traverse();
    printf("\n");
    stree.mid_traverse();
    printf("\n");
    stree.post_traverse();
    printf("\n");
    stree.traverse_layer();
    printf("\n");
    int intfind = 33;
    TNode<int> * pfind =  stree.find(intfind);
    if (pfind)
        printf("bfind value= %d\n",pfind->value);
    else
        printf("value= %d not founded\n" , intfind);

    printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
    TNode<int> * minnode = stree.get_min_node();
    printf("min value= %d \n" , minnode->value);
    TNode<int> * maxnode = stree.get_max_node();
    printf("max value= %d \n" , maxnode->value);

    TNode<int> * pnt = stree.get_parent(pfind);
    if (pnt)
        printf("pfind parent value= %d \n" , pnt->value);

    pnt = stree.get_parent(minnode);
    printf("min parent value= %d \n" , pnt->value);


    printf("oooooooooooooooooooooooooooooooooo\n");
    stree.del_node(pfind);
    stree.mid_traverse();
}

void test_case_2()
{
    sbg_tree<int> stree;
    stree.insert(33);
    stree.insert(24);
    stree.insert(39);
    stree.insert(28);
    stree.insert(34);
    stree.insert(46);
}
