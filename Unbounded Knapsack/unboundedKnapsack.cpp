using namespace std;

#include <iostream>
#include <vector>

class Knapsack {
  public:
    int solveKnapsack(const vector<int> &profits, const vector<int> &weights, int capacity) {
      return this->knapsackRecursive(profits, weights, capacity, 0);
    }

  private:
    int knapsackRecursive(const vector<int> &profits, const vector<int> &weights, int capacity, int currentIndex) {
      if (capacity <= 0 || profits.empty() || weights.size() != profits.size() || currentIndex >= profits.size()) {
        return 0;
      }

      int profit1 = 0;
      if (weights[currentIndex] <= capacity) {
        profit1 = profits[currentIndex] + knapsackRecursive(profits, weights, capacity - weights[currentIndex], currentIndex);
      }
      int profit2 = knapsackRecursive(profits, weights, capacity, currentIndex + 1);

      return max(profit1, profit2);
    }
};

class KnapsackTopDown {
  public:
    int solveKnapsack(const vector<int> &profits, const vector<int> &weights, int capacity) {
      vector<vector<int>> dp(profits.size(), vector<int>(capacity + 1));
      return this->knapsackRecursive(dp, profits, weights, capacity, 0);
    }

  private:
    int knapsackRecursive(vector<vector<int>> &dp, const vector<int> &profits, const vector<int> &weights, int capacity, int currentIndex) {
      if (capacity <= 0 || profits.empty() || weights.size() != profits.size() || currentIndex >= profits.size()) {
        return 0;
      }

      if (!dp[currentIndex][capacity]) {
        int profit1 = 0;
        if (weights[currentIndex] <= capacity) {
          profit1 = profits[currentIndex] + knapsackRecursive(dp, profits, weights, capacity - weights[currentIndex], currentIndex);
        }

        int profit2 = knapsackRecursive(dp, profits, weights, capacity, currentIndex);

        dp[currentIndex][capacity] = max(profit1, profit2);
      }

      return dp[currentIndex][capacity];
    }
};

class KnapsackBottomUp {
  public:
    int solveKnapsack(const vector<int> &profits, const vector<int> &weights, int capacity) {
      if (capacity <= 0 || profits.empty() || weights.size() != profits.size()) {
        return 0;
      }

      int n = profits.size();
      vector<vector<int>> dp(n, vector<int>(capacity + 1));

      for (int i = 0; i < n; i++) {
        dp[i][0] = 0;
      }

      for (int i = 0; i < n; i++) {
        for (int c = 1; c <= capacity; c++) {
          int profit1 = 0, profit2 = 0;
          if (weights[i] <= c) {
            profit1 = profits[i] + dp[i][c - weights[i]];
          }

          if (i > 0) {
            profit2 = dp[i - 1][c];
          }

          dp[i][c] = profit1 > profit2 ? profit1 : profit2;
        }
      }

      return dp[n - 1][capacity];
    }
};