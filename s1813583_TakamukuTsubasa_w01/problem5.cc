/**
 *    author:  Tsubasa Takamuku
 *    student number: 201813583
 *    created: 2020/04/27 8:02      
**/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> daysForMonths = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int residue, days, months, years;

bool isUruu(int y){
    
    if (y % 400 == 0) return true;
    else if (y % 4 == 0 && y % 100 != 0) return true;
    return false;
}


int getTotalDays(int d, int m, int y){
    
    int ans = 0;
    
    for (int i = 1; i < y; i++){
        if (isUruu(i)) ans += 366;
        else ans += 365;
    }
    
    for (int j = 1; j < m; j++){
        ans += daysForMonths[j-1];
        if (j == 2 && isUruu(y) ) ans++;
    }
    
    ans += d;
    return ans;
}


void solve(int d){
    
    int y = 1, m = 1; // start this procedure from year 1, month 1
    
    // calculate the future year
    while (365 <= d){
        
        // 1 year passes
        if ( isUruu(y) ) d -= 366;
        else d -= 365; 
        
        // if d is decreased to be nonpositive number, d must be recovered
        if (d <= 0) {
            d += (isUruu(y) ? 366 : 365);
            break;
        }
        y++;
    }
    
    // calculate the future month
    if(d){
        
       if (isUruu(y)) daysForMonths[1]++; // uruu year
       
       while (d > daysForMonths[m-1]){
           d -= daysForMonths[m-1];
           
           m++;
       }
    }
    
    cout << d << " " << m  << " " << y << endl;
}


int main(){
    
    while (cin >> residue >> days >> months >> years){
        
        if (residue == 0 && days == 0 && months == 0 && years == 0) break;
    
        daysForMonths[1] = 28; // it this line does not exist, results would be incorrect // found by debug
        
        int sumOfDays = getTotalDays(days, months, years);
        
        sumOfDays += residue; // get total number of days
        
        solve(sumOfDays); // translate total number of days into the future date
    }
    
    return 0;
}