using namespace std;

#include <iostream>
#include <vector>
#include <tuple>
#include <unordered_map>

tuple<int, int> suggestTwoProducts(const vector<int> &itemPrices, int amount) {
  unordered_map<int, int> buffDict = {};
  for (int i = 0; i < itemPrices.size(); i++) {
    int price = itemPrices[i];
    int remaining = amount - itemPrices[i];
    if (buffDict.find(remaining) == buffDict.end()) {
      buffDict[price] = i;
    } else {
      return {buffDict.at(remaining), i};
    }
  }
  return {};
}

int main() {
  vector<int> itemPrices {2, 30, 56, 34, 55, 10, 11, 20, 15, 60, 45, 39, 51};
  int amount = 61;
  auto res = suggestTwoProducts(itemPrices, amount);
  cout << "[" << get<0>(res) << "," << get<1>(res) << "]";
  return 0;
}