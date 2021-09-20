using namespace std;

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

vector<string> split(const string &s, char delim) {
  stringstream ss(s);
  string item;
  vector<string> elems;
  while (getline(ss, item, delim)) {
    elems.push_back(item);
  }
  return elems;
}

class Node {
  public:
    string val;
    Node* leftChild;
    Node* rightChild;

    Node(string val) {
      this->val = val;
      this->leftChild = nullptr;
      this->rightChild = nullptr;
    }

    void insert(string val) {
      Node* current = this;
      Node* parent = nullptr;
      while (current != nullptr) {
        parent = current;
        if (val < current->val) {
          current = current->leftChild;
        } else {
          current = current->rightChild;
        }
      }
      if (val < parent->val) {
        parent->leftChild = new Node(val);
      } else {
        parent->rightChild = new Node(val);
      }
    }

    ~Node() {
      delete this->leftChild;
      delete this->rightChild;
    }
};

class BinarySearchTree {
  public:
    Node* root;

    BinarySearchTree() {
      this->root = nullptr;
    }

    void insert(string val) {
      if (root == nullptr) {
        root = new Node(val);
      } else {
        root->insert(val);
      }
    }
};

class Translator {
  public:
    void serialize(Node* root, string &str) {
      vector<string> res;
      preOrder(root, res);
      for (int i = 0; i < res.size(); i++) {
        str += res[i];
        if (i + 1 < res.size()) {
          str += ",";
        }
      }
    }

    void preOrder(Node* root, vector<string> &res) {
      if (root != nullptr) {
        res.push_back(root->val);
        preOrder(root->leftChild, res);
        preOrder(root->rightChild, res);
      }
    }

    Node* deserialize(string &data) {
      Node* root;
      char delim = ',';
      vector<string> lst = split(data, delim);
      for (auto name : lst) {
        if (root == nullptr) {
          root = new Node(name);
        } else {
          root->insert(name);
        }
      }
      return root;
    }
};

int main() {
  BinarySearchTree bst;
  vector<string> names {"Jeanette", "Elia", "Albert", "Latasha", "Elvira", "Kandice", "Maggie"};
  
  for(auto name: names) {
    bst.insert(name);
  }
  
  Translator trans;
  string string = "";
  trans.serialize(bst.root, string);
  cout << "\nSerialized: " << string << endl;

  Node * deserialized = trans.deserialize(string);

  return 0;
}