#pragma once

#include <string>
#include <vector>

typedef std::vector<std::string> stringvec;

namespace tokenizer
{

/**
 * @brief Splits a string into tokens.
 * 
 * @param[in] input The input string to be tokenized.
 * @param[out] result The tokens are added to the end of this vector.
 */
void tokenize(const std::string& in, stringvec& result);
}
