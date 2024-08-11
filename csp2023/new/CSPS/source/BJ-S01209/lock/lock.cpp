#include<bits/stdc++.h>
using namespace std;
int t,a,b,c,d,e,ans=0;
int m[13][13][13][13][13][13];
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>a>>b>>c>>d>>e;
        for(int j=0;j<=9;j++){
            m[j][b][c][d][e][i]=1;
            m[a][j][c][d][e][i]=1;
            m[a][b][j][d][e][i]=1;
            m[a][b][c][j][e][i]=1;
            m[a][b][c][d][j][i]=1;
            m[(a+j)%10][(b+j)%10][c][d][e][i]=1;
            m[a][(b+j)%10][(c+j)%10][d][e][i]=1;
            m[a][b][(c+j)%10][(d+j)%10][e][i]=1;
            m[a][b][c][(d+j)%10][(e+j)%10][i]=1;
        }
    }
    for(int i1=0;i1<=9;i1++){
        for(int i2=0;i2<=9;i2++){
            for(int i3=0;i3<=9;i3++){
                for(int i4=0;i4<=9;i4++){
                    for(int i5=0;i5<=9;i5++){
                        int cnt=0;
                        for(int i6=1;i6<=t;i6++){
                            cnt+=m[i1][i2][i3][i4][i5][i6];
                                //cout<<i1<<i2<<i3<<i4<<i5<<i6<<endl;
                                if(cnt==t) ans++;
                            }
                    }
                }
            }
        }
    }
    cout<<ans-t;
    return 0;
}
