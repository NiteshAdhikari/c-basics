#include<iostream>
using namespace std;
int main()
{
int temp,calculated_temp;
char choose;
cout<<"Enter the temperature: ";
cin>>temp;

cout<<"Enter whether you Want the temperature in (C)elsius Or (F)ahrenheit C or F: "<<endl;
cin>>choose;

if(choose=='C')
{
    calculated_temp=(temp - 32) * 5 / 9;
       cout << "Temperature in Celsius: " <<calculated_temp<< " C" << endl;
}
else if(choose='F')
{

   calculated_temp=(temp * 9 / 5) + 32;
     cout<<"Temperature in Fahrenheit: "<<calculated_temp<< " F"<<endl;
}
else
{
cout<<"Invalid!!!!!"<<endl;
}
return 0;
}
