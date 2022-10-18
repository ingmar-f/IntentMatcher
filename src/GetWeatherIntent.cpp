#include "GetWeatherIntent.hpp"

std::string GetWeatherIntent::describe() const
{
    return GetIntent::describe() + " Weather";
}

void GetWeatherIntent::getMatchedKeywordTypes(std::vector<KeywordType>& result) const
{
    GetIntent::getMatchedKeywordTypes(result);
    result.push_back(KeywordType::Weather);
}

std::unique_ptr<Intent> GetWeatherIntent::clone() const
{
    return std::unique_ptr<Intent>(new GetWeatherIntent(*this));
}
