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


ll gcd(ll a, ll b){
  if (a > b)
    std::swap(a,b);

  if (b%a != 0){
    return gcd(a,b%a);
  } else {
    return a;
  }
}

ll lcm(ll a, ll b){
  return std::abs(a*b)/gcd(a,b);
}

struct Ratio{
  ll num, den; //numerator, denominator, respectively

  Ratio(ll n) : num(n), den(1) {}
  Ratio(ll n, ll d) : num(n), den(d)
  {
    ll m = gcd(num,den);
    num /= m;
    den /= m;
  }

  bool operator==(const Ratio& o) const
  {
    return num == o.num && den == o.den;
  }

  Ratio operator-(const Ratio& o) const
  {
    //do some lcm
    ll l = lcm(den, o.den);
    ll our_num = l*num/den;
    ll their_num = l*o.num/o.den;

    return {our_num - their_num, l};
  }

  Ratio operator*(const Ratio& o) const{
    return {num*o.num, den*o.den};
  }

  Ratio operator/(const Ratio& o) const{
    return {num*o.den, den*o.num};
  }

  Ratio operator+(const Ratio& o) const
  {
    ll l = lcm(den, o.den);
    ll our_num = l*num/den;
    ll their_num = l*o.num/o.den;

    return {our_num + their_num, l};
  }

  bool operator<(const Ratio& o) const {
    //common denominator and all that
    ll common = lcm(den, o.den);
    ll our_num = common*num/den;
    ll their_num = common*o.num/o.den;

    return (our_num < their_num);
  }

  bool operator<=(const Ratio& o) const {
    return (*this < o || *this == o);
  }
};

//I haven't actually interfaced the problem though; that's the real challenge


int main(){
  ll a,b, // ratio 1
     c,d; // ratio 2

  //goal: calculate ratio of empty screen to the total screen size
  std::cin >> a >> b
           >> c >> d;

  Ratio A{a}, B{b}, C{c}, D{d};

  Ratio r1{c,a}, r2{d,b};


  std::string ret = "";
  //try 1
  if (Ratio{a,b} == Ratio{c,d}){
    ret = "0/1";
  } else if (B*r1 <= D){
    Ratio remainder = Ratio{1} - Ratio{(B*r1)/D};
    ret = std::to_string(remainder.num) + "/" + std::to_string(remainder.den);
  } else if (A*r2 <= C){
    Ratio remainder = Ratio{1} - Ratio{(A*r2)/C};
    ret = std::to_string(remainder.num) + "/" + std::to_string(remainder.den);
  }

  std::cout << ret << std::endl;
}

