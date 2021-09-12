using namespace std;

#include <iostream>
#include <vector>

int search(vector<int> &arr, int start, int end, int key) {
  if (start > end) {
    return -1;
  }

  int mid = start + (end - start) / 2;
  if (arr[mid] == key) {
    return mid;
  }

  if (arr[start] <= arr[mid] && key <= arr[mid] && key >= arr[start]) {
    return search(arr, start, mid - 1, key);
  } else if (arr[mid] <= arr[end] && key >= arr[mid] && key <= arr[end]) {
    return search(arr, mid + 1, end, key);
  } else if (arr[end] <= arr[mid] && key <= arr[mid]) {
    return search(arr, mid + 1, end, key);
  } else if (arr[start] >= arr[mid] && key >= arr[mid]) {
    return search(arr, start, mid - 1, key);
  }

  return -1;
}

int findStoryId(vector<int> &arr, int key) {
  return search(arr, 0, arr.size() - 1, key);
}

int main(){
  vector<int> v1 = {6, 7, 1, 2, 3, 4, 5};
  cout << "Key(3) found at: " << to_string(findStoryId(v1, 3)) << endl;
  cout << "Key(6) found at: " << to_string(findStoryId(v1, 6)) << endl;
  
  vector<int> v2 = {4, 5, 6, 1, 2, 3};
  cout << "Key(3) found at: " << to_string(findStoryId(v2, 3)) << endl;
  cout << "Key(6) found at: " << to_string(findStoryId(v2, 6)) << endl;

  vector<int> v3 = {6, 5, 4, 3, 2, 1};
  cout << "Key(3) found at: " << to_string(findStoryId(v3, 2)) << endl;
  cout << "Key(6) found at: " << to_string(findStoryId(v3, 6)) << endl;
  return 0;
}