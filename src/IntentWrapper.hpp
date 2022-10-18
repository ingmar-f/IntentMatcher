#pragma once

#include <memory>
#include "Intent.hpp"

typedef std::unique_ptr<Intent> intent_uptr;

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

    void getMatchedKeywordTypes(std::vector<KeywordType>& result) const
    {
        wrapped->getMatchedKeywordTypes(result);
    }

    intent_uptr createIntent() const
    {
        return intent_uptr(wrapped->clone());
    }

private:
    intent_uptr wrapped;
};
