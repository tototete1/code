#include <iostream>
#include <cmath>
using namespace std;
int n,m;
int a[100001],res[100001];
int RMQ(int u,int v)
{
    int ans=1e9,x,y,i;
    x=u/m-(u%m==0);
    y=v/m-(v%m==0);
    if (x!=y)
    {
        for (i=x+1;i<=y-1;i++) ans=min(a[res[i]],ans);
        for (i=u;i<=(x+1)*m;i++) ans=min(ans,a[i]);
        for (i=v;i>y*m;i--) ans=min(ans,a[i]);
    }
    else
    {
        for (i=u;i<=v;i++) ans=min(a[i],ans);
    }
    return ans;

}
int main()
{
    int u,v,x,i,j;
    cin >>n;
    for (i=1;i<=n;i++) cin >>a[i];
    m=sqrt(n);
    x=1;
    int vt=1;
    for (i=0;i<=m;i++)
    {
        res[i]=1e9;
        for (j=x;j<=x+m-1 && j<=n ;j++)
            {
                if (res[i]>a[j])
                {
                    res[i]=a[j];
                    vt=j;
                }
            }
        res[i]=vt;
        x=x+m;
    }
    cin >>u>>v;
    cout <<RMQ(u,v);
    return 0;
}
