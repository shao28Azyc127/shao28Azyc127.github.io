#include<bits/stdc++.h>
#define int long long

const int N =1e5+10;

using namespace std;

int n;
int a[N];//The price of each station
int v[N];//The distance of 1 ~ (n-1)
int d;//How long can one L accelerate

int ans;//Money
int minn=1e18;//minimum price;
int oil=0;

signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    scanf("%lld%lld",&n,&d);
    for(int i=1;i<=n-1;i++){
        scanf("%lld",&v[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        minn=min(a[i],minn);
    }

    for(int t=1;t<n;){
        if(a[t] >= a[t+1]){
            int OIL_ = ceil((v[t]-oil)*1.0 / d);//accelerate distance to cost OIL_
            ans += OIL_ * a[t];
            oil = OIL_ * d - (v[t]-oil);
            //cout<<"1--"<<oil<<" "<<ans<<" "<<OIL_<<" "<<t<<endl;
            t++;
        }
        if(a[t] == minn){
            int sum=0;
            for(int i=t;i<=n-1;i++){
                sum+=v[i];
            }
            int OIL_ = ceil((sum-oil)*1.0 / d);
            ans += OIL_ * minn;
            //cout<<"2--"<<oil<<" "<<ans<<" "<<OIL_<<" "<<t<<endl;
            printf("%lld\n",ans);
            return 0;
        }
        if(a[t] < a[t+1]){
            int sum=v[t];
            int flag=0;
            for(int i=t;i<=n;i++){
                if(a[i] <= a[i+1]){
                    sum+=v[i];
                    flag = i+1;
                }else break;
            }
            int OIL_ = ceil((sum-oil)*1.0 / d);
            ans += OIL_ * a[t];
            oil = (OIL_ * d) - (sum-oil);
            //cout<<"3--"<<OIL_<<" "<<t<<" "<<oil<<" "<<flag<<endl;
            if(flag==n){
                printf("%lld\n",ans);
                return 0;
            }
            t=flag+1;
        }
    }

    printf("%lld\n",ans);

    return 0;
}
