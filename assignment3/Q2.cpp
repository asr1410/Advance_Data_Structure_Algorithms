#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Trie
{
public:
    unordered_map<char, Trie *> child;
    unordered_map<string, int> data;
};

void insert(string word, Trie *root)
{
    Trie *node = root;
    for (char c : word)
    {
        if (node->child.find(c) == node->child.end())
            node->child[c] = new Trie();
        node->data[word]++;
        node = node->child[c];
    }
}

bool comp(pair<string, int> &a, pair<string, int> &b)
{
    return a.second > b.second;
}

void suggestion(string pref, Trie *root)
{
    Trie *node = root;
    for (char c : pref)
    {
        if (node->child.find(c) == node->child.end())
            return;
        node = node->child[c];
    }
    vector<pair<string, int>> temp;
    for (auto &data : node->data)
        temp.push_back(data);
    sort(temp.begin(), temp.end(), comp);
    for (auto &t : temp)
        cout << t.first << endl;
}

int main()
{
    Trie *root = new Trie();
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string word;
        cin >> word;
        insert(word, root);
    }
    string prefix;
    cin >> prefix;
    suggestion(prefix, root);
    delete root;
    return 0;
}
