#include <bits/stdc++.h>
using namespace std;
int n,cnt = 0;
char lst[1000100],z[1000100];
bool hui(char lst[],int a,int b){
    if(a >= b - 1){
        if(lst[a] == lst[b]) return true;
        else return false;
    }
    for(int i = a;i <= b;i++){
        for(int j = i + 1;j <= b;j++){
            if(lst[i] == lst[j]){
                int index = 0;
                for(int k = a;k <= b;k++){
                    if(k != i && k != j) z[index++] = lst[k];
                }
                return hui(z,0,index - 1);
            }
        }
    }
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> lst[i];
    }
    for(int i = 0;i < n;i++){
        for(int j = i + 1;j < n;j++){
            if((j - i) % 2 == 1 && hui(lst,i,j)){
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
