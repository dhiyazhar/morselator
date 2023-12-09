#include <bits/stdc++.h>
#include "page.hpp"
using namespace std;

int main(){

    system("cls");

    open_page();

int printascii(string filename)
{
	string line = "";
	ifstream infile;
	infile.open("art_ascii.txt");
	if(infile.is_open())
	{
		while(getline(infile,line))
		{
			cout << line << endl;
		}
	}
	else
	{
		cout << "File Failed To Load." << endl;
	}
	infile.close();



}

    return 0;
    
}