#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    Node *links[26];
    int word_count = 0;
    int prefix_count = 0;

    Node() {
        for(int i = 0; i < 26; i++) {
            links[i] = NULL;
        }
    }

    bool containKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }

    void put(char ch, Node *node) {
        links[ch - 'a'] = node;
    }

    Node *get(char ch) {
        return links[ch - 'a'];
    }

    void increaseEnd() {
        word_count++;
    }

    void increasePrefix() {
        prefix_count++;
    }

    void deleteEnd() {
        word_count--;
    }

    void reducePrefix() {
        prefix_count--;
    }

    int getEnd() {
        return word_count;
    }

    int getPrefix() {
        return prefix_count;
    }
};

class Trie {
    Node *root;
public:

    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node *node = root;
        for(int i = 0; i < word.length(); i++) {
            if(!node->containKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string word) {
        Node *node = root;
        for(int i = 0; i < word.length(); i++) {
            if(!node->containKey(word[i])) {
                return 0;
            }
            node = node->get(word[i]);
        }
        return node->getEnd();
    }

    int countWordStartWith(string prefix) {
        Node *node = root;
        for(int i = 0; i < prefix.length(); i++) {
            if(!node->containKey(prefix[i])) {
                return 0;
            }
            node = node->get(prefix[i]);
        }
        return node->getPrefix();
    }

    void erase(string word) {
        Node *node = root;
        for(int i = 0; i < word.length(); i++) {
            if(node->containKey(word[i])) {
                node = node->get(word[i]);
                node->reducePrefix();
            } else {
                return;
            }
        }
        node->deleteEnd();
    }
};
