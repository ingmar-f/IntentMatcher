#pragma once

#include <memory>
#include "Intent.hpp"

typedef std::unique_ptr<Intent> intent_uptr;

/**
 * @brief A wrapper around an Intent.
 *
 * Forwards some calls to the wrapped Intent object and can create a copy.
 */
class IntentWrapper
{
public:
    IntentWrapper() = delete;

    // Constructs a wrapper for the given intent.
    IntentWrapper(intent_uptr in)
    {
        wrapped = std::move(in);
    }

    ~IntentWrapper() = default;

    /// Forwards the call to Intent::getMatchedKeywordTypes().
    void getMatchedKeywordTypes(std::vector<KeywordType>& result) const
    {
        wrapped->getMatchedKeywordTypes(result);
    }

    /// Returns a copy of the wrapped Intent.
    intent_uptr createIntent() const
    {
        return intent_uptr(wrapped->clone());
    }

private:
    intent_uptr wrapped;
};
