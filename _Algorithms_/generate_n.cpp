#include <iostream>
#include <iterator>
#include <sstream>
#include <string>

template <class outputIt, class size, class fun>
void generate_n (outputIt first, size n, fun f)
{
    while (n>0)
    {
        *first = f();
        ++first;
        --n;
    }
}

std::string generate(size_t n, std::string const& str)
{
    std::ostringstream ost;
    generate_n(std::ostream_iterator<std::string>{ ost }, n, [&str] { return str; });
    return ost.str();
}
int main(int argc, char* argv[])
{
    size_t n; 
    std::string str;
    for (n, str; std::cin >> n >> str;)
    {
        std::cout << generate (n, str) << "\n";
    }
}
