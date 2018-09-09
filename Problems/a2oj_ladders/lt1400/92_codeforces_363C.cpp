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
  std::string in, out="";
  std::cin >> in;

  bool lastRepeat = false;
  bool curRepeat  = false;

  char c = in[0];
  out += c;
  ll counter=1;

  ll i=1;
  while (i < in.length()){
    if (in[i] == c){
      curRepeat = true;
      ++counter;
      if (counter + lastRepeat < 3){
        out += in[i];
      } else if (lastRepeat){
        curRepeat=false;
      }
    } else {
      c = in[i];
      counter=1;
      lastRepeat = curRepeat;
      curRepeat = false;
      out += in[i];
    }
    ++i;
  }

  std::cout << out;
}
