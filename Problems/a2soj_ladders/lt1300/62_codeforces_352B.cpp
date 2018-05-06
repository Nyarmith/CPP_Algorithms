#include <cstdio>
#include <cstdint>
#include <map>

//this is a good example of a simple problem runed by not using proper abstractions. Just enough nuance mixed with simplicify to fool you into complacency. Always take setting up abstractions clearly and professionally!


//column 1 = prev indices, 2 = cycle len
int arrc[100001] = {0};
int arrx[100001] = {0};

int main(){
  int n,c;
  int uniq_bois=0;
  std::scanf("%u",&n);
  for (int i=0; i<n; ++i){
    std::scanf("%d", &c);
    if (arrc[c] == 0 && arrx[c] == 0) {
      arrc[c] = -1;
      arrx[c] = i;
      uniq_bois++;
    }
    else if (arrc[c] == -1){  //totally ignore this guy after this step
      arrc[c] = i-arrx[c];
      arrx[c] = i;
    } else if (arrc[c] > 0){
      if (arrc[c] != i-arrx[c]){
        arrc[c] = -2;
        --uniq_bois;
      }
        arrx[c] = i;
    }
  }

  //print out answers
  std::printf("%i\n", uniq_bois);
  if (uniq_bois > 0){
  for (int i=0; i<=100000; ++i){
    if (arrc[i] == -1) {
      std::printf("%d 0\n",i);
    } else if (arrc[i] > 0) {
      std::printf("%d %d\n",i, arrc[i]);
    }
  }
  }
}
