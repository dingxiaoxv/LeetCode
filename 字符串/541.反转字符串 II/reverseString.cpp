#include <iostream>

using namespace std;

string reverseStr(string s, int k)
{
    size_t n = s.size();
    for (size_t i = 0; i < n; i += 2 * k)
    {
        size_t start = i;
        size_t end = min(i + k - 1, n - 1);
        while (start < end)
        {
            swap(s[start], s[end]);
            ++start;
            --end;
        }
    }
    return s;
}

int main()
{
    string s = "abcdefgh";
    cout << s << endl;
    string s1 = reverseStr(s, 3);
    cout << s1 << endl;

    return 0;
}