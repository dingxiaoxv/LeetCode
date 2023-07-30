#include <iostream>
#include <vector>
#include <iterator>
#include <string>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> res;
    auto iter_top = nums.begin();
    auto iter_tail = nums.end() - 1;
    while (iter_top < iter_tail)
    {
        if (*iter_top + *iter_tail < target)
        {
            ++iter_top;
        }
        else if (*iter_top + *iter_tail > target)
        {
            --iter_tail;
        }
        else
        {
            res.push_back(*iter_top);
            res.push_back(*iter_tail);
            break;
        }
    }

    return res;
}

int main()
{
    vector<int> nums({1, 2, 4, 6, 10});
    copy(nums.begin(), nums.end(), ostream_iterator<int>(cout, " "));
    cout << endl << "please input target number : " << endl;
    string str;
    getline(cin, str);
    vector<int> res = twoSum(nums, stoi(str));
    if(!res.empty())
    {
        copy(res.begin(), res.end(), ostream_iterator<int>(cout, " "));
        cout << endl;
    }
    
    return 0;
}
