#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::min;
using std::string;
using std::vector;

const string connection[10] = {
    "xxx.............",
    "...x...x.x.x....",
    "....x.....x...xx",
    "x...xxxx........",
    "......xxx.x.x...",
    "x.x...........xx",
    "...x..........xx",
    "....xx.x......xx",
    ".xxxxx..........",
    "...xxx...x...x.."
};
const int INF = 9999;

int test_cases;
vector<vector<int> > clocks;

void read_input() {
    cin >> test_cases;
    for (int i = 0; i < test_cases; i++) {
        vector<int> clock_data(16);
        for (int j = 0; j < 16; j++) cin >> clock_data[j];
        clocks.push_back(clock_data);
    }
}

void push_switch(int n, int switch_number) {
    vector<int>& clock_list = clocks[n];
    for (int i = 0; i < 16; i++) {
        if (connection[switch_number][i] == 'x') {
            clock_list[i] += 3;
            if (clock_list[i] == 15) clock_list[i] = 3;
        }
    }
}

bool is_synced(int n) {
    for (const int& clock: clocks[n]) {
        if (clock != 12) return false;
    }
    return true;
}

int sync_clock(int n, int switch_number) {
    if (switch_number == 10) return is_synced(n) ? 0 : INF;
    int result = INF;
    for (int count = 0; count < 4; count++) {
        result = min(result, count + sync_clock(n, switch_number + 1));
        push_switch(n, switch_number);
    }
    return result;
}

int main() {
    cin.sync_with_stdio(false);
    read_input();

    for (int i = 0; i < test_cases; i++) {
        int count = sync_clock(i, 0);
        if (count == INF) cout << -1 << '\n';
        else cout << count << '\n';
    }

    return 0;
}
