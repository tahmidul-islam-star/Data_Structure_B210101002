#include<iostream>

using namespace std;

void print(int arra[],int siz)
{
    for(int i=0;i<siz;i++)
    {
        cout<<arra[i]<<" ";
    }
    cout<<endl;
}
void Merge(int arra1[],int arra2[],int arra3[],int m,int n)
{
    int i=0,j=0,k=0;

    while(i<m && j<n)
    {
        if(arra1[i]<arra2[j])
        {
            arra3[k++]= arra1[i++];
        }
        else{

            arra3[k++]= arra2[j++];
        }
    }
    while(i<m)
    {
        arra3[k++]=arra1[i++];
    }
    while(j<n)
    {
        arra3[k++]=arra2[j++];
    }
}
int main()
{
    int arra1[]={1,2,3,4,5,6,7,8,9};

    int m= 9;

    int arra2[]={0,3,10,11,13,15,19,31};

    int n=8;

    int arra3[m+n];

    Merge(arra1,arra2,arra3,m,n);

    print(arra3,m+n);

   return 0;
}
