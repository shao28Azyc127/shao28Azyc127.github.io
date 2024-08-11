#include<bits/stdc++.h>
using namespace std;

int n,cnt;
char s[1919810];

bool c(int a,int b){
    char z[1919810];
	if(a>b){
		swap(a,b);
	}
	int j=0;
    for(int i=a;i<b;i++){
        if(z[j]==s[i]){
            z[j]=0;
            j--;
        }
        else{
            j++;
            z[j]=s[i];
        }
    }
    return j==0;
}

int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",sidout);
    cin>>n;
    cin>>s;
    for(int i=n;i>=0;i--){
        for(int j=0;j<i;j++){
        	int a=i,b=j;
            char z[1919810];
			if(a>b){
				swap(a,b);
			}
			int l=0;
	    	for(int k=a;k<b;k++){
		        if(z[l]==s[k]){
		            z[l]=0;
		            l--;
		        }
		        else{
		            l++;
		            z[l]=s[k];
		        }
	    	}
		    if(l==0){
		    	cnt++;
			}
        }
    }
    cout<<cnt;
    return 0;
}
