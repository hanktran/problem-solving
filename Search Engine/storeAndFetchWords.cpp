using namespace std;

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

class Node {
  public:
    unordered_map<char, Node*> children;
    bool isWord;

    Node() {
      this->isWord = false;
    }
};

class WordDictionary {
  Node* root;
  public:
    WordDictionary() {
      this->root = new Node();
    }

    void insertWord(string word) {
      Node* node = this->root;
      for (auto c : word) {
        if (node->children.find(c) == node->children.end()) {
          node->children[c] = new Node();
        }
        node = node->children[c];
      }
      node->isWord = true;
    }

    bool searchWord(string word) {
      Node* node = this->root;
      for (auto c : word) {
        if (node->children.find(c) == node->children.end()) {
          return false;
        }
        node = node->children[c];
      }
      return node->isWord;
    }
};

int main() {
  vector<string> keys = {"the", "a", "there", "answer", "any", "by", "bye", "their", "abc"};
  WordDictionary d;
  for (int i = 0; i < keys.size(); i++) {
    d.insertWord(keys[i]);
  }

  cout << "Searching 'there' in the dictionary results: " << boolalpha << d.searchWord("there");
}