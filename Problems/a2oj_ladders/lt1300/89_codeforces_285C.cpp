#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int taken[300001];

int shortest(int k, int n){
  int initCost=0;
  int upper=0, lower=0;
  if (k<1){
    initCost=1-k;
    k=1;
  }
  if (k>n){
    initCost=k-n;
    k=n;
  }

  int tmp=k;
  while (tmp <= n && taken[tmp])
    ++tmp;
  if (tmp <= n)
    upper += tmp;
  else
    upper = 2000000000;

  tmp = k;
  while (tmp >= 1 && taken[tmp])
    --tmp;
  if (tmp >= 1){
    lower += tmp;
  } else {
    lower = -2000000000;
  }

  if ((upper-k+initCost) < (k-lower+initCost))
    taken[upper] = true;
  else
    taken[lower] = true;

  return (std::min(upper-k + initCost, k-lower+initCost));

}
int main(){
  std::uint64_t n, moves=0;
  int tmp;
  std::cin >> n;
  for (int i=0; i<n; ++i){
    std::cin >> tmp;
    moves += shortest(tmp,n);
  }

  std::cout << moves;
}
