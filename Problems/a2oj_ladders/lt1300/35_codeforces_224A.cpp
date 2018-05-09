#include <cstdio>
#include <cstdint>
#include <cinttypes>
#include <cmath>

int main(){
  uint64_t a1, a2, a3, l1, l2, l3;
  std::scanf("%" PRIu64 " %" PRIu64 " %" PRIu64,
      &a1, &a2, &a3);
  l1 = sqrt(a1*a3/a2);
  l2 = sqrt(a1*a2/a3);
  l3 = sqrt(a3*a2/a1);

  std::printf("%" PRIu64, (l1*4 + l2*4 + l3*4));
}
