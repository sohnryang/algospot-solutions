#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

string quadtree;

void input() {
    quadtree.clear();
    cin >> quadtree;
}

string solve(string::iterator& it) {
    char head = *it;
    ++it;
    if (head == 'b' || head == 'w') return string(1, head);
    string upper_left = solve(it);
    string upper_right = solve(it);
    string lower_left = solve(it);
    string lower_right = solve(it);
    return string("x") + lower_left + lower_right + upper_left +
           upper_right;
}

int main() {
    int test_cases;
    cin >> test_cases;
    for (int i = 0; i < test_cases; ++i) {
        input();
        string::iterator it = quadtree.begin();
        string reversed = solve(it);
        cout << reversed << '\n';
    }
    return 0;
}
