#include<iostream>

using namespace std;

int arra2[1000];

void print(int arra[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arra[i]<<" ";
    }
    cout<<endl;
}
void Merge(int arra[],int mid,int low,int high)
{
    int i=low;

    int j= mid+1;

    int k=low;

    while(i<=mid && j<=high)
    {
        if(arra[i]<arra[j])
        {
            arra2[k++]= arra[i++];
        }
        else{

            arra2[k++]= arra[j++];
        }
    }
    while(i<=mid)
    {
        arra2[k++]= arra[i++];
    }
    while(j<=high)
    {
        arra2[k++]= arra[j++];
    }
     for(int i=low;i<=high;i++)
    {
        arra[i]= arra2[i];
    }
}
void Merge_sort(int arra[],int low,int high)
{
    if(low<high)
    {
        int mid= (low+high)/2;

        Merge_sort(arra,low,mid);

        Merge_sort(arra,mid+1,high);

        Merge(arra,mid,low,high);
    }
}
int main()
{
    int n;cin>>n;

   int arra[n];

   for(int i=0;i<n;i++)
   {
       cin>>arra[i];
   }
   Merge_sort(arra,0,n-1);

   print(arra,n);

   return 0;
}
