/**
 *    author:  Tsubasa Takamuku
 *    created: 2020/05/06　23:13       
**/

#include <iostream>
#include <vector>

using namespace std;

// one to his left and one to his right.
struct buddies{
    int left, right;
};

vector<buddies> line(101010);

int main(){

    int s, b, l, r;

    while (cin >> s >> b){
        if (s == 0 && b == 0) break;

        // initialization
        for (int i = 1; i <= s; i++){
            line[i].left = i-1;
            line[i].right = i+1;
        }

        line[s].right = 0; // not have a right neighbor

        for (int i = 0; i < b; i++){
            cin >> l >> r;

            if (line[l].left != 0) cout << line[l].left << " ";
            else cout << "* ";

            if (line[r].right != 0) cout << line[r].right << endl;
            else cout << "*" << endl;

            /*
            the next living neighbor to the left or to the right of the soldier
            respectively, should become his buddy
            */
            line[line[l].left].right = line[r].right;
            line[line[r].right].left = line[l].left;
         }

         cout << '-' << endl;
    }

    return 0;
}