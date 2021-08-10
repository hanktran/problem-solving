using namespace std;

#include <iostream>
#include <vector>

class TwoSingleNumbers {
  public:
    static vector<int> findSingleNumbers(vector<int> &nums) {
      int n1xn2 = 0;
      for (int i = 0; i < nums.size(); i++) {
        n1xn2 ^= nums[i];
      }

      int rightmostSetBit = 1;
      while ((rightmostSetBit & n1xn2) == 0) {
        rightmostSetBit = rightmostSetBit << 1;
      }

      int num1 = 0, num2 = 0;
      for (int i = 0; i < nums.size(); i++) {
        int num = nums[i];
        if ((num & rightmostSetBit) != 0) {
          num1 ^= num;
        } else {
          num2 ^= num;
        }
      }

      return vector<int>(num1, num2);
    }
};