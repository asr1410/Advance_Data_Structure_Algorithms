#include <bits/stdc++.h>
using namespace std;

void cSort(vector<int> &nums, int mod)
{
    vector<int> temp(nums.size()), map(10);
    for (int index = 0; index < nums.size(); index++)
        map[(abs(nums[index]) % (mod * 10)) / mod]++;
    for (int index = 1; index < 10; index++)
        map[index] += map[index - 1];
    for (int index = nums.size() - 1; index >= 0; index--)
    {
        temp[map[(abs(nums[index]) % (mod * 10)) / mod] - 1] = nums[index];
        map[(abs(nums[index]) % (mod * 10)) / mod]--;
    }
    nums = temp;
}

vector<int> rSort(vector<int> &nums)
{
    int maxx = abs(nums[0]);
    for (int i = 0; i < nums.size(); i++)
        if (maxx < abs(nums[i]))
            maxx = abs(nums[i]);
    for (int i = 1; i <= maxx; i *= 10)
        cSort(nums, i);
    return nums;
}

int main()
{
    int input;
    cin >> input;
    vector<int> nums(input);
    for (auto &&num : nums)
        cin >> num;
    vector<int> sorted_nums = rSort(nums);
    vector<int> neg;
    vector<int> pos;
    for (auto &&num : nums)
        if (num < 0)
            neg.push_back(num);
        else
            pos.push_back(num);
    reverse(neg.begin(), neg.end());
    for (auto &&num : neg)
        cout << num << " ";
    for (auto &&num : pos)
        cout << num << " ";
    cout << endl;
    return 0;
}
