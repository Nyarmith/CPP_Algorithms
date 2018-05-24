#include <cstdio>
#include <cstdint>
#include <vector>
#include <set>

bool set[100001];
int nums[100001];
int uniq[100001];
int main(){
  int n,m;
  std::scanf("%i %i", &n, &m);
  for (int i=0; i<n; ++i){
    std::scanf("%i", nums+i);
  }
  //now accumulate uniques
  int uniqs=0;
  for (int i=n-1; i>=0; --i){
    if (!set[nums[i]]){
      set[nums[i]] = true;
      ++uniqs;
    }
    uniq[i] = uniqs;
  }
  int tmp;
  for (int i=0; i<m; ++i){
    std::scanf("%i", &tmp);
    std::printf("%i\n", uniq[tmp-1]);
  }
}
