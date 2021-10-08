#include <iostream>
#include <vector>

void QuickSort(std::vector<int> &arr, int left, int right) {
  if (left >= right) return;
  int x = left , y = right;
  int pivot = arr[x];

  while (x < y) {
    while(x < y && arr[y] >= pivot) y--;
    if(x < y) arr[x++] = arr[y];
    while (x < y && arr[x] <= pivot) x++;
    if (x < y) arr[y--] = arr[x];
  }
  arr[x] = pivot;
  QuickSort(arr, left, x - 1);
  QuickSort (arr, x + 1, right);
}

int main () {
  std::vector<int> arr = {3, 2, 5, 1, 8, 7, 11, 18,32, 45, 32, 10, 31, 43, 33, 21, 132, 180,3232};
  QuickSort(arr, 0, arr.size() - 1);
  for (auto val : arr) {
    std::cout << val << ' ';
  }
  std::cout << std::endl;
  return 0;
}
