#include <iostream>
#include <vector>

using namespace std;

int RemoveDuplicates(vector<int>& nums) {
  size_t k = 0, i = 1, num_size = nums.size();
  if (num_size == 0) return 0;
  for ( ; i < num_size; i++) {
    if (nums[i] != nums[i-1]) k++;
    if (k != i) nums[k] = nums[i];
  }
  return k + 1;
}

int main() {
  //vector<int> a = {1,2,2,3,3,4,5,5};
  vector<int> a = {0,0,1,1,1,2,2,3,3,4};
  int k = RemoveDuplicates(a);
  cout << "k is: "  << k << endl;
  for (int j = 0; j < k; j++) {
    cout << a[j] << endl;
  }
  return 0;
}
