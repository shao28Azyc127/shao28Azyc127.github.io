#include <bits/stdc++.h>
using namespace std;
int n,cnt,top;
char a[2000010];
char s[2000010];
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    cin>>a;
    for(int j=0;j<n;j++){
        top=0;
        for(int i=j;i<n;i++){
            if(s[top]==a[i]){
                top--;
            }else{
                s[++top]=a[i];
            }
            if(top==0){
                cnt++;
            }
        }
    }
    cout<<cnt;
    return 0;
}
