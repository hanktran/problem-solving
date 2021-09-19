using namespace std;

#include <iostream>
#include <vector>
#include <unordered_map>

vector<int> findSimilarity(vector<int> &products, vector<int> candidates) {
  int prodN = products.size();
  int candN = candidates.size();
  if (prodN < candN) return {};

  unordered_map<int, int> candCount;
  unordered_map<int, int> prodCount;

  for (int i : candidates) {
    if (candCount.find(i) == candCount.end()) {
      candCount[i] = 0;
    }
    candCount[i] += 1;
  }

  vector<int> output;
  for (int i = 0; i < prodN; i++) {
    int k = products[i];
    if (prodCount.find(k) == prodCount.end()) {
      prodCount[k] = 0;
    }
    prodCount[k] += 1;

    if (i >= candN) {
      k = products[i - candN];
      if (prodCount[k] == 1) {
        prodCount.erase(k);
      } else {
        prodCount[k] -= 1;
      }
    }

    if (candCount == prodCount) {
      output.push_back(i - candN + 1);
    }
  }

  return output;
}

void print(vector<int> &result) {
  cout << "[";
  for (int i = 0; i < result.size(); i++) {
    cout << result[i];
    if (i < result.size() - 1) {
      cout << ", ";
    }
  }
  cout << "]" << endl;
}

int main() {
  vector<int> products = {3, 2, 1, 5, 2, 1, 2, 1, 3, 4};
  vector<int> candidates = {1, 2, 3};
  vector<int> result = findSimilarity(products, candidates);
  print(result);
}