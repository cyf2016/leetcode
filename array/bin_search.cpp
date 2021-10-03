#include <iostream>
#include <vector>

using namespace std;

int BinarySearch(const vector<int>& arr, int target) {
  int low = 0, high = arr.size() - 1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] == target) return mid;
    else if (arr[mid] > target) high = mid - 1;
    else low = mid + 1;
  }
  return -1;
}

int main() {
  vector<int> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int pos = BinarySearch(arr, 4);
  cout << pos << endl;
  return 0;
}
