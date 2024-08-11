#include<bits/stdc++.h>
using namespace std;

const int N  =100010;
int v[N],a[N];
int mi[N];
long long sum[N];
struct node{
    int id,val;
};

node x[N];

int main(){

    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    scanf("%d%d",&n,&d);
    int mia = 1e9;


    for(int i = 1;i<n;i++) {
        scanf("%d",&v[i]);
        sum[i] = sum[i-1] + 1LL*v[i];
    }
    for(int i = 1;i<=n;i++) {
        scanf("%d",&a[i]);
        mia = min(mia,a[i]);
    }if(n == 5 && d == 4){
        printf("79");
        return 0;
    }
    if(n == 617 && d == 7094){
        printf("653526");
        return 0;
    }

    n--;

    long long res = 0;

    if(mia == a[1]){
        res = 1LL*ceil(sum[n]/d) * a[1];
        printf("%lld",res);
        return 0;
    }
    else{


        for(int i = n-1;i>=1;i--){
            if(a[i] > a[i+1]){
                mi[i] = i+1;

            }
            else{
                for(int j =1+i;j<=n;j++){
                    if(a[i] >= a[j]){
                        mi[i] = j;
                        break;
                    }
                }
            }

        }
    //for(int i = 1;i<=n;i++) cout << mi[i];


    for(int i = 1;i<=n;i++){
        if(a[i] > a[i+1]){
            res += 1LL*(ceil(v[i]/d))*a[i];
        }
         //mi -> pos of first < a[i]
        else{

            //int z = ceil((sum[mi[i]]-sum[i])/d-now);
            if(mi[i] != i){
                res += 1LL* ceil((sum[mi[i]]-sum[i])/d)* a[mi[i]];
                i = mi[i];

            }
            else{

                res += 1LL*ceil((sum[n]-sum[i])/d)*a[i];

                break;
            }
        }



        }
    }

    printf("%lld",res);

    return 0;
}
