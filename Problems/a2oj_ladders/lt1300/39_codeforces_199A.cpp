#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
#include <tuple>


//gets nth fibbonacci number
int fibs[1000000];
int Fib(int n){
  if (n==0)
    return 0;
  if (n==1)
    return 1;
  if (fibs[n] == 0)
    fibs[n] = Fib(n-1) + Fib(n-2);
  return fibs[n];
}

class fibNum{
  private:
    int a,b,c;
    void decompose(int n){
      int i=0;
      while (Fib(i) <= n)
        ++i;
      a = Fib(i-1);
      n -= a;
      i=0;
      while (Fib(i) <= n)
        ++i;
      b = Fib(i-1);
      n -= b;
      i=0;
      while (Fib(i) <= n)
        ++i;
      c = Fib(i-1);
    }
  public:
    fibNum(int n){
      decompose(n);
    }
    std::tuple<int,int,int> getTriple(){
      return std::make_tuple(a,b,c);
    }
};

int main(){
  int n;
  std::cin >> n;
  fibNum soln(n);
  auto t = soln.getTriple();
  std::cout << std::get<0>(t) << " " << std::get<1>(t) << " "  << std::get<2>(t);
}

