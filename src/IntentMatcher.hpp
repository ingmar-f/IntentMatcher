#pragma once

#include <memory>
#include <vector>
#include <map>
#include "Intent.hpp"

class IntentMatcher
{
public:
    enum class InputLanguage { English };

    IntentMatcher() = delete;
    IntentMatcher(const InputLanguage lang) { init(lang); }

    std::unique_ptr<Intent> match(const std::vector<std::string>& words);

private:
    void init(const InputLanguage lang);

    // Maps a keyword type to a list of words of that type.
    std::map<KeywordType, std::vector<std::string>> keywordTypeDict;

    // Maps a human language word to a keyword type;
    std::map<std::string, KeywordType> keywordDict;
};
