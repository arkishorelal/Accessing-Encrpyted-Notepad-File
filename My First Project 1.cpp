#include <iostream>
#include <string>
#include <windows.h>
#include<fstream>
//Creating password to text file and opening the text file
using namespace std;
int main()
{
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE); 
    DWORD mode = 0;
    GetConsoleMode(hStdin, &mode);
    SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));

    string s,q;
    int a;
    cout<<"\t \t --------Encrypted mode--------- ";
    cout<<"\nEnter your password "<<endl;
    getline(cin, s);
    cout<<"\n \nre enter your password to open the file "<<endl;
    cin>>q;
    if(s==q)
    {
    cout<<"\n \npassword sucessfully verified "<<endl;
    ifstream ob;
	ob.open("/* your path example.txt */ ", ios :: in);
	if(ob.is_open())
	{
		string line;
		cout<<"\n \n \t \t \t - - File content - - ";
		while(getline(ob,line))
		{
			cout<<"\n \n "<<line<<endl;
		}
		ob.close();
	}
	}
	else
	{
		cout<<"\n \nInvalid password, you can't open the file";
	}
    return 0;
} 
