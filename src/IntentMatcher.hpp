#pragma once

#include <memory>
#include <vector>
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
};
