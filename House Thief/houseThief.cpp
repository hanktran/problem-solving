using namespace std;

#include <iostream>
#include <vector>

class HouseThief {
  public:
    int findMaxSteal(const vector<int> &wealth) {
      return findMaxStealRecursive(wealth, 0);
    }
  
  private:
    int findMaxStealRecursive(const vector<int> &wealth, int currentIndex) {
      if (currentIndex >= wealth.size()) {
        return 0;
      }

      int stealCurrent = wealth[currentIndex] + findMaxStealRecursive(wealth, currentIndex + 2);
      int skipCurrent = findMaxStealRecursive(wealth, currentIndex + 1);
      return max(stealCurrent, skipCurrent);
    }
};

class HouseThiefTopDown {
  public:
    int findMaxSteal(const vector<int> &wealth) {
      vector<int> dp(wealth.size(), 0);
      return findMaxStealRecursive(dp, wealth, 0);
    }

  private:
    int findMaxStealRecursive(vector<int> &dp, const vector<int> &wealth, int currentIndex) {
      if (currentIndex >= wealth.size()) {
        return 0;
      }

      if (dp[currentIndex] == 0) {
        int stealCurrent = wealth[currentIndex] + findMaxStealRecursive(dp, wealth, currentIndex + 2);
        int skipCurrent = findMaxStealRecursive(dp, wealth, currentIndex + 1);
        dp[currentIndex] = max(stealCurrent, skipCurrent);
      }

      return dp[currentIndex];
    }
};

class HouseThiefBottomUp {
  public:
    int findMaxSteal(const vector<int> &wealth) {
      if (wealth.empty()) {
        return 0;
      }

      vector<int> dp(wealth.size() + 1);
      dp[0] = 0;
      dp[1] = wealth[0];

      for (int i = 1; i < wealth.size(); i++) {
        dp[i + 1] = max(wealth[i] + dp[i - 1], dp[i]);
      }

      return dp[wealth.size()];
    }
};

class HouseThiefBottomUp1 {
  public:
    int findMaxSteal(const vector<int> &wealth) {
      if (wealth.empty()) {
        return 0;
      }

      int n1 = 0, n2 = wealth[0], temp;
      for (int i = 1; i < wealth.size(); i++) {
        temp = max(wealth[i] + n1, n2);
        n1 = n2;
        n2 = temp;
      }

      return n2;
    }
};