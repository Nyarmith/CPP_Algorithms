#include <iostream>
#include <cstdio>
#include <cstdint>
#include <string>
#include <algorithm>

int arr[101];
int main(){
  int n;
  std::cin >> n;
  for(int i=0;i<n;++i){
    std::cin >> arr[i];
  }
  std::sort(arr,arr+n);
  std::cout << arr[n-1] << " ";
  for (int i=1;i<n-1;++i){
    std::cout <<arr[i] << " ";
  }
  std::cout << arr[0];
}
