/*给定一个字符串 s ，根据字符出现的 频率 对其进行 降序排序 。一个字符出现的 频率 是它出现在字符串中的次数。
返回 已排序的字符串 。如果有多个答案，返回其中任何一个。
*/
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

bool compareFrequency(const pair<char, size_t>& a, const pair<char, size_t>& b) 
{
    return a.second > b.second;
}

string frequencySort(string s)
{
    unordered_map<char, size_t> frequencyMap;
    for(auto ch : s)
    {
        ++frequencyMap[ch];
    }
    // 将unordered_map转换为vector
    vector<pair<char, size_t>> frequencyVec(frequencyMap.begin(), frequencyMap.end());
    sort(frequencyVec.begin(), frequencyVec.end(), compareFrequency);
    string res;
    for(auto pair : frequencyVec)
    {
        res += string(pair.second, pair.first);
    }
    return res;
}

int main()
{
    string s("ddddbaaabfcc");
    cout << "sort \"" << s << "\" is " << frequencySort(s) << endl;

    return 0;
}