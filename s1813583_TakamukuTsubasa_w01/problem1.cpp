/**
 *    author:  Tsubasa Takamuku
 *    student number: 201813583
 *    created: 2020/04/27 8:02      
**/

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstdio>

using namespace std;

int main(void){
    
    int x, y;
    
    while (scanf("%d%d",&x, &y) == 2){
        cout << x << " " << y << " ";
        
        int start = min(x,y); // be careful! ex: x = 300, y = 2;
        int end = max(x,y);
        
        long long ans = 0;
        
        // iterate all numbers between start and end
        for (long long i = start; i <= end; i++){
            
            // ex 16 -> 8 -> 4 -> 2 -> 1;
            // count must start from 1;
            long long count = 1;
            long long temp = i;
            
            while (temp != 1){
                if (temp% 2 == 1) temp = 3 * temp + 1;
                else temp /= 2;
                count++;
            }
            
            ans = max(ans, count);
            
        }
        cout << ans << endl;
    }
    
    return 0;
}
