#include <bits/stdc++.h>
using namespace std;
int n,m;
char s[3002][3002];
int a[3005][3005];
//int amin[3005][3005];
//int amax[3005][3005];
char smin[3002][3002];
char smax[3002][3002];
int main(){

    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin >> n >>m;
    if(n == 1){
        cout <<"1";
        return 0;
    }
    for(int i = 1; i <= n; i++) cin >> s[i];
    if(m == 1){
        int id;
        char minp = 'z';
        for(int i = 1; i <= n; i++){
            if(s[i][0] < minp){
                minp = s[i][0];
                id = i;
            }
            //if(s[i] == minp) id = -1;
        }
        for(int i = 1; i <= n; i++){
            if(i == id) cout << "1";
            else cout << "0";
        }
        return 0;
    }

    //for(int i = 1; i <= n; i++)cout << s[i] << endl;
    //for(int i = 1; i <= n; i++){
    //    for(int j = 0; j < m; j++) cout << s[i][j];
    //    cout << endl;
    //}
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < m; j++){
            a[i][j] = (int)s[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        sort(a[i],a[i]+m);
    }
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < m; j++)smin[i][j]= (char)a[i][j];

    }
    //for(int i = 1; i <= n; i++){
    //    for(int j = 0; j < m; j++) cout << smin[i][j];
    //    cout << endl;
    //}
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < m; j++){
            smax[i][m-j-1] = smin[i][j];
        }
    }
    //for(int i = 1; i <= n; i++){
    //    for(int j = 0; j < m; j++) cout << smax[i][j];
    //    cout << endl;
    //}
    int id=1;
    char minid[3005];
    char minid2[3005];
    for(int i = 0; i < m; i++) minid[i] = smax[1][i];
    for(int i = 1; i < n; i++){
        int flag = 1;
        for(int j = 0 ; j < m ; j++){
            if(minid[j] < smax[i][j]) flag = 0;
            else if(minid[j]>smax[i][j]) break;
            else {
                if(j==m-1)flag=0;
            }
        }
        if(flag == 1){
            for(int j = 0; j < m; j++) minid2[j] = minid[j];
            for(int j = 0; j < m; j++) minid[j] = smax[i][j];
            id = i;
        }
    }
    //for(int i = 0; i < m; i++)cout << minid[i];
    //cout << endl;
    for(int i = 1; i <= n; i++){
        if(i == id){
            int flag = 1;
            for(int j = 0 ; j < m ; j++){
                if(minid2[j] < smin[i][j]) flag = 0;
                else if(minid2[j]>smin[i][j]) break;
                else {
                    if(j==m-1)flag=0;
                }
            }
            if(flag == 1) cout <<"1";
            else cout <<"0";
        }else{
            int flag = 1;
            for(int j = 0 ; j < m ; j++){
                if(minid[j] < smin[i][j]) flag = 0;
                else if(minid[j]>smin[i][j]) break;
                else {
                    if(j==m-1)flag=0;
                }
            }
            if(flag == 1) cout <<"1";
            else cout <<"0";
        }
    }
    return 0;
}
