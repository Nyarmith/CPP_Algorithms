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

int main(){
  ll a,b,c;
  ll f=0;
  std::cin >> a >> b >> c;

  //special case(!!)
  if (std::min({a,b,c}) == 0){
    std::cout << (a/3) + (b/3) + (c/3);
    return 0;
  }

  if (a>3){
    f += (a-1)/3;
    a = a%3;
    if (a==0)
      a = 3;
  }
  if (b>3){
    f += (b-1)/3;
    b = b%3;
    if (b==0)
      b = 3;
  }
  if (c>3){
    f += (c-1)/3;
    c = c%3;
    if (c==0)
      c = 3;
  }

  if (a == 3 && b == 3 && c == 3){
    a=b=c=0;
    f += 3;
  }

  if (std::min({a,b,c}) == 1 && a+b+c == 7){
    a=b=c=0;
    f += 2;
  }

  if (std::min({a,b,c}) == 2){
    a=b=c=0;
    f += 2;
  }

  if (std::min({a,b,c}) == 1 && a+b+c <= 6){
    a=b=c=0;
    f += 1;
  }

  std::cout << f;
}
