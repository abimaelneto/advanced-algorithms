#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

#define MAX 8  //board size

//each column supports only one queen. Example: if( rows[3] == 5), then there's a queen at column 4, row 5.
int rows[MAX];

int path_count = 0; //recursion counter
vector<int> sums; // vector with sums

int board[MAX][MAX]; // board with values

bool valid(int lin, int col){
	// checks if any queen threats the one we're trying to position
	for (int rp = 0; rp < col; rp++)
		if (rows[rp] == lin || (abs(rows[rp]-lin) == abs(rp-col)))
			return false;
	return true;

}

void count_path_sum(){
    int sum = 0;
    for(int i = 0; i < MAX; i++) {
        sum += board[i][ rows[i] ];
    }
    sums.push_back( sum );
}

void print_lesser_sum(){
    sort(sums.begin(), sums.end(), greater<int>());
    printf("%5d\n", sums[0]);
}

void backtracking(int c){
	// if a path was closed
    if (c == MAX){
		path_count++;
        count_path_sum();
		//imprimeTab(rows);
	} else {
		// for each row, try to position the queen
		for (int lin = 0; lin < MAX; lin++)
			if (valid(lin, c)){
				rows[c] = lin;
				backtracking(c+1);
			}
	}
}

int main() {

    // read number of boards
    int boards_number;
    cin >> boards_number;
    
    // for each board
    for( int b = 0; b < boards_number; b++) {
        
        //array initialization with zeros
        memset(rows, 0, sizeof(rows) );
        path_count = 0;
        sums.clear();

        //reads board values
        for( int i = 0; i < 8; i++) {
                        
            //reads and pushes to board position
            for( int j = 0; j < 8; j++) {
                cin >> board[i][j];
            }

            //next line
            string blank;
            getline(cin, blank);

        }
        
        //starts recursion
        backtracking(0);
        
        //prints desired result
        print_lesser_sum();
    }
   

    return 0;
}