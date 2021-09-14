using namespace std;

#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
#include <unordered_set>

class TreeNode {
  public:
    int val;
    vector<TreeNode*> children;

    TreeNode(int x) {
      val = x;
    }

    ~TreeNode() {
      for (int i = 0; i < children.size(); i++) {
        delete children[i];
      }
      children.clear();
    }
};

int lowestCommonAncestor(TreeNode* root, TreeNode* a, TreeNode* b) {
  stack<TreeNode*> stack;
  unordered_map<TreeNode*, TreeNode*> parent;
  parent[root] = nullptr;
  stack.push(root);

  while (parent.find(a) == parent.end() || parent.find(b) == parent.end()) {
    TreeNode* node = stack.top();
    stack.pop();
    for (auto child : node->children) {
      parent[child] = node;
      stack.push(child);
    }
  }

  unordered_set<TreeNode*> ancestors;
  while (a != nullptr) {
    ancestors.insert(a);
    a = parent[a];
  }

  while (ancestors.find(b) == ancestors.end()) {
    b = parent[b];
  }

  return b->val;
}

int main(){
  TreeNode* root = new TreeNode(1);
  root->children.push_back(new TreeNode(2));
  root->children.push_back(new TreeNode(3));
  root->children.push_back(new TreeNode(4));
  root->children[0]->children.push_back(new TreeNode(5));
  root->children[0]->children[0]->children.push_back(new TreeNode(10));
  root->children[0]->children.push_back(new TreeNode(6));
  root->children[0]->children[1]->children.push_back(new TreeNode(11));
  root->children[0]->children[1]->children.push_back(new TreeNode(12));
  root->children[0]->children[1]->children.push_back(new TreeNode(13));
  root->children[2]->children.push_back(new TreeNode(7));
  root->children[2]->children.push_back(new TreeNode(8));
  root->children[2]->children.push_back(new TreeNode(9));

  TreeNode* a = root->children[0]->children[1]->children[2];
  TreeNode* b = root->children[0]->children[0]->children[0];
  int LCA = lowestCommonAncestor(root, a, b);
  cout << "\"" + to_string(LCA) + "\"" + " is the lowest common ancestor of the nodes " + "\"" + to_string(a->val) + "\"" + " and " + "\"" + to_string(b->val) + "\"";
}