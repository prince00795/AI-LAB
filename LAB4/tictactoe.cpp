#include <iostream>
#include <vector>
using namespace std;

void print_board(vector<string>& b) {
    cout << "\n";
    for (int i = 0; i < 3; ++i) {
        cout << b[i][0] << " | " << b[i][1] << " | " << b[i][2] << "\n";
        if (i < 2) cout << "--+---+--\n";
    }
    cout << "\n";
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

int main() {
    vector<string> b(3, "   ");
    char player = 'X';
    while (true) {
        print_board(b);
        int r, c;
        cout << "Player " << player << ", enter row (0-2): ";
        if (!(cin >> r)) break;
        cout << "Player " << player << ", enter column (0-2): ";
        if (!(cin >> c)) break;
        if (r < 0 || r > 2 || c < 0 || c > 2 || b[r][c] != ' ') {
            cout << "Position already occupied!\n";
            continue;
        }
        b[r][c] = player;
        if (char w = check_winner(b); w != ' ') {
            print_board(b);
            cout << "Winner: " << w << "\n";
            break;
        }
        if (is_full(b)) {
            print_board(b);
            cout << "Draw!\n";
            break;
        }
        player = (player == 'X' ? 'O' : 'X');
    }
}
