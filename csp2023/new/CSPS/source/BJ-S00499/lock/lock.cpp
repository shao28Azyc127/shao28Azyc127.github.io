#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int a[105][105];

int ans=0;
int lp[10],n;
int aps(int a){
    if(a<0)return a+10;
    return a;
}
bool spn(int p){
    int len=-1,lst;
    for(int i=1;i<=5;i++){
        if(lp[i]==a[p][i])continue;
        else{
            if(len==-1){
                len=aps(lp[i]-a[p][i]);
                lst=i;
            }else{
                if(lst==i-1&&aps(lp[i]-a[p][i])==len){

                }else{
                    return false;
                }
            }
        }
    }
    return true;
}
void dfs(int step){
    if(step==6){
        for(int i=1;i<=n;i++){
            if(!spn(i))return;
        }
        ans++;
        return ;
    }
    for(int i=0;i<=9;i++){
        lp[step]=i;
        dfs(step+1);
    }
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=5;j++)
            cin>>a[i][j];
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int flag=true;
            for(int k=1;k<=5;k++){
                if(a[i][k]!=a[j][k]){
                    flag=false;
                    break;
                }
            }
            if(flag==true){
                for(int k=1;k<=5;k++){
                    swap(a[j][k],a[n][k]);
                }
                n--;
                j--;
            }
        }
    }
    dfs(1);
    cout<<ans-n;
    return 0;
}
/*

            int id;
            for(int j=1;j<=5;j++){
                if(eql[j]==-1){
                    id=j;break;
                }
            }
            if(eql[id+1]!=-1){
                cout<<0;
                return 0;
            }else{
                int ans=0;
                int minn=a[1][id]-a[1][id+1];
                if(minn<0)minn+=10;;
                for(int i=1;i<=n;i++){
                    if(aps(a[i][id]-a[i][id+1])!=minn){
                        cout<<0;
                        return 0;
                    }else{
                        if(!vis[a[i][id]]){
                            vis[a[i][id]]=true;
                            ans++;
                        }
                    }
                }
                cout<<n-ans;
                return 0;
            }
*/
/*

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=5;j++)
            cin>>a[i][j];
    int op=0;
    for(int j=1;j<=5;j++){
        eql[j]=a[1][j];
        for(int i=2;i<=n;i++){
            if(a[i][j]==eql[j])continue;
            else{
                if(eql[j]!=-1)op++;
                eql[j]=-1;
            }
        }
    }
    if(op==0)cout<<81<<endl;
    else{
        if(op==1){
            int ans=0;
            for(int j=1;j<=5;j++){
                if(eql[j]==-1){
                    for(int i=1;i<=n;i++){
                        if(!vis[a[i][j]]){
                            vis[a[i][j]]=1;
                            ans++;
                        }
                    }
                }
            }
            cout<<n-ans<<endl;
            return 0;
        }else
        if(op==2){
            int ret=0;
            int c1=-1,c2=-1;
            for(int i=1;i<=5;i++){
                if(eql[i]!=-1)ans[i]=a[1][i];
                else {
                    if(c1=-1)c1=i;
                    else c2=i;
                }
            }
            bool flag=true;
            for(int n1=0;n1<=9;n1++){
                for(int n2=0;n2<=9;n2++){
                    ans[c1]=n1;
                    ans[c2]=n2;
                    for(int i=1;i<=n;i++){
                        if(!check(i)){
                            break;
                        }else{
                            ret++;
                        }
                    }
                }
            }
            cout<<ret;
            return 0;
        }else
        if(op==3){

        }else{
            cout<<0<<endl;
            return 0;
        }
    }
*/
