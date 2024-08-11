#include<bits/stdc++.h>
using namespace std;
int n,m;
char a[3001][3001];
string maxl[3001],minl[3001];

bool cmp(char a,char b){
    return a > b;
}

int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    for(int i = 0;i < n;i++){
        cin>>a[i];
    }
    if(n == 1){
        cout<<1;
        return 0;
    }
    for(int i = 0;i < n;i++){
        sort(a[i],a[i]+m);
        for(int j = 0;j < m;j++){
            minl[i] += 'a';
            minl[i][j] = a[i][j];
        }
    }
    for(int i = 0;i < n;i++){
        sort(a[i],a[i]+m,cmp);
        for(int j = 0;j < m;j++){
            maxl[i] += '0';
            maxl[i][j] = a[i][j];
        }
    }
    bool f;
    for(int i = 0;i < n;i++){
        f = true;
        for(int j = 0;j < n;j++){
            if(i == j){
                continue;
            }
            if(minl[i] >= maxl[j]){
                f = false;
                break;
            }
        }
        if(f == true){
            cout<<1;
        }else{
            cout<<0;
        }
    }
    return 0;
}
