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

    int n, m;

    while (1){
        cin >> n >> m;
        if (n == 0 && m == 0) break; // The last test case is followed by a line containing ‘0 0’.

        vector<int> dragon(n);
        vector<int> knights(m);

        for (int i = 0; i < n; i++) cin >> dragon[i];
        for (int j = 0; j < m; j++) cin >> knights[j];

        sort(dragon.begin(),dragon.end());
        sort(knights.begin(),knights.end());

        int cost = 0;
        bool isSaved = true;

        // use the double pointer technique (syakutori method)
        for (int indexDragon = 0, indexKnights = 0; indexDragon < n && isSaved; indexDragon++){

            while (indexKnights < m && knights[indexKnights] < dragon[indexDragon]) indexKnights++;

            if (indexKnights == m) isSaved = false; // not enough knights to defeat dragons
            else{
                cost += knights[indexKnights];
                indexKnights++; // one knight can fight against only one dragon.
            }
        }

        if (isSaved) cout << cost << endl;
        else cout << "Loowater is doomed!" << endl;
    }

    return 0;
}