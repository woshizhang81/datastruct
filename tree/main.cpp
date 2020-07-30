#include <iostream>

using namespace std;

#include "sbg_tree_traverse.hpp"
#include "sbg_tree_test.h"
#include "sbg_rb_tree.hpp"
#include "sbg_rb_tree_net.hpp"
int main()
{
    RBTree<int> tr_net;
    tr_net.insert(50);
    tr_net.insert(59);
    tr_net.insert(60);
    tr_net.insert(40);
    tr_net.insert(51);
    tr_net.insert(503);
    tr_net.insert(5);
    tr_net.insert(53);
    tr_net.insert(503);
    tr_net.insert(703);
    tr_net.insert(43);
    tr_net.insert(70);
    tr_net.insert(51);
    tr_net.insert(66);
    tr_net.insert(9);
    tr_net.insert(1);
    tr_net.print();

    printf("uuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuu\n");

    sbg_rb_tree<int> tr;
    tr.insert(50);
    tr.insert(59);
    tr.insert(60);
    tr.insert(40);
    tr.insert(51);
    tr.insert(503);
    tr.insert(5);
    tr.insert(53);
    tr.insert(503);
    tr.insert(703);
    tr.insert(43);
    tr.insert(70);
    tr.insert(51);
    tr.insert(66);
    tr.insert(9);
    tr.insert(1);
    tr.print();

}

int main1()
{
    sbg_tree_traverse<int> obj;
    obj.insert(1);
    obj.insert(2);
    obj.insert(3);
    obj.insert(4);
    obj.insert(5);
    obj.insert(6);
    obj.insert(7);
    obj.insert(8);
    obj.insert(9);
    obj.insert(10);
    obj.insert(11);
    obj.set_callback([](TRAVERSE_TYPE type,int val)
    {
        do{
            printf("%d ", val);
            break;
            switch(type)
            {
                case TRAVERSE_TYPE::PRE_TRAVERSE:
                    printf("pre -> %d ", val);
                    break;
                case TRAVERSE_TYPE::MID_TRAVERSE:
                    printf("mid -> %d ", val);
                    break;
                case TRAVERSE_TYPE::BACK_TRAVERSE:
                    printf("back -> %d ", val);
                    break;
                default:
                    break;
            }
        }while(0);
    });

    printf("3种先序遍历\n");
    obj.pre_trav();
    printf("\n");
    obj.for_pre_trav();
    printf("\n");
    obj.for_pre_trav_2();
    printf("\n");

    printf("3种中序遍历\n");
    obj.mid_trav();
    printf("\n");
    obj.for_mid_trav();
    printf("\n");
    obj.for_mid_trav2();
    printf("\n");

    printf("2种后序遍历\n");
    obj.back_trav();
    printf("\n");
    obj.for_back_trav();
    printf("\n");

     printf("1种层序遍历遍历\n");
    obj.broadcast_trav();//广度遍历
    printf("\n");

    int height = obj.height();//get_height_bypostorder()
    printf("height %d\n",height);
    return 0;
}

int main2()
{
    test_case_1();
}
