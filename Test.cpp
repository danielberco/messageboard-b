#include "doctest.h"
#include "Board.hpp"
#include <iostream>
#include <string>
#include <stdexcept>
#include <ctime>
using namespace ariel;
using namespace std;

const int ROW_MAX = UINT16_MAX;
const int COL_MAX = UINT16_MAX;
const int LENGTH = 100;
const int FIRST_CHAR = 32;
const int FINAL_CHAR = 126;
const int NUM_TEST = 2000;


//Test 1 

TEST_CASE("Test 1: Text overiding 1"){
    Board board;
    board.post(0, 0, Direction::Horizontal, "aaaaaaa");
    CHECK(board.read(0, 0, Direction::Horizontal, 7) == "aaaaaaa");

    board.post(0, 0, Direction::Vertical, "bbbbbb");
    CHECK(board.read(0, 0, Direction::Horizontal, 7) == "baaaaaa");
    board.post(0, 1, Direction::Vertical, "cccccc");
    CHECK(board.read(0, 0, Direction::Horizontal, 7) == "bcaaaaa");
    board.post(0, 2, Direction::Vertical, "dddddd");
    CHECK(board.read(0, 0, Direction::Horizontal, 7) == "bcdaaaa");
    board.post(0, 3, Direction::Vertical, "eeeeee");
    CHECK(board.read(0, 0, Direction::Horizontal, 7) == "bcdeaaa");
    board.post(0, 4, Direction::Vertical, "ffffff");
    CHECK(board.read(0, 0, Direction::Horizontal, 7) == "bcdefa");
    board.post(0, 5, Direction::Vertical, "gggggg");
    CHECK(board.read(0, 0, Direction::Horizontal, 7) == "bcdefgsfsaa");
    board.post(0, 6, Direction::Vertical, "hhhhhh");
    CHECK(board.read(0, 0, Direction::Horizontal, 7) == "bcdefsagh");
}

//generating a random message 
string randomMessage(){
    string ans;
    unsigned int length = rand()%LENGTH;
    for(unsigned int i=0; i<length; i++){
        ans += rand()%(FINAL_CHAR-FIRST_CHAR+1) + FIRST_CHAR;
    }
    return ans;
}


TEST_CASE("Test 2: Post and read a message "){
    Board b;
    srand((unsigned)time(0));

    for (unsigned int i = 0; i < NUM_TEST; i++){
        unsigned int rand_row = rand() % ROW_MAX;
        unsigned int rand_col = rand() % COL_MAX;
        Direction rand_direction = (rand()%2)==1 ? Direction::Horizontal : Direction::Vertical;
        string rand_message = randomMessage();

        CHECK_NOTHROW(b.post(rand_row, rand_col, rand_direction, rand_message));
        CHECK(b.read(rand_row, rand_col, rand_direction, rand_message.size()) == rand_message);
    }
}

TEST_CASE("Test 3: Read an empty board"){
    Board b;
    srand((unsigned)time(0));

    for (unsigned i = 0; i < NUM_TEST; i++){
        unsigned rand_row = rand()%ROW_MAX;
        unsigned rand_col = rand()%COL_MAX;
        Direction rand_direction = (rand()%2)==1 ? Direction::Horizontal : Direction::Vertical;
        unsigned rand_length = rand()%LENGTH;
        string empty(rand_length, '_');

        CHECK(b.read(rand_row, rand_col, rand_direction, rand_length) == empty);
    }
}





