#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct Node{
    int x[7];
};
int n,a[7];
queue<Node> q,q2;
bool check(Node tmp){
    int cnt=0;
    for(int i=1;i<=5;i++) if(tmp.x[i]!=a[i]) cnt++;
    if(cnt==1) return true;
    if(cnt==0||cnt>2) return false;
    for(int i=1;i<=4;i++){
        if(tmp.x[i]!=a[i]){
                if(tmp.x[i+1]==a[i+1]) return false;
            int x1=tmp.x[i]-a[i],x2=tmp.x[i+1]-a[i+1];
            if(x1<0) x1+=10;
            if(x2<0) x2+=10;
            if(x1==x2) return true;
            return false;
        }
    }
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    if(n==0){
        cout<<100000<<endl;
        return 0;
    }
    cin>>a[1]>>a[2]>>a[3]>>a[4]>>a[5];
    Node tmp;
    for(int i=1;i<=5;i++) tmp.x[i]=a[i];
    for(int i=1;i<=5;i++){
        for(int j=0;j<=9;j++){
                if(j==a[i]) continue;
            tmp.x[i]=j; q.push(tmp);
            tmp.x[i]=a[i];
        }
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<10;j++){
            tmp.x[i]=(a[i]+j)%10; tmp.x[i+1]=(a[i+1]+j)%10;
            q.push(tmp);
            tmp.x[i]=a[i]; tmp.x[i+1]=a[i+1];
        }
    }
    for(int i=2;i<=n;i++){
            for(int i=1;i<=5;i++) cin>>a[i];
        while(!q.empty()){
            Node tmp=q.front(); q.pop();
            if(check(tmp)) q2.push(tmp);
        }
        while(!q2.empty()){
            q.push(q2.front()); q2.pop();
        }
    }
    int ans=0;
    while(!q.empty()){
        q.pop(); ans++;
    }
    cout<<ans<<endl;
    return 0;
}
