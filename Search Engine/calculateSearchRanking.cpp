using namespace std;

#include <iostream>
#include <vector>

vector<int> searchRanking(vector<int> &pageScores) {
  int length = pageScores.size();
  vector<int> ranking(pageScores.size());
  ranking[0] = 1;
  for (int i = 1; i < length; i++) {
    ranking[i] = pageScores[i - 1] * ranking[i - 1];
  }

  int right = 1;
  for (int i = length - 1; i >= 0; i--) {
    ranking[i] = ranking[i] * right;
    right *= pageScores[i];
  }

  return ranking;
}

int main() {
  vector<int> pageScores = {3, 5, 1, 1, 6, 7, 2, 3, 4, 1, 2};
  vector<int> ranking = searchRanking(pageScores);
  cout << "[";
  for (int i = 0; i < ranking.size(); i++) {
    cout << ranking[i];
    if (i < ranking.size() - 1) {
      cout << ", ";
    }
  }
  cout << "]";
}