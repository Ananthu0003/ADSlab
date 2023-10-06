#include<stdio.h>
#include<conio.h>
void main()
{
 int i,j,k,a[10],b[10],c[20],s1,s2,s3;
 clrscr();
 printf("Enter the 1st array size :");
 scanf("%d",&s1);
 printf("Enter the 1st array elements: ");
 for(i=0;i<s1;i++)
 {
   scanf("%d",&a[i]);
 }
 printf("\n Elements in 1st array are :");
 for(i=0;i<s1;i++)
 {
   printf("\t %d",a[i]);
 }
 printf("\n Enter the 2nd array size :");
 scanf("%d",&s2);
 printf("\n Enter the 2nd array elements: ");
 for(j=0;j<s2;j++)
 {
   scanf("%d",&b[j]);
 }
 printf("\n Elements in 2nd array are :");
 for(j=0;j<s2;j++)
 {
   printf("\t %d",b[j]);
 }
 s3=s1+s2;
 for(k=0;k<s3;k++)
 {
  for(i=0;i<=k;i++)
  {
   for(j=0;j<=i;j++)
   {
    if(a[i]>b[j])
    {
     c[k]=b[j];
    }
    else
    {
     c[k]=a[i];
     break;
    }
   }
  }
 }
 printf("\n Elements in Merged array are :");
 for(k=0;k<s3;k++)
 {
   printf("\t %d",c[k]);
 }
 getch();
}




