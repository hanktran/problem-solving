using namespace std;

#include <iostream>
#include <vector>

bool identifyTitles(vector<int> &scores) {
  bool increasing = true;
  bool decreasing = true;

  for (int i = 0; i < scores.size() - 1; i++) {
    if (scores[i] > scores[i + 1]) {
      increasing = false;
    }

    if (scores[i] < scores[i + 1]) {
      decreasing = false;
    }
  }

  return (increasing || decreasing);
}

int main() {
  vector<vector<int>> movieRatings = {
    {1, 2, 2, 3},
    {4, 5, 6, 3, 4},
    {8, 8, 7, 6, 5, 4, 4, 1}
  };

  for (auto movieRating : movieRatings) {
    if (identifyTitles(movieRating)) {
      cout << "Title Identified and Separated\n";
    } else {
      cout << "Title Score Fluctuating\n";
    }
  }

  return 0;
}