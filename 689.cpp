#include <iostream>
#include <string>
using namespace std;

int main(){
	string str;
	cin >> str;
	int result, start, end, counter = 0;
	bool hasEnd = false;
	string endList[4] = {"TAG", "TAA", "TGA"};
	while(1){
		//find end
		end = 6001;
		hasEnd = false;
		for(int i = 0; i < 3; i++){
			result = str.find(endList[i]);
			if(result < 0);
			else if(result < end){
				hasEnd = true;
				end = result;
			}
		}
		if(!hasEnd && counter == 0){
			cout << "No gene.\n";
			break;
		}
		else if(!hasEnd && counter != 0) break;
		//find start
		if(str.find("ATG") == -1 && counter == 0){
			cout << "No gene.\n";
			break;
		}
		else if(str.find("ATG") == -1 && counter != 0) break;
		else if(str.find("ATG") > end){
			str.erase(0, end + 3);
			continue;
		}
		else{
			start = str.rfind("ATG", end);
		if(end - start - 3 <= 0){
			if(counter == 0){
				cout << "No gene.\n";
				break;
			}
			else{
				str.erase(0, end + 3);
				continue;
			}
		}
		else if((end - start - 3) % 3 == 0){
			for(int i = start + 3; i < end; i++){
				cout << str[i];
			}
			counter++;
			cout << endl;
		}
		}
		str.erase(0, end + 3);
	}
	return 0;
}
