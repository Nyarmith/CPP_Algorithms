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

struct Ratio{
  ll num, den; //numerator, denominator, respectively
  Ratio(ll num, ll den) : num(num), den(den)
  {
    //use gcd to simplify num and denom
  }

  bool operator==(const Ratio& o)
  {
    return num == o.num && den == o.den;
  }

  Ratio operator-(const Ratio& o)
  {
    ll t_num, t_denom;
    if (den != o.den){
      //do some gcd
    }
    return Ratio{t_num, t_denom};
  }

  Ratio operator+(const Ratio& o)
  {
    ll t_num, t_denom;
    if (den != o.den){
      //do some gcd
    }
    return Ratio{t_num, t_denom};
  }
};

//I haven't actually interfaced the problem though; that's the real challenge

int main(){
  ll a,b, // ratio 1
     c,d; // ratio 2
  //goal: calculate ratio of empty screen to the total screen size
  std::cin >> a >> b
           >> c >> d;


}

