#include <string>
#include <map> 
#include "Direction.hpp"
#include <stdint.h>

using namespace std;

//impelmenting a node for each message in the board
struct node{
    char n = '_';
};


namespace ariel {
    class Board {
        unsigned int col_min, col_max;
        unsigned int row_min, row_max;
        
        map<unsigned int, map<unsigned int, node> > board;
        
    public:
        Board() { 
            row_max =  col_max = 0; 
            row_min = col_min = INT8_MAX;
        }
        
        ~Board() { }
        void post(unsigned int row, unsigned int column, Direction direction, string const &message);
        std::string read(unsigned int row, unsigned int column, Direction direction, unsigned int length);
        void show();
    };
}
