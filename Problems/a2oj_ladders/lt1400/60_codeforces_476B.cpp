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
#include <iomanip>
#include <cmath>
#define ll long long

ll choose(ll n, ll k){
  if (n == k || k == 0)
    return 1;
  if (k == 1)
    return n;
  return choose(n-1,k-1) + choose(n-1,k);
}

int main(){
  std::string l1, l2;
  std::cin >> l1 >> l2;

  ll negatives=0;
  ll positives=0;

  for (char c : l1){
    if ( c == '-' )
      ++negatives;
    else
      ++positives;
  }

  ll negs=0, poss=0;
  ll qs=0;
  for (char c : l2){
    if (c == '+')
      ++poss;
    else if (c == '-')
      ++negs;
    else if (c == '?')
      ++qs;
  }

  //biomial thing to count number of ways to get this many +'s
  double prob;

  if (qs == 0 && negatives == negs){
    prob=1;
  } else if (negs > negatives || poss > positives)
    prob = 0;
  else {
    prob = (double)choose(qs,negatives - negs)/(double)std::pow(2,qs);
  }

  std::cout << std::setprecision(11) << prob;
}

