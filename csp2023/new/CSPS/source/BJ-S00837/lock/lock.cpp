#include <bits/stdc++.h>

using namespace std;

int state[10][7];

int bo(int x,int y){
    if(x<y){
        x=x+10;
    }
    return x-y;
}

bool check(int i1,int i2,int i3,int i4,int i5,int n){
    int c0=bo(i1,state[n][0]);
    int c1=bo(i2,state[n][1]);
    int c2=bo(i3,state[n][2]);
    int c3=bo(i4,state[n][3]);
    int c4=bo(i5,state[n][4]);
    if(c0==0&&c1==0&&c2==0&&c3==0&&c4==0)return false;
    if((c0==0)+(c1==0)+(c2==0)+(c3==0)+(c4==0)==4)return true;
    if(c0==c1&&c2==c3&&c3==c4&&c4==0)return true;
    if(c1==c2&&c0==c3&&c3==c4&&c4==0)return true;
    if(c2==c3&&c0==c1&&c1==c4&&c4==0)return true;
    if(c3==c4&&c0==c1&&c1==c2&&c2==0)return true;
    return false;
}

int n;

void work(){
    int ans=0;
    for(int i1=0;i1<=9;i1++){
        for(int i2=0;i2<=9;i2++){
            for(int i3=0;i3<=9;i3++){
                for(int i4=0;i4<=9;i4++){
                    for(int i5=0;i5<=9;i5++){
                        int i;
                        for(i=0;i<n;i++){
                            if(!check(i1,i2,i3,i4,i5,i)){
                                break;
                            }
                        }
                        if(i==n){
                            ans++;
                        }
                    }
                }
            }
        }
    }
	cout<<ans<<endl;
}

int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
        for(int j=0;j<5;j++){
            cin>>state[i][j];
        }
	}
	work();
	return 0;
}
