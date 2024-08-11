#include<bits/stdc++.h>
using namespace std;
int n,ans1=0,ans2=0;
queue<bool>q[5];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    int p=0;
    for(int i=1;i<n;i++)
        q[p].push(1);
    q[p].push(0);
    int i=1;
    while(!q[0].empty()||!q[1].empty()){
        i=1;
        while(!q[p].empty()){
            if(i%3==1){
                if(q[p].front()==0)
                    ans2=ans1;
                q[p].pop();
            }else{
                q[!p].push(q[p].front());
                q[p].pop();
            }
            i++;
        }
        ans1++;
        p=!p;
    }
    cout<<ans1<<' '<<ans2+1<<endl;
    return 0;
}
