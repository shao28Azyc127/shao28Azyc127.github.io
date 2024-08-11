# include <bits/stdc++.h>
using namespace std;
int t,m;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        int dt = b*b - 4*a*c;
        if(dt<0){
            printf("NO\n");
            continue;
        }
        int kf = floor(sqrt(dt));
        if(kf*kf==dt){
            double x1 = double(-1*b+kf)/2*a;
            double x2 = double(-1*b-kf)/2*a;
            int ans1;
            if(x1>=x2){
                ans1 = -1*b+kf;
            }
            else{
                ans1 = -1*b-kf;
            }
            int ans2 = 2*a;
            int g = __gcd(ans1,ans2);
            ans1 /= g;
            ans2 /= g;
            if(ans2<0) ans1 = -1 * ans1;
            ans2 = abs(ans2);
            if(ans2==1) printf("%d\n",ans1);
            else printf("%d/%d\n",ans1,ans2);
            continue;
        }
        int ans1 = -1*b;
        if(b!=0){
            int ans2 = 2*a;
            int g = __gcd(ans1,ans2);
            ans1 /= g;
            ans2 /= g;
            if(ans2<0) ans1 = -1 * ans1;
            ans2 = abs(ans2);
            if(ans2==1) printf("%d+",ans1);
            else printf("%d/%d+",ans1,ans2);
        }
        int r = dt;
        int q1 = 1;
        for(int i=r/2+1;i>=2;i--){
            if(dt%i==0&&floor(sqrt(i))*floor(sqrt(i))==i){
                q1 = sqrt(i);
                r/=i;
                break;
            }
        }
        int q2 = 2*a;
        int g = __gcd(q1,q2);
        q1/=g;
        q2/=g;
        q1 = abs(q1);
        q2 = abs(q2);
        if(q2==q1){
            printf("sqrt(%d)\n",r);
            continue;
        }
        if(q2==1){
            printf("%d*sqrt(%d)\n",q1,r);
            continue;
        }
        if(q2>q1&&q2%q1==0){
            printf("sqrt(%d)/%d\n",r,q2/q1);
            continue;
        }
        printf("%d*sqrt(%d)/%d\n",q1,r,q2);

    }
    return 0;
}
