#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int c,t,n,m,ans;
int c3[112345];
bool c8[2][112345];
char aa[112345];int x1[112345],x2[112345];
int ydy[20],now2[20];
int dfs(int x){
    int bst=2e9;
    if(x==n+1){
//        for(int i=1;i<=n;i++)   cout<<ydy[i]<<" ";
//        cout<<endl;
        for(int i=1;i<=n;i++)  now2[i]=ydy[i];
        for(int i=1;i<=m;i++){
            if(aa[i]=='+')  {now2[x1[i]]=now2[x2[i]];continue;}
            if(aa[i]=='-'){
                if(now2[x2[i]]==1)  now2[x1[i]]=2;
                if(now2[x2[i]]==2)  now2[x1[i]]=1;
                if(now2[x2[i]]==3)  now2[x1[i]]=3;
            }
            if(aa[i]=='T')  now2[x1[i]]=2;
            if(aa[i]=='F')  now2[x1[i]]=1;
            if(aa[i]=='U')  now2[x1[i]]=3;
        }
        bool o=0;
        int mmmmm=0;
        for(int i=1;i<=n;i++)
            if(now2[i]!=ydy[i]){o=1;break;}
        if(o)   return 2e9;
        for(int i=1;i<=n;i++)   if(now2[i]==3)  mmmmm++;
//        if(mmmmm==0){
//                cout<<"wrong";
//            for(int i=1;i<=n;i++)
//                cout<<ydy[i]<<" ";
//            cout<<"||||";
//            for(int i=1;i<=n;i++)
//                cout<<now2[i]<<" ";
//            cout<<endl;
//        }
        return mmmmm;
    }
    for(int i=1;i<=3;i++)
    {
        ydy[x]=i;
        bst=min(bst,dfs(x+1));
    }
    return bst;
}
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>c>>t;
    if(c<=2){
//            cout<<"ysy";
//        cout<<c<<" "<<t<<endl;
        while(t--){
            cin>>n>>m;
//            cout<<n<<" "<<m<<endl;
            for(int i=1;i<=m;i++){
                cin>>aa[i];
                cin>>x1[i];
                if(aa[i]=='+'||aa[i]=='-')  cin>>x2[i];
            }
            cout<<dfs(1)<<endl;
        }
    }
    if(c==3||c==4){
//            cout<<"NO"<<endl;
        while(t--){
           cin>>n>>m;
           ans=0;
           for(int i=1;i<=n;i++)    c3[i]=0;
           for(int i=1;i<=m;i++){
                char a;
                int x;
                cin>>a>>x;
                if(a=='T')
                    c3[x]=1;
                if(a=='F')
                    c3[x]=0;
                if(a=='U')
                    c3[x]=2;
           }
           for(int i=1;i<=n;i++)
                ans+=(bool)(c3[i]==2);
            cout<<ans<<endl;
        }
    }
    if(c==5||c==6){
//        cout<<"yes"<<endl;
        while(t--){
            cin>>n>>m;
//            cout<<n<<" "<<m<<endl;
            ans=-1;
            int ans1=0;
            for(int i=1;i<=n;i++)    c3[i]=0;
            for(int i=1;i<=m;i++){
                cin>>aa[i];
                if(aa[i]=='U')  cin>>x1[i];
                else    cin>>x1[i]>>x2[i];
            }
//            for(int i=1;i<=m;i++){
//                cout<<aa[i]<<" "<<x1[i]<<" "<<x2[i]<<endl;
//            }
            while(ans!=ans1){
                ans=ans1;
                ans1=0;
//                cout<<ans<<" "<<ans1<<endl;
                for(int i=1;i<=m;i++){
                    if(aa[i]=='U')
                        c3[x1[i]]=1;
                    if(aa[i]=='+')
                        c3[x1[i]]=c3[x2[i]];
                }
                for(int i=1;i<=n;i++)
                    ans1+=c3[i];
            }
            cout<<ans<<endl;
        }
    }
    if(c==7||c==8){
//        cout<<"yes"<<endl;
        while(t--){
            cin>>n>>m;
//            cout<<n<<" "<<m<<endl;
            ans=-1;
            int ans1=0;
            for(int i=1;i<=n;i++)    c8[1][i]=0;
            for(int i=1;i<=m;i++){
                cin>>aa[i];
                cin>>x1[i]>>x2[i];
            }
            int now=0;
            while(ans!=ans1){
                now++;
                ans=ans1;
                ans1=0;
//                cout<<ans<<" "<<ans1<<endl;
                for(int i=1;i<=m;i++){
                    if(aa[i]=='-')
                        c8[now%2][x1[i]]=!c8[now%2][x2[i]];
                    if(aa[i]=='+')
                        c8[now%2][x1[i]]=c8[now%2][x2[i]];
                }
                for(int i=1;i<=n;i++)
                    ans1+=c8[now%2][i];
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
