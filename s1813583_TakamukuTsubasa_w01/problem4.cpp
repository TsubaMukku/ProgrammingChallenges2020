/**
 *    author:  Tsubasa Takamuku
 *    student number: 201813583
 *    created: 2020/04/27 10:15      
**/

#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
   
   int t;
   cin >> t;
   
   for (int i = 0; i < t; i++){
       
       cout << "Case " << i+1 << ": ";
       int N;
       cin >> N;
       
       int ans = 1;
       
       for (int j = 0; j < N; j++){
           int s;
           cin >> s;
           
           ans = max(ans, s); // just take the maximum of given speeds : no one can run faster than max speed.
       }
       
       cout << ans << endl;
   }
   
    return 0;
}
