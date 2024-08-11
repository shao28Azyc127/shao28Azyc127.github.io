#include<bits/stdc++.h>
using namespace std;
string a[3009];
string b[3009];
char s[3009];
bool c1(char a1,char a2){
    return a1<a2;
}
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>s[j];
        }
        sort(s+1,s+1+m,c1);
        a[i]=b[i]="";
        for(int j=1;j<=m;j++){
            a[i]+=s[j];
            b[i]+=s[m-j+1];
        }
    }
    for(int i=1;i<=n;i++){
            bool kkksc03;
            kkksc03=1;
        for(int j=1;j<=n;j++){
            if(i!=j){
                if(a[i]>=b[j]){
                    kkksc03=0;
                    break;
                }
            }
        }
        cout<<kkksc03;
    }
    return 0;
}

