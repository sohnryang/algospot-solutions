#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::memset;

const int dx[8] = { -1, -1, -1,  1, 1, 1,  0, 0 };
const int dy[8] = { -1,  0,  1, -1, 0, 1, -1, 1 };

vector<string> board;
vector<string> words;
string word;
int cache[5][5][10];

void read_input() {
    board.clear();
    words.clear();
    for (int i = 0; i < 5; i++) {
        string str;
        cin >> str;
        board.push_back(str);
    }

    int word_count;
    cin >> word_count;

    for (int i = 0; i < word_count; i++) {
        string word;
        cin >> word;
        words.push_back(word);
    }
}

bool test_range(int y, int x) {
    bool is_y_inrange = y >= 0 && y <= 4;
    bool is_x_inrange = x >= 0 && x <= 4;
    return is_x_inrange && is_y_inrange;
}

int has_word_in_pos(int y, int x, int index) {
    if (!test_range(y, x)) return 0;

    int& result = cache[y][x][index];
    if (result != -1) return result;
    if (board[y][x] != word[index]) result = 0;
    if (result != -1) return result;
    if (word.size() == index + 1) result = 1;
    if (result != -1) return result;

    for (int dir = 0; dir < 8; dir++) {
        int next_y = y + dy[dir], next_x = x + dx[dir];
        if (has_word_in_pos(next_y, next_x, index + 1)) {
            result = 1;
            return result;
        }
    }
    result = 0;
    return result;
}

int main() {
    cin.sync_with_stdio(false);

    int test_cases;
    cin >> test_cases;

    for (int i = 0; i < test_cases; i++) {
        read_input();
        for (auto it = words.begin(); it != words.end(); it++) {
            memset(cache, -1, sizeof(cache));
            cout << *it << " ";
            word = *it;
            bool answer_found = false;
            for (int y = 0; y < 5; y++) {
                for (int x = 0; x < 5; x++) {
                    if (has_word_in_pos(y, x, 0) == 1) {
                        answer_found = true;
                        cout << "YES\n";
                        break;
                    }
                }
                if (answer_found) break;
            }
            if (!answer_found) cout << "NO\n";
        }
    }

    return 0;
}
