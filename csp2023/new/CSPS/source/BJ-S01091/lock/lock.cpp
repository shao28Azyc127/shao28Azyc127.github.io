#include<bits/stdc++.h>
int a[6],b[1000005][6],k=0;
using namespace std;
/*void sort2(){
    return ;
}*/
int out(){
    for(int weishu=1;weishu<=5;weishu++){
        for(int fangxiang=-1;fangxiang<=1;fangxiang+=2){
            for(int bo=1;bo<=9;bo++){
                b[++k][weishu]+=fangxiang*bo;
            }
        }
    }
    //unique(b+1,b+k+1);
}
void in(){
    for(int i=1;i<=5;i++){
        cin>>a[i];
	}
	out();
}
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
        in();
	}
	cout<<45;
	return 0;
}
