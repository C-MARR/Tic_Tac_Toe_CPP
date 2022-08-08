#ifndef TIC_TAC_TOE_TICTACTOE_H
#define TIC_TAC_TOE_TICTACTOE_H

class TicTacToe {
private:
    bool isGameOver = false;
    int grid[3][3] = {};
    bool setGrid(int row, int column);
    bool randomComputerMove();
public:
    TicTacToe() { }
    void gameLoop();
    void showGrid();
};


#endif //TIC_TAC_TOE_TICTACTOE_H
