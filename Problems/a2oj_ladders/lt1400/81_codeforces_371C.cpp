#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <cstdio>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <set>
#include <map>
#include <utility>
#include <queue>
#define ll long long
using std::cin;
using std::cout;

int main(){
  std::string in;
  ll nb, ns, nc;
  ll pb, ps, pc;
  ll r;
  std::cin >> in;
  cin >> nb >> ns >> nc;
  cin >> pb >> ps >> pc;
  cin >> r;

  ll rb=0, rs=0, rc=0;
  for (int i=0; i<in.length(); ++i){
    switch (in[i]){
      case 'B':
        ++rb;
        break;
      case 'S':
        ++rs;
        break;
      case 'C':
        ++rc;
        break;
    }
  }

  ll swPrice = rb*pb + rs*ps + rc*pc;
  ll numBurg = 0;

  if (rb == 0){
    nb=0;
  }
  if (rs == 0){
    ns=0;
  }
  if (rc == 0){
    nc=0;
  }

  while ( (nb > 0 || ns > 0 || nc > 0) ){
    ll sp = r;
    if (nb < rb && r >= pb){
      r -= pb;
      ++nb;
    }
    if (ns < rs && r >= ps){
      r -= ps;
      ++ns;
    }
    if (nc < rc && r >= pc){
      r -= pc;
      ++nc;
    }
    if (nb >= rb && ns >= rs && nc >= rc ){
      ++numBurg;
      nb -= rb;
      ns -= rs;
      nc -= rc;
    } else if (sp == r)
      break;
  }

  // no ingredients left
  numBurg += r / swPrice;

  std::cout << numBurg;
}
