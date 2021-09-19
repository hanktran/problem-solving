using namespace std;

#include <iostream>
#include <unordered_map>
#include <vector>

class UpsellProducts {
  unordered_map<int, int> productDict;
  vector<int> productList;

  public:
    UpsellProducts() {}

    bool insertProduct(int prod) {
      if (productDict.find(prod) != productDict.end()) {
        return false;
      }
      productDict[prod] = productList.size();
      productList.push_back(prod);
      return true;
    }

    bool removeProduct(int prod) {
      if (productDict.find(prod) == productDict.end()) {
        return false;
      }
      int last = productList[productList.size() - 1];
      int index = productDict[prod];
      productList[index] = last;
      productDict[last] = index;
      productList.pop_back();
      productDict.erase(prod);
      return true;
    }

    int getRandomProduct() {
      return productList[rand() % productList.size()];
    }
};

int main() {
  UpsellProducts dataset;
  dataset.insertProduct(1212);
  dataset.insertProduct(190);
  dataset.insertProduct(655);
  dataset.insertProduct(327);
  cout << to_string(dataset.getRandomProduct()) << endl;
  dataset.removeProduct(190);
  dataset.removeProduct(1212);
  cout << to_string(dataset.getRandomProduct()) << endl;
  return 0;
}