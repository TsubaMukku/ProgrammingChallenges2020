/**
 *    author:  Tsubasa Takamuku
 *    created: 2020/05/07  
 *    the AC submission code    
**/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    int t;
    cin >> t;
    int count = 1;

    while (t--){
        int n;
        cin >> n;
        vector<int> heights(n);// range of n is not mentioned??
        vector<int> width(n); // range of n is not mentioned??

        for (int i = 0; i < n; i++) cin >> heights[i];
        for (int i = 0; i < n; i++) cin >> width[i];
        vector<int> dp(4000);
        vector<int> rdp(4000);
        
        //for (int i = 0; i < n; i++) cout << width[i] << " ";
        int res = 0;
        int rres = 0;

        // LIS (cf. the ant book p64)
        for (int i = 0; i < n; i++){
            int temp = width[i];
            dp[i] = width[i];

            for (int j = 0; j < i; j++){
                if (heights[j] < heights[i]) dp[i] = max(dp[i],dp[j] + temp);
            }
            res = max(res, dp[i]);
        }
        
        // reverse the input and take LIS
        reverse(heights.begin(),heights.end());
        reverse(width.begin(),width.end());

        // reverse  LIS (cf. the ant book p64)
        for (int i = 0; i < n; i++){
            int temp = width[i];
            rdp[i] = width[i];

            for (int j = 0; j < i; j++){
                if (heights[j] < heights[i]) rdp[i] = max(rdp[i],rdp[j] + temp);
            }
            rres = max(rres, rdp[i]);
        }

        if (res >= rres){
             printf("Case %d. Increasing (%d). Decreasing (%d).\n", count++, res, rres);
        }
        else{
            printf("Case %d. Decreasing (%d). Increasing (%d).\n", count++, rres, res);
        }
        
    }

    return 0;
}