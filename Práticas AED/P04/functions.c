//
// Tomás Oliveira e Silva, AED, October 2021
//
// the functions for the first exercise of class P.04
// (for a given positive value of n, find a formula for the return value of each function)
//

#include <stdio.h>

int f1(int n)
{
  int i,r=0;

  for(i = 1;i <= n;i++)
    r += 1;
  return r;
}

int f2(int n)
{
  int i,j,r=0;

  for(i = 1;i <= n;i++)
    for(j = 1;j <= i;j++)
      r += 1;
  return r;
}

int f3(int n)
{
  int i,j,r=0;

  for(i = 1;i <= n;i++)
    for(j = 1;j <= n;j++)
      r += 1;
  return r;
}

int f4(int n)
{
  int i,r=0;

  for(i = 1;i <= n;i++)
    r += i;
  return r;
}

int f5(int n)
{
  int i,j,r=0;

  for(i = 1;i <= n;i++)
    for(j = i;j <= n;j++)
      r += 1;
  return r;
}

int f6(int n)
{
  int i,j,r=0;

  for(i = 1;i <= n;i++)
    for(j = 1;j <= i;j++)
      r += j;
  return r;
}

int main(void)
{
for(int p=1;p<15;p++){
    if(n < (s64)40 || dt1 < 10.0) { dt1 = cpu_time(); f = F_v1(n); dt1 = cpu_time() - dt1; printf("%3d 1 %20lld %9.6f\n",(int)n,f,dt1); }
    if(n < (s64)40 || dt2 < 10.0) { dt2 = cpu_time(); f = F_v2(n); dt2 = cpu_time() - dt2; printf("%3d 2 %20lld %9.6f\n",(int)n,f,dt2); }
    if(n < (s64)40 || dt3 < 10.0) { dt3 = cpu_time(); f = F_v3(n); dt3 = cpu_time() - dt3; printf("%3d 3 %20lld %9.6f\n",(int)n,f,dt3); }
    if(n < (s64)40 || dt4 < 10.0) { dt4 = cpu_time(); f = F_v4(n); dt4 = cpu_time() - dt4; printf("%3d 4 %20lld %9.6f\n",(int)n,f,dt4); }
    printf("%3d x ",(int)n); printf_s128(F(n)); printf("\n");
    printf("--- - -------------------- ---------\n");
    }
}
