#include "GetWeatherCityIntent.hpp"

std::string GetWeatherCityIntent::describe() const
{
    return GetWeatherIntent::describe() + " City";
}

void GetWeatherCityIntent::getMatchedKeywordTypes(std::vector<KeywordType>& result) const
{
    GetWeatherIntent::getMatchedKeywordTypes(result);
    result.push_back(KeywordType::City);
}

std::unique_ptr<Intent> GetWeatherCityIntent::clone() const
{
    return std::unique_ptr<Intent>(new GetWeatherCityIntent(*this));
}
