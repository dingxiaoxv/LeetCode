/*给定两个字符串 s 和 t ，它们只包含小写字母。
字符串 t 由字符串 s 随机重排，然后在随机位置添加一个字母。
请找出在 t 中被添加的字母。*/
#include <iostream>
#include <string>
#include <set>

using namespace std;

char findTheDifference(string s, string t)
{
#if 1
    int as = 0, at = 0;
    for (char ch : s)
    {
        as += ch;
    }
    for (char ch : t)
    {
        at += ch;
    }
    return at - as;
#else
    int ret = 0;
    for (char ch : s)
    {
        ret ^= ch;
    }
    for (char ch : t)
    {
        ret ^= ch;
    }
    return ret;
#endif
}

int main(int, char **)
{
    string s("aabcd"), t("daceab");
    cout << s << " " << t << endl;
    cout << findTheDifference(s, t) << endl;

    return 0;
}
