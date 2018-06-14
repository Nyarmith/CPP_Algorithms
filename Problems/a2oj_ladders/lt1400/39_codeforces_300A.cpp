#include <vector>
#include <iterator>
#include <iostream>

int main(){
  std::vector<int> s1, s2, s3;
  std::vector<int> arr;
  int n, tmp, negsnum=0;
  std::cin >> n;

  for (int i=0; i<n; ++i){
    std::cin >> tmp;
    arr.push_back(tmp);
    negsnum += (tmp < 0);
  }

  if (negsnum >= 3){ //put two negatives in middle set, one in top set
    int sat=0;
    for (int i=0; i<n; ++i){
      if (arr[i] < 0){
        switch(sat){
          case 0:
            s1.push_back(arr[i]);
            ++sat;
            break;
          case 1:
            s2.push_back(arr[i]);
            ++sat;
            break;
          case 2:
            s2.push_back(arr[i]);
            ++sat;
            break;
          default:
            s3.push_back(arr[i]);
            break;
        }
      }else if (arr[i] == 0){
        s3.push_back(0);
      } else {
        s2.push_back(arr[i]);
      }
    }
  } else { //put one negative in top set, rest in bottom set
    int sat=0;
    for (int i=0; i<n; ++i){
      if (arr[i] < 0 ){
        switch(sat){
          case 0:
            s1.push_back(arr[i]);
            ++sat;
            break;
          default:
            s3.push_back(arr[i]);
            break;
        } 
      }else if (arr[i] == 0){
        s3.push_back(arr[i]);
      } else {
        s2.push_back(arr[i]);
      }
    }
  }

  std::cout << s1.size() << " ";
  std::copy(s1.begin(), s1.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << "\n";

  std::cout << s2.size() << " ";
  std::copy(s2.begin(), s2.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << "\n";

  std::cout << s3.size() << " ";
  std::copy(s3.begin(), s3.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << "\n";
}
