#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <cstdio>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <set>
#include <map>
#include <utility>
#include <queue>
#define ll long long

class vec
{
private:
    int x{0},y{0},z{0};
public:
    vec() {}
    vec(int x, int y, int z) : x(x),y(y),z(z) {}
    vec(const vec &o) : vec(o.x,o.y,o.z) {}
    vec operator +(const vec &o) const
    { return {x+o.x,y+o.y,z+o.y}; }
    vec& operator +=(const vec &o)
    { x+=o.x,o; y+=o.y; z+=o.z;
      return *this; }
    int X() const { return x; }
    int Y() const { return y; }
    int Z() const { return z; }
    friend std::istream& operator>>(std::istream&,vec&);
};

std::ostream& operator<<(std::ostream &os, const vec &v)
{
    if (v.X() == 0 && v.Y() == 0 && v.Z() == 0)
        os << "YES\n";
    else
        os << "NO\n";
    return os;
}

std::istream& operator>>(std::istream &is, vec &v)
{
    std::cin >> v.x >> v.y >> v.z;
    return is;
}


int main()
{
    using namespace std;

    int n;
    vec v,t;

    cin >> n;
    for (int i=0; i<n; ++i)
    {
        cin >> t;
        v += t;
    }
    std::cout << v;
    return 0;
}
