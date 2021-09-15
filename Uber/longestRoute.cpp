using namespace std;

#include <iostream>
#include <string>

class TreeNode {
  public:
    string val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(string x) {
      this->val = x;
      this->left = nullptr;
      this->right = nullptr;
    }

    TreeNode(string x, TreeNode* left, TreeNode* right) {
      this->val = x;
      this->left = left;
      this->right = right;
    }

    ~TreeNode() {
      delete this->left;
      delete this->right;
    }
};

int height(TreeNode* node) {
  int lh, rh;
  if (node == nullptr) {
    return 0;
  } else {
    lh = height(node->left);
    rh = height(node->right);
  }

  return max(lh, rh) + 1;
}

int longestRoute(TreeNode* root) {
  if (root == nullptr) {
    return 0;
  }

  int lHeight = height(root->left);
  int rHeight = height(root->right);

  int lPath = longestRoute(root->left);
  int rPath = longestRoute(root->right);

  int res = max(lHeight + rHeight + 1, max(lPath, rPath));

  return res;
}

int main() {
  TreeNode* root = new TreeNode("a");
  root->left = new TreeNode("b");
  root->right = new TreeNode("c");
  root->left->left = new TreeNode("d");
  root->right->left = new TreeNode("e");
  root->right->right = new TreeNode("f");
  cout << "The longest route will pass through " << to_string(longestRoute(root)) + " checkpints";
}