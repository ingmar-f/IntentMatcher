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

std::unique_ptr<Intent> IntentMatcher::match(const std::vector<std::string>& words) const
{
    if (words.size() == 0)
        return nullptr;

    // Collect matched keywords by type to avoid more string comparisons later.
    // @todo Using a set would be sufficient here, but an extension of this
    // implementation might need to pass the actual keyword to the intent, so
    // multiple keywords of the same type might be needed.
    std::vector<KeywordType> foundKeywords;
    for (auto word : words)
        if (auto entry = keywordDict.find(word); entry != keywordDict.end())
            foundKeywords.push_back(entry->second);

    if (foundKeywords.size() == 0)
        return nullptr;

    return nullptr;
}
