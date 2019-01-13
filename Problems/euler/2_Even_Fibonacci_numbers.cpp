#include <iostream>
#include <cmath>

//using closed-form like a boss

double p_phi = (1.0 + std::sqrt(5.0))/2.0;
double n_phi = (1.0 - std::sqrt(5.0))/2.0;
double sqrt5 = std::sqrt(5.0);

using ull = unsigned long long;

ull getFib(ull n)
{
  return std::round( (std::pow(p_phi,n) - std::pow(n_phi,n)) / sqrt5 );
}

int main()
{
  const ull limit=4000000;
  ull i=3;
  ull sum=0;
  ull fibTerm=0;
  while ((fibTerm=getFib(i)) < limit)
  {
    if (i != 3) std::cout << ", ";
    std::cout << fibTerm;
    sum += fibTerm;
    i += 3;
  }
  std::cout <<  std::endl << sum << std::endl;
}
