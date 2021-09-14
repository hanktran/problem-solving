using namespace std;

#include <iostream>
#include <vector>
#include <string>

class TreeNode {
  public:
    string val;
    TreeNode* next;
    vector<TreeNode*> children;

    TreeNode(string x) {
      this->val = x;
      this->next = nullptr;
    }

    ~TreeNode() {
      delete this->next;
      for (int i = 0; i < children.size(); i++) {
        delete this->children[i];
      }
      this->children.clear();
    }
};

TreeNode* traversingDomTree(TreeNode* root, TreeNode* prev, TreeNode* leftmost) {
  if (root == nullptr) {
    return root;
  }

  leftmost = root;
  TreeNode* curr = leftmost;
  while (leftmost != nullptr) {
    prev = nullptr;
    curr = leftmost;
    leftmost = nullptr;

    while (curr != nullptr) {
      cout << curr->val << endl;

      for (auto child : curr->children) {
        if (child != nullptr) {
          if (prev != nullptr) {
            prev->next = child;
          } else {
            leftmost = child;
          }

          prev = child;
        }
      }

      curr = curr->next;
    }
  }

  return root;
}

int main() {
  TreeNode* prev = nullptr;
  TreeNode* leftmost = nullptr;
  TreeNode* root = new TreeNode("body");
  (root->children).push_back(new TreeNode("div"));
  (root->children).push_back(new TreeNode("h1"));
  (root->children).push_back(new TreeNode("div")); 
  (root->children[0]->children).push_back(new TreeNode("h2"));
  (root->children[0]->children[0]->children).push_back(new TreeNode("ul"));
  (root->children[0]->children).push_back(new TreeNode("h3"));
  (root->children[0]->children[1]->children).push_back(new TreeNode("a"));
  (root->children[0]->children[1]->children).push_back(new TreeNode("p"));
  (root->children[0]->children[1]->children).push_back(new TreeNode("table")); 
  (root->children[2]->children).push_back(new TreeNode("p"));
  (root->children[2]->children).push_back(new TreeNode("a"));
  (root->children[2]->children).push_back(new TreeNode("p"));

  TreeNode* res = traversingDomTree(root, prev, leftmost);
  return 0;
}