#include <iostream>
#include <cstdio>
using namespace std;
int n,ans;
int c[10][10];
int a[1000][10];
int ind;
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++) cin>>c[i][j];
    }
    if(n==1){
        for(int i=1;i<=5;i++){
            int bf=c[1][i];
            for(int j=1;j<=9;j++){
                c[1][i]++;
                if(c[1][i]>=10) c[1][i]-=10;
                int p=0;
                for(int j=1;j<=ind;j++){
                    if(a[ind]==c[1]) break;
                    p++;
                }
                if(p==ind){
                    ind++;
                    for(int k=1;k<=5;k++) a[ind][k]=c[1][k];
                }
            }
            c[1][i]=bf;
        }
        for(int i=1;i<=4;i++){
            int bf1=c[1][i];int bf2=c[1][i+1];
            for(int j=1;j<=9;j++){
                c[1][i]++;c[1][i+1]++;
                if(c[1][i]>=10) c[1][i]-=10;
                if(c[1][i+1]>=10) c[1][i+1]-=10;
                int p=0;
                for(int j=1;j<=ind;j++){
                    if(a[ind]==c[1]) break;
                    p++;
                }
                if(p==ind){
                   ind++;
                   for(int k=1;k<=5;k++) a[ind][k]=c[1][k];
                }
            }
            c[1][i]=bf1;
            c[1][i+1]=bf2;
        }
        ans=ind;
    }
    else{
        if(n==2){
            int cnn=0;
            int d1[3]={0,0,0};
            int d2[3]={0,0,0};
            int indd=-1;
            for(int i=1;i<=5;i++){
                if(c[1][i]!=c[2][i]){
                    d2[++cnn]=c[2][i];
                    d1[cnn]=c[1][i];
                    if(indd==-1) indd=i;
                    else if(i-indd!=1){
                        cout<<0;return 0;
                    }
                }
            }
            if(cnn==1) ans=10;
            else{
                if(d2[1]-d2[2]==d1[1]-d1[2] || (d2[1]-d2[2]-d1[1]+d1[2] ==10) || (d2[1]-d2[2]-d1[1]+d1[2] ==-10)) ans=8;
                else ans=0;
            }
        }
        else{
            int cnn=0;
            int bg1=0;
            int cnr=0;
            int dfi=0;
            int cnrl[100];
            for(int i=1;i<=5;i++){
                bg1=c[1][i];
                for(int j=1;j<=n;j++){
                    if(c[j][i]!=bg1){cnr++;cnrl[cnr]=j;}
                    if(dfi==0) dfi=j;
                    else if(j-dfi!=1){cout<<0;return 0;}

                }
                
            }
            if(cnr==1) ans=10-n;
                else if(cnr>2) ans=0;
                else{
                    int cha=0;
                    for(int j=1;j<=n;j++){
                        int qq=c[j][cnrl[1]]-c[j][cnrl[2]];
                        if(cha==0) cha==qq;
                        else if(cha!=qq){
                            ans=0;break;
                        }
                    }
                    ans=10-n;
                }
        }
    }
    cout<<ans;
    return 0;

}
