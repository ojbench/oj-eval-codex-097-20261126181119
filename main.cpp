#include <array>
#include <iostream>

namespace {
constexpr int kMaxValue = 100000;

// Read integers from the displayed root = [...], cnt = ... format.
bool readInteger(int& value) {
    char ch;
    while (std::cin.get(ch)) {
        if (ch >= '0' && ch <= '9') {
            value = ch - '0';
            while (std::cin.peek() >= '0' && std::cin.peek() <= '9') {
                value = value * 10 + (std::cin.get() - '0');
            }
            return true;
        }
    }
    return false;
}
}  // namespace

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::array<int, kMaxValue + 1> frequency{};
    int pending;
    if (!readInteger(pending)) {
        return 0;
    }

    // Delay each integer until the next one arrives: the final integer is cnt.
    int next;
    while (readInteger(next)) {
        if (pending < 1 || pending > kMaxValue) {
            return 0;
        }
        ++frequency[pending];
        pending = next;
    }

    int rank = pending;
    for (int value = kMaxValue; value >= 1; --value) {
        rank -= frequency[value];
        if (rank <= 0) {
            std::cout << value << '\n';
            return 0;
        }
    }
    return 0;
}
