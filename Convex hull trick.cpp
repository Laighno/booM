//#include<bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<vector>
using namespace std;

typedef __int64 ll;
typedef pair<ll,char> pic;


const int N=2e5+5;
const int mod=1e9+7;
const double PI=atan(1.0)*4;
const int LOG=20;


struct Line {
    ll a, b, get(ll x) { return a * x + b; }
};

struct ConvexHull {
    int size;
    Line *hull;

    ConvexHull(int maxSize) {
        hull = new Line[++maxSize], size = 0;
    }
    void init() { size=0; }

    bool is_bad(ll curr, ll prev, ll next) {
        Line c = hull[curr], p = hull[prev], n = hull[next];
        return (c.b - n.b) * (c.a - p.a) <= (p.b - c.b) * (n.a - c.a);
    }

    void add_line(ll a, ll b) {
        hull[size++] = (Line){a, b};
        while (size > 2 && is_bad(size - 2, size - 3, size - 1))
            hull[size - 2] = hull[size - 1], size--;
    }

    ll query(ll x) {
        int l = -1, r = size - 1;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (hull[m].get(x) <= hull[m + 1].get(x))
                l = m;
            else
                r = m;
        }
        return hull[r].get(x);
    }
};
/*
int n;
int a[N];
ll sum[N];

int main() {
    scanf("%d",&n);
    ConvexHull *hull=new ConvexHull(n);
    ll ans=0,dans=0;
    for(int i=0;i<n;i++) {
        scanf("%d",a+i);
        if(i) sum[i]=sum[i-1]+a[i];
        else sum[i]=a[i];
        ans+=a[i]*1ll*(i+1);
    }
    hull->size=0;
    for(int r=1;r<n;r++) {
        hull->add_line(r-1,r==1?0:-sum[r-2]);
        dans=max(dans,hull->query(a[r])+sum[r-1]-a[r]*1ll*r);
    }
    hull->size=0;
    for(int l=n-2;l>=0;l--) {
        hull->add_line(l+1,-sum[l+1]);
        dans=max(dans,hull->query(a[l])+sum[l]-a[l]*1ll*l);
    }
    printf("%I64d\n",ans+dans);
    return 0;
}
*/
