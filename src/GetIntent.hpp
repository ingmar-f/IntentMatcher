#pragma once

/**
 * @brief Base class for all intents that obtain some sort of information.
 */
class GetIntent : public Intent
{
public:
    virtual std::string describe() const override { return "Get"; }
};
