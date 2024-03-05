#include <iostream>
#include <vector>
#include<chrono>
#include<thread>

using namespace std;

const int W = 50;

/*
Given the position of a cell, returns an integer that
describes the number of living cells around it.
*/

int get_living(int i, int j, vector<vector<bool>>& M) {

    int c_living = 0; 
    if (M[i][j]) --c_living; //If the cell is living

    for (int ii = -1; ii < 2; ++ii) {
        for (int jj = -1; jj < 2; ++jj) {
            if (i+ii > 0 and i+ii < W-1   and 
                j+jj > 0 and j+jj < 2*W-1 and
                M[i+ii][j+jj])  ++c_living;
        }
    } 
    return c_living;
}

/*
    - Rool 1: If a living cell has 2 or 3 cels around living keeps as
      a living cell.
    - Rool 2: If a living cell has less than 2 cels living around it the
      cell dies due to underpopulation.
    - Rool 3: If a living cell has more than 3 cels living around it the
      cell dies due to overpopulation.
*/

bool living_cells_rules(int i, int j, vector<vector<bool>>& M){

    int c_living;
    c_living = get_living(i, j, M);
    if (c_living == 2 or c_living == 3) return true;  
    return false;

}

/*
    - Rool 4: If a dead cell is sorrounded with exactly three living cells
      becomes a living cell, due to reproduction.
*/
bool dead_cells_rules(int i, int j, vector<vector<bool>>& M) {
    int c_living;
    c_living = get_living(i, j, M);
    if (c_living == 3) return true;  
    return false;   

}

int main() {

    char background;
    char cels;    

    cin >> background >> cels; 

    vector<vector<bool>> M (W, vector<bool> (2*W, false));
    vector<vector<bool>> M_post (W, vector<bool> (2*W, false));

    int i, j;

    while (cin >> j >> i) M[i][j] = true;

    cout<<"\x1b[2J"; // Erase all the terminal

    while (true) {

        cout<<"\x1b[H"; // Erase the board 

        //Top part of the board

        cout << "╔";
        for (int i = 1; i < 2*W+1; ++i) cout << "═";
        cout << "╗" << endl;

        //Board
        for (int i = 0; i < W; ++i){
            cout << "║";
            for (int j = 0; j < 2*W; ++j) {
                if (M[i][j]) {
                    cout << cels;
                    M_post[i][j] = living_cells_rules(i, j, M);
                }
                else {
                    cout << background;
                    M_post[i][j] = dead_cells_rules(i, j, M);
                }
            }
            cout << "║" << endl;
        }
        
        //Bottom part of the board

        cout << "╚";
        for (int i = 1; i < 2*W+1; ++i) cout << "═";
        cout << "╝" << endl;

        M = M_post; //Update matrix
        std::this_thread::sleep_for(50ms); //Delay
    }
}