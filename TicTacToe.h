#ifndef TIC_TAC_TOE_TICTACTOE_H
#define TIC_TAC_TOE_TICTACTOE_H

class TicTacToe {
private:
    int grid[3][3] = {};
    bool setGrid(int row, int column);
    bool randomComputerMove();
    int checkRowForWin();
    int checkColumnForWin();
    int checkDiagonalForWin();
    int checkForWin();
    static void gameOver(int winner);
public:
    TicTacToe() { }
    void gameLoop();

    void showGrid();
};


#endif //TIC_TAC_TOE_TICTACTOE_H
