/*给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
字母异位词 是由重新排列源单词的字母得到的一个新单词，所有源单词中的字母通常恰好只用一次。
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    unordered_map<string, vector<string>> anagramMap;
    for (auto str : strs)
    {
        string sortedStr = str;
        sort(sortedStr.begin(), sortedStr.end()); //通过排序就可以判断是否是字母异位词:排序后完全相同
        anagramMap[sortedStr].push_back(str);
    }
    vector<vector<string>> res;
    for (auto it = anagramMap.begin(); it != anagramMap.end(); ++it)
    {
        res.push_back(it->second);
    }
    return res;
}

int main()
{
    // 示例输入
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result = groupAnagrams(strs);

    // 打印结果
    for (const auto &group : result)
    {
        for (const string &str : group)
        {
            cout << str << " ";
        }
        cout << endl;
    }

    return 0;
}