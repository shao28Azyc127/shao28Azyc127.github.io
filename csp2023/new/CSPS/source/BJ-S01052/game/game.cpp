#include<bits/stdc++.h>
using namespace std;
int a[8005][8005];
int b[8005];
int n;
long long ans;
long long m;
string s;
int main()
{
    freopen("game.in","r",stdin);
   freopen("game.out","w",stdout);
    scanf("%d",&n);
    cin>>s;
    for(int i = 0; i< s.size(); i++){
        b[i+1] = int(s[i]-'a'+1);

    }
    for(int len = 2; len<=n; len++){
        if(len%2!=0)continue;
        for(int i = 1; i + len - 1<= n; i++){
            int j = i+len-1;
            if(len==2){
                if(b[i]==b[j]){a[i][j]=1;ans++;}
            }
            else{
                    int flag = 0;
                if(b[i]==b[j]&&a[i+1][j-1]==1){
                    a[i][j] =1;
                    flag = 1;
                }
                else
                {
                    for(int k = i+1; k < j; k++){
                        if((a[i][k]==1)&&(a[k+1][j]==1)){
                            a[i][j]=1;flag = 1;
                            break;
                        }
                    }
                }
                ans+=flag;
            }
        }
    }

    cout<<ans;
    return 0;
}
