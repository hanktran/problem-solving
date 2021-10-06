#include <iostream>
#include <vector>

using namespace std;

int maxPoints(vector<int> deck, int k) {
  int left = 0;
  int right = deck.size() - k;
  int total, best;
  total = 0;
  for (int i = right; i < deck.size(); i++) {
    total += deck[i];
  }

  best = total;
  for (int i = 0; i < k; i++) {
    total += deck[left] - deck[right];
    best = max(best, total);
    left += 1;
    right += 1;
  }

  return best;
}

int main() {
    vector<int> deck = {5, 3, 4, 4, 2, 3, 2, 6, 3};
    int k = 4;
    cout << maxPoints(deck, k);
}