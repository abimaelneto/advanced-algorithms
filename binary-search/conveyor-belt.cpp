#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool test(vector<int> &conveyorBelt, int n_my_vessels, int vesselsSize) {

    vector<int> vesselsMilk;
    int v = 0;
    vesselsMilk.resize(n_my_vessels);
    for (int i = 0; i < (int) conveyorBelt.size(); i++) {
        int milk = vesselsMilk.begin()[v];
        int load = conveyorBelt.begin()[i];
        if ( milk + load > vesselsSize) {
            v++;
        }
        vesselsMilk.begin()[v] = milk + load;
    }
    if( v > n_my_vessels-1)  {
        return false;

    }
    return true;
}

int searchMinimum(vector<int> &conveyorBelt, int n_my_vessels, int min, int max) {

    int ans = max;
    int l = min;
    int r = max;
    while(l <= r) {
        int mid = (l + r) / 2;

        bool valid = test(conveyorBelt, n_my_vessels, mid);

        if(valid){

            r = mid-1;
            ans = std::min(ans, mid);
        }

        else {
            l = mid+1;
        }

    }

    return ans;
}

int main(){
    int n_conveyor_vessels = 0;
    int n_my_vessels = 0;

    cin >> n_conveyor_vessels;
    
    //each test
    while(!feof(stdin)) {

        cin >> n_my_vessels;

        vector<int> conveyorBelt;
        
        int max = 0;
        int greatestMilk = 0;

        int tmp;
        for (int i = 0; i < n_conveyor_vessels; i++) {
            cin >> tmp;
            conveyorBelt.push_back(tmp);
            max += conveyorBelt[i];

            if(tmp > greatestMilk) greatestMilk = tmp;
        }

        int result = searchMinimum(
            conveyorBelt,
            n_my_vessels, 
            greatestMilk,
            max
        );
        cout << result << endl;

        cin >> n_conveyor_vessels;
    }
    return 0;
}