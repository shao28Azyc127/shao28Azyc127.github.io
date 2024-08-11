#include<bits/stdc++.h>
using namespace std;
int n,m,flag1,flag2;
char test;
char data[3005][3005],data_min[3005][3005],data_max[3005][3005];
bool cmp_min(char a,char b){
    return a<b;
}
bool cmp_max(char a,char b){
    return a>b;
}
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>test;
            data[i][j] = test;
            data_min[i][j] = data[i][j];
            data_max[i][j] = data[i][j];
        }
    }
    for(int i = 0;i<n;i++){
        sort(data_min[i],data_min[i]+m,cmp_min);
    }
    for(int i = 0;i<n;i++){
        sort(data_max[i],data_max[i]+m,cmp_max);
    }
    for(int i = 0;i<n;i++){
        flag1 = 0;
        for(int j = 0;j<n;j++){
            if(i==j) continue;
            flag2 = 0;
            for(int p = 0;p<m;p++){
                if(data_min[i][p] < data_max[j][p]){
                    flag2 = 0;
                    break;
                }
                else if(data_min[i][p] < data_max[j][p]){
                    continue;
                }
                else{
                    flag2 = 1;
                    break;
                }
            }
            if(flag2 == 1){
                flag1 = 1;
                break;
            }
        }
        if(flag1 == 1) cout<<0;
        else cout<<1;
    }
    return 0;
}
