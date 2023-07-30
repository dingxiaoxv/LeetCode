/*在二维平面上，有一个机器人从原点 (0, 0) 开始。给出它的移动顺序，判断这个机器人在完成移动后是否在 (0, 0) 处结束。
移动顺序由字符串 moves 表示。字符 move[i] 表示其第 i 次移动。机器人的有效动作有 R（右），L（左），U（上）和 D（下）。
如果机器人在完成所有动作后返回原点，则返回 true。否则，返回 false。
*/
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

bool judgeCircle(string moves)
{
    unordered_map<char, size_t> moveMap;
    for (auto ch : moves)
    {
        ++moveMap[ch];
    }
    if ((moveMap.size() % 2) != 0)
    {
        return false;
    }
    if (moveMap.find('U') == moveMap.find('D') && moveMap.find('L') == moveMap.find('R'))
    {
        return true;
    }
    return false;
}

int main()
{
    cout << judgeCircle("UDRL") << endl;

    return 0;
}