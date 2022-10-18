#pragma once

#include "GetIntent.hpp"
#include "KeywordType.hpp"

/**
 * @brief An intent for obtaining weather information.
 */
class GetWeatherIntent : public GetIntent
{
public:
    ~GetWeatherIntent() = default;

    virtual void getMatchedKeywordTypes(std::vector<KeywordType>& result) const override;
    virtual std::string describe() const override;
    virtual std::unique_ptr<Intent> clone() const override;
};
