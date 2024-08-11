#include<bits/stdc++.h>
#include<stack>
using namespace std;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    string a;
    int n,sum=0;
    cin>>n>>a;
    for(int i=0;i<n;i++){
        stack<char> c;
        for(int j=i;j<n;j++){
            if(c.empty()){c.push(a[j]);continue;}
            if(c.top()==a[j])c.pop();
            else c.push(a[j]);
            if(c.empty())sum++;
        }
    }
    cout<<sum;
    return 0;
}
