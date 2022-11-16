#include <iostream>
#include <vector>
using namespace std;
vector <string> L;
int n,m;
void dfs(int x, int y){
    L[x][y] = '#';
    if((x+1) < n && L[x+1][y] == '.')
        dfs(x+1,y);
    if((x-1) >= 0 && L[x-1][y] == '.')
        dfs(x-1,y);
    if((y+1) < m && L[x][y+1] == '.')
        dfs(x,y+1);
    if((y-1) >= 0 && L[x][y-1] == '.')
        dfs(x,y-1);
}
int main(){
    int wynik = 0;
    cin >> n >> m;
    L.resize(n);
    for(int i = 0; i < n; i++)
        cin >> L[i];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(L[i][j] == '.'){
                dfs(i, j);
                wynik++;
            }
        }
    }
    cout << wynik << endl;
    return 0;
}