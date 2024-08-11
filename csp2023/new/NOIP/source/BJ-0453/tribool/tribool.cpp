#include <bits/stdc++.h>
using namespace std;
int c,t,n,m;
int vis[100001];
int cfz[101];
int cffz[101];
int ans;
int cz[101][5];
void check(){
    for(int i=1;i<=n;i++)cffz[i]=cfz[i];
    //cout <<'\n' <<'\n';
    for(int x=1;x<=m;x++){
        //cout <<cz[x][1] <<'\n';
        if(cz[x][1]==1) cffz[cz[x][2]]=1;
        else if(cz[x][1]==2) cffz[cz[x][2]]=2;
        else if(cz[x][1]==3) cffz[cz[x][2]]=3;
        else if(cz[x][1]==4) cffz[cz[x][2]]=cffz[cz[x][3]];
        else if(cz[x][1]==5){
            if(cffz[cz[x][3]]==1){
                cffz[cz[x][2]]=1;
            }else if(cffz[cz[x][3]]==2){
                cffz[cz[x][2]]=3;
               // cout <<"2" <<'\n';
                //cout <<cz[x][2] <<" " <<cz[x][3] <<'\n';
            }else if(cffz[cz[x][3]]==3){
               // cout <<cz[x][3] <<'\n';
                cffz[cz[x][2]]=2;
               // cout <<"3" <<'\n';
                //cout <<cz[x][2] <<" " <<cz[x][3] <<'\n';
            }
        }
    }
    int popp=0;
    int uu=0;
    for(int i=1;i<=n;i++){
        if(cfz[i]!=cffz[i]) popp=1;
        if(cffz[i]==1) uu++;
        if(i==n && popp==0) ans=min(ans,uu);
        //cout <<cfz[i] <<" ";
    }
    //cout <<ans <<'\n' <<'\n';
}
void ranc(int now,int nowx){
    if(now==n){
        check();
        return;
    }
    for(int i=1;i<=3;i++){
        cfz[nowx]=cffz[nowx]=i;
        ranc(now+1,nowx+1);
    }
}

int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin >>c >>t;
    if(c<3){
        while(t--){
            cin >>n >>m;
            ans=1e9;
            //for(int i=1;i<=n;i++) vis[i]=0;
            for(int i=1;i<=m;i++){
                char s;
                cin >>s;
                if(s=='U' || s=='T' || s=='F'){
                    int l;
                    cin >>l;
                    if(s=='U'){
                        cz[i][1]=1;
                        cz[i][2]=l;
                    }else if(s=='T'){
                        cz[i][1]=2;
                        cz[i][2]=l;
                    }else{
                        cz[i][1]=3;
                        cz[i][2]=l;
                    }
                }else if(s=='+'){
                    int a,b;
                    cin >>a >>b;
                    cz[i][1]=4;
                    cz[i][2]=a;
                    cz[i][3]=b;
                }else if(s=='-'){
                    int a,b;
                    cin >>a >>b;
                    cz[i][1]=5;
                    cz[i][2]=a;
                    cz[i][3]=b;
                }
            }
            //u=1;
            //t=2;
            //f=3;
            ranc(0,1);
            cout <<ans <<'\n';
        }
    }else if(c<5){
        while(t--){
            ans=0;
            cin >>n >>m;
            for(int i=1;i<=n;i++) vis[i]=0;
            while(m--){
                char s;
                cin >>s;
                int ppp;
                cin >>ppp;
                if(s=='U' && vis[ppp]==0){
                    vis[ppp]=1;
                    ans++;
                }else if(s!='U' && vis[ppp]==1){
                    vis[ppp]=0;
                    ans--;
                }
            }
            cout <<ans <<'\n';
        }
    }else{
        while(t--){
            cin >>n >>m;
            for(int i=1;i<=n;i++) vis[i]=0;
            int sums;
            ans=sums=0;
            while(m--){
                char ss;
                cin >>ss;
                if(ss=='+'){
                    int a,b;
                    cin >>a >>b;
                    if(vis[a]!=vis[b]){
                        if(vis[b]==0) ans--;
                        else ans++;
                        vis[a]=vis[b];
                    }
                }else if(ss=='U' || ss=='T' || ss=='F'){
                    int l;
                    cin >>l;
                    if(ss=='U'){
                        if(vis[l]==0){
                            vis[l]=1;
                            ans++;
                        }
                    }else{
                        if(vis[l]==1){
                            vis[l]=0;
                            ans--;
                        }
                    }
                }else{
                    int a,b;
                    cin >>a >>b;
                    if(vis[b]==1){
                        if(vis[a]==1){
                            vis[a]=0;
                            ans--;
                        }
                    }else{
                        if(vis[a]==0){
                            vis[a]=1;
                            ans++;
                        }
                    }
                    sums++;
                }
            }

            if(sums>0 && sums&1) cout <<sums+ans <<'\n';
            else cout <<ans <<'\n';
        }
    }
    return 0;
}
