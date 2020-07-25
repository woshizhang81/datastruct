#include "sbg_dlist_test.h"
#include "sbg_dlist.hpp"
#include <iostream>
#include <unistd.h>
using namespace std;

//toucha ，weicha 查找，
void dlist_insert_test_case()
{
    sbg_dlist<int> dlist;
    dlist.insert_node(1);
    dlist.insert_node(2);
    dlist.insert_node(3);
    dlist.insert_node(4);
    dlist.insert_node(5);

    dlist.print_list();
    int len = dlist.length();
    dlist.push_back(51);
    dlist.push_back(52);
    dlist.push_back(53);
    dlist.push_back(54);
    dlist.push_back(55);
    dlist.print_list();
    cout<<"length="<<dlist.length()<<endl;

   _DNode<int>* result = dlist.find_dnode(51);
   if (result)
   {
       cout<<"result="<<result<<endl;
       dlist.delete_dnode(result);
       cout<<"after delete node"<<endl;
       dlist.print_list();
   }else {
       cout<<"result= nullptr"<<endl;
   }

}

void dlist_pop_test_case()
{
    sbg_dlist<int> dlist;
    dlist.insert_node(1);
    dlist.insert_node(2);
    dlist.insert_node(3);
    dlist.insert_node(4);
    dlist.insert_node(5);
    dlist.push_back(51);
    dlist.push_back(52);
    dlist.push_back(53);
    dlist.push_back(54);
    dlist.push_back(55);
    dlist.print_list();
    for (int i= 0; i< 3; i++) {
        int front;
        auto b = dlist.front(front);
        if(b)
        {
            printf("front value = %d\n",front);
            dlist.pop_front();
            dlist.print_list();
        }
        sleep(1);
    }
}
void dlist_popback_test_case()
{
    sbg_dlist<int> dlist;
    dlist.insert_node(1);
    dlist.insert_node(2);
    dlist.insert_node(3);
    dlist.insert_node(4);
    dlist.insert_node(5);
    dlist.push_back(51);
    dlist.push_back(52);
    dlist.push_back(53);
    dlist.push_back(54);
    dlist.push_back(55);
    dlist.print_list();
    for (int i= 0; i< 3; i++) {
        int front;
        auto b = dlist.back(front);
        if(b)
        {
            printf("front value = %d\n",front);
            dlist.pop_back();
            dlist.print_list();
        }
        sleep(1);
    }
}


void dlist_sort_test_case()
{
    sbg_dlist<int> dlist;
    dlist.insert_node(1);
    dlist.insert_node(22);
    dlist.insert_node(3);
    dlist.insert_node(43);
    dlist.insert_node(5);
    dlist.push_back(511);
    dlist.push_back(52);
    dlist.push_back(34);
    dlist.push_back(14);
    dlist.push_back(76);
    dlist.sort_dlist();
    dlist.print_list();
}


