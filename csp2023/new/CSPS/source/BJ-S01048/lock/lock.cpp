#include<bits/stdc++.h>

const int N =1e1+10;
const int MOD = 1e5;

using namespace std;

int n;
int a[N];
bool h[MOD];
int ans;

int lock(int x, int b, int y, char f){
    x += 1e5;
    int p = pow(10,b);
    int p_1 = pow(10,b-1);
    int c = x%p/p_1;

    if(f=='p')c = (c+y)%10;
    if(f=='m')c = (c-y+10)%10;

    x = (x/p)*p + p_1*c + x%p_1;
    return x%MOD;
}

int lock(int x, int b, int bb, int y, char f){
    //ensure b > bb
    if(b < bb) swap(b,bb);

    x += 1e5;
    int p = pow(10,b);
    int pp = pow(10,bb);
    int p_1 = pow(10,b-1);
    int pp_1 = pow(10,bb-1);

    int c = x%p/p_1;
    int cc = x%pp/pp_1;

    if(f=='p'){
        c = (c+y)%10;
        cc = (cc+y)%10;
    }
    //if(f=='m')c = (c-y+10)%10;

    x = (x/p)*p + p_1*c + cc*pp_1 + x%pp_1;
    return x%MOD;
}

int main(){
    freopen("lock.in","r",stdin);
    //freopen("lock.out","w",stdout);

    scanf("%d",&n);
    //cout<<lock(n,2,3,3,'p');
    for(int i=1;i<=n;i++){
        int c;
        for(int j=1;j<=5;j++){
            scanf("%d",&c);
            a[i]=a[i]*10+c;
        }
    }

    //TURN 1
    for(int i=00000;i<=99999;i++){
        for(int j=1;j<=9;j++){
            for(int g=1;g<=5;g++){
                int cnt=0;
                int res1 = lock(i, g, j, 'p');//plus
                int res2 = lock(i, g, j, 'm');//minus
                for(int k=1;k<=n;k++){
                    if(res1 == a[k] || res2 == a[k]){
                        cnt++;
                    }
                }
                if(cnt==n)ans++;
            }
        }
    }

    //TURN 2
    for(int i=00000;i<=99999;i++){
        for(int j=1;j<=9;j++){
            for(int g=1;g<=5;g++){
                int gg = g-1;
                if(gg<=0)continue;
                int cnt=0;
                int res1 = lock(i, g, gg, j, 'p');//plus
                int res2 = lock(i, g, gg, j, 'p');//plus
                for(int k=1;k<=n;k++){
                    if(res1 == a[k] || res2 == a[k]){
                        cnt++;
                    }
                }
                if(cnt===n){
                    //cout<<i<<" "<<j<<" "<<g<<" "<<gg<<endl;
                    ans++;
                }
            }
        }
    }
    printf("%d\n",ans);

    return 0;
}
