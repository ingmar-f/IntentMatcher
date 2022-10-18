This implementation of an intent matcher has the following goals:
- Decouple language text strings from the code as far as possible.
- Allow easy addition of new intents.
- Allow extension to other languages than English.

The implementation falls short in several aspects, mainly:
- No knowledge of grammar. Matches complete nonsense sentences as long as the
  keywords are present.
- Matching is case-sensitive.
- After tokenizing, the actual keywords are not available to the intent, for
  instance which city exactly. A similar use case would be a time specifier,
  like "today" in the given examples. This could be used for time-specific
  intents, like a weather forecast for "tomorrow", "Friday" or "weekend".

Some of these issues can be addressed with the architecture as it is, but
others would require changes in the architecture.

Also see the @todo tags in the code.
