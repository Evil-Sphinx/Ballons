#include<iostream>
#include<cmath>

int main() {
    double x1,x2,y1,y2;
    while(scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2)!=EOF) {
        double ans=sqrt(pow(abs(x2-x1),2)+pow(abs(y2-y1),2));
        printf("%.2lf\n",ans);
        getchar();
    }
    return 0;

}
