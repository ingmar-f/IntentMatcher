#pragma once

#include "Intent.hpp"
#include "KeywordType.hpp"

/**
 * @brief Base class for all intents that obtain some sort of information.
 */
class GetIntent : public Intent
{
public:
    virtual void getMatchedKeywordTypes(std::vector<KeywordType>& result) const override;
    virtual std::string describe() const override;
};
