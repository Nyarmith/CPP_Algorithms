#include <iostream>
#include <string>
#include <vector>
#include <cstdio>


int main()
{
    uint64_t T;
    std::string input;
    std::string out1, out2;
    
    out1.reserve(100);
    out2.reserve(100);
    std::cin >> T;
    char a{};
    char b{};
    
    for (int t = 0; t < T; ++t)
    {
        std::cin >> input;
        out1 = "";
        out2 = "";
        for (char &ch : input)
        {
            switch (ch)
            {
                case '0':
                    a = '0';
                    b = '0';
                    break;
                case '1':
                    a = '1';
                    b = '0';
                    break;
                case '2':
                    a = '1';
                    b = '1';
                    break;
                case '3':
                    a = '1';
                    b = '2';
                    break;
                case '4':
                    a = '1';
                    b = '3';
                    break;
                case '5':
                    a = '2';
                    b = '3';
                    break;
                case '6':
                    a = '1';
                    b = '5';
                    break;
                case '7':
                    a = '1';
                    b = '6';
                    break;
                case '8':
                    a = '1';
                    b = '7';
                    break;
                case '9':
                    a = '1';
                    b = '8';
                    break;
            }
            out1 += a;
            out2 += b;
        }
        
        while (*out1.begin() == '0')
            out1.erase(out1.begin());
            
        while (*out2.begin() == '0')
            out2.erase(out2.begin());
        
        std::cout << "Case #" << (t+1) << ": "
            << out1 << " " << out2 << "\n";
    }
}
