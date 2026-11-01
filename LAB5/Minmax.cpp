#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void print_board(vector<string>& b) {
    for (auto& r : b) cout << r[0] << " | " << r[1] << " | " << r[2] << "\n---------\n";
}

char check_winner(vector<string>& b) {
    for (int i = 0; i < 3; ++i) {
        if (b[i][0] != ' ' && b[i][0] == b[i][1] && b[i][1] == b[i][2]) return b[i][0];
        if (b[0][i] != ' ' && b[0][i] == b[1][i] && b[1][i] == b[2][i]) return b[0][i];
    }
    if (b[0][0] != ' ' && b[0][0] == b[1][1] && b[1][1] == b[2][2]) return b[0][0];
    if (b[0][2] != ' ' && b[0][2] == b[1][1] && b[1][1] == b[2][0]) return b[0][2];
    return ' ';
}

bool is_full(vector<string>& b) {
    for (auto& r : b) for (char c : r) if (c == ' ') return false;
    return true;
}

int minimax(vector<string>& b, bool maximizing) {
    char w = check_winner(b);
    if (w == 'O') return 1;
    if (w == 'X') return -1;
    if (is_full(b)) return 0;
    int best = maximizing ? -100 : 100;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (b[i][j] == ' ') {
                b[i][j] = maximizing ? 'O' : 'X';
                int s = minimax(b, !maximizing);
                b[i][j] = ' ';
                best = maximizing ? max(best, s) : min(best, s);
            }
    return best;
}

pair<int, int> best_move(vector<string>& b) {
    int best = -100;
    pair<int, int> move = {-1, -1};
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (b[i][j] == ' ') {
                b[i][j] = 'O';
                int s = minimax(b, false);
                b[i][j] = ' ';
                if (s > best) { best = s; move = {i, j}; }
            }
    return move;
}

int main() {
    vector<string> b(3, "   ");
    cout << "You = X\nComputer = O\n";
    while (true) {
        print_board(b);
        int r, c;
        cout << "Enter row (0-2): ";
        if (!(cin >> r)) break;
        cout << "Enter column (0-2): ";
        if (!(cin >> c)) break;
        if (r < 0 || r > 2 || c < 0 || c > 2 || b[r][c] != ' ') {
            cout << "Invalid move!\n";
            continue;
        }
        b[r][c] = 'X';
        if (check_winner(b) == 'X') { print_board(b); cout << "You win!\n"; break; }
        if (is_full(b)) { print_board(b); cout << "Draw!\n"; break; }
        auto [mr, mc] = best_move(b);
        if (mr != -1) b[mr][mc] = 'O';
        if (check_winner(b) == 'O') { print_board(b); cout << "Computer wins!\n"; break; }
        if (is_full(b)) { print_board(b); cout << "Draw!\n"; break; }
    }
}
