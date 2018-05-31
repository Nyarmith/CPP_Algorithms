#include <vector>
#include <iterator>
#include <iostream>

int main(){
  std::vector<int> s1, s2, s3;
  int n, tmp;
  std::cin >> n;
  for (int i=0; i<n; ++i){
    std::cin >> tmp;
 if (tmp > 0)
   s2.push_back(tmp);
 else if (tmp < 0 && s1.size() == 0)
   s1.push_back(tmp);
 else
   s3.push_back(tmp);
  }
  std::copy(s1.begin(), s1.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << "\n";
  std::copy(s2.begin(), s2.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << "\n";
  std::copy(s3.begin(), s3.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << "\n";
}
