using namespace std;

#include <iostream>
#include <math.h>

class CalculateComplement {
  public:
    static int bitwiseComplement(int num) {
      int bitCount = 0;
      int n = num;
      while (n > 0) {
        bitCount++;
        n = n >> 1;
      }

      int allBitsSet = pow(2, bitCount) - 1;

      return num ^ allBitsSet;
    }
};