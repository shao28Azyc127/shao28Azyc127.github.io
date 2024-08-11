#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e3+10;
int n,m;
char a[100][20];
char c[maxn][20];
int check[1000010];

int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);

    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            int x;
            scanf("%d",&x);
            a[i][j]=(char)(x+'0');
            //cout<<a[i][j]<<endl;
        }
    }

    int cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            for(int num=0;num<=9;num++){
                if((char)(num+'0')==a[i][j]) continue;
                cnt++;
                for(int k=1;k<=5;k++){
                    if(k==j) c[cnt][k]=(char)(num+'0');
                    else c[cnt][k]=a[i][k];
                    //cout<<c[cnt][k]<<" ";
                }
            }
        }

        for(int j=1;j<=4;j++){
            for(int num=1;num<=9;num++){
                cnt++;
                //if((char)(num+'0')==a[i][j]) continue;
                for(int k=1;k<=5;k++){
                    if(k==j+1) continue;
                    if(k==j){
                        char s=(char)(a[i][j]+num);
                        //cout<<s<<" "<<(s-10);
                        if(s>'9') s=(char)(s-10);
                        //cout<<s<<endl;
                        c[cnt][k]=s;
                        s=(char)(a[i][j+1]+num);
                        //cout<<s<<" "<<(s-10);
                        if(s>'9') s=(char)(s-10);
                        c[cnt][k+1]=s;
                        //cout<<c[cnt][k]<<" "<<c[cnt][k+1]<<" ";
                    }
                    else c[cnt][k]=a[i][k];//cout<<c[cnt][k]<<" ";
                }
                //cout<<endl;
            }
        }
        //cout<<i<<endl;
    }

    if(n==1){
        printf("81");
        fclose(stdin);
        fclose(stdout);
        return 0;
    }

    for(int i=1;i<=cnt;i++){
        //cout<<i<<endl;
        int tmp=0;
        for(int j=1;j<=5;j++){
               // cout<<(c[i][j]-'0')<<endl;
            tmp=tmp*10+(int)(c[i][j]-'0');
        }
        //cout<<tmp<<endl;
        check[tmp]++;
    }

    int ans=0;
    for(int i=1;i<100000;i++) if(check[i]==n) ans++;
    printf("%d",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
//Ranger_HoFr AK IOI!!!!
//zyctc AK IOI!!!!!
//CZT AK IOI!!!!!
