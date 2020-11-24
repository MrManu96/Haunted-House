#include <windows.h>  //Solo para Windows
#include <GL/gl.h>     // The GL Header File
#include <stdio.h>

#include <math.h>

class CFiguras
{
public:
		void prisma (float altura, float largo, float profundidad, GLuint text);
		void skybox (float altura, float largo, float profundidad, GLuint text);
		void torus(float radioM, float radiom, int meridianos, int paralelos, GLuint text);
		void prisma_text( GLuint text, GLuint text2);
		void cilindro(float radius1, float radius2, float height, GLuint text);
		void esfera(float radio, int nlatitud, int nlongitud, GLuint text);
};
