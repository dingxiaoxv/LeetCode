/*给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。
如果可以，返回 true ；否则返回 false 。
magazine 中的每个字符只能在 ransomNote 中使用一次。*/

#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

bool canConstruct(string ransomNote, string magazine)
{
    if(ransomNote.size() > magazine.size())
    {
        return false;
    }

    unordered_map<char, size_t> charCount;
    for(auto ch : magazine)
    {
        ++charCount[ch];
    }
    
    for(auto ch : ransomNote)
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
    string ransomNote("aa"), magazine("aab");
    cout << canConstruct(ransomNote, magazine) << endl;

    return 0;
}