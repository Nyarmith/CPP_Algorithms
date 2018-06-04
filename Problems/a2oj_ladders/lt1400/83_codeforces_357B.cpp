#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#define ll long long

int actors[100001];

int main(){
  ll n,m;
  ll a,b,c;
  std::cin >> n >> m;
  for (int i=0; i<m; ++i){
    bool left[3] = {true,true,true};
    int taken[3] = {0, 0, 0};
    std::cin >> a >> b >> c;
    if (actors[a]){
      taken[0] = actors[a];
      left[actors[a]-1] = false;
    }
    if (actors[b]){
      taken[1] = actors[b];
      left[actors[b]-1] = false;
    }
    if (actors[c]){
      taken[2] = actors[c];
      left[actors[c]-1] = false;
    }
    if (taken[0] == 0){
      int j=0;
      while (left[j] == false) ++j;
      left[j] = false;
      actors[a] = j+1;
      taken[0] = j+1;
    }
    if (taken[1] == 0){
      int j=0;
      while (left[j] == false) ++j;
      left[j] = false;
      actors[b] = j+1;
      taken[1] = j+1;
    }
    if (taken[2] == 0){
      int j=0;
      while (left[j] == false) ++j;
      left[j] = false;
      actors[c] = j+1;
      taken[2] = j+1;
    }
  }

  for (int i=1; i<=n; ++i){
    std::cout << actors[i] << " ";
  }
}

