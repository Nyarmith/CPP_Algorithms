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

template <typename T>
bool SameSign(T x, T y){
  return (x >= 0) ^ (y < 0);
}

int main(){
  std::map<ll,std::vector<ll>> SCs;
  
  ll n,a,b,c,dir;
  bool intersection = false;  //boolean state
  ll max=2000000000,min=-2000000000;

  std::cin >> n;

  //we know there are no intersections for n <= 3
  if (n <= 3){
    for (int i=0; i<n; ++i) std::cin >> a;
    std::cout << "no";
    return 0;
  }

  //creating a base-case
  std::cin >> a >> b;
  SCs[a].push_back(b);
  SCs[b].push_back(a);

  for (int i=2; i<n; ++i){
    std::cin >> c; //get the next point
    if (intersection)
      continue;

    if (c < min || c > max){
      intersection = true;
    }
    //same direction?
    if (SameSign(a-b,b-c)){
      SCs[c].push_back(b);
      SCs[b].push_back(c);
    } else {
      //am I going over?
      bool over=false;
      if (c-b > 0){
        if (c > SCs.rbegin()->first){
          over=true;
          SCs[b].push_back(c);
          SCs[c].push_back(b);
        }
      } else if (c-b < 0){
        if (c < SCs.begin()->first){
          over=true;
          SCs[b].push_back(c);
          SCs[c].push_back(b);
        }
      }
      //am I going inside a semicircle?
      if (!over){
        //find the smallest bounds that cover us
        if (c-b > 0){
          ll bound = 2000000000;
          for (ll snd : SCs[b]){
            if (snd > c && snd < bound)
              bound = snd;
          }
          min = b; max=bound;
        } else {
          ll bound = -2000000000;
          for (ll snd : SCs[b]){
            if (snd < c && snd > bound)
              bound = snd;
          }
          max = b; min=bound;
        }
      }
      
    }

    //have I passed through any intersections?
    auto it = SCs.find(b);
    if (c-b > 0){ //moving right
      ++it;
      while (it->first < c){
        for (ll snd : it->second){
          if (snd > c || snd < b)
            intersection = true;
        }
        ++it;
      }
    }
    if (c-b < 0){ //moving left
      --it;
      while (it->first > c){
        for (ll snd : it->second){
          if (snd < c || snd > b)
            intersection = true;
        }
        --it;
      }
    }
    
    a = b;
    b = c;
  }

  if (intersection){
    std::cout << "yes";
  } else {
    std::cout << "no";
  }
}

