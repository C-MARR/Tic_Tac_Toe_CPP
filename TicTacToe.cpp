#include <random>
#include <iostream>
#include <regex>
#include <unistd.h>
#include "TicTacToe.h"

using namespace std;

void TicTacToe::gameLoop() {
    int winner = 0;
    cout << "Welcome to C++ Tic-Tac-Toe!" << endl << endl;
    showGrid();
    while (true) {
        string input;
        cout << R"(First enter the coordinates where place your "X". Column, then Row --example "1 3")" << endl;
        getline(cin, input);
        if (input == "!exit") { break; }
        regex validInput("[1-3] [1-3]");
        while (!regex_match(input, validInput)) {
            cout << R"(Invalid entry, please re-enter the coordinates. --example "2 2")" << endl;
            cin >> input;
            if (input == "!exit") { break; }
        }
        if (!setGrid(input[0] - 49, input[2] - 49)) {
            cout << "This spot is already played, let's try again" << endl << endl;
            continue;
        } else {
            showGrid();
            winner = checkForWin();
            if (winner != 0) {
                gameOver(winner);
                break;
            }
            cout << "Now it's the computer's turn...." << endl << endl;
            sleep(3);
            randomComputerMove();
            showGrid();
            winner = checkForWin();
            if (winner != 0) {
                gameOver(winner);
                break;
            }
        }
    }
    cout << "Bye!" << endl;
}

bool TicTacToe::setGrid(int row, int column) {
    if (grid[row][column] != 0) {
        return false;
    } else {
        grid[row][column] = 1;
        return true;
    }
}

bool TicTacToe::randomComputerMove() {
    srand(time(0));
    while (true) {
        int randomColumn = rand() % 3;
        int randomRow = rand() % 3;
        if (grid[randomColumn][randomRow] == 0) {
            grid[randomColumn][randomRow] = -1;
            break;
        }
    }

}

void showMenu() {
//    TODO
}

void TicTacToe::showGrid() {
    cout << "  1 2 3  " << endl;
    cout << "---------" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << "| ";
        for (int j = 0; j < 3; ++j) {
            cout << (grid[i][j] == 1 ? "X" : grid[i][j] == -1 ? "O" : " ") << " ";
        }
        cout << "| " << i + 1 << endl;
    }
    cout << "---------" << endl << endl;
}

int TicTacToe::checkForWin() {
    int columnWin = checkColumnForWin();
    if (columnWin != 0) {
        return columnWin;
    }
    int rowWin = checkRowForWin();
    if (rowWin != 0) {
        return rowWin;
    }
    int diagonalWin = checkDiagonalForWin();
    if (checkDiagonalForWin() != 0) {
        return diagonalWin;
    }
    return 0;
}

int TicTacToe::checkColumnForWin() {
    for (auto & i : grid) {
        if (i[0] != 0 && i[0] == i[1] && i[0] == i[2]) {
            return i[0];
        }
    }
    return 0;
}

int TicTacToe::checkRowForWin() {
    for (int i = 0; i < 3; i++) {
        if (grid[0][i] != 0 && grid[0][i] == grid[1][i] && grid[0][i] == grid[2][i]) {
            return grid[0][i];
        }
    }
    return 0;
}

int TicTacToe::checkDiagonalForWin() {
    if ((grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]) ||
        (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) && grid[1][1] != 0) {
        return grid[1][1];
    } else {
        return 0;
    }
}

void TicTacToe::gameOver(int winner) {
    if (winner == 1) {
        cout << "Congratulations!  You Win!" << endl;
    } else if (winner == -1) {
        cout << "Sorry, the Computer has outplayed you." << endl;
    } else {
        cout << "It's a draw!" << endl;
    }
}
