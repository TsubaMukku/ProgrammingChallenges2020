/**
 *    author:  Tsubasa Takamuku
 *    student number: 201813583
 *    created: 2020/05/01 12:33      
**/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> numbers = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9","10", "Jack", "Queen", "King"};
vector<string> suits = {"Clubs","Diamonds","Hearts","Spades"};

vector<vector<int>> shuffles(110, vector<int>(60));

vector<int> current(60);

void doShuffles(int a){

    vector<int> temp(60);

    for (int i = 1; i <= 52; i++) temp[i] = current[shuffles[a][i]];
    for (int j = 1; j <= 52; j++) current[j] = temp[j];
}

void printAns(){
    for (int i = 1; i <= 52; i++){
        cout << numbers[(current[i]) % 13] << " of " << suits[(current[i]-1)/13] << endl;
    }
}

int main(){

    while(1){

        std::string s; //文字列型

        std::getline(std::cin, s); 

        if(s == "") return 0; 

        int num = atoi(s.c_str());

        for (int i = 0; i < num; i++){
            int n;
            scanf("%d", &n);
            
            for (int j = 1; j <= n; j++){
                for (int k = 1; k <= 52; k++) cin >> shuffles[j][k];
            }
            
            for (int j = 1; j <= 52; j++) current[j] = j;

            while (1){
                int a;
                cin >> a;

                if (std::cin.fail()) break;
                doShuffles(a);
            }
            printAns();
            if (i != num-1) cout << endl;
        }
        

    }
}

