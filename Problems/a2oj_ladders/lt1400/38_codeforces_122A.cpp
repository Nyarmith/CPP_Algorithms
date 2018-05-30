#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define ll long long

int main(){
  ll n;
  //am I divisible by a lucky number?
  std::cin >> n;
  std::vector<ll> seq = {4,7};
  while(true){
    std::vector<ll> nextSeq;
    nextSeq.reserve(2*seq.size());
    for (ll e : seq){
      if (e > n){
        std::cout << "NO";
        return 0;
      }
      if (n % e == 0){
        std::cout << "YES";
        return 0;
      }
      //gen new elems
      nextSeq.push_back(e * 10 + 4);
      nextSeq.push_back(e * 10 + 7);
    }
    seq = nextSeq;
  }
}
