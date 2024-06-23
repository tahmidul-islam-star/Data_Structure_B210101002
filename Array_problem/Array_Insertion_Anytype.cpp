#include<iostream>

using namespace std;


int arra[100]={1,2,3,4,5,6,7,8,9};

static int len= 9;

void traverse()
{
    for(int i=0;i<len;i++)
    {
        cout<<arra[i]<<" ";
    }
    cout<<endl;
}
int findavalue(int arra[],int value,int len)
{
    int pos=-1;

    for(int i=0;i<len;i++){

        if(arra[i]==value){ pos=i; break; }

        else{continue;}
    }
    if(pos!=-1) return pos;

    cout<<"Not found"<<endl;
}
void inserting(int index,int value){

    len +=1;

    for(int i=len-1;i>index;i--){

    arra[i]= arra[i-1];
    }
    arra[index]=value;

}
int main()
{

    cout<<"Before Inserting: "<<endl;

    traverse();

    cout<<"Inserting at first"<<endl;

    inserting(0,55);

    traverse();

    cout<<endl<<"Inserting at index"<<endl;

    inserting(2,777);

    traverse();

    cout<<endl<<"Inserting at last"<<endl;

    int last=len;

    inserting(last,88);

    traverse();

    cout<<endl<<"Inserting after a value"<<endl;

    int pos=findavalue(arra,4,len);

    inserting(pos+1,543);

    traverse();

    cout<<endl<<"Inserting before a value"<<endl;

    int pos1=findavalue(arra,4,len);

    inserting(pos1,443);

    traverse();

    return 0;
}

