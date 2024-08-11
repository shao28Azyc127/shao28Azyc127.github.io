#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
long long c,t,n,m,usum=9e18,globalflag=0,l[1005],l2[1005],y1[1000005],y2[1000005],y3[1000005],cntfrom[1000005];
void dfs(long long p){
    //if(globalflag)return;
    if(p>n){
        long long lsusum=0;
        for(int i=1;i<=n;i++){
            l2[i]=l[i];
            if(l[i]==-1)lsusum++;
        }
        for(int i=1;i<=n;i++){
            if(y1[i]==1){
                l2[y2[i]]=1;
            }
            if(y1[i]==2){
                l2[y2[i]]=0;
            }
            if(y1[i]==3){
                l2[y2[i]]=-1;
            }
            if(y1[i]==4){
                l2[y2[i]]=l2[y3[i]];
            }
            if(y1[i]==5){
                if(l2[y3[i]]==1){
                    l2[y2[i]]=0;
                }else if(l2[y3[i]]==0){
                    l2[y2[i]]=1;
                }else if(l2[y3[i]]==-1){
                    l2[y2[i]]=-1;
                }
            }
        }bool flag=1;
        for(int i=1;i<=n;i++){
            if(l2[i]!=l[i]){
                flag=0;
            }
        }if(flag){
            /*for(int i=1;i<=n;i++){
                cout<<l[i]<<' ';
            }cout<<endl;
            if(lsusum==3)cout<<endl;*/
            usum=min(usum,lsusum);
            globalflag=1;
        }return;
    }
    for(int i=1;i>=-1;i--){
        l[p]=i;
        dfs(p+1);

    }
}
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        memset(y1,0,sizeof(y1));
        cin>>n>>m;
        if(c==1||c==2){
            for(int i=1;i<=m;i++){
                char ch;
                cin>>ch;
                if(ch=='T'){
                    y1[i]=1;
                    cin>>y2[i];
                }
                if(ch=='F'){
                    y1[i]=2;
                    cin>>y2[i];
                }
                if(ch=='U'){
                    y1[i]=3;
                    cin>>y2[i];
                }
                if(ch=='+'){
                    y1[i]=4;
                    cin>>y2[i]>>y3[i];
                }
                if(ch=='-'){
                    y1[i]=5;
                    cin>>y2[i]>>y3[i];
                }
            }
            globalflag=0;
            usum=9e18;
            dfs(1);
            cout<<usum<<endl;
        }else if(c==3||c==4){
            long long cnt=0;
            for(int i=1;i<=m;i++){
                char ch;
                cin>>ch;
                if(ch=='T'){
                    long long a;
                    cin>>a;
                    if(y1[a]==3){
                        cnt--;
                    }
                    y1[a]=1;
                    /*
                    cin>>a;
                    if(y1[a]==3){
                        cnt--;
                    }
                    y1[a]=1;*/
                }
                if(ch=='F'){
                    long long a;
                    cin>>a;
                    if(y1[a]==3){
                        cnt--;
                    }
                    y1[a]=2;
                }
                if(ch=='U'){
                    long long a;
                    cin>>a;
                    if(y1[a]==3){
                        cnt--;
                    }cnt++;
                    y1[a]=3;
                }
            }
            cout<<cnt<<endl;
        }else if(c==5||c==6){
            long long cnt=0;
            for(int i=1;i<=m;i++){
                char ch;
                cin>>ch;
                if(ch=='U'){
                    long long a;
                    cin>>a;
                    if(y1[a]==3){
                        cnt--;
                    }
                    cnt++;
                    y1[a]=3;
                }
                if(ch=='+'){
                    long long a,b;
                    cin>>a>>b;
                    if(y1[b]==3&&y1[a]!=3){
                        y1[a]=3;
                        cnt++;
                    }else if(y1[b]!=3&&y1[a]==3){
                        y1[a]=0;
                        cnt--;
                    }
                }
            }
            cout<<cnt<<endl;
        }else {
            cout<<0<<endl;
        }
    }
    return 0;
}
