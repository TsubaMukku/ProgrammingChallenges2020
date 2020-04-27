/**
 *    author:  Tsubasa Takamuku
 *    student number: 201813583
 *    created: 2020/04/27 10:09      
**/


#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(void){
    
    int n;
    vector<int> a(3030);
    vector<bool> check(3030,false); // check whether i-th element exists or not
    
    while (scanf("%d",&n) == 1){
        
        bool isJolly = true;
        for (int i = 0; i < n; i++) cin>> a[i]; // input
        
        for (int i = 0; i <= 3030; i++) check[i] = false; // initialization
        
        for (int i = 0; i+1 < n; i++){
            if ( abs(a[i+1] - a[i]) < n) check[abs(a[i+1] - a[i])] = true; 
        }
        
        // check whether all the values 1 through n − 1 can be calculated via the input
        for (int i = 1; i < n; i++){
            if (!check[i]){
                isJolly = false;
            }
        }
        
        if (isJolly) cout << "Jolly" << endl;
        else cout << "Not jolly" << endl;
        
    }
    
    return 0;
}


