#include<bits/stdc++.h>
using namespace std;
int n,ans;
char s[1010];
stack<char> st;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;i++) s[i]=getchar();
    for(int i=0;i<n;i++){
        for(int j=!(i&1);j<i;j+=2){
            if((i-j+1)&1) continue;
            for(int k=j;k<=i;k++){
                if(st.size()&&st.top()==s[k]) st.pop();
                else st.push(s[k]);
            }
            if(st.empty()) ans++;
            while(!st.empty()) st.pop();
        }
    }
    printf("%d",ans);
    return 0;
}

