#include "IntentMatcher.hpp"

void IntentMatcher::init(IntentMatcher::InputLanguage lang)
{
    switch (lang)
    {
        case IntentMatcher::InputLanguage::English:
            return;
    }
}

std::unique_ptr<Intent> IntentMatcher::match(const std::vector<std::string>& words)
{
    if (words.size() == 0)
        return nullptr;

    return nullptr;
}
