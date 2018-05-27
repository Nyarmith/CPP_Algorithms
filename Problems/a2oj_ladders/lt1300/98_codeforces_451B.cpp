#include <cstdio>
#include <cstdint>
#include <iostream>
#include <string>

int arr[100000];

int main(){
  int n;
  std::cin >> n;
  int l,r;
  bool isValid=true;
  for (int i=0; i<n; ++i){
    std::cin >> arr[i];
  }

  int i=1;
  while(i<n && arr[i-1] < arr[i]){
    ++i;
  }

  if (i == n){ //special case
    std::cout << "yes\n1 1";
    return 0;
  }

  l=i-1;
  if (i==1){ //special case
    l=0;
  }

  while(i<n && arr[i-1] > arr[i])
    ++i;

  r=i-1;

  while(i<n && arr[i-1] < arr[i]){
    ++i;
  }

  //check validity
  int fst;
  if (l == 0){
    fst = arr[r];
  } else {
    fst = arr[0];
    for (int i=1; i<l; ++i){
      if (fst > arr[i])
        isValid  = false;
      fst = arr[i];
    }
  }

    for (int i=r; i>=l; --i){
      if (fst > arr[i])
        isValid  = false;
      fst = arr[i];
    }

  for (int i=r+1; i<n; ++i){
    if (fst > arr[i])
      isValid  = false;
    fst = arr[i];
  }

  if (i != n || !isValid)
    std::cout << "no";
  else
    std::cout << "yes\n" << l+1 << " " << r+1;
}
