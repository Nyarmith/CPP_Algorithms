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

int main(){
  ll n,k,sum=0,tmp;
  ll smallestabs=2000000000;
  std::priority_queue<ll, std::vector<ll>, std::greater<ll> > minheap;
  std::cin >> n >> k;
  for (int i=0; i<n; ++i){
    std::cin >> tmp;
    if (tmp < 0 && k > 0){
      --k;
      tmp *= -1;
    }
    minheap.push(tmp);
    sum += tmp;
  }
  if (k == 0){
    std::cout << sum;
  } else {
    ll min = minheap.top();
    if (k % 2 == 1){
      sum -= 2*min;
    }
    std::cout << sum;
  }
}
