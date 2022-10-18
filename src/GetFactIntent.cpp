#include "GetFactIntent.hpp"

std::string GetFactIntent::describe() const
{
    return GetIntent::describe() + " Fact";
}

void GetFactIntent::getMatchedKeywordTypes(std::vector<KeywordType>& result) const
{
    GetIntent::getMatchedKeywordTypes(result);
    result.push_back(KeywordType::Fact);
}

std::unique_ptr<Intent> GetFactIntent::clone() const
{
    return std::unique_ptr<Intent>(new GetFactIntent(*this));
}
