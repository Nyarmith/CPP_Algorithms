#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <cstdio>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <set>
#include <map>
#include <utility>
#include <queue>
#define ll long long



const ll maxSize = 10001;
ll memo[maxSize];
ll maxNum(std::vector<ll>& arr, ll k){
  if (k < 0)
    return 0;

  if (memo[k] != -1)
    return memo[k];

  ll max = std::max( maxNum(arr,k-2) + arr[k], + maxNum(arr,k-1) );
  memo[k] = max;
  return max;
}

int main(){
  std::fill(memo, memo+maxSize, -1);
  ll n,tmp;
  std::vector<ll> nums;
  std::cin >> n;
  nums.reserve(n);
  for (int i=0; i<n; ++i){
    std::cin >> tmp;
    nums.push_back(tmp);
  }
  std::cout << maxNum(nums,n-1);
}

