#include<iostream>
#include<string>
#include<vector>
#include<cstdint>
#include<cmath>
using namespace std;

int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int c,t;
    cin>>c>>t;
    for(int I=0;I<t;I++){
        int n,m;
        cin>>n>>m;
        if(c==1||c==2){
            // ‰»Î
            vector<string> opt(m);
            vector<int> nv;
            for(int i=0;i<m;i++){
                cin>>opt[i];
                if(opt[i]=="T"||opt[i]=="F"||opt[i]=="U"){
                    int x;cin>>x;nv.push_back(x);
                }
                else{
                    int x,y;cin>>x>>y;
                    nv.push_back(x);nv.push_back(y);
                }
            }
            //√∂æŸ
            int ans=INT32_MAX;
            for(uint32_t i=0;i<(uint32_t)pow(3,n);i++){
                //init uNum
                int uNum=0;
                vector<int> init(n+1),xx(n+1);
                init[0]=xx[0]=-1;
                uint32_t tmp=i;
                for(int j=1;j<=n;j++){
                    init[j]=xx[j]=tmp%3;
                    tmp/=3;
                    if(init[j]==0)uNum++;
                }
                if(uNum>=ans)continue;
                //can
                int p=0;
                for(int j=0;j<m;j++){
                    if(opt[j]=="T"){
                        int a=nv[p++];
                        xx[a]=1;
                    }
                    else if(opt[j]=="F"){
                        int a=nv[p++];
                        xx[a]=2;
                    }
                    else if(opt[j]=="U"){
                        int a=nv[p++];
                        xx[a]=0;
                    }
                    else if(opt[j]=="+"){
                        int a=nv[p++];int b=nv[p++];
                        xx[a]=xx[b];
                    }
                    else if(opt[j]=="-"){
                        int a=nv[p++];int b=nv[p++];
                        if(xx[b]==0)xx[a]=0;
                        else if(xx[b]==1)xx[a]=2;
                        else if(xx[b]==2)xx[a]=1;
                    }
                }
                if(xx==init)ans=uNum;
            }
            cout<<ans<<endl;
        }
        else if(c==3||c==4){
            int ans=0;
            vector<bool> v(n+1,0);
            for(int i=0;i<m;i++){
                string s;int x;
                cin>>s>>x;
                if(s=="U"){
                    v[x]=1;
                }
                else v[x]=0;
            }
            for(int i=1;i<=n;i++){
                if(v[i])ans++;
            }
            cout<<ans<<endl;
        }
        else if(c==5||c==6){
            int ans=0;
            vector<bool> v(n+1,0);
            for(int i=0;i<m;i++){
                string s;
                cin>>s;
                if(s=="U"){
                    int x;cin>>x;
                    v[x]=1;
                }
                else if(s=="+"){
                    int x,y;cin>>x>>y;
                    v[x]=v[y];
                }
            }
            for(int i=1;i<=n;i++){
                if(v[i])ans++;
            }
            cout<<ans<<endl;
        }
    }

    return 0;
}