#include <cstdio>
#include <iostream>
#include <cstdint>
#include <string>
#include <vector>
#include <algorithm>

int main(){
  int n, m, tmp;
  std::vector<int> slv;
  std::vector<int> was;
  std::scanf("%i %i", &n, &m);
  slv.reserve(n);
  was.reserve(m);
  for(int i=0; i<n; ++i){
    std::scanf("%i", &tmp);
    slv.push_back(tmp);
  }

  for(int i=0; i<m; ++i){
    std::scanf("%i", &tmp);
    was.push_back(tmp);
  }

  int min = *std::min_element(slv.begin(), slv.end());
  int max = *std::max_element(slv.begin(), slv.end());
  int minWA = *std::min_element(was.begin(), was.end());
  if (max >= minWA || min*2 >= minWA){
    std::cout << -1;
    return 0;
  }

  std::cout << std::max(min*2,max);
}
