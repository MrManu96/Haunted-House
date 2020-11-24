//#include <windows.h>  //Solo para Windows
//#include <gl/gl.h>     // The GL Header File
//#include <stdio.h>
//#include <string.h>
#include "Main.h"
//#include "gl.h"

class CTexture
{
public:
	char* name;
	unsigned char*  imageData;
	int		bpp;			// Image Color Depth In Bits Per Pixel
	int		width;			// Image Width
	int		height;		    // Image Height
	unsigned int    GLindex;

	bool LoadTGA(char* filename);		// Loads A TGA File Into Memory y corroborar que la imagen sea TGA y BMP respectivamente
	bool LoadBMP(char* filename);
	void BuildGLTexture();
	void ReleaseImage();			// Al terminar de leer la imagen, se libera la memoria
};
