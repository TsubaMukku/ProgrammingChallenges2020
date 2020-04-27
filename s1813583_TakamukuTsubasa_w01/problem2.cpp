/**
 *    author:  Tsubasa Takamuku
 *    student number: 201813583
 *    created: 2020/04/27 10:10      
**/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++){
        cout << "Case " << i+1 << ": ";
        
        vector<int> a(3);
        for (int j = 0; j < 3; j++) cin >> a[j];
        
        sort(a.begin(), a.end());
        cout << a[1] << endl;
     }
    
    return 0;
}
