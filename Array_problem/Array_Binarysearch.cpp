#include<iostream>

using namespace std;

#define endl '\n'

int Binarysearch(int arra[],int low,int high,int key)
{
    
    while(low<=high)
    {
        int mid= (low+high)/2;

        if(arra[mid]==key) return mid;

        else if(arra[mid]<key) low = mid+1;
        
        //when arra[mid]>key

        else high= mid-1;
    }
    return -1;
}
int main()
{
    int arra[]={1,2,3,4,5,6,7,8,9,10};

    int len = sizeof(arra)/sizeof(arra[0]);

    int key= 9;

    int position= Binarysearch(arra,0,len,key);

    if(position != -1) cout<<key<<" is present at index "<<position+1<<endl;

    else cout<<key<<" is not present in Array"<<endl;

    return 0;
}