#include <iostream>
#include <cstdio>
using namespace std;
long long day[1010];
long long len[1010];
long long reward[1010];
long long dptable[1010][1010];//[1] shi tiaozhan de bianhao ,[2]shi cengjing paoguo de zhi

int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    long long c,t;
    cin>>c>>t;
    for(long long i = 1;i <= t;i++){
        long long n,m,k,d;
        cin>>n>>m>>k>>d;
        for (long long j = 1;j <= m;j++){
            cin>>day[j]>>len[j]>>reward[j];
        }
        for (long long j = 1;j <= m;j++){
            for (long long l = 0;l <= k;l++){
                dptable[j][0] = max(dptable[j][0],dptable[j-1][l]);
            }
            for (long long l = 0;l <= k;l++){
                dptable[j][l] = dptable[j][0];
            }
            if (day[j] - day[j-1] > len[j]){
                for (long long l = 0;max(len[j],l) <= k;l++){
                    dptable[j][len[j]] = max(dptable[j][len[j]],dptable[j-1][l] - len[j]*d + reward[j]);
                }

            }
            else{
                for (long long l = 0;max(len[j],l+day[j]-day[j-1]) <= k;l++){
                    if (l <= len[j]){
                        dptable[j][len[j]] = max(dptable[j][len[j]],dptable[j-1][l] - (len[j]-l)*d + reward[j]);
                    }
                    else{
                        dptable[j][l+day[j]-day[j-1]] = max(dptable[j][l+day[j]-day[j-1]],dptable[j-1][l] - (day[j]-day[j-1])*d + reward[j]);
                    }
                }
            }
        }
        long long maxn = 0;
        for (long long j = 0;j <= k;j++){
            maxn = max(maxn,dptable[m][j]);
        }
        cout<<maxn<<endl;
        for (int j = 1;j <= m;j++){
            for (int l = 0;l <= k;l++){
                dptable[j][l] = 0;
            }
        }
    }
    return 0;
}
