#include<iostream>

using namespace std;

#define endl '\n'

int arra[100]={1,3,4,5,6,7,8,9,22,55};

static int len= 10;

void traverse()
{
    for(int i=0;i<len ;i++)
    {
        cout<<arra[i]<<" ";
    }
    cout<<endl;
}

int findavalue(int value)
{
    int pos=-1;

    for(int i=0;i<len;i++){

        if(arra[i]==value){ pos=i; break; }

        else{continue;}
    }
    if(pos!=-1) return pos;

    cout<<"Not found"<<endl;
}

int Delete(int index)
{
    for (int i = index; i < len - 1; i++)
    {
        arra[i] = arra[i + 1];
    }
    len = len-1;
}

int main()
{

    cout<<"Before Delete : "<<endl;

    traverse();

    cout<<"Delete at first index"<<endl;

    Delete(0);

    traverse();

    int index= 7;

    cout<<"After Delete "<<index<<" th index value "<<endl;

    Delete(index);

    traverse();

    cout<<"Delete at last index "<<endl;

    Delete(len-1);

    traverse();

    cout<<"Deletion given value"<<endl;

    int pos=findavalue(4);

    Delete(pos);

    traverse();

    cout<<"Deletion After a given value "<<endl;

    int pos1=findavalue(3);

    Delete(pos1+1);

    traverse();

    cout<<"Deletion Before a Given value "<<endl;

    int pos2=findavalue(8);

    Delete(pos2-1);

    traverse();

    return 0;
}

