#include <stdio.h>
typedef long long ll;
int onSeg(ll x1,ll y1,ll x2,ll y2,ll x3,ll y3){return x2<= (x1>x3?x1:x3) && x2>= (x1<x3?x1:x3) && y2<= (y1>y3?y1:y3) && y2>= (y1<y3?y1:y3);}
int orient(ll x1,ll y1,ll x2,ll y2,ll x3,ll y3){
    ll val=(y2-y1)*(x3-x2)-(x2-x1)*(y3-y2);
    if(val==0) return 0;
    return (val>0)?1:2;
}
int main(){
    ll x1,y1,x2,y2,x3,y3,x4,y4;
    if(scanf("%lld %lld %lld %lld %lld %lld %lld %lld",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4)!=8) return 0;
    int o1=orient(x1,y1,x2,y2,x3,y3);
    int o2=orient(x1,y1,x2,y2,x4,y4);
    int o3=orient(x3,y3,x4,y4,x1,y1);
    int o4=orient(x3,y3,x4,y4,x2,y2);
    int inter=0;
    if(o1!=o2 && o3!=o4) inter=1;
    else if(o1==0 && onSeg(x1,x3,y1,y3,x2,y2)) inter=1;
    else if(o2==0 && onSeg(x1,x4,y1,y4,x2,y2)) inter=1;
    else if(o3==0 && onSeg(x3,x1,y3,y1,x4,y4)) inter=1;
    else if(o4==0 && onSeg(x3,x2,y3,y2,x4,y4)) inter=1;
    if(inter) printf("Intersect\n"); else printf("No Intersection\n");
    return 0;
}
