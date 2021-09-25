using namespace std;

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

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

void dfs(TreeNode* parent, TreeNode* child, unordered_map<int, vector<int>> &neighbors) {
  if (child == nullptr) {
    return;
  }

  if (parent != nullptr) {
    if (neighbors.find(parent->val) == neighbors.end()) {
      neighbors[parent->val] = {};
    }

    if (neighbors.find(child->val) == neighbors.end()) {
      neighbors[child->val] = {};
    }

    neighbors[parent->val].push_back(child->val);
    neighbors[child->val].push_back(parent->val);
  }

  for (int i = 0; i < (child->children).size(); i++) {
    dfs(child, child->children[i], neighbors);
  }
}

void getDevices(TreeNode* root, TreeNode* server, int ttl, vector<int> &bfs) {
  unordered_map<int, vector<int>> neighbors;
  dfs(nullptr, root, neighbors);

  bfs.push_back(server->val);
  set<int> lookup(bfs.begin(), bfs.end());

  for (int i = 0; i < ttl; i++) {
    vector<int> temp;
    for (int node : bfs) {
      for (int nei : neighbors[node]) {
        if (lookup.find(nei) == lookup.end()) {
          temp.push_back(nei);
        }
      }
    }
    bfs = temp;
    lookup.insert(bfs.begin(), bfs.end());
  }
}

void print(vector<int> &res) {
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

  TreeNode* server = root->children[0]->children[1];
  int ttl = 2;
  vector<int> res; 
  getDevices(root, server, ttl, res);
  cout << "The TTL value will expire on node IDs: ";
  print(res);
}