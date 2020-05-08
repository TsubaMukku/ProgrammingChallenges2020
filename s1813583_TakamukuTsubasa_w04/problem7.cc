#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const long long INF = 1LL<<50;

int main(){
    
    int t;
    cin >> t;

    for (int a = 0; a < t; a++){

        int target, n;
        cin >> target;
        cin >> n;

        vector<long long> values(n);
        for (int j = 0; j < n; j++) cin >> values[j];

        // numberofcoins
        // i円ちょうどを支払うために必要なコインの枚数の最小値を表す
        vector<long long> numberOfCoins(10101,INF);
        numberOfCoins[0] = 0; //0円を支払うためにはコインは不要である

        // cf. the ans book p59 (DP ナップサック)
        for (int i = 0; i < n; i++){
            for (int j = 10000; j - values[i] >= 0; j--){
                numberOfCoins[j] = min(numberOfCoins[j], numberOfCoins[j-values[i]] + 1);
            }
        }

        int numberOfTotalAmountPaid = target;
        while (numberOfCoins[numberOfTotalAmountPaid] == INF) numberOfTotalAmountPaid++;
        int ans = numberOfTotalAmountPaid;
        cout << ans  << " " << numberOfCoins[ans] << endl;
    }
	return 0;
}