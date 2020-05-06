#include <iostream>
#include <vector>

using namespace std;

class UnionFind{
public:

    //親の番号を格納する. Parentだった場合は−(the size)とする
    vector<int> Parent;
    
    //作るときはParentの値を全て-1にする
    //こうすると, すべての頂点が根となる
    UnionFind(int N){
        Parent = vector<int>(N, -1);
    }
    
    //Aがどのグループに属しているか調べる
    int root(int A){
        if (Parent[A] < 0) return A; //自分のグループにいる
        return Parent[A] = root(Parent[A]); //親をつなぎ替える
    }
    
    //size関数を作る
    //自分の所属するグループの頂点数を調べる
    long long size(int A){
        return -Parent[root(A)]; //親をとりたい
    }
    
    //AとBをくっつける
    void connect(int A, int B){
        //AとBを直接繋がない
        //root(A) に root(B)をくっつける　
        //リーダー同士をくっつける
        
        A = root(A);
        B = root(B);
        
        if (A == B){
            return; //すでにくっついてる
        }
            
        //大きい方に小さい方をくっつけたい
        //大小が逆だったらひっくり返す
            
        if(size(A) < size(B)) swap(A, B);
        
        //Aのサイズを更新する
        Parent[A] += Parent[B];
        
        //BのParentをAに変更する
        Parent[B] = A;
        
        return; //くっついた
    }
    
};

vector<vector<int>> check(10000,vector<int>(10000));

int main(){
    int n;
    cin >> n;
    UnionFind uni(n);
    int c, x, y;

    while (cin >> c >> x >> y){
        if (c == 0 && x == 0 && y == 0) break;

        if (c == 1){
            if (check[x][y] == 1 && (uni.root(x) != uni.root(y))) cout << -1 << endl;
            else if (check[x][y] == 1 && (uni.root(x) == uni.root(y))) continue;
            else{
                check[x][y] = 1, check[y][x] = 1;
                uni.connect(x,y);
            }
        }
        else if (c == 2){
            if (check[x][y] == 1 && (uni.root(x) == uni.root(y))) cout << -1 << endl;
            else if (check[x][y] == 1 && (uni.root(x) != uni.root(y))) continue;
            else {
                check[x][y] = 1, check[y][x] = 1;
                uni.connect(x,y);
            }
        }
        else if (c == 3){
            if (check[x][y]){
                if (uni.root(x) == uni.root(y)) cout << 1 << endl;
                else cout << 0 << endl;
            }
            else{
                cout << 0 << endl;
            }
        }
        else if (c == 4){
            if (check[x][y]){
                if (uni.root(x) != uni.root(y)) cout << 1 << endl;
                else cout << 0 << endl;
            }
            else{
                cout << 0 << endl;
            }
        }

    }

    return 0;
}