#include<bits/stdc++.h>
using namespace std;
int cnt=0,n;
string s;
char st[2000002];
int top=0;
void print(){
    for(int i=1;i<=top;i++){
        cout<<st[i];
    }
    cout<<endl;
    return;
}
void check(int l){
    top=0;
    st[++top]=s[l];
    // cout<<l<<" "<<l<<endl;
    // print();
    for(int i=l+1;i<n;i++){
        // cout<<l<<" "<<i<<endl;
        
        if(s[i]==st[top]){
            top--;
        }else{
            st[++top]=s[i];
        }
        // print();
        if(top==0){
            cnt++;
        }
    } 
    return;
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n>>s;
    for(int i=0;i<n;i++){
        check(i);
    }    
    cout<<cnt<<endl;
    return 0;
}