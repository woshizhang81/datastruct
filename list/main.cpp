#include <iostream>
#include <sbg_list.hpp>
#include "sbg_list_test.h"
#include "sbg_dlist_test.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode new_head(-1);
        new_head.next = head;
        ListNode * p = new_head.next;
        new_head.next = nullptr;
        while(p )
        {
            ListNode * t = p->next;
            p->next = new_head.next;
            new_head.next = p;
            p = t;
        }
        return new_head.next;
    }
    ListNode* reverseList1(ListNode* head) {
        ListNode * p = head;
        head = nullptr;
        while(p )
        {
            ListNode * t = p->next;
            p->next = head;
            head = p;
            p = t;

        }
        return head;
    }

    ListNode* reverseList2(ListNode* head) {
        ListNode * p = head;
        ListNode * pre = nullptr;
        while(p )
        {
            ListNode * t = p->next;
            p->next = pre;
            pre = p;
            p = t;
        }
        return pre;
    }
};
int main()
{
    printf("xxxxxxxxxxxxxxxxxxx\n");
    ListNode n1(0);
    ListNode n2(1);
    ListNode n3(2);
    ListNode n4(3);
    ListNode n5(4);
    ListNode n6(5);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;
    ListNode * ttt = &n1;
    while(ttt)
    {
        printf("%d ",ttt->val);
        ttt = ttt->next;
    }
       Solution sl;
    ListNode * ret  = sl.reverseList1(&n1);

    while(ret)
    {
        printf("%d",ret->val);
        ret = ret->next;
    }

}

int main1()
{
    //链表测试
    //list_tail_test_case();
    //list_test_case();
    //双向列表测试用例
    //dlist_insert_test_case();
    //dlist_pop_test_case();
    //dlist_popback_test_case();
    //dlist_sort_test_case();
    list_digui_case();
    return 0;
}
