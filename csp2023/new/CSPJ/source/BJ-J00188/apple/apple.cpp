#include<iostream>
using namespace std;
int ori[1001000];
int main(){
	int numberx,remainx,cnt=0,nexe,exect;
	bool modif=0;
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	cin>>numberx;
	remainx=numberx;
	for (int i=1; i<=numberx; i++){
		ori[i]=i;
	}
//	for(int i=1;i<=numberx;i++){
//                cout<<ori[i];
//        }
//        cout<<endl;
	ori[numberx+1]=0;
	ori[numberx+2]=0;
	ori[numberx+3]=0;
	while(remainx){		
		if(remainx%3 == 1 && modif == 0){
 //               cout<<"!!!"<<endl;
                nexe=cnt+1;
                modif=1;
        }

	if(remainx %3 == 0){
		exect=remainx/3;
	}else{
		exect=remainx/3+1;
	}

	for(int i=1;i<=exect;i++){
		
		ori[2*i-1]=ori[i*3-1];
		ori[2*i]=ori[3*i];
		remainx--;
	}
	for(int i=remainx+1;i<=numberx;i++){
		ori[i]=0;
	}
//	for(int i=1;i<=numberx;i++){
//	cout<<ori[i]<< " ";
//
//	}
	cnt++;
//	cout<<endl<<remainx<<endl<<remainx%3<<endl;
//	if(remainx%3 == 1 && modif == 0){
//		cout<<"!!!"<<endl;
//		nexe=cnt+1;
//		modif=1;
//	}
	}
	cout<<cnt<<" "<<nexe;
	return 0;
}

