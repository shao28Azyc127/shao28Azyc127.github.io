#include<iostream>
#include<string>
#include<cstdio>
#include<stack>
using namespace std;
int n,sum;
string a;
bool c(string k){
    //if(k[0]==k[1]&&k.size()==2) return 1;
    if(k.size()%2==1) return 0;
    stack<char> st;
    st.push(k[0]);
    for(int i=1;i<k.size();i++){
        if(st.empty()) st.push(k[i]);
        else if(st.top()==k[i]) st.pop();
        else st.push(k[i]);
    }
    if(!st.empty()) return 0;
    return 1;
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    cin>>a;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j+=2){
            string b=a.substr(i,j-i+1);
            if(c(b)) sum++;
        }
    }
    cout<<sum;
    return 0;
}
