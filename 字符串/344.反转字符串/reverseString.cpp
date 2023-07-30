#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

void reverseString(vector<char>& s)
{
    auto iter_head = s.begin();
    auto iter_tail = s.end() - 1;
    while(iter_head < iter_tail)
    {
        char temp;
        temp = *iter_head;
        *iter_head = *iter_tail;
        *iter_tail = temp;
        ++iter_head;
        --iter_tail;
    }
}

int main()
{
    vector<char> s({'h','e','l','l','o'});
    copy(s.begin(), s.end(), ostream_iterator<char>(cout));
    cout << endl;
    reverseString(s);
    copy(s.begin(), s.end(), ostream_iterator<char>(cout));
    cout << endl;

    return 0;
}