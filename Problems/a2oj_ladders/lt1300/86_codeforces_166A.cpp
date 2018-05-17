#include <cstdio>
#include <cstdint>
#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <map>


//todo, try to make a heap do this for you automatically
int main(){
  int n, k, t_in, p_in;
  std::scanf("%i %i",&n,&k);
  for (int i=0; i<n; ++i){
    std::scanf("%i %i", &t_in, &p_in);
    ++teams[t_in].first;
    teams[t_in].second += p_in;
  }
  for (int i=0; i<k; ++i){
  }
}
