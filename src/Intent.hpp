#pragma once

#include <string>
#include <ostream>

/**
 * @brief Base class for all intents.
 */
class Intent
{
public:
    virtual std::string describe() const = 0;

    virtual ~Intent() {}
};

std::ostream& operator<<(std::ostream& os, const Intent& intent);
