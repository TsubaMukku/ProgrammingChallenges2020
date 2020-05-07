/**
 *    author:  Tsubasa Takamuku
 *    created: 2020/05/07  
 *    the AC submission code    
**/

/*
strategy:
use binary search for 
・numerator
・denominator
respecitively...
*/

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){

    int m, n;

    while (1){
        cin >> m >> n;
        if (m == 1 && n == 1) break;

        int pm = 0, nm = 1;
        int pn = 1; int nn = 0;
        string ans = "";

        while (1){

            int midM = (pm + nm);
            int midN = (pn + nn);

            if (midM == m && midN == n){

                // found the number
                cout << ans << endl;
                break;
            } 
            else{

                if (midM * n > midN * m){

                    // going left
                    ans += 'L';
                    nm = midM;
                    nn = midN;
                }
                else{
                    // going right
                    ans += 'R';
                    pm = midM;
                    pn = midN;
                }

            }
        }  


    }


}