#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>

std::map<std::pair<int64_t,int64_t>,int64_t> memo;

int64_t maxPick(std::vector<int64_t>& p, int64_t m, int64_t k, int64_t l){
  if (k == 0 || (int)p.size()-l < m)
    return 0;

  std::pair<int64_t,int64_t> key = std::make_pair(k,l);
  int64_t maxSum=0;
  if (memo.find(key) == memo.end()){

    for (uint32_t i=l; i<p.size()-k*m+1; ++i){
      int64_t thisSum=0;
      for(uint32_t j=0; j<m; ++j){
        thisSum += p[i+j];
      }
      thisSum += maxPick(p,m,k-1,i+m);
      if (thisSum > maxSum)
        maxSum = thisSum;
    }
    memo[key]=maxSum;
  }

  return memo[key];
}

int main(){
  std::vector<int64_t> p;
  int64_t n,m,k,tmp;
  std::cin >> n >> m >> k;
  p.reserve(n);
  memo.reserve(n);
  for (int64_t i=0; i<n; ++i){
    std::cin >> tmp;
    p.push_back(tmp);
  }

  int64_t max = maxPick(p,m,k,0);

  std::cout << max;
}
