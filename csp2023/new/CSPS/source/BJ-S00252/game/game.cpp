#include<bits/stdc++.h>
using namespace std;
char a[100010];
bool same(int b,int e){
    stack<char> st;
    for(int i=b;i<=e;i++){
        if(!st.empty()&&st.top()==a[i]) st.pop();
        else st.push(a[i]);
    }
    return st.empty();
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n;
    cin>>n;
    char a1;
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(same(i,j)) sum++;
        }
    }
    cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
