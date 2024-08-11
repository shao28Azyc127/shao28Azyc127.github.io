#include<bits/stdc++.h>
using namespace std;
int x[9][6],cur[6],tmp[6];
bool check(){
    if(cur[1]==tmp[1]&&cur[2]==tmp[2]&&cur[3]==tmp[3]&&cur[4]==tmp[4]&&cur[5]==tmp[5]) return false;
    int cnt=0,cf[6];
    for(int i=1;i<=5;i++) cf[i]=cur[i]-tmp[i];
    for(int i=1;i<=5;i++) if(cf[i]!=0) cnt++;
    if(cnt==1) return true;
    if(cnt>2) return false;
    int pos1=-114,pos2=-514;
    for(int i=1;i<=4;i++){
        if(cf[i]!=0){
            pos1=i;
            break;
        }
    }
    for(int i=pos1+1;i<=5;i++) if(cf[i]!=0) pos2=i;
    if(abs(pos1-pos2)!=1) return false;
    if(cf[pos1]==cf[pos2]) return true;
    if(cf[pos1]+10==cf[pos2]) return true;
    if(cf[pos1]==cf[pos2]+10) return true;
    return false;
}//check if u get a from b
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++) for(int j=1;j<=5;j++) cin>>x[i][j];
    cur[0]=0,cur[1]=0,cur[2]=0,cur[3]=0,cur[4]=0,cur[5]=0;
    for(int i=0;i<=9;i++){
        cur[1]=i;
        for(int j=0;j<=9;j++){
            cur[2]=j;
            for(int k=0;k<=9;k++){
                cur[3]=k;
                for(int p=0;p<=9;p++){
                    cur[4]=p;
                    for(int q=0;q<=9;q++){
                        cur[5]=q;
                        bool flag=true;
                        for(int pos=1;pos<=n;pos++){
                            tmp[1]=x[pos][1],tmp[2]=x[pos][2],tmp[3]=x[pos][3],tmp[4]=x[pos][4],tmp[5]=x[pos][5];
                            if(check()!=true) flag=false;
                        }
                        if(flag==true) ans++;
                    }
                }
            }
        }
    }
    cout<<ans;
    return 0;
//  rp++
//  check scanf int use d ll use lld
//  dont scanf in nosync mode
}