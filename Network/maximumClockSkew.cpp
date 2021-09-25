using namespace std;

#include <iostream>
#include <vector>

class TreeNode {
  public:
    int val;
    vector<TreeNode*> children;

    TreeNode(int val) {
      this->val = val;
    }

    ~TreeNode() {
      for (int i = 0; i < this->children.size(); i++) {
        delete this->children[i];
      }
      this->children.clear();
    }
};

int maxDiff = 0;

void dfs(TreeNode* node, int maxVal, int minVal) {
  if (node == nullptr) return;

  int possibleMaxDiff = max(abs(maxVal - node->val), abs(minVal - node->val));
  maxDiff = max(maxDiff, possibleMaxDiff);

  maxVal = max(maxVal, node->val);
  minVal = min(minVal, node->val);

  for (TreeNode* child : node->children) {
    dfs(child, maxVal, minVal);
  }
}

int maxClockSkew(TreeNode* root) {
  if (root == nullptr) {
    return 0;
  }

  maxDiff = 0;
  dfs(root, root->val, root->val);
  return maxDiff;
}

int main() {
  TreeNode* root = new TreeNode(8);
  root->children.push_back(new TreeNode(3));
  root->children.push_back(new TreeNode(10));
  root->children.push_back(new TreeNode(12));
  root->children[0]->children.push_back(new TreeNode(6));
  root->children[0]->children[0]->children.push_back(new TreeNode(1));
  root->children[0]->children.push_back(new TreeNode(5));
  root->children[0]->children[1]->children.push_back(new TreeNode(2));
  root->children[0]->children[1]->children.push_back(new TreeNode(3));
  root->children[0]->children[1]->children.push_back(new TreeNode(4));
  root->children[2]->children.push_back(new TreeNode(8));
  root->children[2]->children.push_back(new TreeNode(7));
  root->children[2]->children.push_back(new TreeNode(9));

  cout << "The maximum clock skew we'll encounter is: " <<  to_string(maxClockSkew(root)) << " seconds" << endl;
  return 0;
}