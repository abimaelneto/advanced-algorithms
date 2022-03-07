#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
void printPeople(vector<int> people) {
    
    for(int i : people) {
        cout << i << " ";
    }
    cout << endl;
}
int main() {
    
    // read number of tests
    int n_tests = 0;
    cin >> n_tests;
    
    //reads rest of line and line skip
    string blank;
    getline(cin, blank);
    getline(cin, blank);

    // main loop for each test
    for ( int test = 0; test < n_tests; test++) {
        
        // reads number of people
        int n_people = 0;
        cin >> n_people;
        
        vector <int> left_side, right_side;

        //reads each person from input and push into people vector
        for ( int i = 0 ; i < n_people; i++){
            int person;
            cin >> person;
            left_side.push_back( person );
        } 

        //sort by speed
        sort( left_side.begin(), left_side.end() );

        //crossing main loop
        int total_crossing_time = 0;
        string output_string;

        while( !left_side.empty()) {
            
            switch (left_side.size())
            {
            case 1:
                output_string += to_string(left_side.front()) + '\n';
                total_crossing_time += left_side.front();
                
                left_side.pop_back();
                break;
            case 2:
                output_string += to_string(left_side.front()) + " " + to_string(left_side.back() ) + '\n';

                total_crossing_time += left_side.back();

                left_side.pop_back();
                left_side.pop_back();

                break;
            case 3:
                
                output_string += to_string(left_side.front()) + " " + to_string(left_side.begin()[1] )+ '\n';
                output_string += to_string(left_side.front()) + '\n';
                output_string += to_string(left_side.front()) + " " + to_string(left_side.back() )+ '\n';

                for(int i : left_side) {
                    total_crossing_time += i;
                }

                left_side.pop_back();
                left_side.pop_back();
                left_side.pop_back();

                break;

            default:
                 /* 
                    compares time of crossing options

                    common_case: 
                    - fastest pair crosses
                    - fastest person crosses back
                    - slowest pair crosses
                    - second fastest person crosses back

                    specific_case:
                    - fastest person crosses with slowest person
                    - fastest person crosses back
                     - fastest person crosses with second slowest person
                    - fastest person crosses back
                */
                
                int first_crossing_option_time = left_side.begin()[1] + left_side.front() + left_side.back() + left_side.begin()[1];
                int second_crossing_option_time = left_side.back() + left_side.front() + left_side.rbegin()[1] + left_side.front();

                // if common case is faster, do it
                if( first_crossing_option_time < second_crossing_option_time ) {
                    // fastest pair crosses
                    right_side.insert( right_side.begin(), left_side.begin()[1] );
                    right_side.insert( right_side.begin(), left_side.front() );
                    
                    left_side.erase( left_side.begin() );
                    left_side.erase( left_side.begin() );

                    total_crossing_time += right_side.begin()[1];
                    output_string += to_string(right_side.begin()[0]) + " " + to_string(right_side.begin()[1]) + '\n';
                    // the fastest crosses back
                    left_side.insert( left_side.begin(), right_side.front() );
                    right_side.erase( right_side.begin() );
                    
                    total_crossing_time += left_side.front();
                    output_string += to_string(left_side.front()) + '\n';
                    // slowest pair crosses
                    right_side.push_back( left_side.rbegin()[1] );
                    right_side.push_back( left_side.back() );
                    
                    total_crossing_time += left_side.back();
                    output_string += to_string(left_side.rbegin()[1]) + " " + to_string(left_side.back()) + '\n';
                    
                    left_side.pop_back();
                    left_side.pop_back();
                    // 2nd fastest crosses back
                    left_side.insert( left_side.begin() + 1, right_side.front() );
                    right_side.erase( right_side.begin() );

                    output_string += to_string(left_side.begin()[1]) + '\n';
                    total_crossing_time += left_side.begin()[1];
                }
                else {
                    // fastest person crosses with second slowest person
                    right_side.insert( right_side.begin(), left_side.front() );
                    right_side.push_back( left_side.rbegin()[1] );
                    
                    left_side.erase( left_side.begin() ); 
                    left_side.erase( left_side.end() - 2);
                    
                    total_crossing_time += right_side.back();
                    output_string += to_string(right_side.front()) + " " + to_string(right_side.back()) + '\n';
                    
                    
                    // fastest person crosses back
                    left_side.insert( left_side.begin(), right_side.front() );
                    right_side.erase( right_side.begin() );

                    total_crossing_time += left_side.front();
                    output_string += to_string(left_side.front()) + '\n';

                    
                    // fastest person crosses with slowest person
                    right_side.insert( right_side.begin(), left_side.front() );
                    right_side.push_back( left_side.back() );
                    
                    left_side.erase( left_side.begin() );
                    left_side.pop_back();
                    
                    total_crossing_time += right_side.back();
                    output_string += to_string(right_side.front()) + " " + to_string(right_side.back()) + '\n';
                    // fastest person crosses back
                    left_side.insert( left_side.begin(), right_side.front() );
                    right_side.erase( right_side.begin() );

                    total_crossing_time += left_side.front();
                    output_string += to_string(left_side.front()) + '\n';
                }
                break;
            }
        }
        //desired output
        cout << total_crossing_time << endl << output_string;
        
        if ( test != (n_tests - 1) && n_tests > 1) {
            cout << endl; 
        }

    }
}