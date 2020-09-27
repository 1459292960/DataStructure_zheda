/*@date:
    2020-09-27
@功能：
    求一个数列的最大子列和
@目的：

*/


# include <stdio.h>

int MaxSubseqSum(int * a,int N)
{
    int ThisSum,MaxSum;
    int i;
    ThisSum =MaxSum=0;
    for (i=0;i<N;i++)
    {
        ThisSum +=a[i];
        if (ThisSum >MaxSum)
            MaxSum = ThisSum;
        else if (ThisSum <0)
            ThisSum=0;
    }
    return MaxSum;

}
int main(void)
{
    int i;
    int N=7;
    int a[7]={6,1,-8,1,5,-1,-1};  // 写成a[N]时报错：variable-sized object may not be initialized
    int max;
    // for (i=0;i<N;i++)
    //     a[i]=i;
    max=MaxSubseqSum(a,N);
    printf("最大子列和为 %d\n",max);
    return 0;
}