#include <algorithm>
#include "IntentFactory.hpp"
#include "GetWeatherIntent.hpp"

IntentFactory::IntentFactory()
{
    wrappers.push_back(std::make_unique<IntentWrapper>(std::make_unique<GetWeatherIntent>()));
}

intent_uptr IntentFactory::getMatchingIntent(const std::vector<KeywordType>& keywordTypes) const
{
    if (keywordTypes.empty())
        return nullptr;

    // Try each registered wrapper.
    for (auto&& wrapper : wrappers)
    {
        std::vector<KeywordType> cmptypes;
        wrapper->getMatchedKeywordTypes(cmptypes);

        bool found = true;
        for (auto kwtype : keywordTypes)
        {
            if (std::find(cmptypes.begin(), cmptypes.end(), kwtype) == std::end(cmptypes))
            {
                found = false;
                break;
            }
        }
        if (found)
            return wrapper->createIntent();
    }
    return nullptr;
}
