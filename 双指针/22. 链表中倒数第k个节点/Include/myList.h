#ifndef MYLIST_H
#define MYLIST_H

#include <vector>

namespace MYLIST
{
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(nullptr) {}
    };

    ListNode *createList(const std::vector<int> &nums);
    void destoryList(ListNode *head);
    void printList(ListNode *head);
}

#endif