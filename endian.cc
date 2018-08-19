#include <iostream>

using std::cin;
using std::cout;

int main() {
    int test_cases;
    cin >> test_cases;
    for (int i = 0; i < test_cases; ++i) {
        unsigned int number;
        cin >> number;
        unsigned int seg1 = number >> 24;
        unsigned int seg2 = (number >> 16) % 0x100;
        unsigned int seg3 = (number >> 8) % 0x100;
        unsigned int seg4 = number % 0x100;
        unsigned int converted = (seg4 << 24) + (seg3 << 16) + (seg2 << 8) + seg1;
        cout << converted << '\n';
    }
    return 0;
}
