#include <iostream>
#include <cstdint>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#define ll int64_t

int main(){
  ll l,r;
  std::cin >> l >> r;
  std::vector<ll> seq;
  std::vector<ll> luckyNums = {4,7};
  ll i=0;
  ll cur=luckyNums[i];
  while (cur < l){
    ++i;
    if (i >= luckyNums.size()){
      i=0;
      std::vector<ll> out;
      for (ll a : luckyNums){
        out.push_back(a*10+4);
        out.push_back(a*10+7);
      }
      luckyNums = out;
    }
    cur = luckyNums[i];
  }

  if (r <= cur){
    std::cout << (r-l+1)*cur;
  }
  else {
    ll sum=(cur-l+1)*cur;

    while (cur <= r){
      ++i;
      if (i >= luckyNums.size()){
        i=0;
        std::vector<ll> out;
        for (ll a : luckyNums){
          out.push_back(a*10+4);
          out.push_back(a*10+7);
        }
        luckyNums = out;
      }
      ll next = luckyNums[i];
      if (next <= r){
        sum +=  (next-cur)*next;
      } else {
        sum += (r-cur)*next;
      }
      cur = next;
    }

    std::cout << sum;
  }
}

