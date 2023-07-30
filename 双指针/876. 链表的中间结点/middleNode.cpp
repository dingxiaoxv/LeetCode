#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *middleNode(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    // 注意循环条件不能写成fast->next && fast这种形式，原因在于fast走两步后可能就指向空了
    // 再执行循环条件fast->next会导致越界。但是fast写在前面就不会出现上述情况，因为&&存在短路求值
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode *createLinkedList(vector<int> &nums)
{
    ListNode *dummy = new ListNode(0);
    ListNode *curr = dummy;

    for (int num : nums)
    {
        curr->next = new ListNode(num);
        curr = curr->next;
    }

    return dummy->next;
}

void printLinkedList(ListNode *head)
{
    ListNode *curr = head;
    while (curr != nullptr)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }
}

int main()
{
    vector<int> ivec({1, 2, 3, 4, 5});
    copy(ivec.begin(), ivec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    ListNode *head = createLinkedList(ivec);
    ListNode *mid = middleNode(head);
    printLinkedList(mid);
    cout << endl;

    return 0;
}