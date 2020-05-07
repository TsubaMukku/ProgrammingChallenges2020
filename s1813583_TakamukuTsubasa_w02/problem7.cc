/**
 *    author:  Tsubasa Takamuku
 *    student number: 201813583
 *    created: 2020/05/07 9:17      
**/

#include <iostream>
#include <map>
#include <cstdio>
#include <vector>

using namespace std;

int main(){

    int t; // the number of test cases;
    cin >> t;

    string st;

    for (int i = 0; i < t; i++){
        int k;
        cin >> k;

        double ans = 0;

        vector<char> letters(k+1);
        vector<double> pay(k+1);

        for (int j = 0; j < k; j++){
            char c;
            double v;
            cin >> c >> v;
            letters[j] = c;
            pay[j] = v;
        }

        int m;
        cin >> m;

        getline(cin,st);
        for (int j = 0; j < m; j++){
            getline(cin,st);

            for (int k = 0; k < st.size(); k++){
                for (int p = 0; p < k; p++){

                    if (st[k] == letters[p]) ans += pay[p];
                }
            }

        }
        double money = ans / 100.0;
        printf("%.2lf",money); // cents with one leading zero if necessary
        cout << '$' << endl;
    }

    return 0;
}