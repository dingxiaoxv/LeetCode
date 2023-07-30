/*给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。
*/
#include <string>
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

bool isAnagram(string s, string t)
{
    if(s.size() != t.size())
    {
        return false;
    }

    unordered_map<char, size_t> charCount;
    for(auto ch : s)
    {
        ++charCount[ch];
    }
    for(auto ch : t)
    {
        if(charCount[ch] > 0)
        {
            --charCount[ch];
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string s("rat"), t("car");
    cout << s << " and " << t << ((isAnagram(s, t))? " is Anagram" : " is Not Anagram") << endl;
    return 0;
}