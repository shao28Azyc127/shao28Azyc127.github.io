#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    int n,m;
    cin>>n>>m;
    string a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    string c;
    if(n==1&&m==1){
        cout<<1;
    }
    else if(m==1&&n!=1){
        int min = 114514;
        int d[n];
        for(int i=0;i<n;i++){
            c = a[i];
            d[i] = c[0] - 'a';
            if(d[i]<min) min = d[i];
        }
        for(int i=0;i<n;i++){
            if(d[i]==min) cout<<1;
            else cout<<0;
        }
    }
    else {
        int d[n][2];
        for(int i=0;i<n;i++){
            c = a[i];
            d[i][0] = c[0] - 'a';
            d[i][1] = c[1] - 'a';
        }
        int h[2],k[2];
        int win = 0,cnt = 0;
        for(int i=0;i<n;i++){
            win = 0;
            cnt = 0;
            for(int j=0;j<n;j++){
                win = 0;
                if(j==i) j++;
                if(j<n){
                    h[0] = d[i][0];
                    h[1] = d[i][1];
                    k[0] = d[j][0];
                    k[1] = d[j][1];
                    if(win == 0){
                        if((h[0]<k[0])||(h[0]==k[0]&&h[1]<k[1])) win = 1;
                    }
                    h[0] = d[i][1];
                    h[1] = d[i][0];
                    k[0] = d[j][1];
                    k[1] = d[j][0];
                    if(win == 0){
                        if((h[0]<k[0])||(h[0]==k[0]&&h[1]<k[1])) win = 1;
                    }
                    h[0] = d[i][0];
                    h[1] = d[i][1];
                    k[0] = d[j][1];
                    k[1] = d[j][0];
                    if(win == 0){
                        if((h[0]<k[0])||(h[0]==k[0]&&h[1]<k[1])) win = 1;
                    }
                    h[0] = d[i][1];
                    h[1] = d[i][0];
                    k[0] = d[j][0];
                    k[1] = d[j][1];
                    if(win == 0){
                        if((h[0]<k[0])||(h[0]==k[0]&&h[1]<k[1])) win = 1;
                    }
                    if(win==1) cnt++;
                }
            }
            if(cnt==n-1) cout<<1;
            else cout<<0;
        }
    }
    return 0;
}