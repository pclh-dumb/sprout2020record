#include <iostream>
#include <cstdlib>
#include "bmp_handler.h"

using namespace std;

const int R = 2, G = 1, B = 0;
int level(int color){
	if(color == 0) color = 0;
	else if(color <= 95) color = 95;
	else if(color <= 135) color = 135;
	else if(color <= 175) color = 175;
	else if(color <= 215) color = 215;
	else if(color <= 255) color = 255;
	return color;
}
int toRGB(int r, int g, int b){
	int sheet[6] = {0, 95, 135, 175, 215, 255};
	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 6; j++){
			for(int k = 0; k < 6; k++){
				if(r == sheet[i] && g == sheet[j] && b == sheet[k]){
					return (i * 36 + j * 6 + k) + 16;
				}
			}
		}
	}
}
int main()
{
    // change charset for windows
#ifdef _WIN32
    system("chcp 65001");
#endif

    // read in bmp file with filename "redleaf.bmp"
    char filename[] = "celtics450.bmp";

    BMP bmp(filename);

    cout << "successly input image : " << filename << endl;

    // get image height and width
    int height = bmp.height(), width = bmp.width();

    cout << "height = " << height << endl;
    cout << "width = " << width << endl;
    for(int i = 0; i < height; i++){
		for(int j = 0; j < width; j++){
			for(int k = 0; k < 3; k++){
				bmp.bitmap[i][j][k]  = level(bmp.bitmap[i][j][k]);
			}
		}
	}	
	int RGB[height][width];
	for(int i = 0; i < height; i++){
		for(int j = 0; j < width; j++){
			RGB[i][j] =toRGB(bmp.bitmap[i][j][R],
				             bmp.bitmap[i][j][G],
				             bmp.bitmap[i][j][B]);
			cout << "\e[30;48;5;" << RGB[i][j] << "m ";
		}
		cout << endl;
	}


    return 0;
}
