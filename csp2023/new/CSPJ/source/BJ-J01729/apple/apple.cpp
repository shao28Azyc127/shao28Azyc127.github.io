#include<bits/stdc++.h>
using namespace std;
int n;
int ans=1,tot;

int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int a[1000000];
    for(int i=1;i<=n;i++){
        a[i]=1;
    }
    cin>>n;
    int j=1;
    for(int i=1;i<=n;i++){
        if(a[i]==0){
                int x=i+1;
               a[i]=a[x];
            }
        tot++;
        if(j==n){
            ans=i;
        }
        for(j=i;j<=n;j+=3){
            a[j]=0;
        }
    }
    cout<<tot<<" "<<ans;
    return 0;
}
/*#include<bits/stdc++.h>
using namespace std;
int n;

queue <int> p;
queue <int> q;
int main(){
    int ans=0,tot=0;
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    //int a[1000000];
    //for(int i=1;i<=n;i++){
    //    a[i]=1;
    //}
    cin>>n;
    for(int i=1;i<=n;i++){
        q.push(i);
    }

    int j=1;
    while(q.size()||p.size()){

        tot++;
        if(q.size()){
            for(int i=1;i<=q.size();i++){
                q.pop();
                p.push(q.front());
                q.pop();
                p.push(q.front());
                q.pop();
            }
        }else{
            for(int i=1;i<=p.size();i++){
                if(i==n){
                    ans=i;
                }
                p.pop();
                q.push(p.front());
                p.pop();
                q.push(p.front());
                p.pop();
            }
        }
    }

    cout<<tot<<" "<<ans;
    return 0;
}*/
