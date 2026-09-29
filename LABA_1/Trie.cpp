#include "Trie.h"

#include <string>


TrieNode::~TrieNode() {
    for (std::pair<const char, TrieNode*>& pair : children) {
        delete pair.second;
    }
}

Trie::Trie() {
    root = new TrieNode();
}

Trie::Trie(std::vector<int>& sourse) {
    root = new TrieNode();
    for (int i : sourse) {
        insert(i);
    }
}

Trie::~Trie() {
    delete root;
}

void Trie::insert(int number) {
    std::string digits = std::to_string(number);
    TrieNode* current = root;

    for (char c : digits) {
        if (current->children.find(c) == current->children.end()) {
            current->children[c] = new TrieNode();
        }
        current = current->children[c];
    }

    current->terminal = true;
}


bool Trie::search(int number) const {
    std::string digits = std::to_string(number);
    TrieNode* current = root;

    for (char c : digits) {
        if (current->children.find(c) != current->children.end()) {
            current = current->children[c];
        } else {
            return false;
        }
    }

    return current->terminal;
}