using namespace std;

#include <iostream>
#include <vector>

bool isPalindrome(vector<int> &arr, int left, int right) {
  while (left < right) {
    if (arr[left] != arr[right]) {
      return false;
    }
    left++;
    right--;
  }

  return true;
}

int transmissionError(vector<int> &arr) {
  int left = 0, right = arr.size() - 1;

  while (left < right) {
    if (arr[left] == arr[right]) {
      left++;
      right--;
    } else {
      if (isPalindrome(arr, left + 1, right)) {
        return 1;
      }

      if (isPalindrome(arr, left, right - 1)) {
        return 1;
      }

      return -1;
    }
  }

  return 0;
}

int main() {
  vector<int> arr = {1, 2, 3, 3, 4, 2, 1};
  int res = transmissionError(arr);
  if (res == 1 || res == 0) {
    cout << "Network Sustained. No Transmission Error Occured!\n";
  } else {
    cout << "Network Broke. Transmission Error Occured!\n";
  }
  return 0;
}