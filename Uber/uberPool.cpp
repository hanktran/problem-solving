using namespace std;

#include <iostream>
#include <vector>

class Uber {
  vector<int> cumSums;

  public:
    Uber(vector<int> metrics) {
      int cumSum = 0;
      for (int i = 0; i < metrics.size(); i++) {
        cumSum += metrics[i];
        this->cumSums.push_back(cumSum);
      }
    }

    int pickRoute() {
      double random = (double)rand() / RAND_MAX;
      double sum = (double)this->cumSums[this->cumSums.size() - 1];
      double target = random * sum;

      int low = 0, high = this->cumSums.size();
      while (low < high) {
        int mid = low + (high - low) / 2;
        if (target > this->cumSums[mid]) {
          low = mid + 1;
        } else {
          high = mid;
        }
      }

      return low;
    }
};

int main() {
  vector<int> metrics = {1, 2, 3};
  Uber uber(metrics);

  for (int i = 0; i < 10; i++) {
    cout << "Randomly choose route " << to_string(uber.pickRoute()) << endl;
  }

  return 0;
}