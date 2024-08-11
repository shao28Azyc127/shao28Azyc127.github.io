#include <bits/stdc++.h>
using namespace std;

const int N=10;
int num[N][N],num_all[N],n;
int ten[N];

queue <int>q;//may true

int f(int x,int y){
    return (x%ten[y])/ten[y-1];
}

bool check(int x,int y){
    if(x==y)return 0;
    int n1=x,n2=y;
    int ready=0;
    int dir;
    int k=0;
    for(int i=1;i<=5;i++){
        if(n1%10==n2%10){
            if(ready)ready++;
            n1/=10,n2/=10;
            continue;
        }
        if(!ready)dir=i;
        ready++;
        k++;
        if(ready>2)return 0;
        n1/=10,n2/=10;

    }
    if(k==1)return 1;
    else{
        int x1=f(x,dir),x2=f(x,dir+1),
            y1=f(y,dir),y2=f(y,dir+1);
        if(x1-y1==x2-y2)return 1;
        else return 0;
    }
    //yes: ret=1
    //no : ret=0
}

int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);

    //10^0~6
    ten[0]=1;
    for(int i=1;i<=8;i++)ten[i]=ten[i-1]*10;

    //input
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %d %d %d %d",&num[i][1],&num[i][2],&num[i][3],&num[i][4],&num[i][5]);
        //turn num[i][1~5] to num_all[i]
        num_all[i]=100000+num[i][1]*10000+num[i][2]*1000+num[i][3]*100+num[i][4]*10+num[i][5];

    }

    //all the possibilities in the beginning
        //change 1 num
    for(int i=1;i<=5;i++){
        for(int j=0;j<=9;j++){
            int k=f(num_all[1],i);
            if(k==j)continue;
            int put_num = num_all[1] - k*ten[i-1]+j*ten[i-1];
            q.push(put_num);
        }
    }
        //change 2 num
    for(int i=5;i>=2;i--){
        for(int j=1;j<=9;j++){
            int out1=f(num_all[1],6-i),out2=f(num_all[1],6-i+1);
            int in1=(out1+j)%10,in2=(out2+j)%10;
            int put_num = num_all[1] - out1*ten[5-i] - out2*ten[5-i+1] + in1*ten[5-i] + in2*ten[5-i+1];
            q.push(put_num);
        }
    }
    //check others

    for(int i=2;i<=n;i++){
        for(int j=1;j<=81;j++){
            int x=q.front(),y=num_all[i];
            q.pop();
            bool ch=check(x,y);
            if(ch)q.push(x);

        }
    }

    int cnt=0;
    while(!q.empty()){
        q.pop();
        cnt++;
    }
    printf("%d",cnt);
    return 0;
}