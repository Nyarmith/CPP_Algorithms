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
  std::vector<ll> bookSum;
  ll n, t;
  ll tmp;
  std::cin >> n >> t;
  bookSum.reserve(n+1);
  bookSum.push_back(0);

  for (int i=1; i<=n; ++i){
    std::cin >> tmp;
    bookSum.push_back(bookSum[i-1] + tmp);
  }

  ll maxSeq=0;
  for (int i=1; i + maxSeq <= n; ++i){
    ll sum = bookSum[i+maxSeq] - bookSum[i-1];

    while (sum < t && i+maxSeq+1 <= n){
      if (bookSum[i+maxSeq+1] - bookSum[i-1] <= t){
        maxSeq++;
        sum = bookSum[i+maxSeq+1] - bookSum[i-1];
      }
    }
  }

  std::cout << maxSeq;
}
