using namespace std;

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <stack>
#include <algorithm>

vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
  unordered_map<string, string> emailToName;
  unordered_map<string, unordered_set<string>> graph;
  for (auto acc : accounts) {
    string name = acc[0];
    for (int i = 1; i < acc.size(); i++) {
      string email = acc[i];
      graph[acc[1]].insert(email);
      graph[email].insert(acc[1]);
      emailToName[email] = name;
    }
  }

  unordered_set<string> seen;
  vector<vector<string>> ans;
  for (auto g : graph) {
    auto email = g.first;
    if (seen.find(email) == seen.end()) {
      seen.insert(email);
      stack<string> stack;
      stack.push(email);
      vector<string> component;
      while (!stack.empty()) {
        string node = stack.top();
        stack.pop();
        component.push_back(node);
        for (auto neighbor : graph[node]) {
          if (seen.find(neighbor) == seen.end()) {
            seen.insert(neighbor);
            stack.push(neighbor);
          }
        }
      }
      sort(component.begin(), component.end());
      component.insert(component.begin(), emailToName[email]);
      ans.push_back(component);
    }
  }

  return ans;
}

void print(vector<vector<string>> &result) {
  cout << "[";
  for (int i = 0; i < result.size(); i++) {
    cout << "[";
    for (int j = 0; j < result[i].size(); j++) {
      cout << result[i][j];
      if (j < result[i].size() - 1) {
        cout << ", ";
      }
    }
    cout << "]";
    if (i < result.size() - 1) {
      cout << ", ";
    }
  }
  cout << "]" << endl;
}

int main() {
  vector<vector<string>> accounts = {{"Sarah", "sarah22@email.com", "sarah@gmail.com", "sarahhoward@email.com"}, {"Alice", "alicexoxo@email.com", "alicia@email.com", "alicelee@gmail.com"}, {"Sarah", "sarah@gmail.com", "sarah10101@gmail.com"}, {"Sarah", "sarah10101@gmail.com", "misshoward@gmail.com"}};
  auto result = accountsMerge(accounts);
  print(result);
}