using namespace std;

#include <iostream>
#include <vector>
#include <queue>

class TreeNode {
  public:
    string val;
    vector<TreeNode*> children;

    TreeNode(string x) {
      val = x;
    }

    ~TreeNode() {
      for (int i = 0; i < children.size(); i++) {
        delete children[i];
      }
      children.clear();
    }
};

void traverse(TreeNode* root, vector<vector<string>> &result) {
  if (root == nullptr) {
    return;
  }

  queue<TreeNode*> queue;
  queue.push(root);
  while (!queue.empty()) {
    int levelSize = queue.size();
    vector<string> currentLevel;
    for (int i = 0; i < levelSize; i++) {
      TreeNode* currentNode = queue.front();
      queue.pop();
      currentLevel.push_back(currentNode->val);

      for (auto child : currentNode->children) {
        queue.emplace(child);
      }
    }
    result.push_back(currentLevel);
  }
}

void print(vector<vector<string>> &result) {
  int k = 0;
  cout << "[";
  for (auto arr : result) {
    int j = 0;
    cout << "[";
    for (int i = 0; i < arr.size(); i++) {
      cout << arr[i];
      if (j < arr.size() - 1) {
        cout << ", ";
      }
      j++;
    }
    cout << "]";
    if (k < result.size() - 1) {
      cout << ", ";
    }
    k++;
  }
  cout << "]";
}

int main() {
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

  vector<vector<string>> result;
  traverse(root, result);
  print(result);
}