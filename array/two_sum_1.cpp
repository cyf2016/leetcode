//Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
//You may assume that each input would have exactly one solution, and you may not use the same element twice.
//You can return the answer in any order.

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
vector<int> Solution(vector<int>& nums, int target) {
  vector<int> res;
  unordered_map<int, size_t> m;
  size_t sz = nums.size();
  m.reserve(sz);
  for (size_t i = 0; i < sz; i++) {
    auto iter = m.find(nums[i]);
    if (iter == m.end()) {
      m[target - nums[i]] = i;
    } else {
      res.push_back(iter->second);
      res.push_back(i);
      break;
    }
  }
  return res;
}

int main () {
  vector<int> nums = {2,3,8,4,1,9};
  auto res = Solution(nums, 17);
  for (auto v : res) {
    cout << v << endl;
  }
  return 0;
}
