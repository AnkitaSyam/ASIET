#include <stdio.h>
void main()
{
    int a[100][100],b[100][100],c[100][100],i,j,m,n,k=1;
    printf("\nEnter the number of rows: ");
    scanf("%d",&m);
    printf("\nEnter the number of columns: ");
    scanf("%d",&n);
    
    printf("\nEnter the elements in the matrix:\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }

    printf("\nThe elements are: ");
    for(i=0;i<m;i++)
    {
        printf("\n");
        for(j=0;j<n;j++)
        {
            printf("\t%d",a[i][j]);
        }
    }

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i][j]!=0)
            {
                b[k][0]=i;
                b[k][1]=j;
                b[k][2]=a[i][j];
                k++;
            }
        }
    }

    b[0][0]=m;
    b[0][1]=n;
    b[0][2]=k-1;
 
    c[0][0]=b[0][1];
    c[0][1]=b[0][0];
    c[0][2]=b[0][2];
    k=1;

    for(i=0;i<b[0][1];i++)
    {
        for(j=1;j<=b[0][2];j++)
        {
            if(b[j][1]==i)
            {
                c[k][0]=b[j][1];
                c[k][1]=b[j][0];
                c[k][2]=b[j][2];
                k++;
            }
        }
    }

    printf("\nThe transpose is: \n");
    for(i=0;i<k;i++)
    {
        printf("\n");
        for(j=0;j<3;j++)
        {
            printf("\t%d",c[i][j]);
        }
    }
}
