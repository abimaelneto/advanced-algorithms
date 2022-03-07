#include <cstdio>
#include <iostream>
#include <vector>

#define ERRO 0.001
using namespace std;


int teste(vector<int> &vector, int k) {
    int aux = k;

    for( int i = 0; i < (int) vector.size() - 1; i++ ) {
        if(vector[i+1]-vector[i] > aux) return 0;
        if(vector[i+1]-vector[i] == aux) aux--;
    }

    return 1;
}

int binarySearch(vector<int> &vector, int min, int max){
    
    int mid = (max+min)/2;
    // cout << mid << " " << min << " " << max;
    
    int result = teste(vector, mid);
    
    //ends search
    if(min == mid){
        if(result != 1) {
            if(teste(vector, max) == 1) {
                return max;
            };
        }
        return 0;
    } 
    
    
    
    //k worked
    if(result == 1) {
        // cout << "worked " << endl;
        //this k2 worked, but is it the lowest?
        int aux = binarySearch(vector, min, mid);
        if(aux == 0) {
                // cout << mid << " " << min << " " << max;

            return mid;
        }
        mid = aux;
    }

    else {
        //k is too small 
        // cout << "not worked" << endl;
        int aux = binarySearch(vector, mid, max);
        if(aux == 0) {
                // cout << mid << " " << min << " " << max;

            return mid;
        }
        mid = aux;
    }


    return mid;
}

int main(int argc, char const *argv[])
{
	int n_tests;
    cin >> n_tests;

    for( int i = 0; i < n_tests; i++ ){
        int n;
        cin >> n;
        vector<int> rungs_heights(n);

        //for each test: reads the rungs_heights vector, and starts binary search
        long int sum = 0;
        
        for( int j = 0; j < n; j++ ){
            int tmp;
            cin >> tmp;
            rungs_heights.push_back(tmp);
            sum += rungs_heights.rbegin()[0] - rungs_heights.rbegin()[1];
        }

        int result = binarySearch(rungs_heights, 0, sum);
        cout << "Case " << i+1 << ": " << result << endl;
    }


	return 0;
}