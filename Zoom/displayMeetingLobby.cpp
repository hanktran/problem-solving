using namespace std;

#include <iostream>
#include <vector>
#include <string>
#include <stack>

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
        this->root->insert(val);
      }
    }
};

class DisplayLobby {
  stack<Node*>* stack;
  public:
    DisplayLobby(Node* root) {
      this->push_all(root);
    }

    void push_all(Node* node) {
      while (node != nullptr) {
        this->stack->push(node);
        node = node->leftChild;
      }
    }

    bool has_next() {
      return !stack->empty();
    }

    string next_name() {
      Node* tmpNode = this->stack->top();
      this->stack->pop();
      this->push_all(tmpNode->rightChild);
      return tmpNode->val;
    }

    void next_page(vector<string> &res) {
      res.clear();
      for (int i = 0; i < 10; i++) {
        if (this->has_next()) {
          res.push_back(this->next_name());
        } else {
          break;
        }
      }
    }
};

void print(vector<string> &res) {
  cout << "[";
  for (int i = 0; i < res.size(); i++) {
    cout << res[i];
    if (i < res.size() - 1) {
      cout << ", ";
    }
  }
  cout << "]" << endl;
}

int main() {
  BinarySearchTree bst;
  vector<string> names = {"Jeanette", "Latasha", "Elvira", "Caryl", "Antoinette", "Cassie", "Charity", "Lyn", "Elia", "Anya", "Albert", "Cherlyn", "Lala", "Kandice", "Iliana"};
  for(auto name: names) {
    bst.insert(name);
  }

  vector<string> res;
  DisplayLobby display(bst.root);
  display.next_page(res);
  print(res);
}