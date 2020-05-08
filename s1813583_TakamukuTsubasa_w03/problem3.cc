/**
 *    author:  Tsubasa Takamuku
 *    created: 2020/05/08  
 *    the AC submission code    
**/

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t;
    cin >> t;

    while (t--){
        int n;
        cin >> n;

        int p;
        cin >> p;

        vector<int> bars(p);
        for (int i = 0; i < p; i++) cin >> bars[i];

        // dp[j] cf. the ant book (p63)
        // jを作れるか否かを表す
        // dp[n] == 1であれば答えはyesとなる.
        vector<int> dp(101010,0);

        dp[0] = 1; // 0はもともと作ることができる

        for (int i = 0; i < p; i++){
            for (int j = 1000-bars[i]; j >= 0; j--) dp[j+bars[i]] |= dp[j];
        }

        if (dp[n] == 1){
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }
    return 0;
}