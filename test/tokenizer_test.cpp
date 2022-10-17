#include <gtest/gtest.h>
#include "tokenizer.hpp"

TEST(TokenizerTest, EmptyString)
{
    std::string input{""};
    std::vector<std::string> result;
    tokenizer::tokenize(input, result);
    EXPECT_EQ(0, result.size());
}

TEST(TokenizerTest, SimpleTokens)
{
    std::string input{"one two three"};
    std::vector<std::string> result;
    tokenizer::tokenize(input, result);
    EXPECT_EQ(3,       result.size());
    EXPECT_EQ("one",   result[0]);
    EXPECT_EQ("two",   result[1]);
    EXPECT_EQ("three", result[2]);
}

TEST(TokenizerTest, Whitespace)
{
    std::string input{"  four     five   "};
    std::vector<std::string> result;
    tokenizer::tokenize(input, result);
    EXPECT_EQ(2,      result.size());
    EXPECT_EQ("four", result[0]);
    EXPECT_EQ("five", result[1]);
}

TEST(TokenizerTest, Punctuation)
{
    std::string input{"...six, seven?? eight!"};
    std::vector<std::string> result;
    tokenizer::tokenize(input, result);
    EXPECT_EQ(3,       result.size());
    EXPECT_EQ("six",   result[0]);
    EXPECT_EQ("seven", result[1]);
    EXPECT_EQ("eight", result[2]);
}
