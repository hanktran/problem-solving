#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class TrieNode {
  public:
    vector<shared_ptr<TrieNode>> children;
    bool isWord;
    const int ALPHABET_SIZE = 26;
    TrieNode();
};

class Trie {
  public:
    Trie();
    void insert(string key);
    bool search(string key);
    shared_ptr<TrieNode> root;
};

TrieNode::TrieNode() {
  this->isWord = false;
  this->children = vector<shared_ptr<TrieNode>>(ALPHABET_SIZE);
}

Trie::Trie() {
  this->root = make_shared<TrieNode>();
}

void Trie::insert(string key) {
  shared_ptr<TrieNode> node = this->root;
  int index = 0;

  for (int level = 0; level < key.length(); level++) {
    index = key[level] - 'A';
    if (node->children[index] == nullptr) {
      node->children[index] = make_shared<TrieNode>();
    }
    node = node->children[index];
  }
  node->isWord = true;
}

bool Trie::search(string key) {
  shared_ptr<TrieNode> node = this->root;
  int index = 0;

  for (int level = 0; level < key.length(); level++) {
    index = key[level] - 'A';
    if (node->children[index] == nullptr) {
      return false;
    }
    node = node->children[index];
  }

  if (node->isWord) {
    return true;
  }

  return false;
}

void dfs(shared_ptr<TrieNode> node, vector<vector<char>> &grid, int row, int col, vector<string> &result, string word) {
  if (node->isWord) {
    result.push_back(word);
    node->isWord = false;
  }

  if (0 <= row && row < grid.size() && 0 <= col && col < grid[0].size()) {
    char c = grid[row][col];
    int index = c - 'A';
    if (c != '#' && node->children[index] != nullptr) {
      shared_ptr<TrieNode> child = node->children[index];
      word += c;
      grid[row][col] = '#';

      vector<vector<int>> offsets {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
      for (auto offset : offsets) {
        int rowOffset = offset[0];
        int colOffset = offset[1];
        dfs(child, grid, row + rowOffset, col + colOffset, result, word);
      }
      grid[row][col] = c;
    }
  }
}

void searchWords(vector<vector<char>> &grid, vector<string> words, vector<string> &result) {
  Trie t;
  for (auto word : words) {
    t.insert(word);
  }

  for (int row = 0; row < grid.size(); row++) {
    for (int col = 0; col < grid[0].size(); col++) {
      dfs(t.root, grid, row, col, result, "");
    }
  }
}

void print(vector<string> output) {
  cout << "[";
  for (int i = 0; i < output.size(); i++) {
    cout << output[i];
    if (i < output.size() - 1) {
      cout << ", " << endl;
    }
  }
  cout << "]" << endl;
}

int main() {
  vector<vector<char>> grid {
    {'B', 'S', 'L', 'I', 'M'}, 
    {'R', 'I', 'L', 'M', 'O'}, 
    {'O', 'L', 'I', 'E', 'O'}, 
    {'R', 'Y', 'I', 'L', 'N'}, 
    {'B', 'U', 'N', 'E', 'C'}
  };

  vector<string> words {"BUY", "SLICK", "SLIME", "ONLINE", "NOW"};
  vector<string> result;
  searchWords(grid, words, result);
  print(result);
  return 0;
}