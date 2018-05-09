#include <cstdio>
#include <cstdint>
#include <vector>

//int arr[100];
//
//void swap(int i, int j){
//  int k = arr[i];
//  arr[i] = arr[j];
//  arr[j] = k;
//}

/*  Not actually the right problem, lol
int bubbleSortCount(int n){
  int cnt=0;
  bool unsorted=true;
  while(unsorted){
    unsorted=false;
    int i=0;
    while (i<n-1){
      if (arr[i] < arr[i+1]){
        swap(i,i+1);
        ++cnt;
        unsorted=true;
        ++i;
      }
      ++i;
    }
  }
  return cnt;
}
*/

int main(){
  uint32_t n;
  std::scanf("%u", &n);

  int largest =-1,   li=-1;
  int smallest=9999, si=-1;

  int c;
  for (uint32_t i=0; i<n; ++i){
    std::scanf("%i", &c);
    if (c > largest){
      li = i;
      largest = c;
    }

    if (c <= smallest){
      si = i;
      smallest = c;
    }
  }

  if (li > si)
    std::printf("%i", (li-1 + (n-(si+1))));
  else
    std::printf("%i", (li + (n-(si+1))));
}
