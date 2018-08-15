#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::max;
using std::min;
using std::vector;

vector<int> fence;

void input() {
    int fence_count;
    cin >> fence_count;
    fence.clear();

    for (int i = 0; i < fence_count; ++i) {
        int fence_height;
        cin >> fence_height;
        fence.push_back(fence_height);
    }
}

int solve(int left, int right) {
    if (left == right) return fence[left];

    int mid = (left + right) / 2;
    int result = max(solve(left, mid), solve(mid + 1, right));
    int lo = mid, hi = mid + 1;
    int height = min(fence[lo], fence[hi]);
    result = max(result, height * 2);

    while (left < lo || hi < right) {
        if (hi < right && (lo == left || fence[lo - 1] < fence[hi + 1])) {
            ++hi;
            height = min(height, fence[hi]);
        } else {
            --lo;
            height = min(height, fence[lo]);
        }

        result = max(result, height * (hi - lo + 1));
    }
    return result;
}

int main() {
    int test_cases;
    cin >> test_cases;
    for (int i = 0; i < test_cases; ++i) {
        input();
        int result = solve(0, fence.size() - 1);
        cout << result << '\n';
    }
    return 0;
}
