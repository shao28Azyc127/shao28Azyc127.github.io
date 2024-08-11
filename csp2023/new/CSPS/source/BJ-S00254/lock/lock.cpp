#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll ans,n,f[100][100],m[10];
int main(){
freopen("lock.in","r",stdin);
freopen("lock.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++){
    for(int j=1;j<=5;j++){
        cin>>f[i][j];
    }
}
for(int a=0;a<=9;a++){
    m[1]=a;
    for(int b=0;b<=9;b++){
        m[2]=b;
        for(int c=0;c<=9;c++){
            m[3]=c;
            for(int d=0;d<=9;d++){
                m[4]=d;
                for(int e=0;e<=9;e++){
                    m[5]=e;
                    int flag=0,nono=0;
                    for(int i=1;i<=n;i++){
                        if(f[i][1]==a and f[i][2]==b and f[i][3]==c and f[i][4]==d and f[i][5]==e){flag=1;}
                    }
                    if(flag==1)continue;
                    //1
                    int ok=1;int yes=1;int fine=1;
                    for(int i=1;i<=n;i++){
                        ok=1,yes=1;
                        int cnt=0;
                        for(int j=1;j<=5;j++){
                            if(j==1)
                                if(a!=f[i][j])cnt++;
                            if(j==2)
                                if(b!=f[i][j])cnt++;
                            if(j==3)
                                if(c!=f[i][j])cnt++;
                            if(j==4)
                                if(d!=f[i][j])cnt++;
                            if(j==5)
                                if(e!=f[i][j])cnt++;
                        }
                        if(cnt>2)nono=1;
                        if(cnt>1){
                            ok=0;
                        }
                        //2

                            int flagg=0;
                            for(int j=2;j<=5;j++){
                                int num1=(f[i][j]-f[i][j-1]+10)%10,num2=(m[j]-m[j-1]+10)%10;
                                if(num1==num2 and f[i][j]!=m[j] and f[i][j-1]!=m[j-1]){
                                    flagg=1;
                                    break;
                                }
                            }
                            if(flagg==0)yes=0;
                            if(yes==0 and ok==0){
                                fine=0;
                                break;
                            }
                    }
                    if(nono==1)continue;
                    if(fine==1){
                            ans++;
                            continue;
                        }
                }
            }
        }
    }
}
cout<<ans;
return 0;
}
