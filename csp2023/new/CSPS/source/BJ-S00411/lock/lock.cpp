#include<bits/stdc++.h>
using namespace std;
int n,ans;
string a[15];
unordered_map<string,int> m;
int read(){
    int ans=0,w=1;
    char ch=getchar();
    while(ch>'9'||ch<'0'){
        if(ch=='-'){
            w=-1;
        }
        ch=getchar();
    }
    while(ch<='9'&&ch>='0'){
        ans=(ans<<3)+(ans<<1)+(ch^48);
        ch=getchar();
    }
    return ans*w;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    n=read();
    /**/
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            char temp;
            temp=getchar();
            if(temp==' '){
                j--;
                continue;
            }
            a[i]+=temp;
        }
    }

    if(n==1){
        cout<<"81";
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int p=1;p<=5;p++){
            for(int j=1;j<=9;j++){
                string tmp=a[i];
                int tmpt=(tmp[p]^48)+j;
                while(tmpt>=10){
                    tmpt=tmpt%10;
                }
                tmp[p]=char(tmpt^48);
                m[tmp]+=1;
                if(m[tmp]==n){
                    ans++;
                }
            }
        }
        for(int p=1;p<=4;p++){
            for(int j=1;j<=9;j++){
                string tmp=a[i];
                int tmpa=(tmp[p]^48)+j;
                int tmpb=(tmp[p+1]^48)+j;
                while(tmpa>=10){
                    tmpa=tmpa%10;
                }
                while(tmpb>=10){
                    tmpb=tmpb%10;
                }
                tmp[p]=char(tmpa^48);
                tmp[p+1]=char(tmpb^48);
                m[tmp]++;
                if(m[tmp]==n){
                    ans++;
                }
            }
        }
    }
    cout<<ans/2;
    return 0;
}
