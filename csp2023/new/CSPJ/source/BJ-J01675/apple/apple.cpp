#include <bits/stdc++.h>
using namespace std;
int vis[1000000+10];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    memset(vis,0,sizeof(vis));
    int n,now=1,day=0,date;
    cin>>n;
    cout<<n<<endl;
    vis[1]=1;
    while(true){
        int flag=0,real=0;
        for(int i=1;i<=n;i++){
            if(vis[i]==0){
                now=i;
                flag=1;
                break;
            }
        }
        cout<<"d"<<endl;
        cout<<vis[2]<<endl;
        if(flag==0){
            break;
        }

        while(true){
            int next=now+1;
            cout<<"sdf"<<endl;
            if(real==3){
                break;
            }
            if(next>n){
                next=1;
                day++;
            }
            if(vis[next]==1){
                continue;
            }else{
                real++;
            }

            now=(now+1)%n;

        }
        vis[now]=1;
        if(now==n){
            date=day;
        }
    }
    cout<<day<<" "<<date<<endl;
    return 0;
}
