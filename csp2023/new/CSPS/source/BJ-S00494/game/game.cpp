#include <bits/stdc++.h>
using namespace std;
int n,len,sum;
string s;
bool dele(string a){
    char x[200005];
    int l=a.size(),k=1;
    for(int i=0;i<=l;i++){
        x[k]=a[i];
        if(x[k]==x[k-1]){
            x[k]=0;
            x[k-1]=0;
            k-=2;
        }
        k++;
    }
    for(int i=0;i<k;i++){
        if(x[i]==x[i+1]){
            x[i]=0;
            x[i+1]=0;
        }
    }
    for(int i=0;i<=k;i++){
        if(x[i]!=0){
            return false;
        }
    }
    return true;
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>len>>s;
    for(int i=0;i< len;i++){
        char str[20005];
        for(int j=i+1;j<len;j++){
            for(int k=i;k<=j;k++){
                str[k-i]=s[k];
            }
            if(dele(str)){
                sum++;
            }
            memset(str,0,len);
            }
       }
    cout<<sum;
    return 0;
}
