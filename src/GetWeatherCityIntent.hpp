#pragma once

#include "GetWeatherIntent.hpp"
#include "KeywordType.hpp"

/**
 * @brief An intent for getting weather information for a city.
 *
 * @todo Depending on what the Intent classes are supposed to be used for,
 *       this kind of intent would need knowledge of the keyword in addition
 *       to the keyword type.
 */
class GetWeatherCityIntent : public GetWeatherIntent
{
public:
    ~GetWeatherCityIntent() = default;

    virtual void getMatchedKeywordTypes(std::vector<KeywordType>& result) const override;
    virtual std::string describe() const override;
    virtual std::unique_ptr<Intent> clone() const override;
};
