#include <iostream>
using namespace std;

char board[9] = {'1','2','3','4','5','6','7','8','9'};
char currentPlayer = 'X';

void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 9; i += 3) {
        cout << board[i] << " | " << board[i+1] << " | " << board[i+2] << endl;
        if (i < 6) cout << "--|---|--\n";
    }
    cout << "\n";
}

bool isWin() {
    int winComb[8][3] = {
        {0,1,2},{3,4,5},{6,7,8},
        {0,3,6},{1,4,7},{2,5,8},
        {0,4,8},{2,4,6}
    };
    for (auto &comb : winComb) {
        if (board[comb[0]] == currentPlayer && board[comb[1]] == currentPlayer && board[comb[2]] == currentPlayer)
            return true;
    }
    return false;
}

bool isDraw() {
    for (int i = 0; i < 9; i++)
        if (board[i] != 'X' && board[i] != 'O') return false;
    return true;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void playGame() {
    int move;
    while (true) {
        displayBoard();
        cout << "Player " << currentPlayer << ", enter position (1-9): ";
        cin >> move;
        move--;

        if (move < 0 || move >= 9 || board[move] == 'X' || board[move] == 'O') {
            cout << "move is invalid! please try again.\n";
            continue;
        }

        board[move] = currentPlayer;

        if (isWin()) {
            displayBoard();
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        } else if (isDraw()) {
            displayBoard();
            cout << "It's a draw!\n";
            break;
        }

        switchPlayer();
    }
}

int main() {
    playGame();
    return 0;
}