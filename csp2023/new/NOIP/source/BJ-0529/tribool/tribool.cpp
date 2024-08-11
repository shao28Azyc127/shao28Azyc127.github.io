#include<bits/stdc++.h>
using namespace std;
const int MAXN =1e5+7;

int fa_a[2*MAXN+10];//初始值
int fa_b[2*MAXN+10];//最终值
int cnt[2*MAXN+10];//某一变量的使用次数
int c,t,m,n;
int sizen[2*MAXN+10];
int xa,ya;
int getchange(int x){
    return MAXN+x;
}

int getback(int x){
    return abs(x-MAXN);
}

int getfa(int x){
    if(fa_a[x]!=x&&x<=2*MAXN){
        return fa_a[x]=getfa(fa_a[x]);
    }
    return x;
}

int oppo(int x){
    if(x>MAXN){
        return 2*MAXN-x;
    }
    else{
        return MAXN-x;
    }
}

void merge1(int x,int cmd){//定向和并
    x=getchange(x);
    x=getfa(x);
    sizen[2*MAXN+cmd]+=sizen[x];
    sizen[x]=0;
    fa_a[x]=2*MAXN+cmd;
    xa=getback(x);
    //cout<<"merge"<<xa<<"to"<<2*MAXN+cmd<<endl;
    x=oppo(x);
    x=getfa(x);
    if(cmd==1){
        cmd=2;
    }
    else if(cmd==2){
        cmd=1;
    }
    sizen[2*MAXN+cmd]+=sizen[x];
    sizen[x]=0;
    fa_a[x]=2*MAXN+cmd;
    //cout<<"merge"<<xa<<"to"<<2*MAXN+cmd<<endl;
    sizen[x]=0;
}


void modify(int x,int cmd){
    merge1(x,cmd);
}


void merge2(int x,int y){//启发式合并
    if(sizen[x]<sizen[y]){
       swap(x,y);
    }
    sizen[x]+=sizen[y];
    sizen[y]=0;
    fa_a[y]=x;
    xa=getback(x);
    ya=getback(y);
    //cout<<"merge"<<ya<<"to"<<xa<<endl;
}


void modify2(int x,int y,int cmd){
    x=getchange(x);
    x=getfa(x);
    y=getchange(y);
    y=getfa(y);
    if(x==getfa(oppo(y))){
        merge1(x,3);
    }
    if(cmd==1){
        merge2(x,y);
    }
    else{
        merge2(getfa(oppo(x)),y);
    }
}

int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin>>c>>t;
    char q;
    int x,y;
    for(int s=1;s<=t;s++){
        cin>>n>>m;//n个变量m条语句
        for(int i=MAXN-n;i<=MAXN;i++){
            fa_a[i]=i;
            sizen[i]=0;
            cnt[i]=0;
            fa_b[i]=i;
        }
        for(int i=MAXN;i<=MAXN+n;i++){
            fa_a[i]=i;
            sizen[i]=2;
            cnt[i]=1;
            fa_b[i]=i;
        }
        for(int i=1;i<=3;i++){
            sizen[2*MAXN+i]=0;
            cnt[2*MAXN+i]=0;
        }
        //cout<<'a'<<endl;
        for(int i=1;i<=m;i++){

            cin>>q>>x;
            //cout<<i<<' '<<q<<endl;
            if(q=='+'){
                cin>>y;
                modify2(x,y,1);
            }
            else if(q=='-'){
                cin>>y;
                modify2(x,y,2);
            }
            else{
                if(q=='T'){
                    modify(x,1);

                }
                else if(q=='F'){
                    modify(x,2);
                }
                else if(q=='U'){
                    modify(x,3);
                }
            }
        }
        int ans=sizen[2*MAXN+3]/2;
        cout<<ans<<endl;
    }
}
