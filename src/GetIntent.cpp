#include "GetIntent.hpp"

std::string GetIntent::describe() const
{
    return "Get";
}

void GetIntent::getMatchedKeywordTypes(std::vector<KeywordType>& result) const
{
    result.push_back(KeywordType::Interrogative);
}
