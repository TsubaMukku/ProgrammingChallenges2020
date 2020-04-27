/**
 *    author:  Tsubasa Takamuku
 *    student number: 201813583
 *    created: 2020/04/27 8:02      
**/

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

vector<int> cycleLength(1000000,0);

int getCycleLength(int n){
    
    // base case
    if (n == 1) return 1;
    
    // n >= 2
    
    if (cycleLength[n] > 0) return cycleLength[n];
    
    int length;
    
    if (n % 2 == 1){
        length = 1 + getCycleLength(3*n+1);
    }
    else{
        length = 1 + getCycleLength(n/2);
    }
    
    return cycleLength[n] = length;
}

int main(void){
    
    int x, y;
    
    while (cin >> x >> y){
        cout << x << " " << y << " ";
        
        if (x > y) swap(x,y);
        
        int ans = 0;
        
        for (int i = x; i <= y; i++) ans = max(ans, getCycleLength(i));
        
        cout << ans << endl;
    }
    
    return 0;
}
