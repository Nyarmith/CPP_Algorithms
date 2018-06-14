#include <vector>
#include <iostream>

int main(){
  int n,m;
  std::cin >> n >> m;
  std::vector<bool> c(n,true);
  for (int i=0; i<m; ++i){
    int a,b;
 std::cin >> a >> b;
 c[a-1] = false;
 c[b-1] = false;
  }
  int i=0;
  while(!c[i]) ++i;
  //this implementation is probably wrong
  std::cout << (n-1) << "\n";
  for (int j=0;j<n; ++j){
    if (i != j){
   std::cout << i+1 << " " << j+1 << "\n";
 }
  }
}
//lol wtf it worked??
