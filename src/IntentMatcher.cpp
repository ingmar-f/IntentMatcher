#include "IntentMatcher.hpp"

void IntentMatcher::init(IntentMatcher::InputLanguage lang)
{
    // @todo Move this to an external file to be read at runtime.
    if (lang == IntentMatcher::InputLanguage::English)
    {
        keywordTypeDict[KeywordType::Interrogative] = { "What", "Tell" };
        keywordTypeDict[KeywordType::Weather]       = { "weather" };
        keywordTypeDict[KeywordType::Fact]          = { "fact" };

        // @todo City names are language-dependent, and this list might get
        // very long. Consider using an external library for location handling.
        keywordTypeDict[KeywordType::City] =
            { "Berlin", "Paris", "Amsterdam", "Barcelona" };
    }

    // Build the keyword dictionary from the above map.
    // Yields e.g. "Amsterdam" -> city; "What" -> interrogative.
    for (auto it : keywordTypeDict)
    {
        for (auto word : it.second)
            keywordDict[word] = it.first;
    }
}

std::unique_ptr<Intent> IntentMatcher::match(const std::vector<std::string>& words)
{
    if (words.size() == 0)
        return nullptr;

    return nullptr;
}
