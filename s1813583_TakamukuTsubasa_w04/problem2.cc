

#include <iostream>
#include <vector>
using namespace std;

int main(){

    int b;
    cin >> b;

    for (int i = 1; i <= b; i++){

        int s;
        cin >> s;

        vector<int> niceness(s);
        for (int j = 1; j < s; j++) cin >> niceness[j];

        int temp_sum = 0;
        int temp_max = 0;

        int minIndex = 0;
        int maxIndex = 0;
        int startPos = 0;

        for (int k = 1; k < s; k++){

            temp_sum += niceness[k];
            int diff = maxIndex - minIndex;

            if ((temp_sum == temp_max && (k - startPos) > diff) || temp_max < temp_sum){
                temp_max = temp_sum;
                maxIndex = k;
                minIndex = startPos;
            }
            if (temp_sum < 0){
                temp_sum = 0; // sum must not be negative
                startPos = k; // reset the start position
            }
        }

        if (temp_max){
            cout << "The nicest part of route " << i << " is between stops "  << minIndex+1 << " and " << maxIndex+1 << endl;
        }
        else{
            cout << "Route " << i << " has no nice parts" << endl;
        }
    }

}