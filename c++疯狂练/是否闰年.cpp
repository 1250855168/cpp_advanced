#include<iostream>
using namespace std;

int main(int argc,char const *argv[])
{
    int year;
    bool isleapyear;
    cout<<"Enter the year:";
    cin>>year;
    isleapyear = ((year%4==0)&&(year%100!=0)||(year%400==0));
    if (isleapyear)
    {
        cout<<year<<" is a leap year"<<endl;
    }
    else
    {
        cout<<year<<"is not a leap year"<<endl;
    }

    getchar();

    return 0;
    
}