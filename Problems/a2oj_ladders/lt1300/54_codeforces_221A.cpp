#include <string>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iterator>

void f(int x, std::vector<int> &v){
  if (x<=1)
    return;
  std::swap(v[x-1],v[x-2]);
  f(x-1,v);
}

int main(){
  int n;
  std::cin >> n;
  std::vector<int> seq(n);
  std::iota(std::begin(seq),std::end(seq),1);
  f(n,seq);
  std::copy(std::begin(seq),std::end(seq),
      std::ostream_iterator<int>(std::cout," "));
}
