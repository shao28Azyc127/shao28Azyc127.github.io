#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int d;
int v[100007];
int sum[100007];
int nxt[100007];
int a[100007];
int rem=0;
/*
rem: how many kms remain
*/
/*
csh: the cash now you need
*/
int csh=0;
struct node{
    int id;
    int c;
};
stack<node> st;
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>v[i];
        sum[i]=sum[i-1]+v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        node nw={i,a[i]};
        while(!st.empty()&&st.top().c>nw.c){
            nxt[st.top().id]=i;
            st.pop();
        }
        st.push(nw);
    }
    while(!st.empty()){
        nxt[st.top().id]=n;
        st.pop();
    }
    int l=1;
    while(l<n){
        int t=nxt[l];
        int dis=sum[t-1]-sum[l-1];
        int j=(dis-rem+d-1)/d;
        csh+=j*a[l];
        rem=rem+j*d-dis;
        l=t;
    }
    cout<<csh<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
/*
zyctc AK IOI
*/
