#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5;
/*
idea:
    a b b a a a 
->gx0 0 1 0 0 2
we can see that there are actually 5 substrings that can be found,but they counted only 3
-gx20 0 0 0 2 0
    a a a b a b b
aa(1,2) aa(2,3) bb 
->3 substrings 

aaa
aa aa
aaaa
aa aa aaaa
aaaaa
12 23 34 45 1234 2345
aaaaaa
12 23 34 45 56 1234 2345 3456 123456
bbaaaaa
0102132
aaabbaaa
01102233
*/
struct STACK{
    int SIZE;
    int st[N];
    STACK(){SIZE=0;}
    int size(){return SIZE;}
    bool empty(){return SIZE==0;}
    int top(){return st[SIZE];}
    void push(int ch){st[++SIZE]=ch;}
    void pop(){if(SIZE)SIZE--;}
}st;
int n;
string s;
int gx[N];
int pre[N];
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>s;
    pre[0]=1;
    for(int i=1;i<s.size();i++){
        if(s[i]==s[i-1]){
            pre[i]=pre[i-1]+1;
        }
        else pre[i]=1;
        if(pre[i]%2)gx[i]=pre[i]/2;
    }
    ll sm=0;
    for(int i=0;i<s.size();i++){
        if(!st.empty()&&s[st.top()]==s[i]){
            int u=st.top();
            st.pop();
            gx[i]++;
            if(u!=0)gx[i]+=gx[u-1];
            //cerr<<i<<" ";
        }
        else{
            gx[i]+=gx[i-pre[i]+1];
            st.push(i);
        }
       //cerr<<gx[i]<<" ";
        sm+=gx[i];
    }
    cout<<sm<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}