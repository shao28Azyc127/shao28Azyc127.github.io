#include<bits/stdc++.h>
using namespace std;
string s[3005];
char minn[3005];
char maxn[3005];
int cnt[3005][26];
//bool ypre[3005];
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    int n,m;
    cin>>n>>m;
    //cout<<n<<endl;
    if(n==1){
        cout<<"1";
        return 0;
    }
    //cout<<"aa"<<n<<endl;
    for(int i=1;i<=n;i++){
        minn[i]=127;
        //ypre[i]=1;
        cin>>s[i];
        for(int j=0;j<m;j++){
            minn[i]=min(minn[i],s[i][j]);
            maxn[i]=max(maxn[i],s[i][j]);
            cnt[i][(s[i][j]-'a')]++;
        }
    }
    //cout<<"bb"<<n<<endl;
    for(int i=1;i<=n;i++){
        bool b=1;
        /*if(!ypre[i]){
            b=0;
        }
        cout<<"cc"<<n<<endl;*/
        for(int j=1;j<=n;j++){
            /*if(minn[j]>maxn[i]){
                ypre[j]=0;
            }else if(minn[j]<maxn[i]){
                ypre[j]&=1;
            }else{

            }*/
            if(minn[i]>maxn[j]){
                b=0;
            }else if(minn[i]<maxn[j]){
                b&=1;
                //ypre[j]=0;
            }else{
                for(int k=0;k<26;k++){
                    if(cnt[i][k]>cnt[j][k]){
                        //ypre[j]=0;
                        b&=1;
                        break;
                    }
                    if(cnt[i][k]<cnt[j][k]){
                        //ypre[j]&=1;
                        b=0;
                        break;
                    }
                }
            }
            //cout<<i<<" "<<j<<" "<<minn[i]<<" "<<maxn[i]<<" "<<minn[j]<<" "<<maxn[j]<<" "<<ypre[j]<<" "<<b<<endl;
            //cout<<n<<" "<<j<<"dd"<<endl;
        }
        cout<<(int)b;
    }
    return 0;
}
