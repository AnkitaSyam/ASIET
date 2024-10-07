#include<stdio.h>
void main()
{
    int a[10],i,j,n,key,temp,flag=0,choice;
    
    printf("\nEnter limit: ");
    scanf("%d",&n);
    
    printf("\nEnter elements: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    
    printf("\nThe elements are: ");
    for(i=0;i<n;i++)
    {
        printf("\t%d",a[i]);
        
    }
    
    printf("\nEnter the element to be searched: ");
    scanf("%d",&key);
    
    printf("\nCLICK 1 TO CHECK LINEAR SEARCH...");
    printf("\nCLICK 2 TO CHECK BINARY SEARCH...");
    printf("\nCLICK 3 TO EXIT...\n");
    
    do
    {
        printf("\nEnter the choice: ");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1:printf("\nLINEAR SEARCH...\n");
            for(i=0;i<n;i++)
            {
                if(a[i]==key)
                {
                    printf("\nElement found at location %d\n",i+1);
                    flag==1;
                    break;
                }
                if(flag=0)
                {
                    printf("\nElement not found\n");
                    break;
                }
            }
            break;
            
            case 2:printf("\nBINARY SEARCH...\n");
            for(i=0;i<n-1;i++)
            {
                for(j=0;j<n-i-1;j++)
                {
                    if (a[j]>a[j+1])
                    {
                        temp=a[j];
                        a[j]=a[j+1];
                        a[j+1]=temp;
                    }
                }
            }
            for(j=0;j<n;j++)
            {
                printf("\t%d",a[j]);
            }
            int low=0,high = n-1, mid = (low+high)/2;
            while(low <= high)
            {
                if(a[mid] == key)
                {
                    flag =1;
                    i=mid;
                    break;
                }
                if(key > a[mid])
                {
                    low =mid+1;
                    mid = (low+high)/2;
                }
                else
                {
                    high = mid-1;
                    mid = (low+high)/2;
                }
            }
            if (flag==1)
            {
                printf("\nElement found at position %d \n",i+1);
            }
            else
            {
                printf("\nElement not found\n");
            }
            break;
            
            case 3:printf("\nEXITING...");
            break;
            
            default: printf("\nINVALID CHOICE...");
        }
    }
    while(choice!=3);
}

 
 
 
 
 

