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
#include <bitset>
#include <cmath>
#define ll long long

//milk tea
//we're going to customize (either-or mixing of options) some milk tea
//the customer's preferences are a binary string

//here we seem to have 4 options, e.g. the string
//1100 = "With Ice, With Cream, No Bubbles, No Sugar"

//A given shop offers P binary options

//Each person has a bunch of preferences, so we will aggregate them into one request somehow

//For each friend, for every unsatisfied preference, you get an additional complaint

//Furthermore, M item types are forbidden

//Given a bunch of requests, what is the minimum number of complaints we can get?


//let's just brute force this for the simple solution
bool g_forbiddenTea[1024];
ll g_friendpref[10];


uint16_t getFriendScore(uint16_t num, uint16_t p, uint16_t friendNum)
{
  uint16_t ret=0;
  uint16_t bit=0;
  uint16_t one=1;
  while(bit < p){
    if(num & one)
      ret += (friendNum - g_friendpref[bit]);
    else
      ret += g_friendpref[bit];

    ++bit;
    num>>=1;
  }
  return ret;
}

ll minWhine(ll n, ll p){
  uint16_t minwhine=101;

  for (uint16_t i=0; i<(1u<<p); ++i)
  {
    uint16_t fs = getFriendScore(i,p,n);
    if ( fs < minwhine && !g_forbiddenTea[i])
    {
      minwhine =  fs;
    }
  }

  return minwhine;
}


int main(){
  ll T;
  std::vector<ll> results;
  std::string tmp;
  std::cin >> T;

  ll N, M, P;
  for (ll i = 0; i < T; ++i)
  {
    std::cin >> N >> M >> P;
    for (ll k = 0; k < P; ++k){
      g_friendpref[k] = 0;
    }
    for (ll j = 0; j < N; ++j)
    {
      std::cin >> tmp;
      for (ll k = 0; k < P; ++k){
        g_friendpref[k] += (tmp[k]=='1');
      }
    }

    for (ll j = 0; j < M; ++j)
    {
      std::cin >> tmp;
      tmp = std::string(tmp.rbegin(), tmp.rend());
      g_forbiddenTea[std::stoi(tmp,nullptr,2)] = true;
    }

    results.push_back(minWhine(N,P));
    std::fill(g_forbiddenTea, g_forbiddenTea+(1u<<P),false);
  }

  for (size_t i=0; i<results.size(); ++i)
  {
    std::cout << "Case #" << (i+1) << ": " << results[i] << "\n";
  }
}

