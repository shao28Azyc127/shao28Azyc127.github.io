#include<bits/stdc++.h>
using namespace std;
vector<int>ve;
stack<int>st;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,ansI=0,con=0,m;
    cin>>n;
    for(int i=n;i>=1;i--){
        ve.push_back(i);
    }
    while(ve.empty()==false){
        m=ve.size();
        for(int i=0;i<m;i++){
            if(i%3==0){
                if(ve.back()==n){
                    ansI=con+1;
                }
                ve.pop_back();
            }
            else{
                st.push(ve.back());
                ve.pop_back();
            }
        }
        m=st.size();
        for(int i=0;i<m;i++){
            ve.push_back(st.top());
            st.pop();
        }
        con++;
    }
    cout<<con<<" "<<ansI;
    return 0;
}
