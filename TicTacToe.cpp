#include <random>
#include <iostream>
#include <regex>
#include <unistd.h>
#include "TicTacToe.h"

using namespace std;

void TicTacToe::gameLoop() {
    cout << "Welcome to C++ Tic-Tac-Toe!" << endl << endl;
    while (!isGameOver) {
        showGrid();
        string input;
        cout << R"(First enter the column where you would like to place your "X". (1 - 3))" << endl;
        cin >> input;
        if (input == "!exit") { break; }
        regex validInput("[1-3]");
        while (!regex_match(input, validInput)) {
            cout << "Invalid number, please re-enter the column number. (1 - 3)" << endl;
            cin >> input;
            if (input == "!exit") { break; }
        }
        string column = input;
        cout << R"(Now please enter the row where you would like to place your "X". (1 - 3))" << endl;
        cin >> input;
        if (input == "!exit") { break; }
        while (!regex_match(input, validInput)) {
            cout << "Invalid number, please re-enter the row number. (1 - 3)" << endl;
            cin >> input;
            if (input == "!exit") { break; }
        }
        string row = input;
        if (!setGrid(stoi(row) - 1, stoi(column) - 1)) {
            cout << "This spot is already played, let's try again" << endl << endl;
            continue;
        } else {
            showGrid();
            cout << "Now it's the computer's turn...." << endl << endl;
            sleep(3);
            randomComputerMove();
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
