#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>

using namespace std;

int numRescueBoats(vector<int> &people, int limit)
{
    sort(people.begin(), people.end());
    auto iter_head = people.begin();
    auto iter_tail = people.end() - 1;
    int num = 0;
    while (iter_head <= iter_tail)
    {
        if (*iter_head + *iter_tail <= limit)
        {
            ++iter_head;
        }
        --iter_tail;
        ++num;
    }
    return num;
}

vector<vector<int>> resRescueBoats(vector<int> &people, int limit)
{
    sort(people.begin(), people.end());
    auto iter_head = people.begin();
    auto iter_tail = people.end() - 1;
    vector<vector<int>> res;
    while (iter_head <= iter_tail)
    {
        vector<int> vecTmp;
        if (*iter_head + *iter_tail <= limit)
        {
            vecTmp.push_back(*iter_head);
            vecTmp.push_back(*iter_tail);
            ++iter_head;
        }
        else
        {
            vecTmp.push_back(*iter_tail);
        }
        --iter_tail;
        if (!vecTmp.empty())
        {
            res.push_back(vecTmp);
        }
    }
    return res;
}

int main()
{
    vector<int> people({3, 5, 3, 4, 1, 2});
    copy(people.begin(), people.end(), ostream_iterator<int>(cout, " "));
    cout << endl
         << "救生艇重量限制: ";
    string strLimit;
    getline(cin, strLimit);
    cout << "承载所有人所需的最小船数: " << numRescueBoats(people, stoi(strLimit)) << endl;
    vector<vector<int>> res = resRescueBoats(people, stoi(strLimit));
    for (auto vec : res)
    {
        copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
        cout << endl;
    }

    return 0;
}