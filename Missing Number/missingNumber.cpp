using namespace std;

#include <iostream>
#include <vector>

class MissingNumber {
  public:
    static int findMissingNumber(vector<int> &arr) {
      int n = arr.size() + 1;
      int s1 = 0;
      for (int i = 1; i <= n; i++) {
        s1 += i;
      }

      for (int i = 0; i < arr.size(); i++) {
        s1 -= arr[i];
      }

      return s1;
    }
};

class MissingNumberXOR {
  public:
    static int findMissingNumber(vector<int> &arr) {
      int n = arr.size() + 1;
      int x1 = 1;
      for (int i = 2; i <= n; i++) {
        x1 = x1 ^ i;
      }

      int x2 = arr[0];
      for (int i = 1; i < n - 1; i++) {
        x2 = x2 ^ arr[i];
      }

      return x1 ^ x2;
    }
};