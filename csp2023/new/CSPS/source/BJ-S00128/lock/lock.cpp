#include<bits/stdc++.h>
using namespace std;
bool stat[100100];
int n,dest[10],minu[10],cnt=0;
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	cin>>n;
	        for(int i=00000;i<=99999;i++){stat[i]=1;}

	while(n--){
	for(int i=1;i<=5;i++){
		cin>>dest[i];
	}
	//for(int i=00000;i<=99999;i++){stat[i]=1;}
	for(int i=00000;i<=99999;i++){
		minu[1]=i/10000-dest[1];
		minu[2]=i/1000%10-dest[2];
		minu[3]=i/100%10-dest[3];
		minu[4]=i/10%10-dest[4];
		minu[5]=i%10-dest[5];
		
		for(int j=1;j<=5;j++){
			if(minu[j]<0){minu[j]+=10;}
		//	cout<<minu[j]<<" ";
		}
		//cout<<endl<<i<<endl;
		if(stat[i]==1){
		if(minu[1]+minu[2]+minu[3]+minu[4]+minu[5] == 0){
			stat[i]=0;}
		else if(minu[1]==minu[2] && minu[1] != 0 && minu[3]+minu[4]+minu[5] == 0){
			//stat[i]=1;
		}else if(minu[2]==minu[3] && minu[2] != 0 && minu[1]+minu[4]+minu[5] == 0){
                        //stat[i]=1;
                }else if(minu[3]==minu[4] && minu[3] != 0 && minu[1]+minu[2]+minu[5] == 0){
                        //stat[i]=1;
                }else if(minu[4]==minu[5] && minu[4] != 0 && minu[1]+minu[2]+minu[3] == 0){
			//stat[i]=1;
                }/*else if(minu[5]==minu[1] && minu[5] != 0 && minu[2]+minu[3]+minu[4] == 0){
                        stat[i]=1;
                }*/else if(minu[1] != 0 && minu[2]+minu[3]+minu[4]+minu[5] == 0){
			//stat[i]=1;
		}else if(minu[2] != 0 && minu[1]+minu[3]+minu[4]+minu[5] == 0){
                        //stat[i]=1;
                }else if(minu[3] != 0 && minu[1]+minu[2]+minu[4]+minu[5] == 0){
                        //stat[i]=1;
                }else if(minu[4] != 0 && minu[1]+minu[2]+minu[3]+minu[5] == 0){
                        //stat[i]=1;
                }else if(minu[5] != 0 && minu[2]+minu[3]+minu[4]+minu[1] == 0){
                        //stat[i]=1;
                }else{
			stat[i]=0;}
		}
		//if(stat[i]==1){cout<<i<<endl;}
	}
/*	for(int i=00000;i<=99999;i++){
		//cnt+=stat[i];
		                if(stat[i]==1){cnt++;}

	}
	cout<<cnt;
	return 0;
*/







	}
//output
//
//
for(int i=00000;i<=99999;i++){
                //cnt+=stat[i];
                                if(stat[i]==1){cnt++;}

        }
        cout<<cnt;
        return 0;

	}
