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
#define ll long long

int ind(int i){
  if (i < 0){
    while (i<0){
      i += 3;
    }
    return i;
  } else if (i >= 3){
    return i%3;
  }
  return i;
}

int main(){
  ll in[3] = {0,0,0};
  std::cin >> in[0] >> in[1] >> in[2];
  ll out[3] = {0,0,0};
  ll maxi = std::distance(in, std::max_element(in, in+3));
  int o1=ind(maxi-1);
  int o2=ind(maxi-2);
  while ( in[o1] > in[o2] ){
    ++out[o1];
    --in[o1];
    --in[maxi];
  }
  while ( in[o2] > in[o1] ){
    ++out[maxi];
    --in[o2];
    --in[maxi];
  }
  //eliminate maxi
  int mod=0;
  while (in[maxi] > 0){
    if (mod == 0 && in[o1] > 0){
      ++out[o1];
      --in[maxi];
      --in[o1];
      mod = 1;
    } else {
      --in[maxi];
      --in[o2];
      ++out[maxi];
      mod = 0;
    }
  }
  //now make o1 o2 equal
  while (in[o1] > 0){
    --in[o1];
    --in[o2];
    ++out[o2];
  }
  if (in[0] == 0 && in[1] == 0 && in[2] == 0){
    std::cout << out[0] << " " << out[1] << " " << out[2];
  } else {
    std::cout << "Impossible";
  }
}

