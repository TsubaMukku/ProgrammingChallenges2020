/**
 *    author:  Tsubasa Takamuku
 *    created: 2020/05/09　21:38       
**/

#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

vector<int> dx = {1,0,-1,0};
vector<int> dy = {0,1,0,-1};

// 再帰処理を行う
void solve(vector<vector<int>> &grid,int &count){
    bool isAllZero = true;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (grid[i][j] == 1) isAllZero = false;
        }
    }

    if (isAllZero) return;

    vector<vector<int>> temp(3,vector<int>(3));

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            int temp_sum = 0;

            // 上下左右４方向を調べる
            for (int k = 0; k < 4; k++){
                int nx = i + dx[k];
                int ny = j + dy[k];

                if (0 <= nx && nx < 3 && 0 <= ny && ny < 3 && grid[nx][ny] == 1) temp_sum++;
            }
            if (temp_sum % 2 == 0) temp[i][j] = 0;
            else temp[i][j] = 1;
        }
    }
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++) grid[i][j] = temp[i][j];
    }
    count++;
    solve(grid,count);
}

int main(){
    int n;
   scanf("%d",&n);

   while (n--){
       vector<vector<int>> grid(3,vector<int>(3));
       scanf("\n"); // 空白行を処理する
       for (int i = 0; i < 3; i++){
           string s;
           cin >> s;
           
           for (int j = 0; j < 3; j++){
            int input = s[j] - '0';
            grid[i][j] = input;
            }
       }
       int count = -1;
       solve(grid,count);
       cout << count << endl;
   }

}