#include <iostream>
#include <vector>

void QuickSort(std::vector<int>& arr, int left, int right) {
  if (left >= right) return;
  int low = left, high = right;
  int pivot = arr[low];

  while (low < high) {
    while (low < high && pivot <= arr[high]) high--;
    if (low < high) arr[low++] = arr[high];
    while (low < high && arr[low] <= pivot) low++;
    if (low < high) arr[high--] = arr[low];
  }
  arr[low] = pivot;
  QuickSort(arr, left, low - 1);
  QuickSort(arr, low + 1, right);
}

int main() {
  std::vector<int> arr = {3, 4, 23, 21, 31, 12, 0, 8, 123, 131, 73, 3323, 312, 314, 431, 312};
  QuickSort(arr, 0, arr.size() - 1);
  for (auto v : arr) {
    std::cout << v << ' ';
  }
  std::cout << '\n';
  return 0;
}
