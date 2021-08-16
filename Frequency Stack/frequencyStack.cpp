using namespace std;

#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>

class Element {
  public:
    int number = 0;
    int frequency = 0;
    int sequenceNumber = 0;

    Element(int number, int frequency, int sequenceNumber) {
      this->number = number;
      this->frequency = frequency;
      this->sequenceNumber = sequenceNumber;
    }
};

class FrequencyStack {
  public:
    struct frequencyCompare {
      bool operator()(const Element &e1, const Element &e2) {
        if (e1.frequency != e2.frequency) {
          return e2.frequency > e1.frequency;
        }
        return e2.sequenceNumber > e1.sequenceNumber;
      }
    };

    int sequenceNumber = 0;
    priority_queue<Element, vector<Element>, frequencyCompare> maxHeap;
    unordered_map<int, int> frequencyMap;

    virtual void push(int num) {
      frequencyMap[num] += 1;
      maxHeap.push({num, frequencyMap[num], sequenceNumber++});
    }

    virtual int pop() {
      int num = maxHeap.top().number;
      maxHeap.pop();

      if (frequencyMap[num] > 1) {
        frequencyMap[num] -= 1;
      } else {
        frequencyMap.erase(num);
      }

      return num;
    }
};