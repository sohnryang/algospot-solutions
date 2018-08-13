#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::vector;

vector<vector<int> > board;
const int cover_type[4][3][2] = {
    {{0, 0}, {1, 0}, {0, 1}},
    {{0, 0}, {0, 1}, {1, 1}},
    {{0, 0}, {1, 0}, {1, 1}},
    {{0, 0}, {1, 0}, {1, -1}}
};

void input() {
    int height, width;
    cin >> height >> width;
    board.clear();
    for (int y = 0; y < height; ++y) {
        string line;
        cin >> line;
        vector<int> v;
        for (int i = 0; i < line.size(); ++i)
            v.push_back(line[i] == '#' ? 1 : 0);
        board.push_back(v);
    }
}

bool set_block(vector<vector<int> >& board, int y, int x, int type,
               int delta) {
    bool available = true;
    for (int i = 0; i < 3; ++i) {
        const int ny = y + cover_type[type][i][0];
        const int nx = x + cover_type[type][i][1];
        if (ny < 0 || ny >= board.size() || nx < 0 || nx >= board[0].size())
            available = false;
        else if ((board[ny][nx] += delta) > 1)
            available = false;
    }
    return available;
}

int cover_board(vector<vector<int> >& board) {
    int y = -1, x = -1;
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[0].size(); ++j)
            if (board[i][j] == 0) {
                y = i;
                x = j;
                break;
            }
        if (y != -1) break;
    }

    if (y == -1) return 1;
    int result = 0;
    for (int type = 0; type < 4; ++type) {
        if (set_block(board, y, x, type, 1))
            result += cover_board(board);
        set_block(board, y, x, type, -1);
    }
    return result;
}

int main() {
    int test_cases;
    cin >> test_cases;
    for (int i = 0; i < test_cases; ++i) {
        input();
        int result = cover_board(board);
        cout << result << '\n';
    }
    return 0;
}
