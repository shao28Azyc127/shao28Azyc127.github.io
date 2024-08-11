#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,d,u[100005],a[100005],op=10000000,all=0;
    long long ans=0;
    cin>>n>>d;
    for(int i=1;i<=n-1;i++){
        cin>>u[i];
        all+=u[i];
    }
    for(int i=1;i<=n;){
        cin>>a[i];
        op=min(op,a[i]);
    }
    int mins=100000;
    if(n<=8){
        for(int i=1;i<=n;i++){
            if(a[i]<mins){
                mins=a[i];
            }
            ans+=u[i]/mins*d;
        }
        cout<<ans<<endl;
        return 0;#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,d,u[100005],a[100005],op=10000000,all=0;
    long long ans=0;
    cin>>n>>d;
    for(int i=1;i<=n-1;i++){
        cin>>u[i];
        all+=u[i];
    }
    for(int i=1;i<=n;){
        cin>>a[i];
        op=min(op,a[i]);
    }
    int mins=100000;
    if(n<=8){
        for(int i=1;i<=n;i++){
            if(a[i]<mins){
                mins=a[i];
            }
            ans+=u[i]/mins*d;
        }
        cout<<ans<<endl;
        return 0;
    }else if(op==a[1]){
        if(all%op!=0){
            cout<<all/op+1<<endl;
        }else{
            cout<<all/op<<endl;
        }
        return 0;
    }
    int k=n;
    for(int i=1;i<=n;i++){
        long long alll=0;
        for(int j=i;j<=n;j++){
            if(a[j]<a[i]){
                k=j;
                break;
            }
            alll+=u[j];
        }
        if(k==n){
            if((all%a[i])!=0){
                cout<<(alll/a[i]*d)+1<<endl;
            }else{
                cout<<alll/a[i]*d<<endl;
            }
            return 0;
        }
        if((alll%a[i])!=0){
            ans+=(alll/a[i]*d)+1;
        }else{
            ans+=alll/a[i]*d;
        }
        i=k;
    }
    cout<<ans<<endl;
    return 0;
}


    }else if(op==a[1]){
        if(all%op!=0){
            cout<<all/op+1<<endl;
        }else{
            cout<<all/op<<endl;
        }
        return 0;
    }
    int k=n;
    for(int i=1;i<=n;i++){
        long long alll=0;
        for(int j=i;j<=n;j++){
            if(a[j]<a[i]){
                k=j;
                break;
            }
            alll+=u[j];
        }
        if(k==n){
            if((all%a[i])!=0){
                cout<<(alll/a[i]*d)+1<<endl;
            }else{
                cout<<alll/a[i]*d<<endl;
            }
            return 0;
        }
        if((alll%a[i])!=0){
            ans+=(alll/a[i]*d)+1;
        }else{
            ans+=alll/a[i]*d;
        }
        i=k;
    }
    cout<<ans<<endl;
    return 0;
}