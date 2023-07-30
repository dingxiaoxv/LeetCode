/*给你一个字符串 s ，其中包含字母顺序打乱的用英文单词表示的若干数字（0-9）。按 升序 返回原始的数字。*/
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

string originalDigits(string s)
{
    vector<int> count(26, 0);
    vector<int> digits(10, 0);
    
    // 统计每个字母的出现次数
    for (char c : s) {
        count[c - 'a']++;
    }
    // 根据特定的字符出现次数推断数字的出现次数
    digits[0] = count['z' - 'a']; // 字母'z'只在数字0中出现
    digits[2] = count['w' - 'a']; // 字母'w'只在数字2中出现
    digits[4] = count['u' - 'a']; // 字母'u'只在数字4中出现
    digits[6] = count['x' - 'a']; // 字母'x'只在数字6中出现
    digits[8] = count['g' - 'a']; // 字母'g'只在数字8中出现
    digits[1] = count['o' - 'a'] - digits[0] - digits[2] - digits[4]; // 字母'o'只在数字1中出现
    digits[3] = count['h' - 'a'] - digits[8]; // 字母'h'只在数字3中出现
    digits[5] = count['f' - 'a'] - digits[4]; // 字母'f'只在数字5中出现
    digits[7] = count['s' - 'a'] - digits[6]; // 字母's'只在数字7中出现
    digits[9] = count['i' - 'a'] - digits[5] - digits[6] - digits[8]; // 字母'i'只在数字9中出现
    
    string result;
    
    // 构建升序的原始数字字符串
    for (int i = 0; i < 10; i++) {
        result += string(digits[i], '0' + i);
    }
    
    return result;
}

int main() {
    string s = "owoztneoer";
    string original = originalDigits(s);
    cout << "Original Digits: " << original << endl;

    return 0;
}