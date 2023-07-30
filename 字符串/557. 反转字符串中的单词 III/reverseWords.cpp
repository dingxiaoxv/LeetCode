#include <iostream>
#include <sstream>

using namespace std;

// 给定一个字符串 s ，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。
string reverseWords(string s)
{
    istringstream is(s);
    string::size_type i = 0;
    string word;
    while (is >> word)
    {
        size_t head = 0, tail = word.size() - 1;
        while (head < tail)
        {
            swap(word[head], word[tail]);
            ++head;
            --tail;
        }
        s.replace(i, word.size(), word);
        i += word.size() + 1;
    }
    return s;
}

int main()
{
    string s("Let's take LeetCode contest");
    cout << s << endl;
    string sr = reverseWords(s);
    cout << sr << endl;

    return 0;
}