#include <iostream>
#include <cstdio>
#include <cstdint>
#include <map>

#define ll long long


std::map<std::pair<ll,ll>, ll> memo;

ll gcds(ll a, ll b){
  ll ret=2000000000;

  if (a == b)
    return 0;

  if (b>a){
    ll c = a;
    a = b;
    b = c;
  }

  auto key = std::make_pair(b,a);
  auto it = memo.find(key);

  if (it != memo.end())
    return memo[key];

  if (a>b) {
    if (a%5 == 0)
      ret = std::min(ret,gcds(a/5,b));
    if (a%3 == 0)
      ret = std::min(ret,gcds(a/3,b));
    if (a%2 == 0)
      ret = std::min(ret,gcds(a/2,b));
  }

  memo[key] = ret+1;

  return ret+1;
}

int main(){
  ll a,b;
  std::cin >> a >> b;
  ll o = gcds(a,b);
  if (o >= 2000000000)
    o = -1;
  std::cout << o;
}
