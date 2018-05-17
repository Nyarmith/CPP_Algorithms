#include <string>
#include <iostream>
#include <cstdint>

class helloMatcher{
  private:
    std::string hello;
    uint32_t i;
  public:
    helloMatcher(){
      hello="hello";
      i=0;
    }
    void feed(char c){
      if (i < hello.size() && c == hello[i]){
        ++i;
      }
    }
    bool wasMatched(){
      return (hello.size() == i);
    }
};

int main(){
  helloMatcher mt;
  std::string w;
  std::cin >> w;
  for (auto it=w.begin(); it!=w.end(); ++it){
    mt.feed(*it);
  }
  if (mt.wasMatched())
    std::cout << "YES";
  else
    std::cout << "NO";
}
