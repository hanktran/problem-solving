using namespace std;

#include <iostream>
#include <vector>

class Node {
  public:
    int val;
    Node* leftChild;
    Node* rightChild;

    Node(int val) {
      this->val = val;
      this->leftChild = nullptr;
      this->rightChild = nullptr;
    }

    void insert(int val) {
      Node* current = this;
      Node* parent = current;
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

    void insert(int val) {
      if (this->root == nullptr) {
        this->root = new Node(val);
      } else {
        this->root->insert(val);
      }
    }

    ~BinarySearchTree() {
      delete this->root;
    }
};

void preOrder(Node* node, int low, int high, vector<int> &output) {
  if (node != nullptr) {
    if (node->val <= high && low <= node->val) {
      output.push_back(node->val);
    }

    if (low <= node->val) {
      preOrder(node->leftChild, low, high, output);
    }

    if (node->val <= high) {
      preOrder(node->rightChild, low, high, output);
    }
  }
}

vector<int> productsInRange(Node* root, int low, int high) {
  vector<int> output;
  preOrder(root, low, high, output);
  return output;
}

void print(vector<int> &output) {
  cout << "[";
  for (int i = 0; i < output.size(); i++) {
    cout << output[i];
    if (i < output.size() - 1) {
      cout << ", ";
    }
  }
  cout << "]" << endl;
}

int main() {
  BinarySearchTree bst;
  bst.insert(9);
  bst.insert(6);
  bst.insert(14);
  bst.insert(20);
  bst.insert(1);
  bst.insert(30);
  bst.insert(8);
  bst.insert(17);
  bst.insert(5);
  auto result = productsInRange(bst.root, 7, 20);
  print(result);
  return 0;
}