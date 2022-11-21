#include <bits/stdc++.h>
 
using namespace std;
 
int n, m;
vector<string> flat;
 
bool good(pair<int,int> xy){
    if(xy.first < 0 or n <= xy.first or xy.second < 0 or m <= xy.second)
        return false;
    if(flat[xy.first][xy.second] != '.' )
        return false;
    return true;
}
 
int main(){
    cin >> n >> m;
    flat.resize(n);
    pair<int,int> A;
    pair<int,int> B;
    for(int i = 0; i < n; i++){
        cin >> flat[i];
        for(int j = 0; j < m; j++){
            if(flat[i][j] == 'A')
                A = {i, j};
            if(flat[i][j] == 'B'){
                B = {i, j};
                flat[i][j] = '.';
            }
        }
    }
    queue<pair<int,int>> q;
    q.push(A);
    while(q.size()){
        pair<int,int> akt = q.front();
        q.pop();
        if(good({akt.first + 1, akt.second})){
            flat[akt.first + 1][akt.second] = 'D';
            q.push({akt.first + 1, akt.second});
        }
        if(good({akt.first - 1, akt.second})){
            flat[akt.first - 1][akt.second] = 'U';
            q.push({akt.first - 1, akt.second});
        }
        if(good({akt.first, akt.second + 1})){
            flat[akt.first][akt.second + 1] = 'R';
            q.push({akt.first, akt.second + 1});
        }
        if(good({akt.first, akt.second - 1})){
            flat[akt.first][akt.second - 1] = 'L';
            q.push({akt.first, akt.second - 1});
        }
    }
    if(flat[B.first][B.second] == '.'){
        cout << "NO" << endl;
        return 0;
    }
    string ans = "";
    while(B != A){
        //cout << B.first << ' ' << B.second << endl;
        ans += flat[B.first][B.second];
        if(flat[B.first][B.second] == 'D')
            B.first--;
        else if(flat[B.first][B.second] == 'U')
            B.first++;
        else if(flat[B.first][B.second] == 'R')
            B.second--;
        else if(flat[B.first][B.second] == 'L')
            B.second++;
    }
    reverse(ans.begin(), ans.end());
    cout << "YES" << endl;
    cout << ans.size() << endl;
    cout << ans << endl;
}