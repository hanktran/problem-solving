#include <iostream>
#include <queue>

class MedianOfAges {
  public:
    std::priority_queue<int> maxHeap;
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

    void insertNum(int num) {
      if (maxHeap.empty() || maxHeap.top() >= num) {
        maxHeap.push(num);
      } else {
        minHeap.push(num);
      }

      if (maxHeap.size() > minHeap.size() + 1) {
        minHeap.push(maxHeap.top());
        maxHeap.pop();
      } else if (maxHeap.size() < minHeap.size()) {
        maxHeap.push(minHeap.top());
        minHeap.pop();
      }
    }

    double findMedian() {
      if (maxHeap.size() == minHeap.size()) {
        return maxHeap.top() / 2.0 + minHeap.top() / 2.0;
      }

      return maxHeap.top();
    }
};

int main() {
  MedianOfAges medianOfAges;
  medianOfAges.insertNum(22);
  medianOfAges.insertNum(35);
  std::cout << "The recommnded content will be for ages under: " << std::to_string(medianOfAges.findMedian()) << std::endl;
  medianOfAges.insertNum(30);
  std::cout << "The recommnded content will be for ages under: " << std::to_string(medianOfAges.findMedian()) << std::endl;
  medianOfAges.insertNum(25);
  std::cout << "The recommnded content will be for ages under: " << std::to_string(medianOfAges.findMedian()) << std::endl;
  return 0;
}