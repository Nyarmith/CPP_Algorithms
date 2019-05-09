#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <cstdio>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <set>
#include <map>
#include <utility>
#include <queue>
#define ll long long

struct EndNode
{
    std::string str;
};

struct TrieNode
{
    TrieNode* child[4]; // 4 letters: a, b, c, d
    EndNode* end; // $
    TrieNode(){ child[0] = child[1] = child[2] = child[3] = nullptr; end = nullptr;}
};

void addNode(TrieNode* root, std::string in)
{
    for (char &c : in)
    {
        int ind = c - 'a';
        if (!root->child[ind])
        {
            root->child[ind] = new TrieNode();
        }
        root = root->child[ind];
    }
    if (!root->end)
    {
        root->end = new EndNode();
    }
    root->end->str = in;
}

void printTreeInOrder(TrieNode* root)
{
    if (root->end)
    {
        std::cout << "found string: " << root->end->str << "\n";
    }

    for (int i=0; i<4; ++i)
    {
        if (root->child[i])
        {
            std::cout << "entering : \'" << static_cast<char>('a' + i ) << "\'\n";
            printTreeInOrder(root->child[i]);
        }
    }
}

int main()
{
    TrieNode root {};
    addNode(&root, "abc");
    addNode(&root, "abcd");
    addNode(&root, "aaad");
    addNode(&root, "bab");

    printTreeInOrder(&root);
}
