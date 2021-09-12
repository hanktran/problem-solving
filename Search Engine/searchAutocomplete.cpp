using namespace std;

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>

class Node {
  public:
    unordered_map<char, Node*> children;
    bool isEnd;
    string data;
    int rank;
    vector<Node*> hot;

    Node() {
      this->isEnd = false;
      this->rank = 0;
    }

    void update(Node* n) {
      if (find(this->hot.begin(), this->hot.end(), n) == this->hot.end()) {
        this->hot.push_back(n);
      }
      sort(hot.begin(), hot.end());
      if (hot.size() > 3) {
        hot.pop_back();
      }
    }
};

class AutocompleteSystem {
  Node* root;
  Node* current;
  string keyword;

  public:
    AutocompleteSystem(vector<string> sentences, vector<int> times) {
      this->root = new Node();
      this->current = root;
      this->keyword = "";

      for (int i = 0; i < sentences.size(); i++) {
        this->addRecord(sentences[i], times[i]);
      }
    }

    void addRecord(string sentence, int t) {
      Node* node = this->root;
      vector<Node*> visited;
      for (auto c : sentence) {
        if (node->children.find(c) == node->children.end()) {
          node->children[c] = new Node();
        }
        node = node->children[c];
        visited.push_back(node);
      }
      node->isEnd = true;
      node->data = sentence;
      node->rank += t;

      for (auto i : visited) {
        i->update(node);
      }
    }

    void autoComplete(char c, vector<string> &res) {
      if (c == '#') {
        addRecord(keyword, 1);
        keyword = "";
        current = root;
        return;
      }

      this->keyword += c;
      if (current != nullptr) {
        if (current->children.find(c) == current->children.end()) {
          return;
        } else {
          current = current->children[c];
        }
      } else {
        return;
      }

      for (auto node : current->hot) {
        res.push_back(node->data);
      }
    }
};

void print(vector<string> res) {
  int len = res.size();
  int i = 0;
  string ans = "[";
  for (auto s : res) {
    ans += s;
    if (i < (len - 1)) {
      ans += ", ";
    }
    i++;
  }
  ans += "]";
  cout << ans << endl;
}

int main() {
  vector<string> sentences = {"beautiful", "best quotes", "best friend", "best birthday wishes", "instagram", "internet"};
  vector<int> times = {30, 14, 21, 10, 10, 15};
  AutocompleteSystem autoComplete(sentences, times);
  vector<string> res;

  autoComplete.autoComplete('b', res);
  print(res);
  res.clear();

  autoComplete.autoComplete('e', res);
  print(res);
  res.clear();

  autoComplete.autoComplete('s', res);
  print(res);
  res.clear();

  autoComplete.autoComplete('t', res);
  print(res);
  res.clear();

  autoComplete.autoComplete('#', res);
  print(res);
  res.clear();
}