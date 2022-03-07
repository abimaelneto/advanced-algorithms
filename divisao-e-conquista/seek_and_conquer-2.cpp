#include <iostream>
#include <set>
#include <vector>
#include <math.h>

using namespace std;

int rec(vector<int> &vector, int i, int j, set< pair<int,int> > &C) {
    
    //acha o menor valor
    auto it = C.begin();
    pair<int, int> val;
    val = *it;

    int k = val.second;
    // do conjunto
    int sij = (val.first)*(j-i+1); 
    int sij1 = 0, sij2 = 0; 
    set < pair<int, int> > C1;

    // cout << endl;
    C.erase({val.first, val.second});
    if(C.size() == 0) {
        return sij;
    }
    //quebra em dois
    if(i<=k-1){   
    
        for(int a = i; a < k; a++){
            C1.insert({vector[a], a});
            C.erase({vector[a], a});            
        }
        sij1 = rec(vector, i, k-1, C1);
    }
    if(k+1<=j) {
        sij2 = rec(vector, k+1, j, C);
    }

    return max(sij, max(sij1, sij2));

}

int main() {
    int n = 0;
    cin >> n;

    vector<int> a(n);
    set < pair<int, int> > s;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s.insert( {a[i], i});
    }

    int c = rec(a, 0, n-1, s);
    cout << c << endl;

    

    return 0;

}