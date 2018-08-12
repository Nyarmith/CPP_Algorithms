#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <map>

const int NSIZE = 5000;

//memoization globals
uint64_t memo[NSIZE][NSIZE];
bool     calculated[NSIZE][NSIZE];

uint64_t maxPick(std::vector<uint64_t> &s, int p, int m, int k){

  if (k == 0 || p + k*m > s.size())
    return 0;

  if (calculated[p][k])
    return memo[p][k];

  uint64_t res = std::max( maxPick(s, p+1, m, k),
                    s[p] + maxPick(s, p+m, m, k-1) );

  memo[p][k] = res;
  calculated[p][k] = true;
  return res;
}

int main(){
  std::vector<uint64_t> p;
  std::vector<uint64_t> s;

  uint64_t n,m,k; //params: n - number of elements, m - subarray size, k - # of subarrays to pick
  uint64_t tmp;
  std::cin >> n >> m >> k;
<<<<<<< HEAD
  //we prepare memory in advance
  p.reserve(n); //the elements
  s.reserve(n-m+1); //the number of all possible subarrays
  uint64_t sum=0;

  //populate array
  for (int i=0; i<n; ++i){
=======
  p.reserve(n);
  memo.reserve(n);
  for (int64_t i=0; i<n; ++i){
>>>>>>> c8f7fe16a3ca92f0d40400310c754f4797191529
    std::cin >> tmp;
    p.push_back(tmp);
  }

  //computing the first sum
  int i=0;
  while (i < m)
  {
    sum += p[i];
    ++i;
  }
  s.push_back(sum);

  //computing all other subarray sums
  while (i<n)
  {
    sum += p[i];
    sum -= p[i-m]; //old subarray elem
    ++i;
    s.push_back(sum);
  }

  uint64_t max;

  ////super special case where we just sum the entire set
  if (m == 1 && k == s.size())
    max = std::accumulate(s.begin(), s.end(), static_cast<uint64_t>(0));
  else
    max = maxPick(s,0,m,k);

  std::cout << max;
}

