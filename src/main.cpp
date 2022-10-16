#include <iostream>
#include <iomanip>
#include <cstdlib>

int main(int argc, char* argv[])
{
    // Force the user to quote the input.
    // @todo Allow unquoted/mixed input, which requires concatenation before parsing.
    if (argc != 2)
    {
        std::cout << "Usage: " << argv[0] << " \"quoted sentence\"" << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
