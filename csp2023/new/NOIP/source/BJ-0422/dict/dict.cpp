#include<bits/stdc++.h>
using namespace std;
const int N=26+10,M=3000+10;
struct PP{
    int cnt[N];
    bool operator<(const PP&rhs)const{
        for(int i=0;i<26;i++)if(cnt[i]!=rhs.cnt[i])return cnt[i]<rhs.cnt[i];
        return 0;
    }
    bool operator>(const PP&rhs)const{
        for(int i=0;i<26;i++)if(cnt[i]!=rhs.cnt[i])return cnt[i]>rhs.cnt[i];
        return 0;
    }
    PP(){
        memset(cnt,0,sizeof(cnt));
    }
}p[M],pm1,pm2,pt;
int pos1,pos2;
char c[M];

int check(int x){
    for(int i=0,j=0;i<26;i++){
        if(pos1!=x){
            while(pm1.cnt[j]==0&&j<26)j++;
            //cout<<x<<": "<<i<<','<<j<<endl;
            while(p[x].cnt[i]==0&&i<26)i++;
            //cout<<x<<": "<<i<<','<<j<<endl;
            if(i==26||j==26)break;
            if(25-j!=i){
                //cout<<"\t"<<(int)(i<25-j)<<endl;
                return (int)(i<25-j);
            }else{
                if(pm1.cnt[j]!=p[x].cnt[i])return pm1.cnt[j]>p[x].cnt[i];
            }
        }else{
            while(pm2.cnt[j]==0&&j<26)j++;
            //cout<<x<<": "<<i<<','<<j<<endl;
            while(p[x].cnt[i]==0&&i<26)i++;
            //cout<<x<<": "<<i<<','<<j<<endl;
            if(i==26||j==26)break;
            if(25-j!=i){
                //cout<<"\t"<<(int)(i<25-j)<<endl;
                return (int)(i<25-j);
            }else{
                if(pm2.cnt[j]!=p[x].cnt[i])return pm2.cnt[j]>p[x].cnt[i];
            }
        }
    }
    return 0;
}

void test(){
    int n,m;
    scanf("%d%d",&n,&m);pos1=pos2=-1e9;
    for(int i=1;i<=n;i++){
        for(int i=0;i<26;i++)pt.cnt[i]=0;
        scanf("%s",c+1);for(int j=1;j<=m;j++)p[i].cnt[c[j]-'a']++,pt.cnt['z'-c[j]]++;
        /*cout<<endl;cout<<c+1<<endl;
        for(int i=0;i<26;i++)cout<<pt.cnt[i]<<" ";//cout<<endl;
        for(int i=0;i<26;i++)cout<<pm1.cnt[i]<<" ";//cout<<endl;
        for(int i=0;i<26;i++)cout<<pm2.cnt[i]<<" ";//cout<<endl;*/
        if(pm1>pt||pos1<0)pm2=pm1,pm1=pt,pos2=pos1,pos1=i;
        else if(pm2>pt||pos2<0)pm2=pt,pos2=i;
        //cout<<pos1<<','<<pos2<<endl;
    }
    for(int i=1;i<=n;i++){
        printf("%d",check(i));
        //cout<<endl<<endl;
    }
}

signed main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    test();
    return 0;
}
