#include <cstring>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::memset;
using std::vector;

int student_count;
int relationships[10][10];

void input() {
    memset(relationships, 0, sizeof(relationships));
    int pair_count;
    cin >> student_count >> pair_count;
    for (int i = 0; i < pair_count; i++) {
        int a, b;
        cin >> a >> b;
        relationships[a][b] = 1;
        relationships[b][a] = 1;
    }
}

int solve(bool picked_students[10]) {
    int result = 0;
    int first_unpicked = -1;
    for (int i = 0; i < student_count; i++) {
        if (!picked_students[i]) {
            first_unpicked = i;
            break;
        }
    }
    if (first_unpicked == -1) return 1;
    picked_students[first_unpicked] = true;
    for (int i = first_unpicked + 1; i < student_count; i++) {
        if (!picked_students[i] && relationships[first_unpicked][i] == 1) {
            picked_students[i] = true;
            result += solve(picked_students);
            picked_students[i] = false;
        }
    }
    picked_students[first_unpicked] = false;
    return result;
}

int main() {
    int test_cases;
    cin >> test_cases;
    for (int i = 0; i < test_cases; i++) {
        input();
        bool arr[10];
        memset(arr, false, sizeof(arr));
        int result = solve(arr);
        cout << result << '\n';
    }
    return 0;
}
