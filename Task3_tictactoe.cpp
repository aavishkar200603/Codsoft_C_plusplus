#include <iostream>
using namespace std;

class TicTacToe {
private:
    char board[3][3];
    char currentPlayer;

public:
    TicTacToe() {
        initializeBoard();
        currentPlayer = 'X';
    }

    void initializeBoard() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = ' ';
            }
        }
    }

    void drawBoard() {
        cout << "-------------\n";
        for (int i = 0; i < 3; i++) {
            cout << "| ";
            for (int j = 0; j < 3; j++) {
                cout << board[i][j] << " | ";
            }
            cout << "\n-------------\n";
        }
    }

    bool makeMove(int row, int col) {
        if (board[row][col] == ' ' && row >= 0 && row < 3 && col >= 0 && col < 3) {
            board[row][col] = currentPlayer;
            return true;
        }
        return false;
    }

    bool checkWin() {
        // Check rows, columns, and diagonals
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
                return true;
            if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
                return true;
        }
        if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
            return true;
        if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
            return true;
        return false;
    }

    char getCurrentPlayer() {
        return currentPlayer;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
};

void playGame(TicTacToe &game) {
    int row, col;

    cout << "Welcome to Tic-Tac-Toe!\n";

    for (int turn = 0; turn < 9; turn++) {
        game.drawBoard();

        while (true) {
            cout << "Player " << game.getCurrentPlayer() << ", enter row (0-2) and column (0-2): ";
            cin >> row >> col;

            if (game.makeMove(row, col)) {
                break;
            } else {
                cout << "Invalid move. Try again.\n";
            }
        }

        if (game.checkWin()) {
            game.drawBoard();
            cout << "Player " << game.getCurrentPlayer() << " wins!\n";
            break;
        }

        game.switchPlayer();
    }

    game.drawBoard();

    if (!game.checkWin() && game.getCurrentPlayer() == 'X') {
        cout << "It's a draw!\n";
    }
}

int main() {
    TicTacToe game;
    playGame(game);

    char playAgain;
    cout << "Do you want to play again? (y/n): ";
    cin >> playAgain;

    while (playAgain == 'y' || playAgain == 'Y') {
        game.initializeBoard();
        playGame(game);
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    }

    cout << "Thank you for playing Tic-Tac-Toe!\n";

    return 0;
}
