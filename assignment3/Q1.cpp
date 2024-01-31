#include <iostream>
#include <vector>
using namespace std;
vector<pair<int, int>> st;
void bST(vector<int> &input, int node, int low, int high)
{
    if (low == high)
        st[node].first = input[low];
    else
    {
        int mid = (low + high) / 2, lChild = 2 * node + 1, rChild = 2 * node + 2;
        bST(input, lChild, low, mid);
        bST(input, rChild, mid + 1, high);
        st[node].first = st[lChild].first + st[rChild].first;
    }
}

void pLazy(int node, int low, int high)
{
    if (st[node].second != 0)
    {
        st[node].first += (high - low + 1) * st[node].second;
        if (low != high)
        {
            int lChild = 2 * node + 1;
            int rChild = 2 * node + 2;
            st[lChild].second += st[node].second;
            st[rChild].second += st[node].second;
        }
        st[node].second = 0;
    }
}

void updateST(int node, int low, int high, int pos, int newValue)
{
    pLazy(node, low, high);
    if (low == high)
        st[node].first = newValue;
    else
    {
        int mid = (low + high) / 2, lChild = 2 * node + 1, rChild = 2 * node + 2;
        if (pos <= mid)
            updateST(lChild, low, mid, pos, newValue);
        else
            updateST(rChild, mid + 1, high, pos, newValue);
        st[node].first = st[lChild].first + st[rChild].first;
    }
}

void iST(int node, int low, int high, int queryLeft, int queryRight, int inc)
{
    pLazy(node, low, high);
    if (queryLeft > high || queryRight < low)
        return;
    if (queryLeft <= low && queryRight >= high)
    {
        st[node].first += (high - low + 1) * inc;
        if (low != high)
        {
            int lChild = 2 * node + 1, rChild = 2 * node + 2;
            st[lChild].second += inc, st[rChild].second += inc;
        }
        return;
    }
    int mid = (low + high) / 2, lChild = 2 * node + 1, rChild = 2 * node + 2;
    iST(lChild, low, mid, queryLeft, queryRight, inc);
    iST(rChild, mid + 1, high, queryLeft, queryRight, inc);
    st[node].first = st[lChild].first + st[rChild].first;
}

int qST(int node, int low, int high, int queryPosition)
{
    pLazy(node, low, high);
    if (low == high)
        return st[node].first;
    int mid = (low + high) / 2, lChild = 2 * node + 1, rChild = 2 * node + 2;
    if (queryPosition <= mid)
        return qST(lChild, low, mid, queryPosition);
    else
        return qST(rChild, mid + 1, high, queryPosition);
}

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    int N, K;
    cin >> N >> K;
    vector<int> input(N);
    st.resize(4 * N);
    for (int i = 0; i < N; i++)
        cin >> input[i];
    bST(input, 0, 0, N - 1);
    for (int i = 0; i < K; i++)
    {
        char operation;
        cin >> operation;
        if (operation == 'U')
        {
            int pos, newValue;
            cin >> pos >> newValue;
            updateST(0, 0, N - 1, pos - 1, newValue);
        }
        else if (operation == 'I')
        {
            int low, high, inc;
            cin >> low >> high >> inc;
            iST(0, 0, N - 1, low - 1, high - 1, inc);
        }
        else if (operation == 'G')
        {
            int pos;
            cin >> pos;
            int res = qST(0, 0, N - 1, pos - 1);
            cout << res << " ";
        }
    }
    return 0;
}