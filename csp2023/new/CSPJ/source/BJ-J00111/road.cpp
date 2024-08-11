#include<bits/stdc++.h>

using namespace std;

int n,d;
int v[100005],a[100005];
long long int sum;

int main(){
   freopen("road.in","r",stdin);
   freopen("road.out","w",stdout);
   cin>>n>>d;
   for(int i=1;i<=(n-1);i++){
        int temp;
        cin>>temp;
        sum+=temp;
   }
   for(int i=1;i<=n;i++){
       cin>>a[i];
   }
   int s=a[1];
   int k=sum/d;
   if(sum%d!=0)k++;
   cout<<(k*s);
   fclose(stdin);
   fclose(stdout);
   return 0;
}

