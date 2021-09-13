using namespace std;

#include <iostream>
#include <vector>
#include <unordered_set>

int lengthOfLongestBusyPeriod(vector<int> &schedule) {
  int logestBusyPeriod = 0;
  unordered_set<int> slotSet(schedule.begin(), schedule.end());
  for (auto slot : slotSet) {
    if (slotSet.find(slot - 1) == slotSet.end()) {
      int currentSlot = slot;
      int currentConsecutiveSlot = 1;
      while (slotSet.find(currentSlot + 1) != slotSet.end()) {
        currentSlot++;
        currentConsecutiveSlot++;
      }
      if (currentConsecutiveSlot > logestBusyPeriod) {
        logestBusyPeriod = currentConsecutiveSlot;
      }
    }
  }

  return logestBusyPeriod;
}

int main() {
  vector<int> schedule = {3, 1, 8, 5, 2, 12, 10, 4, 8, 9};
  cout << to_string(lengthOfLongestBusyPeriod(schedule)) << endl;
}