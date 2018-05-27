#include <iostream>
#include <cstdio>
#include <string>
#include <cstdint>
#include <algorithm>
#include <numeric>

bool canOpen[1000]={false};
int  bottles[1000]={0};
int  singlos[1000]={0};
int main(){
  int n;
  int a,b;
  std::cin >> n;
  for (int i=0; i<n; ++i){
    std::cin >> a >> b;
    ++bottles[a-1];
    if (!canOpen[b-1] && a != b){
      canOpen[b-1] = true;
    } else if (!canOpen[b-1] && a==b && !singlos[b-1]) {
        singlos[b-1] = true;
    } else if(a==b && singlos[b-1]){
        singlos[b-1] = false;
        canOpen[b-1] = true;
    }
  }

  int opened=0;
  for (int i=0; i<1000; ++i){
    if (canOpen[i])
        opened += bottles[i];
    else if (singlos[i]){
        opened += bottles[i]-1;
    }
  }

  std::cout << (n - opened);
}
