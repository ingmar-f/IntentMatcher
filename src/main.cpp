#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "tokenizer.hpp"
#include "IntentMatcher.hpp"

int main(int argc, char* argv[])
{
    // Force input as a single string.
    // @todo Allow unquoted/mixed input, which requires concatenation before parsing.
    if (argc != 2)
    {
        std::cout << "Usage: " << argv[0] << " \"quoted sentence\"" << std::endl;
        return EXIT_FAILURE;
    }

    stringvec words;
    tokenizer::tokenize(argv[1], words);

    IntentMatcher matcher(IntentMatcher::InputLanguage::English);
    std::unique_ptr<Intent> intent = matcher.match(words);

    if (intent)
        std::cout << *intent << std::endl;
    else
        std::cout << "no match" << std::endl;

    return EXIT_SUCCESS;
}
