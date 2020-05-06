/**
 *    author:  Tsubasa Takamuku
 *    created: 2020/05/06　23:13       
**/

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> grid(3,vector<int>(3));
vector<int> dx = {0,-1,0,1};
vector<int> dy = {1,0,-1,0};

bool isAllZero(){

    bool check = true;

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (grid[i][j] != 0) check = false;
        }
    }
    
    return check;
}

void takeSum(){
    vector<vector<int>> temp(3,vector<int>(3));
    
    // calculation

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){

            int adjecentCell = 0;

            for (int k = 0; k < 4; k++){
                int nx = i + dx[k];
                int ny = j + dy[k];

                if (nx < 0 || 3 <= nx || ny < 0 || 3 <= ny)continue;

                if (grid[nx][ny] == 1) adjecentCell++;
            }
            if(adjecentCell % 2 == 0) temp[i][j] = 0;
            else temp[i][j] = 1;
        }
    }

    // revise the grid

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++) grid[i][j] = temp[i][j];
    }
}

int main(){

    int t; // number of test cases
    cin >> t;

    for (int i = 0; i < t; i++){
       
        for (int j = 0; j < 3; j++){
            for (int k = 0; k < 3; k++) cin >> grid[j][k];
        }

        int index = -1;

        while (!isAllZero()){
            takeSum();
            index++;
        }
        cout << index << endl;
    }

    return 0;
}