/*@date:
    2020-09-21
@功能：
    大概估计程序运行的时间
@目的：
    time.h中clock方法的使用
*/


# include <stdio.h>
# include <time.h>
# include <math.h>
#include <unistd.h>
# include <stdlib.h>
# define MAXN 10

clock_t start,stop;
double duration;

double f1(int n,double * a,double x)
{
    int i;
    double p=a[0];
    for (i=1;i<=n;i++)
        p+=(a[i]*pow(x,i));
    return p;
}
double f2(int n,double *a,double x)
{
    int i;
    double p=a[n];
    for (i=n;i>0;i--)
        p=a[i-1]+x*p;
    return p;
}
int main(void)
{
    int i;
    double a[MAXN];
    for (i=0;i<MAXN;i++)
        a[i]=(double)i;
    
    start  =clock();
    f1(MAXN-1,a,1.1);
    stop=clock();
    duration=((double)(stop-start))/_SC_CLK_TCK; // CLK_TCK为常数，表示机器时钟每秒所走的时钟打点数
    printf("ticks1= %f\n",(double)(stop-start));
    printf("duration = %6.2e\n",duration);
    
    start  =clock();
    f2(MAXN-1,a,1.1);
    stop=clock();
    duration=((double)(stop-start))/_SC_CLK_TCK; // CLK_TCK为常数，表示机器时钟每秒所走的时钟打点数
    printf("ticks1= %f\n",(double)(stop-start));
    printf("duration = %6.2e\n",duration);

    return 0;

}