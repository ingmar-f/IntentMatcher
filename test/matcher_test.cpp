#include <gtest/gtest.h>
#include "IntentMatcher.hpp"

TEST(MatcherTest, GetWeather)
{
    std::vector<std::string> input
        {"What", "is", "the", "weather", "like", "today"};

    IntentMatcher matcher(IntentMatcher::InputLanguage::English);
    std::unique_ptr<Intent> intent = matcher.match(input);

    EXPECT_EQ("Get Weather", intent->describe());
}

TEST(MatcherTest, GetWeatherCity)
{
    std::vector<std::string> input
        {"What", "is", "the", "weather", "like", "in", "Paris", "today"};

    IntentMatcher matcher(IntentMatcher::InputLanguage::English);
    std::unique_ptr<Intent> intent = matcher.match(input);

    EXPECT_EQ("Get Weather City", intent->describe());
}

TEST(MatcherTest, GetFact)
{
    std::vector<std::string> input
        {"Tell", "me", "an", "interesting", "fact"};

    IntentMatcher matcher(IntentMatcher::InputLanguage::English);
    std::unique_ptr<Intent> intent = matcher.match(input);

    EXPECT_EQ("Get Fact", intent->describe());
}
