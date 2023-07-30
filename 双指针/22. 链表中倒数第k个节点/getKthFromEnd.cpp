#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include "myList.h"

using namespace std;
using ListNode = MYLIST::ListNode;

ListNode *getKthFromEnd(ListNode *head, int k)
{
    if (head == nullptr || k <= 0)
    {
        return nullptr;
    }
    ListNode *slow = head;
    ListNode *fast = head;
    // 将fast指针先移动k-1个节点，这样fast指针到末尾时slow指针就正好走到倒数第k个节点
    for (size_t i = 0; i < k - 1; ++i)
    {
        if (fast->next != nullptr)
        {
            fast = fast->next;
        }
        else
        {
            return nullptr;
        }
    }
    while (fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

int main()
{
    vector<int> ivec({1, 2, 3, 4, 5, 6, 7});
    copy(ivec.begin(), ivec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    cout << "input a number : ";
    string str;
    getline(cin, str);

    ListNode *pList = MYLIST::createList(ivec);
    ListNode *pKth = getKthFromEnd(pList, stoi(str));
    MYLIST::printList(pKth);
    MYLIST::destoryList(pList);

    return 0;
}