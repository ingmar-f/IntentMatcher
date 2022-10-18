#pragma once

#include <memory>
#include <vector>
#include "IntentWrapper.hpp"

class IntentFactory
{
public:
    IntentFactory();

    intent_uptr getMatchingIntent(const std::vector<KeywordType>& keywordTypes) const;

private:
    std::vector<std::unique_ptr<IntentWrapper>> wrappers; 
};
