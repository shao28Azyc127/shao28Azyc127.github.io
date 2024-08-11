#include<bits/stdc++.h>
using namespace std;
int c,t,n,m,a[11],rbs[11],ans=2147483647,tt[100001],ans2;
struct mmh{
    char A;
    int b,c;
}mmh2[100001];
void solve2(int x2[11]){
    for(int i=1;i<=n;i++)a[i]=x2[i];
    for(int i=1;i<=m;i++){
        if(mmh2[i].A=='T')x2[mmh2[i].b]=1;
        else if(mmh2[i].A=='F')x2[mmh2[i].b]=2;
        else if(mmh2[i].A=='U')x2[mmh2[i].b]=3;
        else if(mmh2[i].A=='+')x2[mmh2[i].b]=x2[mmh2[i].c];
        else if(mmh2[i].A=='-'){
            if(x2[mmh2[i].c]==3)x2[mmh2[i].b]=x2[mmh2[i].c];
            else if(x2[mmh2[i].c]==2)x2[mmh2[i].b]=1;
            else if(x2[mmh2[i].c]==1)x2[mmh2[i].b]=2;
        }
    }
    //for(int i=1;i<=n;i++)cout<<a[i]<<" ";
    //cout<<endl;for(int i=1;i<=n;i++)cout<<x2[i]<<" ";
    //cout<<endl<<endl;
    for(int i=1;i<=n;i++){
        if(x2[i]!=a[i])return;
    }
    int wqh=0;
    for(int i=1;i<=n;i++){
        if(x2[i]==3)++wqh;
    }
    ans=min(wqh,ans);
}
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    scanf("%d%d",&c,&t);
    if(c==1||c==2){
        while(t--){
            memset(mmh2,0,sizeof(mmh2));
            scanf("%d%d",&n,&m);
            ans=n;
            for(int i=1;i<=m;i++){
                cin>>mmh2[i].A>>mmh2[i].b;
                if(mmh2[i].A=='+'||mmh2[i].A=='-')cin>>mmh2[i].c;
            }memset(a,0,sizeof(a));
            for(int z1=1;z1<=3;z1++){
                for(int z2=1;z2<=3;z2++){
                    for(int z3=1;z3<=3;z3++){
                        for(int z4=1;z4<=3;z4++){
                            for(int z5=1;z5<=3;z5++){
                                for(int z6=1;z6<=3;z6++){
                                    for(int z7=1;z7<=3;z7++){
                                        for(int z8=1;z8<=3;z8++){
                                            for(int z9=1;z9<=3;z9++){
                                                for(int z10=1;z10<=3;z10++){
                                                    rbs[1]=z1,rbs[2]=z2,rbs[3]=z3,rbs[4]=z4,rbs[5]=z5,rbs[6]=z6,rbs[7]=z7,rbs[8]=z8,rbs[9]=z9,rbs[10]=z10;
                                                    for(int z11=10;z11>n;z11--)rbs[z11]=0;
                                                    solve2(rbs);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            cout<<ans<<endl;
        }
    }else if(c==3||c==4){
        while(t--){
            memset(mmh2,0,sizeof(mmh2));
            memset(tt,0,sizeof(tt));
            ans2=0;
            scanf("%d%d",&n,&m);
            for(int i=1;i<=m;i++){
                cin>>mmh2[i].A>>mmh2[i].b;
                if(mmh2[i].A=='T')tt[mmh2[i].b]=1;
                else if(mmh2[i].A=='F')tt[mmh2[i].b]=2;
                else if(mmh2[i].A=='U')tt[mmh2[i].b]=3;
            }for(int i=1;i<=n;i++){
                if(tt[i]==3)++ans2;
            }
            printf("%d\n",ans2);
        }
    }else if(c==5||c==6){
        while(t--){
            memset(mmh2,0,sizeof(mmh2));
            memset(tt,0,sizeof(tt));
            ans2=0;
            scanf("%d%d",&n,&m);
            for(int i=1;i<=m;i++){
                cin>>mmh2[i].A>>mmh2[i].b;
                if(mmh2[i].A=='U')tt[mmh2[i].b]=1;
                else{
                    cin>>mmh2[i].c;
                    tt[mmh2[i].b]=tt[mmh2[i].c];
                }
            }for(int i=1;i<=n;i++){
                if(tt[i]==1)++ans2;
            }printf("%d\n",ans2);
        }
    }
    return 0;
}
