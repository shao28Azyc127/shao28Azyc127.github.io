#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n,i,top,r=0,conn=0;
    string s;
    int st[2*1000000+10];
    cin>>n;
    cin>>s;
    st[1]=s[0];
    top=1;

    for(i=1;i<s.length();i++){

        if(s[i]==st[top]){
            top--;
            r++;
        }else{
            st[++top]=s[i];
        }
        if(top==0)conn++;

    }
    r=r+conn-1;
    cout<<r;


    return 0;
}
