#pragma once

#include <map>
#include <vector>

struct TrieNode {
    std::map<char, TrieNode*> children;
    bool terminal;

    TrieNode() : terminal(false) {}
    ~TrieNode();
};


class Trie {
private:
    TrieNode* root;

public:
    Trie();
    Trie(std::vector<int>& sourse);
    ~Trie();
    
    // вставить число
    void insert(int number);

    // Найти число в боре
    bool search(int number) const;

};