#include <string>
#include <map> 
#include "Direction.hpp"
#include <stdint.h>

using namespace std;

struct node{
    char val = '_';
};


namespace ariel {
    class Board {
        unsigned int row_min, row_max;
        unsigned int col_min, col_max;

        map<unsigned int, map<unsigned int, node> > board;
        
    public:
        Board() { 
            row_max =  col_max = 0; 
            row_min = col_min = INT8_MAX;
        }
        
        ~Board() { }
        void post(unsigned int row, unsigned int column, Direction direction, string message);
        std::string read(unsigned int row, unsigned int column, Direction direction, unsigned int length);
        void show();
    };
}
