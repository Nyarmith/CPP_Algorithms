#include <cstdio>
#include <cstdint>
#include <set>

std::set<int> smallprimes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

int main(){
  int n, m;
  std::scanf("%i %i", &n, &m);
  auto it = smallprimes.find(n);
  ++it;
  if (it == smallprimes.end() || *it != m)
    printf("NO");
  else
    printf("YES");
}
