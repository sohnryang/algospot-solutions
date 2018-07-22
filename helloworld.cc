#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

int main() {
    cin.sync_with_stdio(false);

    int test_cases;
    cin >> test_cases;

    for (int i = 0; i < test_cases; i++) {
        string name;
        cin >> name;
        cout << "Hello, " << name <<"!\n";
    }

    return 0;
}
