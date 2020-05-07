/**
 *    author:  Tsubasa Takamuku
 *    created: 2020/05/07  
 *    the AC submission code    
**/

/*
strategy:
状態数を減らしたい・・・状態をまとめる・・・以前の結果をメモして後で利用する
典型的なDP問題である
dp[x][y] : total x円で y番目まで購入できるか
*/


#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;

    int m, c;
    
    while (n--){
        scanf("%d%d", &m, &c);

        vector<vector<int>> dp(220, vector<int>(22));
        dp[0][0] = 1; // 0円で0番目のものを購入できる（何も買わないならばコスト０円）

        for (int i = 0; i < c; i++){
            int k;
            cin >> k;
            
            for (int j = 0; j < k; j++){

                int money;
                cin >> money;

                // bitを立てる (or操作を行う)

                for (int x = 0; x + money <= m; x++){
                    dp[x+money][i+1] |= dp[x][i]; //予算内のものをすべて買う
                }
            }

            int ans = m;
            for (; ans >= 0; ans--){
                if (dp[ans][c] > 0) break;
            }
            if (ans < 0) cout << "no solution" << endl;
            else cout << ans << endl;

        }


    }
    return 0;
}
