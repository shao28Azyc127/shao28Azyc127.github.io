#include<bits/stdc++.h>
using namespace std;
int n,d,minn=9999999,s[100001],al,v[100001],a[100001],ans,le,you;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d",&n,&d);
    for(int i=1;i<=n-1;i++){
        cin>>v[i];
        al+=v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=i;
    }
    for(int i=1;i<=n-1;i++){
        minn=min(minn,a[i]);
    }
    for(int i=1;i<=n;i++){
        le=v[i];
        if(minn==a[1]){
           if(al%d==0){
                cout<<a[1]*(al/d);
                return 0;
           }else{
              cout<<a[i]*(al/d+1);
              return 0;
           }
        }else{
            if(al%d==0){
                for(int j=1;j<=n;j++){
                    if(a[i]>a[i+j]){
                        if(you-le*d>0){
                            you-le/d;
                        }
                        ans+=a[i]*le/d;
                        you+=le/d;
                        break;
                    }else{
                        if(a[i+j]==n){
                            ans+=a[i]+le/d;
                        }
                        le+=v[i+j-1];
                        i++;
                    }
                }
            }else{
                    for(int j=1;j<=n;j++){
                        if(a[i]>a[i+j]){
                            if(you-le*d>0){
                                you-le/d;
                            }
                            ans+=a[i]*(le/d+1);
                            you+=le/d+1;
                            break;
                        }else{
                            if(a[i+j]==n){
                                ans+=a[i]+le/d;
                            }
                            le+=v[i+j];
                            i++;
                        }
                    }
                }
        }
    }
    cout<<ans;
    return 0;
}