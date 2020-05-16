#include <iostream>
#include <cstdint>

int main()
{
    std::string p;
    p.reserve(100);
    std::cin >> p;

    int acc{0};
    bool print{false};

    for (const char &c : p)
    {
        switch(c)
        {
            case 'H':
            case 'Q':
            case '9':
                print = true;
                break;
            case '+':
                ++acc;
                break;
        }
        if (print) break;
    }

    std::cout << (print ? "YES" : "NO") << "\n";
    return 0;
}
