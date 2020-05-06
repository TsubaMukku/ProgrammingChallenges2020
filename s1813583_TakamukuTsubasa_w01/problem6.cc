/**
 *    author:  Tsubasa Takamuku
 *    student number: 201813583
 *    created: 2020/05/01 12:33      
**/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> numbers = {"Ace","2", "3", "4", "5", "6", "7", "8", "9","10", "Jack", "Queen", "King"};
vector<string> suits = {"Clubs","Diamonds","Hearts","Spades"};

int main(){
        int t;
        cin >> t;

        for (int i = 0; i < t; i++){
            int n;
            cin >> n;
            vector<vector<int>> shuffles(110, vector<int>(60));
            vector<int> current(60);
            
            for (int j = 1; j <= n; j++){
                for (int k = 1; k <= 52; k++) cin >> shuffles[j][k];
            }
            
            for (int j = 1; j <= 52; j++) current[j] = j;
                
            string buf;
            getline(cin,buf);

            while (1){
                std::string s;
                std::getline(std::cin, s);

                if (s == "") break;

                int num = atoi(s.c_str());
                
                vector<int> temp(60);
                
                for (int i = 1; i <= 52; i++) temp[i] = current[shuffles[num][i]];
                for (int j = 1; j <= 52; j++) current[j] = temp[j];
            }
            
             for (int i = 1; i <= 52; i++){
             cout << numbers[(current[i]) % 13] << " of " << suits[(current[i]-1)/13] << endl;
             }
            if (i != t-1) cout << endl;
        }
        
}

