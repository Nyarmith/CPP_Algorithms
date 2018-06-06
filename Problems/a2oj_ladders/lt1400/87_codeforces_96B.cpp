#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define ll long long

bool isSuperLucky(ll n){
  ll fours=0;
  ll sevens=0;
  while(n){
    ll r = n%10;
    if (r == 4){
      ++fours;
    } else {
      ++sevens;
    }
    n /= 10;
  }

  return fours == sevens;
}

int main(){
  ll n;
  //am I divisible by a lucky number?
  std::cin >> n;
  std::vector<ll> seq = {4,7};
  while(true){
    std::vector<ll> nextSeq;
    nextSeq.reserve(2*seq.size());
    for (ll e : seq){
      if (e >= n){
        if (isSuperLucky(e)){
          std::cout << e;
          return 0;
        }
      }
      //gen new elems
      nextSeq.push_back(e * 10 + 4);
      nextSeq.push_back(e * 10 + 7);
    }
    seq = nextSeq;
  }
}
