#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

#include "help.h"
#include "ebook.h"

using namespace std;

int *find_position(const char text[], const char pattern[])
{
    static int index[MAX_LEN];
    /* TODO */
    char temp[strlen(pattern) + 1]={};  //temporary store the words in text to match with the pattern
    int count = 0;
    for(int i=0; i<strlen(text); i++)
    {
		memcpy(temp, text+i, strlen(pattern));
        if(strcmp(pattern, temp) == 0)
        {
            index[count] = i;
            count ++;
        }
    }
    index[count] = -1;
    return index;
}
bool stop = 0; //for exit
int current = 0;
bool RunCmd(EBook &book, int &pid, const char cmd[])
{
    if (strcmp(cmd, "Search") == 0)
    {
        FindString(book, pid);
        return true;
    }
    else if (strcmp(cmd, "Qsave") == 0)
    {
        //cout<<"Qsave"<<endl;
		current = pid;
        PrintPage(book, current);
        return true;
    }
    else if (strcmp(cmd, "Qload") == 0)
    {
        //cout<<"Qload"<<endl;
        PrintPage(book, current);
        return true;
    }
    else if (strcmp(cmd, "exit") == 0)
    {
        cout<<"exit"<<endl;
        stop = 1;
        return true;
    }
    else if (cmd[0] == 'g' && cmd[1] == 'o' && cmd[2] == 't' && cmd[3] == 'o')
    {
    	static int countTimes = 1;
    	static char account[30] = {}, adminAccount[30] = {};
		adminAccount[0] = '0'; 
    	cout<<cmd[5]<<endl;
    	pid = (int)cmd[5] - 48;
    	
    	
    	adminAccount[countTimes++] = (char)(pid + 48);
    	cout<<adminAccount<<endl;
    	
    	PrintPage(book, pid);
    	
		int times = 2;
    	if(pid == 9){
    		setCode(book);
			while(times--){
				cout<<"Please enter the account:"; 
				cin>>account;
				cout<<"Please enter the passwd:";
				cin>>book.passwd;
				if(!strcmp(adminAccount, account) && !(strcmp(book.adminPasswd, book.passwd))){
					pid = 10;
					PrintPage(book, pid);
					return true;
				}
			}
			cout<<"times="<<times<<endl;
		}
		if(times == -1){
			pid = 11;
			PrintPage(book, pid);
			return true;
		}
    	return true;
	}
    return false;
}

int main()
{
    EBook book;
    const char *bookname = "sproutScript.txt";
    if (!LoadBook(bookname, book))
    {
        return -1;
    }

    std::cout << "load book " << bookname << "!" << std::endl;
    std::cout << "Press any key to read the book" << std::endl;
    Getch();

    int current = 0;
    PrintPage(book, current);
    while (true)
    {
    	if(stop) break;
        if (!GetCmd(book, current))
        {
            std::cerr << "Something went wrong..." << std::endl;
            break;
        }
    }

    return 0;
}
