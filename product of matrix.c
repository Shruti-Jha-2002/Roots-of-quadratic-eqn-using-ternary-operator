#include <stdio.h>
int main()
{
     int a[3][3],b[3][3],m[3][3],i,j,k;
     printf("Enter Elements for First 3*3 Matrix:\n\n");
     /* Reads the elements of first matrix */
     for(i=0;i<=2;i++)
          for(j=0;j<=2;j++)
          {
               scanf("%d",&a[i][j]);
          }
     /* print the elements of first matrix */
     printf("\nFirst Matrix :\n\n");
     for(i=0;i<=2;i++)
     {
          for(j=0;j<=2;j++)
          {
               printf("%d ",a[i][j]);
          }
          printf("\n");
     }
     printf("\nEnter Elements for Second 3*3 Matrix: \n\n");
     /* Reads the elements of second matrix */
     for(i=0;i<=2;i++)
          for(j=0;j<=2;j++)
          {
               scanf("%d",&b[i][j]);
          }
     printf("\nSecond Matrix :\n\n");
     /* print elements of first matrix */
     for(i=0;i<=2;i++)
     {
          for(j=0;j<=2;j++)
          {
               printf("%d ",b[i][j]);
          }
          printf("\n");
     }
     /* Calculate the product of matrices*/
     for(i=0;i<=2;i++)
     {
          for(j=0;j<=2;j++)
          {
               m[i][j]=0;
               for(k=0;k<=2;k++)
                    m[i][j]=m[i][j]+a[i][k]*b[k][j];;
          }
     }
     /* Print product of the matrices */
     printf("\nProduct of Matrices:\n\n");
     for(i=0;i<=2;i++)
     {
          for(j=0;j<=2;j++)
          {
               printf("%d ",m[i][j]);
          }
          printf("\n");
     }
     return 0;
}

