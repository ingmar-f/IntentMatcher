#pragma once

#include <string>
#include <ostream>
#include <vector>
#include <memory>
#include "KeywordType.hpp"

/**
 * @brief Base class for all intents.
 */
class Intent
{
public:
    /// Returns a human-readable description of the intent.
    virtual std::string describe() const = 0;

    /**
     * Obtains a list of keyword types that that match this intent.
     * @param[out] The list of keyword types.
     */
    virtual void getMatchedKeywordTypes(std::vector<KeywordType>& result) const = 0;

    /// Creates a copy of this intent.
    virtual std::unique_ptr<Intent> clone() const = 0;

    virtual ~Intent() = default;
};

std::ostream& operator<<(std::ostream& os, const Intent& intent);
