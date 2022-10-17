#include "tokenizer.hpp"
#include <algorithm>
#include <iterator>
#include <regex>

namespace tokenizer
{

void tokenize(const std::string& input, stringvec& result)
{
    // Regex to tokenize the input.
    // @todo Fine-tune according to detailed requirements.
    const std::regex re("\\w+");
    std::copy(std::sregex_token_iterator(input.begin(), input.end(), re),
              std::sregex_token_iterator(),
              std::back_inserter(result));
}

} // namespace tokenizer
