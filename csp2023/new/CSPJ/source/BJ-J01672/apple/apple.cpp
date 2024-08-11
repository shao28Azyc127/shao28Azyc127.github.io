#include<iostream>
#include<algorithm>
#include<vector>

std::vector<int> apple;
int n,tp,nzln=0,day=0;

//1 2 3 4 5 6 7 8
//  2 3   5 6   8
//v1.拿走，v2.判断是否拿走了n  v2.5判空 3.排序 4.继续拿走

void nz()
{
    int j=0;
    day++;
    for(int i=1;i<=tp;i+=3)
    {
        if(apple[i]==n)
            nzln=day;
        j++;
        apple.pop_back();
    }
    tp-=j;
    std::stable_sort(&apple[1],&apple[tp+1]);
}

int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%d",&n);
    tp=n;
    for(int i=1;i<=n;i++)
    {
        apple.push_back(i);
    }
    while(!apple.empty())
    {
        nz();
    }
    printf("%d %d",day,nzln);
    return 0;
}
