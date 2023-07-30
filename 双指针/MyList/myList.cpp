#include "myList.h"
#include <iostream>

MYLIST::ListNode *MYLIST::createList(const std::vector<int> &nums)
{
    ListNode *head = new ListNode(0);
    ListNode *curr = head;
    for (auto num : nums)
    {
        curr->next = new ListNode(num);
        curr = curr->next;
    }
    return head->next;
}

void MYLIST::destoryList(ListNode *head)
{
    ListNode *curr = head;
    while (curr != nullptr)
    {
        ListNode *temp = curr;
        curr = curr->next;
        delete temp;
    }
    head = nullptr;
}

void MYLIST::printList(ListNode *head)
{
    ListNode *curr = head;
    while (curr != nullptr)
    {
        std::cout << curr->val << " ";
        curr = curr->next;
    }
    std::cout << std::endl;
}
