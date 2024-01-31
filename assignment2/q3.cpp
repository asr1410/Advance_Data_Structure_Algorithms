#include <bits/stdc++.h>
using namespace std;

vector<int> pSubGroup(vector<int> &incomes, int gSize)
{
    vector<int> medians;
    for (int i = 0; i < incomes.size(); i += gSize)
    {
        int len = incomes.size();
        int endIndex = min(i + gSize, len);
        sort(incomes.begin() + i, incomes.begin() + endIndex);
        int medianIndex = i + (endIndex - i) / 2;
        medians.push_back(incomes[medianIndex]);
    }
    return medians;
}
int medOmed(vector<int> &incomes, int rank)
{
    if (incomes.size() <= 5)
    {
        sort(incomes.begin(), incomes.end());
        return incomes[rank];
    }

    vector<int> medians = pSubGroup(incomes, 5);
    int mom = medOmed(medians, medians.size() / 2);

    vector<int> left, right;
    for (int i = 0; i < incomes.size(); i++)
    {
        if (incomes[i] < mom)
            left.push_back(incomes[i]);
        else if (incomes[i] > mom)
            right.push_back(incomes[i]);
    }

    if (rank < left.size())
        return medOmed(left, rank);
    else if (rank >= (incomes.size() - right.size()))
        return medOmed(right, rank - (incomes.size() - right.size()));
    else
        return mom;
}

int findNthLargest(vector<int> &incomes, int rank)
{
    if (rank < 1 || rank > incomes.size())
        return -1;
    return medOmed(incomes, rank - 1);
}

int findRank(vector<int> &incomes, int input)
{
    int sCount = 0, lCount = 0;
    for (auto &&income : incomes)
        if (income < input)
            sCount++;
        else if (income > input)
            lCount++;
    if (incomes.size() > sCount + lCount)
        return sCount + 1;
    return -1;
}
int main()
{
    int N, K, M;
    cin >> N >> K >> M;
    vector<int> incomes(N);
    for (int i = 0; i < N; i++)
        cin >> incomes[i];
    cout << findNthLargest(incomes, N - K + 1) << endl;
    cout << findRank(incomes, M) << endl;
    return 0;
}