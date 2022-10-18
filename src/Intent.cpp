#include "Intent.hpp"

std::ostream& operator<<(std::ostream& os, const Intent& intent)
{
    os << "(Intent: " << intent.describe() << ")";
    return os;
}
