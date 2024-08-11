#include<bits/stdc++.h>
using namespace std;
struct node{
    int op,ii,jj;
    char tfu;
}arr[100005];
int x[100005],y[100005],ans;
int n,m;
bool ck(){
    for(int i=1;i<=n;i++){
        y[i]=x[i];
    }
    for(int i=1;i<=m;i++){
        if(arr[i].op==1){
            if(arr[i].tfu=='T'){
                x[arr[i].ii]=0;
            }else if(arr[i].tfu=='F'){
                x[arr[i].ii]=1;
            }else{
                x[arr[i].ii]=2;
            }
        }else if(arr[i].op==2){
            x[arr[i].ii]=x[arr[i].jj];
        }else{
            int p=x[arr[i].jj];
            if(p==0) p=1;
            else if(p==1) p=0;
            x[arr[i].ii]=p;
        }
    }
    for(int i=1;i<=n;i++){
        if(x[i]!=y[i]){
            return false;
        }
    }
    return true;
}
void dfs(int l){
    if(l>n){
            for(int i=1;i<=n;i++){
                cout<<x[i]<<" ";
            }
            cout<<endl;
        if(ck()){
            int Ucnt=0;
            for(int i=1;i<=n;i++){
                if(x[i]==2){
                    Ucnt++;
                }
                //if(x[i]==-1) cout<<"NO\n";
                //cout<<x[i]<<" ";
            }
            //cout<<endl;
            ans=min(ans,Ucnt);
        }
        return;
    }
    x[l]=0;
    dfs(l+1);
    x[l]=1;
    dfs(l+1);
    x[l]=2;
    dfs(l+1);
    x[l]=-1;
    return;
}
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int c,T;
    scanf("%d%d",&c,&T);
    while(T--){
        ans=114514;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) x[i]=-1;
        for(int i=1;i<=m;i++){
            char opt;
            cin>>opt;
            if(opt=='+'){
                int ii,jj;
                scanf("%d%d",&ii,&jj);
                arr[i].ii=ii;
                arr[i].jj=jj;
                arr[i].op=2;
            }else if(opt=='-'){
                int ii,jj;
                scanf("%d%d",&ii,&jj);
                arr[i].ii=ii;
                arr[i].jj=jj;
                arr[i].op=3;
            }else{
                int ii;
                scanf("%d",&ii);
                arr[i].op=1;
                arr[i].ii=ii;
                arr[i].tfu=opt;
            }
        }
        int ful=pow(3,n)-1;
        for(int i=0;i<=ful;i++){
            int p=i;
            for(int j=1;j<=n;j++){
                x[j]=p%3;
                p/=3;
                //cout<<x[j]<<" ";
            }
            //cout<<endl;
            if(ck()){
                    //cout<<"OK\n";
                int Ucnt=0;
                for(int j=1;j<=n;j++){
                    if(x[j]==2){
                        Ucnt++;
                    }
                }
                    ans=min(ans,Ucnt);
            }
        }
        //dfs(1);
        printf("%d\n",ans);
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
/*
3 3
- 2 1
- 3 2
- 1 3
*/
