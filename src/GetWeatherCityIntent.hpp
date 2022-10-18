#pragma once

#include "GetWeatherIntent.hpp"
#include "KeywordType.hpp"

/**
 * @brief An intent for getting weather information for a city.
 */
class GetWeatherCityIntent : public GetWeatherIntent
{
public:
    ~GetWeatherCityIntent() = default;

    virtual void getMatchedKeywordTypes(std::vector<KeywordType>& result) const override;
    virtual std::string describe() const override;
    virtual std::unique_ptr<Intent> clone() const override;
};
