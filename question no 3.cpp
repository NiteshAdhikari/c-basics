#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    string name;
    string searchh;
    int roll;
    int marks;

    cout<<"enter the name of the student: ";
    cin>>name;
    cout<<"enter the roll number of "<<name<<": ";
    cin>>roll;


    try
    {
        cout<<"enter the marks obtained by "<<name<<": ";
        cin>>marks;
      if (marks < 0 || marks > 100)
        {
            throw 1;
        }
    }

    catch (int)
    {
        cout<<"please enter a valid marks obtained";
        return 1;
    }

    ofstream records("stdRecords.txt", ios::app);
    records<<roll<<" "<<name<<" "<<marks<<" "<<endl;
    records.close();


    cout<<"enter the name of the student you want to check: ";
    cin>>searchh;

    ifstream infile("stdRecords.txt");
    bool found= false;

    while (infile>>roll>>name>>marks)
    {
       if (searchh == name)
        {

            found=true;
            break;
        }

    }
    if (found)
    {
        cout<<roll<<". "<<name<<" "<<marks<<endl;;
    }
    else
    {
        cout<<"the record does not exist";
    }

infile.close();



    return 0;

}
