

// reading a text file

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

typedef vector<int> Vec;
typedef vector<Vec> Matrix;

int main () {
    Matrix womensPreferences;
    Matrix mensPreferences;
    string line;
    ifstream myfile ("1.in");
    
    int testsNumber = 0;
    int marriagesNumber = 0;

    if (myfile.is_open())
    {
        myfile >> testsNumber ;

        for ( int n = 0 ; n < testsNumber; n++ ){
            myfile >> marriagesNumber ;

            for ( int c = 0 ; c < marriagesNumber; c++ ){
                for ( int c = 0 ; c < marriagesNumber; c++ ){

                    getline(myfile, line);
                    womensPreferences[c].push_back(line[2*c])
                    cout << womensPreferences[c];
                }
            }
        }
        myfile.close();
    }

    else cout << "Unable to open file"; 

    return 0;
}