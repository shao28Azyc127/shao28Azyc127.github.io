#include <iostream>
using namespace std;
int c,t;
int var[200000];
bool sen[200000];
int beg[200000];
bool ttm[200000];
int n,m;
char s;
int v1,v2;
int ans;
int nxt(int i,int tm,bool eq){
    if(beg[i]==2){
        ttm[i]=!eq;
        //cout<<eq<<" ";
        beg[i]=3;
        int res=nxt(var[i],++tm,eq==sen[i]);
        beg[i]=res;
        return res;
    }
    else{
        if(beg[i]==3){
            //cout<<" "<<i<<" "<<ttm[i];
            if(eq!=ttm[i]) return 0;
            else return 1;
        }
        else if(beg[i]==1) return 1;
        else return 0;
    }
}
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        ans=0;
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            var[i]=i;
            sen[i]=true;
            beg[i]=2;
            ttm[i]=false;
        }
        for(int j=1;j<=m;j++){
            cin>>s;
            if(s=='+'|| s=='-'){
                cin>>v1>>v2;
                if(var[v2]<0){
                    if(s=='+'){
                        var[v1]=var[v2];
                    }
                    else{
                        if(var[v2]==-1) var[v1]=-2;
                        if(var[v2]==-2) var[v1]=-1;
                        if(var[v2]==-3) var[v1]=-3;
                    }
                    sen[v1]=true;
                }
                else{
                    var[v1]=var[v2];
                    sen[v1]=sen[v2]==(s=='+');
                }
            }
            else{
                cin>>v1;
                if(s=='T') var[v1]=-1;
                if(s=='F') var[v1]=-2;
                if(s=='U') var[v1]=-3;
            }
        }
        // for(int i=1;i<=n;i++) cout<<var[i]<<" ";
        // cout<<endl;
        // for(int i=1;i<=n;i++) cout<<sen[i]<<" ";
        // cout<<endl;
        for(int i=1;i<=n;i++){
            if(var[i]==i){
                //cout<<i<<endl;
                if(sen[i]) beg[i]=0;
                else beg[i]=1;
            }
            else if(var[i]<0){
                if(var[i]==-3) beg[i]=1;
                else beg[i]=0;
            }
            else beg[i]=2;
        }
        
        for(int i=1;i<=n;i++){
            if(beg[i]==2){
                beg[i]=3;
                ttm[i]=false;
                beg[i]=nxt(var[i],1,sen[i]);
                // cout<<endl;
            }
        }
        for(int i=1;i<=n;i++){
            if(beg[i]==1) ans++;
        }
        // for(int i=1;i<=n;i++) cout<<beg[i]<<" ";
        // cout<<endl;
        cout<<ans<<endl;
        // cout<<endl;
    }
    return 0;
}