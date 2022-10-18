#pragma once

#include <memory>
#include <vector>
#include <map>
#include "Intent.hpp"
#include "IntentFactory.hpp"

/**
 * @brief Entry point for matching a sentence to an intent.
 */
class IntentMatcher
{
public:
    /// The available input languages.
    enum class InputLanguage { English };

    IntentMatcher() = delete;

    /**
     * Constructor.
     * @param lang The input language to be used by this matcher.
     */
    IntentMatcher(const InputLanguage lang) { init(lang); }

    /**
     * Matches a list of words to an intent.
     * @param[in] The words of the sentence to be matched.
     * @return An intent matching the list of words, nullptr if no match could be found.
     */
    std::unique_ptr<Intent> match(const std::vector<std::string>& words) const;

private:
    /// Initializes the keyword dictionary.
    void init(const InputLanguage lang);

    /// The factory that knows the individual intents.
    IntentFactory intentFactory;

    /// Maps a keyword type to a list of words of that type.
    /// @todo The current implementation only uses this for initialization.
    std::map<KeywordType, std::vector<std::string>> keywordTypeDict;

    /// Maps a human language word to a keyword type.
    std::map<std::string, KeywordType> keywordDict;
};
