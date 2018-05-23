#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <cstdint>

int arr[300001];

int main(){
  int n;
  std::cin >> n;
  for (int i=0; i<n; ++i){
    std::cin >> arr[i];
  }
  std::sort(arr,arr+n);
  uint64_t diffs=0;
  for (int i=0; i<n; ++i){
    diffs +=  std::abs( (i+1)-arr[i]) ;
  }

  std::cout << diffs;
}
