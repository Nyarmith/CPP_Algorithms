#include <vector>
#include <iostream>

int arr[101][101];

void print0s(int n, bool extraSpace=false){
  if (n<=0)
    return;
  for (int i=0; i<n-1; ++i){
    std::cout << "0 ";
  }
  std::cout << "0";
  if (extraSpace)
    std::cout << " ";
};
int main(){
  int n,k;
  std::cin >> n >> k;
  if (n==1){
    std::cout << k;
    return 0;
  }
  for (int i=0; i<n-1; ++i){
    print0s(i, true);
    std::cout << 1 << " " << k-1 << " ";
    print0s(n-i-2);
    std::cout << "\n";
  }
  std::cout << k-1 << " ";
  print0s(n-2, true);
  std::cout << 1;
}
