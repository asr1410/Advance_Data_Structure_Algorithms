#include <bits/stdc++.h>

using namespace std;

int tReached = 0;

int partition(int nums[], int low, int high)
{
    int pIndex = low;
    int pValue = nums[high];
    for (int i = low; i < high; i++)
    {
        if (nums[i] < pValue)
            swap(nums[i], nums[pIndex++]);
    }
    swap(nums[high], nums[pIndex]);
    return pIndex;
}

void quickSort(int nums[], int left, int right, int threshold, int sProblem)
{
    cout << "Current Sub Problems: " << sProblem << endl;
    while (left < right)
    {
        if (sProblem > threshold)
            tReached++;
        int pivot = partition(nums, left, right);
        if (pivot - left < right - pivot)
        {
            sProblem++;
            quickSort(nums, left, pivot - 1, threshold, sProblem);
            sProblem--;
            left = pivot + 1;
        }
        else
        {
            sProblem++;
            quickSort(nums, pivot + 1, right, threshold, sProblem);
            sProblem--;
            right = pivot - 1;
        }
    }
}

int main()
{
    int n;
    cout << "enter input array size: ";
    cin >> n;
    int nums[n], threshold = 2 * log2(n), tReached = 0, sProblem = 0;
    cout << "enter elements of array: ";
    for (auto &&num : nums)
        cin >> num;
    quickSort(nums, 0, n - 1, threshold, sProblem);
    cout << "Sorted Sequence : ";
    for (auto &&num : nums)
        cout << num << " ";
    cout << endl;
    cout << "Threshold Reached: " << tReached << endl;
}
