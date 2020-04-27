/**
 *    author:  Tsubasa Takamuku
 *    student number: 201813583
 *    created: 2020/04/27 10:14      
**/

#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(void){
    int n, b, h, w;
    
    // input while EOF
    while(scanf("%d %d %d %d", &n, &b, &h, &w) == 4){
        
        int ans = b + 1; // threshold value to distinguish "stay home" from '"stay hotel".
        
        for (int i = 0; i < h; i++){
            
            int p;
            cin >> p;
            
            int capacity = 0; // if capacity >= n, they could stay that hotel.
            
            for (int j = 0; j < w; j++){
                
                int a;
                cin >> a;
                
                if (a >= n) capacity = a; // altough this point could be optimized, this implementation is intuitive.

            }
            
            if (n <= capacity) ans = min(ans, p*n); // if capacity >= n, they could stay that hotel.
        }
        
        if (ans == b + 1) cout << "stay home" << endl; // cost outnumbers the budget: do not stay hotel
        else cout << ans << endl; // cost is lower than or equal to the budget: stay hotel
    }
    
    return 0;
}
