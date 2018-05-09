#include <cstdio>
#include <cstdint>
#include <cinttypes>
#include <map>

std::map<uint64_t, std::map<uint64_t,uint64_t> > memoizeTable;

uint64_t binom(uint64_t n, uint64_t k){
  if (k == 0 || n == k)
    return 1;
  if (memoizeTable[k].count(n) != 0)
    return memoizeTable[k][n];
  memoizeTable[k][n] = binom(n-1,k) + binom(n-1,k-1);
  return memoizeTable[k][n];
}

int main(){
  uint32_t n;
  int c;
  std::map<int,uint64_t> diffs;
  std::scanf("%u", &n);

  for (uint32_t i=0; i<n; ++i){
    std::scanf("%i", &c);
    diffs[c]++;  //assume this does what you want
  }

  auto smallest =  diffs.begin();
  auto biggest =  diffs.rbegin();

  uint64_t diff = biggest->first - smallest->first;
  uint64_t combos = 0;

  if (diff == 0){
    combos = binom(n,2);
  }
  else {
    combos = biggest->second * smallest->second;
  }

  std::printf("%" PRIu64 " %" PRIu64 , diff, combos);
}
