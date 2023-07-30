// 给定一个字符串 s ，找到 它的第一个不重复的字符，并返回它的索引 。如果不存在，则返回 -1 。
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int firstUniqChar(string s)
{
    unordered_map<char, size_t> umapFrequency;
    for (auto ch : s)
    {
        ++umapFrequency[ch];
    }
    for (size_t i = 0; i < s.size(); ++i)
    {
        if(umapFrequency[s[i]] == 1)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    string s("leetcode");
    cout << s << endl;
    cout << firstUniqChar(s) << endl;

    return 0;
}