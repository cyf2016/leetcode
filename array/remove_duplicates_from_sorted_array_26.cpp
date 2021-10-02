#include <iostream>
#include <vector>

using namespace std;

int main() {
  //vector<int> a = {1,2,2,3,3,4,5,5};
  vector<int> a = {0,0,1,1,1,2,2,3,3,4};
  size_t k = 0, i = 1;
  for ( ; i < a.size(); i++) {
    if (a[i] != a[i-1]) k++;
    if (k != i) a[k] = a[i];
  }
  cout << "k is: "  << k << endl;
  for (size_t j = 0; j <= k; j++) {
    cout << a[j] << endl;
  }
  return 0;
}
