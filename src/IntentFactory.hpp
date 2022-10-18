#pragma once

#include <memory>
#include <vector>
#include "IntentWrapper.hpp"

/**
 * @brief Factory for Intent objects.
 *
 * This factory holds a wrapper for each known intent and can return copies
 * based on matching keyword types.
 */
class IntentFactory
{
public:
    IntentFactory();

    /**
     * Matches keyword types to Intent implementations.
     * @param[in] keywordTypes The types of keywords the intent should match.
     * @return An Intent or nullptr if no match was found.
     */
    intent_uptr getMatchingIntent(const std::vector<KeywordType>& keywordTypes) const;

private:
    /// Holds the wrappers for the known intents.
    std::vector<std::unique_ptr<IntentWrapper>> wrappers; 
};
