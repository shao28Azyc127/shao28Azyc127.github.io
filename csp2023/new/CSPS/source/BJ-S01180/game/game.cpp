#include<bits/stdc++.h>
using namespace std;

int n,ans=0;
char a[1000077];

stack <char> q;

void xxl(int start,int end){
    q.push('X');
    for(int i=start;i<=end;i++){
        if(a[i]!=q.top()) q.push(a[i]);
        else q.pop();

    }
    if(q.size()==1) ans++;

    while(q.size()!=0){
        q.pop();
    }

}

int main(){

    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);

    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }


    for(int i=1;i<n;i++){
       for(int j=i+1;j<=n;j++){
           xxl(i,j);
        }
    }

    cout<<ans;
    return 0;
}

