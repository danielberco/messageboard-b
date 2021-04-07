#include "Board.hpp"
using namespace std;
#include <iostream>

namespace ariel {
    void Board::post(unsigned int row, unsigned int column , Direction direction , string const &message) {
        this->col_max = max(this->col_max,column);
        this->row_max = max(this->row_max,row);
        this->col_min = min(this->col_min,column);
        this->row_min = min(this->row_min,row);

        for (char mes: message) {
            this->board[row][column].n = mes;
            (direction == Direction::Horizontal)? column++ : row++;
        }
    }

    string Board::read(unsigned int row, unsigned int column, Direction direction,unsigned int length) {
        string read;
        for (unsigned int i =0 ; i<length;i++) {
            read += this->board[row][column].n;
            (direction == Direction::Horizontal)? column++ : row++;
        }
        return read;
    }

    void Board::show() {
        for (unsigned int i = this->row_min;i <= this->row_max;i++) {
            for (unsigned int j = this->col_min;j <= this->col_max;j++) {
                cout << this->board[i][j].n << " ";//space for each message
            }
            cout << "\n\n";
        }
    }
}
