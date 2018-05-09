//Problem-Name: Even Odds
// given n, k, you have to pick the kth number from 1,3,5,...,n & 2,4,6,...,n-1  (assuming n is odd)

#include <cstdio>
#include <cstdint>
#include <cinttypes>

const char* fmtStr = "%" PRIu64 " %" PRIu64;

using std::uint64_t;

int main(){
  uint64_t n, k;
  std::scanf(fmtStr, &n, &k);

  uint64_t oddsetSize = n/2 + n%2;

  if (k <= oddsetSize){
    std::printf("%" PRIu64, 2*k-1);
    return 0;
  }

  std::printf("%" PRIu64, 2*(k-oddsetSize));
}
