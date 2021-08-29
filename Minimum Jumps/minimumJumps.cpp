using namespace std;

#include <iostream>
#include <limits>
#include <vector>

class ArrayJump {
  public:
    int countMinJumps(const vector<int> &jumps) {
      return this->countMinJumpsRecursive(jumps, 0);
    }

  private:
    int countMinJumpsRecursive(const vector<int> &jumps, int currentIndex) {
      if (currentIndex == jumps.size() - 1) {
        return 0;
      }

      if (jumps[currentIndex] == 0) {
        return numeric_limits<int>::max();
      }

      int totalJumps = numeric_limits<int>::max();
      int start = currentIndex + 1;
      int end = currentIndex + jumps[currentIndex];
      while (start < jumps.size() && start <= end) {
        int minJumps = countMinJumpsRecursive(jumps, start++);
        if (minJumps != numeric_limits<int>::max()) {
          totalJumps = min(totalJumps, minJumps + 1);
        }
      }

      return totalJumps;
    }
};

class ArrayJumpTopDown {
  public:
    int countMinJumps(const vector<int> &jumps) {
      vector<int> dp(jumps.size(), 0);
      return this->countMinJumpsRecursive(dp, jumps, 0);
    }

  private:
    int countMinJumpsRecursive(vector<int> &dp, const vector<int> &jumps, int currentIndex) {
      if (currentIndex == jumps.size() - 1) {
        return 0;
      }

      if (jumps[currentIndex] == 0) {
        return numeric_limits<int>::max();
      }

      if (dp[currentIndex] != 0) {
        return dp[currentIndex];
      }

      int totalJumps = numeric_limits<int>::max();
      int start = currentIndex + 1;
      int end = currentIndex + jumps[currentIndex];
      while (start < jumps.size() && start <= end) {
        int minJumps = countMinJumpsRecursive(dp, jumps, start++);
        if (minJumps != numeric_limits<int>::max()) {
          totalJumps = min(totalJumps, minJumps + 1);
        }
      }
      dp[currentIndex] = totalJumps;
      return dp[currentIndex];
    }
};

class ArrayJumpBottomUp {
  public:
    int countMinJumps(const vector<int> &jumps) {
      vector<int> dp(jumps.size());

      for (int i = 1; i < jumps.size(); i++) {
        dp[i] = numeric_limits<int>::max();
      }

      for (int start = 0; start < jumps.size(); start ++) {
        for (int end = start + 1; end <= start + jumps[start] && end < jumps.size(); end++) {
          dp[end] = min(dp[end], dp[start] + 1);
        }
      }

      return dp[jumps.size() - 1];
    }
};