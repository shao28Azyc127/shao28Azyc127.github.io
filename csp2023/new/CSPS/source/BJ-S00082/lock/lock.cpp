#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
map<int,int> mp;
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    cin>>n;
    int a[10][10];
    for(int i=0;i<n;i++){
        for(int j=0;j<5;j++){
            cin>>a[i][j];
        }
    }
    int sum=0;
    if(n==1){
        cout<<81;
        return 0;
    }
    else if(n==2){
        for(int j=0;j<=1;j++){
            for(int i=0;i<=9;i++){
                if(i==a[j][0]) continue;
                mp[i*10000+a[j][1]*1000+a[j][2]*100+a[j][3]*10+a[j][4]]++;
            }
            for(int i=0;i<=9;i++){
                if(i==a[j][1]) continue;
                mp[i*1000+a[j][0]*10000+a[j][2]*100+a[j][3]*10+a[j][4]]++;
            }
            for(int i=0;i<=9;i++){
                if(i==a[j][2]) continue;
                mp[i*100+a[j][1]*1000+a[j][0]*10000+a[j][3]*10+a[j][4]]++;
            }
            for(int i=0;i<=9;i++){
                if(i==a[j][3]) continue;
                mp[i*10+a[j][1]*1000+a[j][2]*100+a[j][0]*10000+a[j][4]]++;
            }
            for(int i=0;i<=9;i++){
                if(i==a[j][4]) continue;
                mp[i+a[j][1]*1000+a[j][2]*100+a[j][3]*10+a[j][0]*10000]++;
            }

            for(int i=1;i<=9;i++){
                int x=a[j][0],y=a[j][1];
                a[j][0]=(a[j][0]+i)%10,a[j][1]=(a[j][1]+i)%10;
                mp[a[j][0]*10000+a[j][1]*1000+a[j][2]*100+a[j][3]*10+a[j][4]]++;
                a[j][0]=x;a[j][1]=y;
            }
            for(int i=1;i<=9;i++){
                int x=a[j][1],y=a[j][2];
                a[j][1]=(a[j][1]+i)%10,a[j][2]=(a[j][2]+i)%10;
                mp[a[j][0]*10000+a[j][1]*1000+a[j][2]*100+a[j][3]*10+a[j][4]]++;
                a[j][1]=x;a[j][2]=y;
            }
            for(int i=1;i<=9;i++){
                int x=a[j][2],y=a[j][3];
                a[j][2]=(a[j][2]+i)%10,a[j][3]=(a[j][3]+i)%10;
                mp[a[j][0]*10000+a[j][1]*1000+a[j][2]*100+a[j][3]*10+a[j][4]]++;
                a[j][2]=x;a[j][3]=y;
            }
            for(int i=1;i<=9;i++){
                int x=a[j][3],y=a[j][4];
                a[j][3]=(a[j][3]+i)%10,a[j][4]=(a[j][4]+i)%10;
                mp[a[j][0]*10000+a[j][1]*1000+a[j][2]*100+a[j][3]*10+a[j][4]]++;
                a[j][3]=x;a[j][4]=y;
            }
        }
        for(int i=0;i<=99999;i++){
            if(mp[i]==n){
                sum++;
            }
        }
    }
    else{
        for(int j=0;j<n;j++){
            for(int i=0;i<=9;i++){
                if(i==a[j][0]) continue;
                mp[i*10000+a[j][1]*1000+a[j][2]*100+a[j][3]*10+a[j][4]]++;
            }
            for(int i=0;i<=9;i++){
                if(i==a[j][1]) continue;
                mp[i*1000+a[j][0]*10000+a[j][2]*100+a[j][3]*10+a[j][4]]++;
            }
            for(int i=0;i<=9;i++){
                if(i==a[j][2]) continue;
                mp[i*100+a[j][1]*1000+a[j][0]*10000+a[j][3]*10+a[j][4]]++;
            }
            for(int i=0;i<=9;i++){
                if(i==a[j][3]) continue;
                mp[i*10+a[j][1]*1000+a[j][2]*100+a[j][0]*10000+a[j][4]]++;
            }
            for(int i=0;i<=9;i++){
                if(i==a[j][4]) continue;
                mp[i+a[j][1]*1000+a[j][2]*100+a[j][3]*10+a[j][0]*10000]++;
            }
            for(int i=1;i<=9;i++){
                int x=a[j][0],y=a[j][1];
                a[j][0]=(a[j][0]+i)%10,a[j][1]=(a[j][1]+i)%10;
                mp[a[j][0]*10000+a[j][1]*1000+a[j][2]*100+a[j][3]*10+a[j][4]]++;
                a[j][0]=x;a[j][1]=y;
            }
            for(int i=1;i<=9;i++){
                int x=a[j][1],y=a[j][2];
                a[j][1]=(a[j][1]+i)%10,a[j][2]=(a[j][2]+i)%10;
                mp[a[j][0]*10000+a[j][1]*1000+a[j][2]*100+a[j][3]*10+a[j][4]]++;
                a[j][1]=x;a[j][2]=y;
            }
            for(int i=1;i<=9;i++){
                int x=a[j][2],y=a[j][3];
                a[j][2]=(a[j][2]+i)%10,a[j][3]=(a[j][3]+i)%10;
                mp[a[j][0]*10000+a[j][1]*1000+a[j][2]*100+a[j][3]*10+a[j][4]]++;
                a[j][2]=x;a[j][3]=y;
            }
            for(int i=1;i<=9;i++){
                int x=a[j][3],y=a[j][4];
                a[j][3]=(a[j][3]+i)%10,a[j][4]=(a[j][4]+i)%10;
                mp[a[j][0]*10000+a[j][1]*1000+a[j][2]*100+a[j][3]*10+a[j][4]]++;
                a[j][3]=x;a[j][4]=y;
            }
        }
        for(int i=0;i<=99999;i++){
            if(mp[i]==n) sum++;
        }
    }
    cout<<sum;
    return 0;
}
