/**
 *    author:  Tsubasa Takamuku
 *    created: 2020/05/08  
 *    the AC submission code    
**/

#include <iostream>
#include <vector>
using namespace std;

const int boundary = 1025;

int main(){
    int t;
    cin >> t;

    while(t--){
        int d;
        cin >> d;

        int n;
        cin >> n;

        vector<vector<int>> deadRat(1030,vector<int>(1030));

        for (int i = 0; i < n; i++){
            int x, y, p;
            cin >> x >> y >> p;
            
            // idea: two-dimensional accumulation of sum
            // ２次元累積和を用いて, 正方形領域で殺されるネズミの数を効率よく計算する
            for (int row = x-d; row <= x+d; row++){
                for (int column = y-d; column <= y+d; column++){

                    // grid外にはみ出したらアウト
                    // 考えやすくするために格子点で考える
                    if (0 <= row && row < boundary && 0 <= column && column < boundary){
                        deadRat[row][column] += p;
                    }
                }
            }
        }

        int numberOfDeadRats = 0;
        int ansIndex_x = 0;
        int ansIndex_y = 0;
        // iterate every position in the grid
        for (int i = 0; i < boundary; i++){
            for (int j = 0; j < boundary; j++){
                
                if (deadRat[i][j] > numberOfDeadRats){
                    numberOfDeadRats = deadRat[i][j];
                    ansIndex_x = i;
                    ansIndex_y = j;
                }
            }
        }

        cout << ansIndex_x << " " << ansIndex_y << " " << numberOfDeadRats << endl;

    }

    return 0;
}