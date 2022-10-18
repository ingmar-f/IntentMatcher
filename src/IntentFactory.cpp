#include <algorithm>
#include "IntentFactory.hpp"
#include "GetWeatherIntent.hpp"
#include "GetWeatherCityIntent.hpp"
#include "GetFactIntent.hpp"

IntentFactory::IntentFactory()
{
    // Create an object of each known intent. These will be used for matching.
    wrappers.push_back(std::make_unique<IntentWrapper>(std::make_unique<GetWeatherIntent>()));
    wrappers.push_back(std::make_unique<IntentWrapper>(std::make_unique<GetWeatherCityIntent>()));
    wrappers.push_back(std::make_unique<IntentWrapper>(std::make_unique<GetFactIntent>()));
}

intent_uptr IntentFactory::getMatchingIntent(const std::vector<KeywordType>& keywordTypes) const
{
    if (keywordTypes.empty())
        return nullptr;

    // Try each registered wrapper.
    for (auto&& wrapper : wrappers)
    {
        std::vector<KeywordType> cmptypes;

        // @todo Doing this for each wrapper here is not good for performance
        //       in the long term. A better way would be to initialize the
        //       lists once and store them in the wrappers alongside the intents.
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
