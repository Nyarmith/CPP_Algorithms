#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
int main(){
  ll n,k;
  ll j,t,joy;
  ll maxJoy = -1000000000;
  std::cin >> n >> k;
  for (int i=0; i<n; ++i){
    std::cin >> j >> t;
    joy = j + (t > k ? k - t : 0);
    if (joy > maxJoy)
      maxJoy = joy;
  }
  std::cout << maxJoy;
}
