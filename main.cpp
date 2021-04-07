#include "Board.hpp"
#include "Direction.hpp"
#include <iostream>
#include <stdexcept>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;
using ariel::Direction;

//using ANSI color codes
const string red_line = "\e[1;31m"; 
const string colors[] {"\e[1;92m", "\e[1;93m", "\e[1;94m", "\e[1;95m", "\e[1;96m"};

int main() {
    srand((unsigned)time(0));
    ariel::Board board;
    string message;

    /*
    a = row
    b = column
    */
    unsigned int a,b,c,d;
    for (int i=0;true;i++) {
        system("clearing");
        cout << colors[i%5];
        board.show();
        cout << red_line << "-----------------------------" << flush;
        this_thread::sleep_for(chrono::milliseconds(600));
        unsigned int option;
        cout << "\nTo post a message press 1, to read a message press 2 \n";
        cin >> option;

        if (option == 1) {
           cout << "\nEnter row col direction(1 or 2) and the message\n";
            cin >> a >> b >> c >> message;
            if (c == 1) {
                board.post(a,b,Direction::Vertical,message);
            }
            else {
                board.post(a,b,Direction::Horizontal,message);
            }
        }
        else {
            cout << "\nEnter row col direction(1 or 2) and the message\n";
            cin >> a >> b >> c >> message;
            cout << "\nYour message :\n";
            if(c==1){
                cout << board.read(a,b, Direction::Vertical, d) << endl;
            }
            else{
                cout << board.read(a, b, Direction::Horizontal,d) << endl;
            }
            cout << "add more content to the board to continue:" << endl;
            cin >> a;
        }
    }
}
