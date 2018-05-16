#include <cstdio>
#include <iostream>
#include <string>
#include <cstdint>
#include <algorithm>

int main(){
  int n, k, l, c, d, p, nl, np;
  std::scanf("%i %i %i %i %i %i %i %i",
      &n, &k, &l, &c, &d, &p, &nl, &np);
  int lpieces = c*d;
  int drinks = k*l/nl;
  int salts = p/np;
  int toasts = std::min({lpieces/n, drinks/n, salts/n});
  std::printf("%i", toasts);
}
