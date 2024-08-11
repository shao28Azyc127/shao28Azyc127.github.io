#include <bits/stdc++.h>
using namespace std;
long long n,ans=0,lvl[2222222];
vector<long long> start;
string s;
long long judge(long long l){//以l为开始
    stack<char> st;
    long long sum=0,cnt=0;
    for(long long i=l;i<n;i++){
        if(!st.empty()&&st.top()==s[i]){
            st.pop();
        }
        else{
            st.push(s[i]);
        }
        if(st.empty()){
                //cout<<i<<" "<<l<<endl;
            sum++;
        }
        /*if(lvl[i]==lvl[l]){

                sum++;
            //return 1;
        }*/
    }
    return sum;
}
void init(){
    stack<char> st;
    long long sum=0;
    for(long long i=0;i<n;i++){
        if(!st.empty()&&st.top()==s[i]){
            lvl[i]=st.size();
            start.push_back(i);
            st.pop();
        }
        else{
            st.push(s[i]);
            lvl[i]=st.size();
        }
    }
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n>>s;
    init();
    //judge(0,n-1);
    //cout<<start.size();
    for(long long i=0;i<n;i++){
        ans+=judge(i);
        //cout<<ans<<endl;
        //if(i%100==0)cout<<i<<endl;
    }
    //cout<<fstjudge(0,n-1);
    cout<<ans;
    return 0;
}


