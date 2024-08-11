#include<bits/stdc++.h>
using namespace std;
int ans, n, c;
int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        c=0;
        for(int k=1;(k-1)*3+1<=n;k++){
            if((k-1)*3+1==n){
                ans=i;
            }
            c++;
        }
        n-=c;
        if(n==0){
            cout << i << " " << ans;
            return 0;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

