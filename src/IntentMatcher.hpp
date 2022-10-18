#pragma once

#include <memory>
#include <vector>
#include <map>
#include "Intent.hpp"
#include "IntentFactory.hpp"

class IntentMatcher
{
public:
    enum class InputLanguage { English };

    IntentMatcher() = delete;
    IntentMatcher(const InputLanguage lang) { init(lang); }

    /**
     * Matches a list of words to an intent.
     * @param[in] The words of the sentence to be matched.
     * @return An intent matching the list of words, nullptr if no match could be found.
     */
    std::unique_ptr<Intent> match(const std::vector<std::string>& words) const;

private:
    void init(const InputLanguage lang);

    IntentFactory intentFactory;

    // Maps a keyword type to a list of words of that type.
    std::map<KeywordType, std::vector<std::string>> keywordTypeDict;

    // Maps a human language word to a keyword type;
    std::map<std::string, KeywordType> keywordDict;
};
