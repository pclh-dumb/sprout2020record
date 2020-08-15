#include <iostream>
#include <cstdlib>
#include <cmath>
#include "bmp_handler.h"

using namespace std;
void filter(BMP pic);
const int R = 2, G = 1, B = 0;
int main(){
#ifdef _WIN32
	system("chcp 65001");
#endif
	//read in bmp file with filename
	char filename[] = "git1.bmp";
	BMP bmp(filename);

	cout << "successfully input your file : " << filename << endl;
	int height = bmp.height(), width = bmp.width();

	cout << "height = " << height << endl;
	cout << "width = " << width << endl;
	filter(bmp); 
	return 0;
}

void filter(BMP pic){
	int list[11] = {1, 2, 1, 2, 4, 2, 1, 2, 1};
	int height = pic.height(), width = pic.width();
	int move[11][3] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 0}, {0, 1},
					   {1, -1}, {1, 0}, {1, 1}};
	float picList[height+1][width+1][4] = {0};
	for(int i = 0; i < height; i++){
		for(int j = 0; j < width; j++){
			for(int k = 0; k < 9; k++){
				if(i + move[k][0] >= 0 && i + move[k][0] < height &&
				   j + move[k][1] >= 0 && j + move[k][1] < width){
					picList[i][j][0] = picList[i][j][0] + (pic.bitmap[i+move[k][0]][j+move[k][1]][0] * list[k]);
					picList[i][j][1] = picList[i][j][1] + (pic.bitmap[i+move[k][0]][j+move[k][1]][1] * list[k]);
					picList[i][j][2] = picList[i][j][2] + (pic.bitmap[i+move[k][0]][j+move[k][1]][2] * list[k]);
				}
			}
		}
	}
	for(int i = 0; i < height; i++){
		for(int j = 0; j < width; j++){
		/*	cout << "[" << (int)picList[i][j][R]/16 << ","
						<< (int)picList[i][j][G]/16 << ","
						<< (int)picList[i][j][B]/16 << "]";*/
			if((int)picList[i][j][R]/16 < 230 && (int)picList[i][j][G]/16 < 230 && (int)picList[i][j][B]/16 < 180){
				cout << "#";
			}
			else{
				cout << " ";
			}
		}
		cout << endl;
	}
}
