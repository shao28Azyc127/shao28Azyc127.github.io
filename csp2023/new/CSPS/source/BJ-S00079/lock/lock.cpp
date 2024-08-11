#include <iostream>
using namespace std;
int n;
int status[12][5];
int temp[5];
int avaliable[100000]={0};
int update[100000]={0};
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>status[i][0]>>status[i][1]>>status[i][2]>>status[i][3]>>status[i][4];
        for(int j=0;j<5;j++){
            for(int k=0;k<5;k++) temp[k]=status[i][k];
            for(int k=0;k<9;k++){
                temp[j]++;
                temp[j]=temp[j]%10;
                int num=temp[0]*10000+temp[1]*1000+temp[2]*100+temp[3]*10+temp[4];
                if(update[num]<i){
                    avaliable[num]++;
                    update[num]=i;
                }
            }
        }
        for(int j=0;j<4;j++){
            for(int k=0;k<5;k++) temp[k]=status[i][k];
            for(int k=0;k<9;k++){
                temp[j]++;
                temp[j+1]++;
                temp[j]=temp[j]%10;
                temp[j+1]=temp[j+1]%10;
                int num=temp[0]*10000+temp[1]*1000+temp[2]*100+temp[3]*10+temp[4];
                if(update[num]<i){
                    avaliable[num]++;
                    update[num]=i;
                }
            }
        }
    }
    for(int i=0;i<100000;i++) if(avaliable[i]==n) ans++;
    cout<<ans;
    return 0;
}
