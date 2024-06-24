#include<iostream>
#include<algorithm>

using namespace std;
#define endl '\n'

void Bubble_sort(int arra[],int len)
{
    bool ok =false;

    for(int i=0;i<len;i++)
    {
        for(int j= 0;j<len-i-1;j++)
        {
            if(arra[j]>arra[j+1]){

                int temp = arra[j];

                arra[j]= arra[j+1];

                arra[j+1]= temp;

                ok =true;
            }
        }
        if(ok== false) {break;}
    }
}
void Merge_Array(int arra1[],int arra2[],int mergeArra[],int n1,int n2)
{
    int i=0,j=0,k=0;

    while(i<n1 && j<n2)
    {
        if(arra1[i]<= arra2[j]){

            mergeArra[k++]= arra1[i++];
        }
        else{

            mergeArra[k++]=arra2[j++];
        }
    }
    while(i<n1){

        mergeArra[k++]=arra1[i++];
    }
     while(j<n2){

        mergeArra[k++]=arra2[j++];
    }

}
void Tahmid(int arra[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        cout<<arra[i]<<" ";
    }
    cout<<arra[n-1]<<endl;// avoid to print last space 

}

signed main()
{
    int arra1[]={2,3,1,5,4};

    int len1 = sizeof(arra1)/sizeof(arra1[0]);

    int arra2[]={1,3,5,2,0};

    int len2 = sizeof(arra2)/sizeof(arra2[0]);

    int mergeArra[len1+len2];

    Bubble_sort(arra1,len1);

    Bubble_sort(arra2,len2);

    Merge_Array(arra1,arra2,mergeArra,len1,len2);

    cout<<"After Merge Array " <<endl;

    Tahmid(mergeArra,len1+len2);

    return 0;

}
