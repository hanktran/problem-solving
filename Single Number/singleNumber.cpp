using namespace std;

#include <iostream>
#include <vector>

class SingleNumber {
  public:
    static int findSingleNumber(const vector<int> &arr) {
      int num = 0;
      for (int i = 0; i < arr.size(); i++) {
        num = num ^ arr[i];
      }
      return num;
    }
};