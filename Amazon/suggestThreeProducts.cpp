using namespace std;

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

void twoProducts(vector<int> &itemPrices, int i, vector<vector<int>> &res) {
  unordered_set<int> seen;
  int j = i + 1;
  while (j < itemPrices.size()) {
    int complement = 200 - itemPrices[i] - itemPrices[j];
    if (seen.find(complement) != seen.end()) {
      res.push_back({itemPrices[i], itemPrices[j], complement});
      while (j + 1 < itemPrices.size() && itemPrices[j] == itemPrices[j + 1]) {
        j++;
      }
    }
    seen.insert(itemPrices[j]);
    j++;
  }
}

void suggestThreeProducts(vector<int> &itemPrices, vector<vector<int>> &res) {
  unordered_map<int, int> buffDict = {};
  sort(itemPrices.begin(), itemPrices.end());
  for (int i = 0; i < itemPrices.size(); i++) {
    int price = itemPrices[i];
    if (price > 200) {
      break;
    }
    if (i == 0 || itemPrices[i - 1] != price) {
      twoProducts(itemPrices, i, res);
    }
  }
}

void print(vector<vector<int>> &res) {
  cout << "[";
  for (int i = 0; i < res.size(); i++) {
    cout << "[";
    for (int j = 0; j < res[i].size(); j++) {
      cout << res[i][j];
      if (j < res[i].size() - 1) {
        cout << ", ";
      }
    }
    cout << "]";
    if (i < res.size() - 1) {
      cout << ", ";
    }
  }
  cout << "]";
}

int main(){
  vector<int> itemPrices {100, 75, 150, 200, 50, 65, 40, 30, 15, 25, 60};
  vector<vector<int>> res;
  suggestThreeProducts(itemPrices, res);
  print(res);
  return 0;
}