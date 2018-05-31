#include <iostream>
#include <cstdio>
#include <string>

int arr[100000];
int main(){
  int n;
  std::scanf("%i", &n);
  for (int i=0; i<n; ++i){
    std::scanf("%i", arr+i);
  }
  int maxLen=2;
  int curLen=2;
  int i=2;
  while (i<n){
    if (arr[i-2]+arr[i-1]==arr[i]){
      ++curLen;
    } else {
      if (curLen > maxLen)
        maxLen = curLen;
      curLen=2;
    }
    ++i;
  }
  if (curLen > maxLen)
    maxLen = curLen;
  if (n < maxLen)
    maxLen = n;
  std::printf("%i\n", maxLen);
}
