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
#include <thread>

void iofn()
{
    std::cout << "Beauty is only skin-deep\n";
}

int main(){
    std::cout << std::thread::hardware_concurrency() << " threads are supported \n";

    std::thread t1(iofn);
    //t1.join();
    t1.detach(); 
    if (t1.joinable())
        t1.join(); //just running join after detaching breaks
    std::cout << "am here";
    return 0;
}

