//Semestre 2019 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************											******//
//*************											******//
//************************************************************//
#include "texture.h"
#include "figuras.h"
#include "Camera.h"
#include "cmodel/CModel.h"
#include "MMSystem.h"

#if (_MSC_VER >=1900)
#pragma comment (lib,"legacy_stdio_definitions.lib")
#endif

CCamera objCamera;
CCamera objCamera2;
CCamera objCamera3;
GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW) 
GLfloat g_lookupdown2 = 0.0f;    // Look Position In The Z-Axis (NEW) 
GLfloat g_lookupdown3 = 0.0f;    // Look Position In The Z-Axis (NEW) 

int camera = 1;

float pos_camX = 0, pos_camY = 0, pos_camZ = -8.5;
int eye_camX = 30, eye_camY = 0.0, eye_camZ = 0;

int sonido = 0;

float text_der = 1.0;
float text_izq = 0.0;

float mov_pez = 0;
float rot_pez = 0;
float camY = 0;
float rotBruja1 = 0;
bool animBruja = 1;
bool animBrazo = 1;
bool temp = 0;

//GLfloat Diffuse[]= { 1.0f, 1.0f, 1.0f, 1.0f };				// Diffuse Light Values
GLfloat Diffuse[] = { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[] = { 0.0f, 3.0f, 0.0f, 1.0f };			// Light Position
GLfloat Position2[] = { 0.0f, -5.0f, 0.0f, 1.0f };			// Light Position


CTexture t_Ajedrez1;
CTexture t_Ajedrez2;
CTexture t_metal01;
CTexture exterior;
CTexture piso1;
CTexture piso2;
CTexture pared1;
CTexture pared2;
CTexture techo2;
CTexture ventana;
CTexture ventana2;
CTexture picado1;
CTexture calaveras1;
CTexture caja;
CTexture picado2;
CTexture picado3;
CTexture picado4;
CTexture puerta1;
CTexture fantasma1;
CTexture flor;
CTexture olla1;
CTexture cadaver1;
CTexture cadaver2;
CTexture cadaver3;
CTexture bruja;
CTexture murcielago;
CTexture torso;
CTexture brazoizq;
CTexture brazoder;
CTexture pieizq;
CTexture pieder;
CTexture zero;
CTexture catrin;

CModel mueble;

bool mov = true;
int random = 0;
float movFantasma = 0.0, x = 0.0, rotFantasma = 180.0, rotFantasma2 = 0.0;
bool animFantasma = 1;
bool animPuerta = 0;
bool animCatrin = 1;

float transCempa1 = -2.025;

int font = (int)GLUT_BITMAP_TIMES_ROMAN_24;

/////////////// KEYFRAMES

float rotPuerta = 0.0, rotIzq = 0.0, rotDer = 0.0, rotSkull = 0.0, movBrazoDer = 0.0;
float rotCatrin = 0.0;

#define MAX_FRAMES 30
int i_max_steps = 20;
int i_curr_steps = 0;
typedef struct _frame
{
	float rotIzq;
	float rotDer;
	float incIzq;
	float incDer;
	float rotSkull;
	float incSkull;
}FRAME;

FRAME KeyFrame[MAX_FRAMES];
int FrameIndex = 0;
bool play = false;
int playIndex = 0;

int w = 500, h = 500;
int frame = 0, time, timebase = 0;
char s[30];



void InitGL(GLvoid)     // Inicializamos parametros
{

	glClearColor(0.5f, 0.5f, 0.5f, 0.0f);				// Negro de fondo	

	glEnable(GL_TEXTURE_2D);

	glShadeModel(GL_SMOOTH);
	glLightfv(GL_LIGHT1, GL_POSITION, Position);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, Diffuse);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable(GL_COLOR_MATERIAL);

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);

	/* setup blending */
	glEnable(GL_BLEND);			// Turn Blending On

								/*glClearColor(0.5f, 0.5f, 0.5f, 0.0f);				// Azul de fondo

	glEnable(GL_TEXTURE_2D);

	glShadeModel (GL_SMOOTH);
	glLightfv(GL_LIGHT0, GL_POSITION, Position);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);
	glEnable(GL_COLOR_MATERIAL);

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);*/


	t_Ajedrez1.LoadTGA("01.tga");
	t_Ajedrez1.BuildGLTexture();
	t_Ajedrez1.ReleaseImage();

	t_metal01.LoadBMP("metal2.bmp");
	t_metal01.BuildGLTexture();
	t_metal01.ReleaseImage();

	t_Ajedrez2.LoadTGA("02.tga");
	t_Ajedrez2.BuildGLTexture();
	t_Ajedrez2.ReleaseImage();

	exterior.LoadTGA("exterior.tga");
	exterior.BuildGLTexture();
	exterior.ReleaseImage();

	piso1.LoadTGA("piso1.tga");
	piso1.BuildGLTexture();
	piso1.ReleaseImage();

	piso2.LoadTGA("piso2.tga");
	piso2.BuildGLTexture();
	piso2.ReleaseImage();

	pared1.LoadTGA("pared1.tga");
	pared1.BuildGLTexture();
	pared1.ReleaseImage();

	pared2.LoadTGA("pared2.tga");
	pared2.BuildGLTexture();
	pared2.ReleaseImage();

	ventana.LoadTGA("ventana.tga");
	ventana.BuildGLTexture();
	ventana.ReleaseImage();

	ventana2.LoadTGA("ventana2.tga");
	ventana2.BuildGLTexture();
	ventana2.ReleaseImage();

	techo2.LoadTGA("techo2.tga");
	techo2.BuildGLTexture();
	techo2.ReleaseImage();

	picado1.LoadTGA("picado1.tga");
	picado1.BuildGLTexture();
	picado1.ReleaseImage();

	calaveras1.LoadTGA("calaveras1.tga");
	calaveras1.BuildGLTexture();
	calaveras1.ReleaseImage();

	caja.LoadTGA("caja.tga");
	caja.BuildGLTexture();
	caja.ReleaseImage();

	picado2.LoadTGA("picado2.tga");
	picado2.BuildGLTexture();
	picado2.ReleaseImage();

	picado3.LoadTGA("picado3.tga");
	picado3.BuildGLTexture();
	picado3.ReleaseImage();

	picado4.LoadTGA("picado4.tga");
	picado4.BuildGLTexture();
	picado4.ReleaseImage();

	puerta1.LoadTGA("puerta1.tga");
	puerta1.BuildGLTexture();
	puerta1.ReleaseImage();

	fantasma1.LoadTGA("fantasma1.tga");
	fantasma1.BuildGLTexture();
	fantasma1.ReleaseImage();

	flor.LoadTGA("flor.tga");
	flor.BuildGLTexture();
	flor.ReleaseImage();

	olla1.LoadTGA("olla1.tga");
	olla1.BuildGLTexture();
	olla1.ReleaseImage();

	cadaver1.LoadTGA("cadaver1.tga");
	cadaver1.BuildGLTexture();
	cadaver1.ReleaseImage();

	cadaver2.LoadTGA("cadaver2.tga");
	cadaver2.BuildGLTexture();
	cadaver2.ReleaseImage();

	cadaver3.LoadTGA("cadaver3.tga");
	cadaver3.BuildGLTexture();
	cadaver3.ReleaseImage();

	bruja.LoadTGA("bruja.tga");
	bruja.BuildGLTexture();
	bruja.ReleaseImage();

	murcielago.LoadTGA("murcielago.tga");
	murcielago.BuildGLTexture();
	murcielago.ReleaseImage();

	torso.LoadTGA("torso.tga");
	torso.BuildGLTexture();
	torso.ReleaseImage();

	brazoizq.LoadTGA("brazoizq.tga");
	brazoizq.BuildGLTexture();
	brazoizq.ReleaseImage();

	brazoder.LoadTGA("brazoder.tga");
	brazoder.BuildGLTexture();
	brazoder.ReleaseImage();

	pieder.LoadTGA("pieder.tga");
	pieder.BuildGLTexture();
	pieder.ReleaseImage();

	pieizq.LoadTGA("pieizq.tga");
	pieizq.BuildGLTexture();
	pieizq.ReleaseImage();

	zero.LoadTGA("zero.tga");
	zero.BuildGLTexture();
	zero.ReleaseImage();

	catrin.LoadTGA("catrin.tga");
	catrin.BuildGLTexture();
	catrin.ReleaseImage();

	//mueble._3dsLoad("table/Table.3ds");

	objCamera.Position_Camera(-4.0, 1.0f, 4, -4.0, 1.0f, 0, 0, 1, 0);
	objCamera2.Position_Camera(4.5, 1.0f, 2.5, 0.0, 1.0f, 0.0, 0, 1, 0);
	objCamera3.Position_Camera(4.5, 1.0f, -6, 0.0, 1.0f, 0.0, 0, 1, 0);
}


void renderBitmapCharacter(float x, float y, float z, void *font, char *string)
{

	char *c;     //Almacena los caracteres a escribir
	glRasterPos3f(x, y, z);	//Posicion apartir del centro de la ventana
	//glWindowPos2i(150,100);
	for (c = string; *c != '\0'; c++) //Condicion de fin de cadena
	{
		glutBitmapCharacter(font, *c); //imprime
	}
}

void plano(GLuint textura) {
	glBindTexture(GL_TEXTURE_2D, textura);
	glBegin(GL_POLYGON);	//Front
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5, -0.5, 0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.5, -0.5, 0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.5, 0.5, 0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5, 0.5, 0);
	glEnd();
}

void cempa(GLuint textura) {
	glBindTexture(GL_TEXTURE_2D, textura);
	glScalef(0.15, 0.15, 0.15);
	plano(textura);
	for (int j=0; j<23; j++) {
		glRotatef(15, 0, 1, 0);
		plano(textura);
	}
}

void olla(GLuint textura) {
	glBindTexture(GL_TEXTURE_2D, textura);
	glScalef(0.3, 0.3, 0.3);
	plano(textura);
	for (int j = 0; j < 360; j++) {
		glRotatef(1, 0, 1, 0);
		plano(textura);
	}
}

void prisma(GLuint textura1, GLuint textura2)  //Funcion creacion prisma
{

	GLfloat vertice[8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
	};


	glBindTexture(GL_TEXTURE_2D, textura2);   // choose the texture to use.
	glBegin(GL_POLYGON);	//Front
		//glColor3f(0.0,0.0,1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
	glEnd();

	glBegin(GL_POLYGON);	//Right
		//glColor3f(0.0,0.0,1.0);
	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);	//Back
		//glColor3f(0.0,1.0,0.0);
	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Left
		//glColor3f(1.0,1.0,1.0);
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Bottom
		//glColor3f(0.4,0.2,0.6);
	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[2]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[3]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura1);   // choose the texture to use.
	glBegin(GL_POLYGON);  //Top
		//glColor3f(0.8,0.2,0.4);
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(1.0, 0.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(1.0, 1.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(0.0, 1.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[7]);
	glEnd();
}

void esfera(float radio, int nlatitud, int nlongitud, GLuint text)
{
	const float pi = 3.14159265358979323846;
	float inct, incf;
	int i, j;
	float vertice[3];
	inct = 2 * pi / nlatitud;
	incf = pi / nlatitud;
	for (i = 0; i < nlatitud; i++)
	{
		glBegin(GL_LINE_STRIP);
		vertice[0] = vertice[1] = 0;
		vertice[2] = -radio;
		glVertex3fv(vertice);
		for (j = 1; j < nlongitud - 1; j++)
		{
			vertice[0] = radio * cos(i*inct) * cos(j*incf - 0.5*pi);
			vertice[1] = radio * sin(i*inct) * cos(j*incf - 0.5*pi);
			vertice[2] = radio * sin(j*incf - 0.5*pi);
			glVertex3fv(vertice);
			vertice[0] = radio * cos((i + 1)*inct)*cos(j*incf - 0.5*pi);
			vertice[1] = radio * sin((i + 1)*inct)*cos(j*incf - 0.5*pi);
			glVertex3fv(vertice);
		}
		vertice[0] = vertice[1] = 0;
		vertice[2] = radio;
		glVertex3fv(vertice);
	}
	glEnd();
}

void cilindro(float radius1, float radius2, float height, GLuint text) {
	// Number of segments a circle is divided into.
	const unsigned DIV_COUNT = 32;

	// Calculate angle increment from point to point, and its cos/sin.
	float angInc = 2.0f * 3.1416 / static_cast<float>(DIV_COUNT);
	float cosInc = cos(angInc);
	float sinInc = sin(angInc);

	// Draw top cap.
	glColor3f(0.0f, 0.7f, 0.7f);
	glBegin(GL_TRIANGLE_FAN);

	glTexCoord2f(0.5f, 0.5f);
	glVertex3f(0.0f, height, 0.0f);

	glTexCoord2f(1.0f, 0.5f);
	glVertex3f(radius1, height, 0.0f);

	float xc = 1.0f;
	float yc = 0.0f;
	for (unsigned iDiv = 1; iDiv < DIV_COUNT; ++iDiv) {
		float xcNew = cosInc * xc - sinInc * yc;
		yc = sinInc * xc + cosInc * yc;
		xc = xcNew;
		glTexCoord2f(0.5f + 0.5f * xc, 0.5f + 0.5f * yc);
		glVertex3f(radius1 * xc, height, -radius1 * yc);
	}

	glTexCoord2f(1.0f, 0.5f);
	glVertex3f(radius1, height, 0.0f);

	glEnd();

	// Draw bottom cap.
	glBegin(GL_TRIANGLE_FAN);

	glTexCoord2f(0.5f, 0.5f);
	glVertex3f(0.0f, 0.0f, 0.0f);

	glTexCoord2f(1.0f, 0.5f);
	glVertex3f(radius2, 0.0f, 0.0f);

	xc = 1.0f;
	yc = 0.0f;
	for (unsigned iDiv = 1; iDiv < DIV_COUNT; ++iDiv) {
		float xcNew = cosInc * xc - sinInc * yc;
		yc = sinInc * xc + cosInc * yc;
		xc = xcNew;
		glTexCoord2f(0.5f + 0.5f * xc, 0.5f + 0.5f * yc);
		glVertex3f(radius2 * xc, 0.0f, radius2 * yc);
	}

	glTexCoord2f(1.0f, 0.5f);
	glVertex3f(radius2, 0.0f, 0.0f);

	glEnd();

	float texInc = 1.0f / static_cast<float>(DIV_COUNT);

	// Draw cylinder.
	glColor3f(0.8f, 0.0f, 0.0f);
	glBegin(GL_TRIANGLE_STRIP);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(radius2, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(radius1, height, 0.0f);

	xc = 1.0f;
	yc = 0.0f;
	float texCoord = 0.0f;
	for (unsigned iDiv = 1; iDiv < DIV_COUNT; ++iDiv) {
		float xcNew = cosInc * xc - sinInc * yc;
		yc = sinInc * xc + cosInc * yc;
		xc = xcNew;
		texCoord += texInc;
		glTexCoord2f(texCoord, 0.0f);
		glVertex3f(radius2 * xc, 0.0f, radius2 * yc);
		glTexCoord2f(texCoord, 1.0f);
		glVertex3f(radius1 * xc, height, radius1 * yc);
	}

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(radius2, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(radius1, height, 0.0f);

	glEnd();
}

void prismaEsc(float altura, float largo, float profundidad, GLuint text)  //Funcion creacion prisma
{

	GLfloat vertice[8][3] = {
				{0.5*largo ,-0.5*altura, 0.5*profundidad},    //Coordenadas Vértice 1 V1
				{-0.5*largo ,-0.5*altura , 0.5*profundidad},    //Coordenadas Vértice 2 V2
				{-0.5*largo ,-0.5*altura , -0.5*profundidad},    //Coordenadas Vértice 3 V3
				{0.5*largo ,-0.5*altura , -0.5*profundidad},    //Coordenadas Vértice 4 V4
				{0.5*largo ,0.5*altura , 0.5*profundidad},    //Coordenadas Vértice 5 V5
				{0.5*largo ,0.5*altura , -0.5*profundidad},    //Coordenadas Vértice 6 V6
				{-0.5*largo ,0.5*altura , -0.5*profundidad},    //Coordenadas Vértice 7 V7
				{-0.5*largo ,0.5*altura , 0.5*profundidad},    //Coordenadas Vértice 8 V8
	};

	glBindTexture(GL_TEXTURE_2D, text);   // choose the texture to use.
	//glBindTexture(GL_TEXTURE_2D, texture[filter]);   // choose the texture to use.
	glBegin(GL_POLYGON);	//Front
		//glColor3f(0.0,0.0,1.0);
	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
	glEnd();

	glBegin(GL_POLYGON);	//Right
		//glColor3f(0.0,0.0,1.0);
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);	//Back
		//glColor3f(0.0,1.0,0.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Left
		//glColor3f(1.0,1.0,1.0);
	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Bottom
		//glColor3f(0.4,0.2,0.6);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[2]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[3]);
	glEnd();

	glBegin(GL_POLYGON);  //Top
		//glColor3f(0.8,0.2,0.4);
	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(2.0f, 0.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(2.0f, 2.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 2.0f); glVertex3fv(vertice[7]);
	glEnd();
}

void monito()
{
	//glNewList(1, GL_COMPILE);
	glPushMatrix();//Pecho
		glScalef(0.5, 0.5, 0.5);
		prismaEsc(2.0, 2.0, 1.0, t_metal01.GLindex);
	
		glPushMatrix();//Cuello
			glTranslatef(0, 1.0, 0.0);
			cilindro(0.25, 0.25, 0.3, 0);
			glPushMatrix();//Cabeza
				glTranslatef(0, 1.0, 0);
				esfera(0.75, 15, 15, 0);
			glPopMatrix();
		glPopMatrix();

		glPushMatrix(); //Brazo derecho-->
			glTranslatef(1.25, 0.65, 0);
			esfera(0.5, 12, 12, 0);
			glPushMatrix();
				glTranslatef(0.25, 0, 0);
				glRotatef(movBrazoDer, 0.0, 0.0, 1.0);
				glRotatef(-45, 0, 1, 0);
				glTranslatef(0.75, 0, 0);
				prismaEsc(0.7, 1.5, 0.7, 0);
			glPopMatrix();
		glPopMatrix();

		glPushMatrix(); //Brazo izquierdo <--
			glTranslatef(-1.25, 0.65, 0);
			esfera(0.5, 12, 12, 0);
			glPushMatrix();
				glTranslatef(-0.25, 0, 0);
				glRotatef(45, 0, 1, 0);
				glRotatef(25, 0, 0, 1);
				glRotatef(25, 1, 0, 0);
				glTranslatef(-0.75, 0, 0);
				prismaEsc(0.7, 1.5, 0.7, 0);
			glPopMatrix();
		glPopMatrix();

		glPushMatrix();//Cintura
			glColor3f(0, 0, 1);
			glTranslatef(0, -1.5, 0);
			prismaEsc(1, 2, 1, 0);

			glPushMatrix(); //Pie Derecho -->
				glTranslatef(0.75, -0.5, 0);
				glRotatef(-15, 1, 0, 0);
				glTranslatef(0, -0.5, 0);
				prismaEsc(1.0, 0.5, 1, 0);

				glPushMatrix();
					glTranslatef(0, -0.5, 0);
					glRotatef(15, 1, 0, 0);
					glTranslatef(0, -0.75, 0);
					prismaEsc(1.5, 0.5, 1, 0);

					glPushMatrix();
						glTranslatef(0, -0.75, 0.3);
						prismaEsc(0.2, 1.2, 1.5, 0);
					glPopMatrix();
				glPopMatrix();
			glPopMatrix();


			glPushMatrix(); //Pie Izquierdo -->
				glTranslatef(-0.75, -0.5, 0);
				glRotatef(-5, 1, 0, 0);
				glTranslatef(0, -0.5, 0);
				prismaEsc(1.0, 0.5, 1, 0);

				glPushMatrix();
					glTranslatef(0, -0.5, 0);
					glRotatef(15, 1, 0, 0);
					glTranslatef(0, -0.75, 0);
					prismaEsc(1.5, 0.5, 1, 0);

					glPushMatrix();
						glTranslatef(0, -0.75, 0.3);
						prismaEsc(0.2, 1.2, 1.5, 0);
					glPopMatrix();
				glPopMatrix();
			glPopMatrix();


		glPopMatrix();


		glColor3f(1, 1, 1);
	glPopMatrix();
	//glEndList();
}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	glPushMatrix();
	if (camera == 1) {
		glRotatef(g_lookupdown, 1.0f, 0, 0);
		gluLookAt(objCamera.mPos.x, objCamera.mPos.y, objCamera.mPos.z,
			objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,
			objCamera.mUp.x, objCamera.mUp.y, objCamera.mUp.z);
	}
	else {
		if (camera == 2) {
			glRotatef(g_lookupdown2, 1.0f, 0, 0);
			gluLookAt(objCamera2.mPos.x, objCamera2.mPos.y, objCamera2.mPos.z,
				objCamera2.mView.x, objCamera2.mView.y, objCamera2.mView.z,
				objCamera2.mUp.x, objCamera2.mUp.y, objCamera2.mUp.z);
		}
		else {
			glRotatef(g_lookupdown3, 1.0f, 0, 0);
			gluLookAt(objCamera3.mPos.x, objCamera3.mPos.y, objCamera3.mPos.z,
				objCamera3.mView.x, objCamera3.mView.y, objCamera3.mView.z,
				objCamera3.mUp.x, objCamera3.mUp.y, objCamera3.mUp.z);
		}
	}
	glDisable(GL_LIGHTING);
	/*glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glPushMatrix();
		glTranslatef(objCamera.mPos.x, objCamera.mPos.y, objCamera.mPos.z-0.2);
		glRotatef(camY, 0,1,0);
		glScalef(0.2,0.2,0.2);
		plano(zero.GLindex);
	glPopMatrix();*/

	glPushMatrix();
	
	glPushMatrix();
	glTranslatef(0.0, 0.0, -2.0);

	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	////////////////////// PISO   ////////////////////////
	//Piso1
	glPushMatrix();
		glColor3f(1.0, 1.0, 1.0);
		glTranslatef(0.0f, 0.0f, 2.5f);
		glScalef(10.0, 0.1, 5.0);
		prisma(piso1.GLindex, exterior.GLindex);
	glPopMatrix();

	//Piso2
	glPushMatrix();
		glColor3f(1.0, 1.0, 1.0);
		glTranslatef(0.0f, 0.0f, -2.5f);
		glScalef(10.0, 0.1, 5.0);
		prisma(piso2.GLindex, exterior.GLindex);
	glPopMatrix();

	////////////////////// TECHO   ////////////////////////
	//Techo1
	glPushMatrix();
		glColor3f(1.0, 1.0, 1.0);
		glTranslatef(0.0f, 2.05f, 2.5f);
		glScalef(10.0, 0.1, 5.0);
		glRotatef(180, 1, 0, 0);
		prisma(pared1.GLindex, exterior.GLindex);
	glPopMatrix();

	//Techo2
	glPushMatrix();
		glColor3f(1.0, 1.0, 1.0);
		glTranslatef(0.0f, 2.05f, -2.5f);
		glScalef(10.0, 0.1, 5.0);
		glRotatef(180, 1, 0, 0);
		prisma(techo2.GLindex, exterior.GLindex);
	glPopMatrix();

	////////////////////// PAREDES 1 ////////////////////////
	//Pared frontal
	glPushMatrix();
		glColor3f(1.0, 1.0, 1.0);
		glTranslatef(1.0, 1.0, 4.95);
		glScalef(8.0, 2.0, 0.1);
		glRotatef(-90, 1.0, 0.0, 0.0);
		prisma(pared1.GLindex, exterior.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(4.0, 1.0, 4.90);
		glScalef(0.8, 0.8, 0.8);
		glRotatef(180, 0.0, 1.0, 0.0);
		plano(cadaver1.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(2.5, 1.0, 4.90);
		glScalef(0.8, 0.8, 0.8);
		glRotatef(180, 0.0, 1.0, 0.0);
		plano(cadaver2.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(1.0, 1.0, 4.90);
		glScalef(0.8, 0.8, 0.8);
		glRotatef(180, 0.0, 1.0, 0.0);
		plano(cadaver3.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-0.5, 1.0, 4.90);
		glScalef(0.8, 0.8, 0.8);
		glRotatef(180, 0.0, 1.0, 0.0);
		plano(cadaver2.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-2.0, 1.0, 4.90);
		glScalef(0.8, 0.8, 0.8);
		glRotatef(180, 0.0, 1.0, 0.0);
		plano(cadaver1.GLindex);
	glPopMatrix();

	//Division central
	glPushMatrix();
		glColor3f(1.0, 1.0, 1.0);
		glTranslatef(-0.95, 1.0, 0.0);
		glScalef(7.9, 2.0, 0.1);
		glRotatef(90, 1.0, 0.0, 0.0);
		prisma(pared1.GLindex, pared2.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(1.0, 1.0, 0.05);
		glScalef(0.8, 0.8, 0.8);
		plano(cadaver2.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(2.5, 1.0, 0.05);
		glScalef(0.8, 0.8, 0.8);
		plano(cadaver3.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-3.0, 1.0, 0.05);
		glScalef(0.8, 0.8, 0.8);
		plano(cadaver1.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-4.5, 1.0, 0.05);
		glScalef(0.8, 0.8, 0.8);
		plano(cadaver3.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(1.0, 1.0, -0.05);
		glScalef(0.8, 0.4, 0.8);
		glRotatef(180, 0, 1, 0);
		plano(murcielago.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(2.5, 1.5, -0.05);
		glScalef(0.8, 0.4, 0.8);
		glRotatef(180, 0, 1, 0);
		plano(murcielago.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-0.5, 0.5, -0.05);
		glScalef(0.8, 0.4, 0.8);
		glRotatef(180, 0, 1, 0);
		plano(murcielago.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-2.0, 1.5, -0.05);
		glScalef(0.8, 0.4, 0.8);
		glRotatef(180, 0, 1, 0);
		plano(murcielago.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-3.5, 0.5, -0.05);
		glScalef(0.8, 0.4, 0.8);
		glRotatef(180, 0, 1, 0);
		plano(murcielago.GLindex);
	glPopMatrix();

	//Puerta central
	glPushMatrix();
		glColor3f(1.0, 1.0, 1.0);
		glTranslatef(4.9, 1.0, 0.0);
		glRotatef(rotPuerta, 0, 1, 0);
		glPushMatrix();
			glTranslatef(-0.95, 0.0, 0.0);
			glScalef(1.9, 2.0, 0.1);
			glRotatef(90, 1.0, 0.0, 0.0);
			prisma(puerta1.GLindex, puerta1.GLindex);
		glPopMatrix();
	glPopMatrix();

	//Pared izquierda
	glPushMatrix();
		glColor3f(1.0, 1.0, 1.0);
		glTranslatef(-4.95, 1.0, 2.5);
		glScalef(0.1, 2.0, 5);
		glRotatef(90, 1.0, 0.0, 0.0);
		glRotatef(90, 0.0, 0.0, -1.0);
		prisma(pared1.GLindex, exterior.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-4.90, 1.0, 1.0);
		glScalef(0.8, 0.8, 0.8);
		glRotatef(90, 0.0, 1.0, 0.0);
		plano(cadaver1.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-4.90, 1.0, 2.5);
		glScalef(0.8, 0.8, 0.8);
		glRotatef(90, 0.0, 1.0, 0.0);
		plano(cadaver3.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-4.90, 1.0, 4.0);
		glScalef(0.8, 0.8, 0.8);
		glRotatef(90, 0.0, 1.0, 0.0);
		plano(cadaver2.GLindex);
	glPopMatrix();

	//Pared derecha
	glPushMatrix();
		glColor3f(1.0, 1.0, 1.0);
		glTranslatef(4.95, 1.0, 2);
		glScalef(0.1, 2.0, 4);
		glRotatef(90, 1.0, 0.0, 0.0);
		glRotatef(90, 0.0, 0.0, 1.0);
		prisma(pared1.GLindex, exterior.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(4.90, 1.0, 0.5);
		glScalef(0.8, 0.8, 0.8);
		glRotatef(-90, 0.0, 1.0, 0.0);
		plano(cadaver1.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(4.90, 1.0, 2.0);
		glScalef(0.8, 0.8, 0.8);
		glRotatef(-90, 0.0, 1.0, 0.0);
		plano(cadaver3.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(4.90, 1.0, 3.5);
		glScalef(0.8, 0.8, 0.8);
		glRotatef(-90, 0.0, 1.0, 0.0);
		plano(cadaver2.GLindex);
	glPopMatrix();

	////////////////////// PAREDES 2 ////////////////////////
	//Pared trasera
	glPushMatrix();
		glColor3f(1.0, 1.0, 1.0);
		glTranslatef(0.95, 1.0, -4.95);
		glScalef(7.9, 2.0, 0.1);
		glRotatef(90, 1.0, 0.0, 0.0);
		prisma(pared2.GLindex, exterior.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(4.0, 0.5, -4.90);
		glScalef(0.8, 0.4, 0.8);
		plano(murcielago.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(2.5, 1.5, -4.90);
		glScalef(0.8, 0.4, 0.8);
		plano(murcielago.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(1.0, 1.0, -4.90);
		glScalef(0.8, 0.4, 0.8);
		plano(murcielago.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-0.5, 0.5, -4.90);
		glScalef(0.8, 0.4, 0.8);
		plano(murcielago.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-2.0, 1.0, -4.90);
		glScalef(0.8, 0.4, 0.8);
		plano(murcielago.GLindex);
	glPopMatrix();

	//Pared izquierda
	glPushMatrix();
		glColor3f(1.0, 1.0, 1.0);
		glTranslatef(-4.95, 1.0, -2.5);
		glScalef(0.1, 2.0, 5);
		glRotatef(90, 1.0, 0.0, 0.0);
		glRotatef(90, 0.0, 0.0, -1.0);
		prisma(pared2.GLindex, exterior.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-4.90, 0.5, -1.0);
		glScalef(0.8, 0.4, 0.8);
		glRotatef(90, 0.0, 1.0, 0.0);
		plano(murcielago.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-4.90, 1.5, -2.5);
		glScalef(0.8, 0.4, 0.8);
		glRotatef(90, 0.0, 1.0, 0.0);
		plano(murcielago.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-4.90, 1.0, -4.0);
		glScalef(0.8, 0.4, 0.8);
		glRotatef(90, 0.0, 1.0, 0.0);
		plano(murcielago.GLindex);
	glPopMatrix();

	//Pared derecha
	glPushMatrix();
		glColor3f(1.0, 1.0, 1.0);
		glTranslatef(4.95, 1.0, -2.5);
		glScalef(0.1, 2.0, 5);
		glRotatef(90, 1.0, 0.0, 0.0);
		glRotatef(90, 0.0, 0.0, 1.0);
		prisma(pared2.GLindex, exterior.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(4.90, 1.0, -0.5);
		glScalef(0.8, 0.4, 0.8);
		glRotatef(-90, 0.0, 1.0, 0.0);
		plano(murcielago.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(4.90, 1.5, -2.0);
		glScalef(0.8, 0.4, 0.8);
		glRotatef(-90, 0.0, 1.0, 0.0);
		plano(murcielago.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(4.90, 1.0, -3.5);
		glScalef(0.8, 0.4, 0.8);
		glRotatef(-90, 0.0, 1.0, 0.0);
		plano(murcielago.GLindex);
	glPopMatrix();

	////////////////////// ------- OBJETOS -------- /////////////////////
	/////////////////// Catrines /////////////////
	glPushMatrix();
		glTranslatef(-4.5, 1.95, 1.0);
		glRotatef(rotCatrin, 0, 0, 1);
		glPushMatrix();
			glTranslatef(0.0, -0.55, 0.0);
			glScalef(0.6, 1.2, 1.0);
			plano(catrin.GLindex);
		glPopMatrix();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-3.5, 1.95, 1.0);
		glRotatef(rotCatrin, 0, 0, 1);
		glPushMatrix();
			glTranslatef(0.0, -0.55, 0.0);
			glScalef(0.6, 1.2, 1.0);
			plano(catrin.GLindex);
		glPopMatrix();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-4.0, 1.95, 1.5);
		glRotatef(-1*rotCatrin, 0, 0, 1);
		glPushMatrix();
			glTranslatef(0.0, -0.55, 0.0);
			glScalef(0.6, 1.2, 1.0);
			plano(catrin.GLindex);
		glPopMatrix();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-3.0, 1.95, 1.5);
		glRotatef(-1 * rotCatrin, 0, 0, 1);
		glPushMatrix();
			glTranslatef(0.0, -0.55, 0.0);
			glScalef(0.6, 1.2, 1.0);
			plano(catrin.GLindex);
		glPopMatrix();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(1.0, 1.95, 1.0);
		glRotatef(rotCatrin, 0, 0, 1);
		glPushMatrix();
			glTranslatef(0.0, -0.55, 0.0);
			glScalef(0.6, 1.2, 1.0);
			plano(catrin.GLindex);
		glPopMatrix();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(2.0, 1.95, 1.0);
		glRotatef(rotCatrin, 0, 0, 1);
		glPushMatrix();
			glTranslatef(0.0, -0.55, 0.0);
			glScalef(0.6, 1.2, 1.0);
			plano(catrin.GLindex);
		glPopMatrix();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(1.5, 1.95, 1.5);
		glRotatef(-1*rotCatrin, 0, 0, 1);
		glPushMatrix();
			glTranslatef(0.0, -0.55, 0.0);
			glScalef(0.6, 1.2, 1.0);
			plano(catrin.GLindex);
		glPopMatrix();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(2.5, 1.95, 1.5);
		glRotatef(-1 * rotCatrin, 0, 0, 1);
		glPushMatrix();
			glTranslatef(0.0, -0.55, 0.0);
			glScalef(0.6, 1.2, 1.0);
			plano(catrin.GLindex);
		glPopMatrix();
	glPopMatrix();


	//////////////// MONITO //////////////////////
	glPushMatrix();
		glTranslatef(2.5, 0.875, 4.0);
		glRotatef(-90, 0, 1, 0);
		glScalef(0.35, 0.35, 0.35);
		monito();
	glPopMatrix();

	////////////////////// ALTAR ////////////////////////////////////////
	glPushMatrix();
		glTranslatef(-1.0, 0.2, 0.9);

		glPushMatrix();
			glTranslatef(0.0, 0.4, -0.3);

			glPushMatrix();
				glTranslatef(0.0, 0.4, -0.3);
				glScalef(2.5, 0.4, 0.6);
				prisma(caja.GLindex, caja.GLindex);
				glTranslatef(0.0, 0.0, 0.5);
				//plano(picado2.GLindex);
			glPopMatrix();

			glScalef(2.5, 0.4, 1.2);
			prisma(caja.GLindex, caja.GLindex);
			glTranslatef(0.0, 0.0, 0.5);
			//plano(picado3.GLindex);
		glPopMatrix();

		glScalef(2.5, 0.4, 1.8);
		prisma(caja.GLindex, caja.GLindex);
		glTranslatef(0.0, 0.0, 0.5);
		//plano(picado4.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-1.6, 1.35, 0.45);
		olla(olla1.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-1.2, 1.35, 0.45);
		olla(olla1.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-0.8, 1.35, 0.45);
		olla(olla1.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-0.4, 1.35, 0.45);
		olla(olla1.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-1.6, 0.2, 2.2);
		olla(olla1.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-1.6, 0.2, 2.8);
		olla(olla1.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-0.4, 0.2, 2.2);
		olla(olla1.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-0.4, 0.2, 2.8);
		olla(olla1.GLindex);
	glPopMatrix();

	////////////////////// FLOR DE CEMPASUCHIL /////////////////////////
	glPushMatrix();
		glTranslatef(-2.175, 0.475, 1.725);
		cempa(flor.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.175, 0.475, 1.575);
	cempa(flor.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.175, 0.475, 1.425);
	cempa(flor.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.175, 0.475, 1.275);
	cempa(flor.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-2.025, 0.475, 1.725);
		cempa(flor.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.875, 0.475, 1.725);
	cempa(flor.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.725, 0.475, 1.725);
	cempa(flor.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.575, 0.475, 1.725);
	cempa(flor.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.425, 0.475, 1.725);
	cempa(flor.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.275, 0.475, 1.725);
	cempa(flor.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.125, 0.475, 1.725);
	cempa(flor.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.975, 0.475, 1.725);
	cempa(flor.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.825, 0.475, 1.725);
	cempa(flor.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.675, 0.475, 1.725);
	cempa(flor.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.525, 0.475, 1.725);
	cempa(flor.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.375, 0.475, 1.725);
	cempa(flor.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.225, 0.475, 1.725);
	cempa(flor.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.075, 0.475, 1.725);
	cempa(flor.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.075, 0.475, 1.725);
	cempa(flor.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.075, 0.475, 1.575);
	cempa(flor.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.075, 0.475, 1.425);
	cempa(flor.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.075, 0.475, 1.275);
	cempa(flor.GLindex);
	glPopMatrix();


	///////////// NIVEL 2

	glPushMatrix();
	glTranslatef(-2.175, 0.875, 1.125);
	cempa(flor.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.175, 0.875, 0.975);
	cempa(flor.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.175, 0.875, 0.825);
	cempa(flor.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.175, 0.875, 0.675);
	cempa(flor.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.025, 0.875, 1.125);
	cempa(flor.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.875, 0.875, 1.125);
	cempa(flor.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.725, 0.875, 1.125);
	cempa(flor.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.575, 0.875, 1.125);
	cempa(flor.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.425, 0.875, 1.125);
	cempa(flor.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.275, 0.875, 1.125);
	cempa(flor.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.125, 0.875, 1.125);
	cempa(flor.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.975, 0.875, 1.125);
	cempa(flor.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.825, 0.875, 1.125);
	cempa(flor.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.675, 0.875, 1.125);
	cempa(flor.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.525, 0.875, 1.125);
	cempa(flor.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.375, 0.875, 1.125);
	cempa(flor.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.225, 0.875, 1.125);
	cempa(flor.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.075, 0.875, 1.125);
	cempa(flor.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.075, 0.875, 1.125);
	cempa(flor.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.075, 0.875, 0.975);
	cempa(flor.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.075, 0.875, 0.825);
	cempa(flor.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.075, 0.875, 0.675);
	cempa(flor.GLindex);
	glPopMatrix();

	///////////// NIVEL 3

	glPushMatrix();
	glTranslatef(-2.175, 1.275, 0.525);
	cempa(flor.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.175, 1.275, 0.375);
	cempa(flor.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.175, 1.275, 0.225);
	cempa(flor.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.025, 1.275, 0.525);
	cempa(flor.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.875, 1.275, 0.525);
	cempa(flor.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.225, 1.275, 0.525);
	cempa(flor.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.075, 1.275, 0.525);
	cempa(flor.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.075, 1.275, 0.525);
	cempa(flor.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.075, 1.275, 0.375);
	cempa(flor.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.075, 1.275, 0.225);
	cempa(flor.GLindex);
	glPopMatrix();

	///////////////////// CRUZ

	glPushMatrix();
	glTranslatef(-1.125, 0.075, 1.975);
	cempa(flor.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.125, 0.075, 2.125);
	cempa(flor.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.275, 0.075, 2.125);
	cempa(flor.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.275, 0.075, 2.275);
	cempa(flor.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.275, 0.075, 2.425);
	cempa(flor.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.125, 0.075, 2.425);
	cempa(flor.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.125, 0.075, 2.575);
	cempa(flor.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.125, 0.075, 2.725);
	cempa(flor.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.125, 0.075, 2.875);
	cempa(flor.GLindex);
	glPopMatrix();



	glPushMatrix();
	glTranslatef(-0.975, 0.075, 1.975);
	cempa(flor.GLindex);
	glPopMatrix();



	glPushMatrix();
	glTranslatef(-0.825, 0.075, 1.975);
	cempa(flor.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.825, 0.075, 2.125);
	cempa(flor.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.675, 0.075, 2.125);
	cempa(flor.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.675, 0.075, 2.275);
	cempa(flor.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.675, 0.075, 2.425);
	cempa(flor.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.825, 0.075, 2.425);
	cempa(flor.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.825, 0.075, 2.575);
	cempa(flor.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.825, 0.075, 2.725);
	cempa(flor.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.825, 0.075, 2.875);
	cempa(flor.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.975, 0.075, 2.875);
	cempa(flor.GLindex);
	glPopMatrix();


	////////////////////// CALAVERAS Y PAPEL PICADO /////////////////////
	glPushMatrix();
		glTranslatef(2.5f, 1.75f, 2.5f);
		glScalef(5.0, 1.0, 5.0);
		glRotatef(90, 0, 1, 0);
		plano(calaveras1.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(2.0f, 1.75f, 2.5f);
		glScalef(5.0, 1.0, 5.0);
		glRotatef(90, 0, 1, 0);
		plano(picado1.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(1.5f, 1.75f, 2.5f);
		glScalef(5.0, 1.0, 5.0);
		glRotatef(90, 0, 1, 0);
		plano(calaveras1.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(1.0f, 1.75f, 2.5f);
		glScalef(5.0, 1.0, 5.0);
		glRotatef(90, 0, 1, 0);
		plano(picado1.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.5f, 1.75f, 2.5f);
		glScalef(5.0, 1.0, 5.0);
		glRotatef(90, 0, 1, 0);
		plano(calaveras1.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.0f, 1.75f, 2.5f);
		glScalef(5.0, 1.0, 5.0);
		glRotatef(90, 0, 1, 0);
		plano(picado1.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-0.5f, 1.75f, 2.5f);
		glScalef(5.0, 1.0, 5.0);
		glRotatef(90, 0, 1, 0);
		plano(calaveras1.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-1.0f, 1.75f, 2.5f);
		glScalef(5.0, 1.0, 5.0);
		glRotatef(90, 0, 1, 0);
		plano(picado1.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-1.5f, 1.75f, 2.5f);
		glScalef(5.0, 1.0, 5.0);
		glRotatef(90, 0, 1, 0);
		plano(calaveras1.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-2.0f, 1.75f, 2.5f);
		glScalef(5.0, 1.0, 5.0);
		glRotatef(90, 0, 1, 0);
		plano(picado1.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-2.5f, 1.75f, 2.5f);
		glScalef(5.0, 1.0, 5.0);
		glRotatef(90, 0, 1, 0);
		plano(calaveras1.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-3.0f, 1.75f, 2.5f);
		glScalef(5.0, 1.0, 5.0);
		glRotatef(90, 0, 1, 0);
		plano(picado1.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-3.5f, 1.75f, 2.5f);
		glScalef(5.0, 1.0, 5.0);
		glRotatef(90, 0, 1, 0);
		plano(calaveras1.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-4.0f, 1.75f, 2.5f);
		glScalef(5.0, 1.0, 5.0);
		glRotatef(90, 0, 1, 0);
		plano(picado1.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-4.5f, 1.75f, 2.5f);
		glScalef(5.0, 1.0, 5.0);
		glRotatef(90, 0, 1, 0);
		plano(calaveras1.GLindex);
	glPopMatrix();

	////////////////////// ------- OBJETOS CUARTO 2-------- /////////////////////
	////////////////////// Zeros /////////////////////////
	glPushMatrix();
		glTranslatef(2.5, 1.95, -4.0);
		glRotatef(-1 * rotCatrin, 0, 0, 1);
		glPushMatrix();
			glTranslatef(0.0, -0.45, 0.0);
			glScalef(0.7, 1.0, 1.0);
			plano(zero.GLindex);
		glPopMatrix();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(3.5, 1.95, -4.0);
		glRotatef(-1 * rotCatrin, 0, 0, 1);
		glPushMatrix();
			glTranslatef(0.0, -0.45, 0.0);
			glScalef(0.7, 1.0, 1.0);
			plano(zero.GLindex);
		glPopMatrix();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(3.0, 1.95, -3.5);
		glRotatef(rotCatrin, 0, 0, 1);
		glPushMatrix();
			glTranslatef(0.0, -0.45, 0.0);
			glScalef(0.7, 1.0, 1.0);
			plano(zero.GLindex);
		glPopMatrix();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(4.0, 1.95, -3.5);
		glRotatef(rotCatrin, 0, 0, 1);
		glPushMatrix();
			glTranslatef(0.0, -0.45, 0.0);
			glScalef(0.7, 1.0, 1.0);
			plano(zero.GLindex);
		glPopMatrix();
	glPopMatrix();

	/////////////////////// BRUJAS ///////////////////////
	glPushMatrix();
		glTranslatef(-1.75, 1.95, -3.0);
		glRotatef(rotBruja1, 0, 0, 1);
		glPushMatrix();
			glTranslatef(0.0, -0.75, 0.0);
			glScalef(1.6, 1.6, 1.6);
			plano(bruja.GLindex);
		glPopMatrix();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.0, 1.95, -3.0);
		glRotatef(rotBruja1, 0, 0, 1);
		glPushMatrix();
			glTranslatef(0.0, -0.75, 0.0);
			glScalef(1.6, 1.6, 1.6);
			plano(bruja.GLindex);
		glPopMatrix();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-2.35, 1.95, -2.0);
		glRotatef(-1 * rotBruja1, 0, 0, 1);
		glPushMatrix();
			glTranslatef(0.0, -0.75, 0.0);
			glScalef(1.6, 1.6, 1.6);
			glRotatef(180, 0, 1, 0);
			plano(bruja.GLindex);
		glPopMatrix();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-0.6, 1.95, -2.0);
		glRotatef(-1 * rotBruja1, 0, 0, 1);
		glPushMatrix();
			glTranslatef(0.0, -0.75, 0.0);
			glScalef(1.6, 1.6, 1.6);
			glRotatef(180, 0, 1, 0);
			plano(bruja.GLindex);
		glPopMatrix();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(1.15, 1.95, -2.0);
		glRotatef(-1 * rotBruja1, 0, 0, 1);
		glPushMatrix();
			glTranslatef(0.0, -0.75, 0.0);
			glScalef(1.6, 1.6, 1.6);
			glRotatef(180, 0, 1, 0);
			plano(bruja.GLindex);
		glPopMatrix();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-1.75, 1.95, -1.0);
		glRotatef(rotBruja1, 0, 0, 1);
		glPushMatrix();
			glTranslatef(0.0, -0.75, 0.0);
			glScalef(1.6, 1.6, 1.6);
			plano(bruja.GLindex);
		glPopMatrix();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.0, 1.95, -1.0);
		glRotatef(rotBruja1, 0, 0, 1);
		glPushMatrix();
			glTranslatef(0.0, -0.75, 0.0);
			glScalef(1.6, 1.6, 1.6);
			plano(bruja.GLindex);
		glPopMatrix();
	glPopMatrix();

	/////////////////////// Fantasma 1 ///////////////////
	glPushMatrix();
		glEnable(GL_ALPHA_TEST);
		glAlphaFunc(GL_GREATER, 0.1);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glColor3f(1, 1, 1);
		glTranslatef(-3.0, 1.0, -4.5);
		glTranslatef(x, movFantasma, 0.0);
		glScalef(0.8, 1.5, 1.0);
		glRotatef(rotFantasma, 0, 1, 0);
		//if (random >= 0) {
			glDisable(GL_LIGHTING);
			plano(fantasma1.GLindex);
			glEnable(GL_LIGHTING);
		//}
		glDisable(GL_BLEND);
		glDisable(GL_ALPHA_TEST);
	glPopMatrix();

	/////////////////////// Fantasma 2 ///////////////////
	glPushMatrix();
		glEnable(GL_ALPHA_TEST);
		glAlphaFunc(GL_GREATER, 0.1);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glColor3f(1, 1, 1);
		glTranslatef(-3.0, 1.0, -4.0);
		glTranslatef((-1*x)+2.5, -1*movFantasma, 0.0);
		glScalef(0.8, 1.5, 1.0);
		glRotatef(rotFantasma2, 0, 1, 0);
		glDisable(GL_LIGHTING);
		plano(fantasma1.GLindex);
	glPopMatrix();

	////////////////////////// Skull /////////////////////////
	glPushMatrix();
		glTranslatef(3.95, 0.1, -1.0);
		glRotatef(rotSkull, 0, 0, 1);
		glPushMatrix();
			glTranslatef(0.0, 0.6, 0.0);

			glPushMatrix();
				glTranslatef(0.25, 0.2, 0.0);
				glRotatef(rotDer,0.0,0.0,1.0);
				glPushMatrix();
					glTranslatef(0.1, -0.35, 0.0);
					glScalef(0.3, 0.8, 1.0);
					plano(brazoder.GLindex);
				glPopMatrix();
			glPopMatrix();

			glPushMatrix();
				glTranslatef(-0.2, 0.25, 0.0);
				glRotatef(rotIzq, 0.0, 0.0, 1.0);
				glPushMatrix();
					glTranslatef(-0.1, -0.35, 0.0);
					glScalef(0.3, 0.8, 1.0);
					plano(brazoizq.GLindex);
				glPopMatrix();
			glPopMatrix();

			glScalef(0.5, 1.2, 1.0);
			plano(torso.GLindex);
		glPopMatrix();
	glPopMatrix();

	glEnable(GL_LIGHTING);
	glDisable(GL_BLEND);
	glDisable(GL_ALPHA_TEST);


	////////////////////// VENTANA /////////////////////
	glPushMatrix();
		glColor3f(1.0, 1.0, 1.0);
		glTranslatef(4.95, 1.0, 4.9);
		//glRotatef(rotVentana, 0, 1, 0);
		glPushMatrix();
			glTranslatef(0, 0, -0.45);
			glScalef(0.1, 2.0, 0.9);
			glRotatef(90, 1.0, 0.0, 0.0);
			glRotatef(90, 0.0, 0.0, 1.0);
			glEnable(GL_ALPHA_TEST);
			glAlphaFunc(GL_GREATER, 0.1);
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glDisable(GL_LIGHTING);
			prisma(ventana.GLindex, ventana2.GLindex);
			glEnable(GL_LIGHTING);
			glDisable(GL_BLEND);
			glDisable(GL_ALPHA_TEST);
		glPopMatrix();
	glPopMatrix();


	glPopMatrix();

	glPopMatrix();

	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	//renderBitmapCharacter(-11, 12.0, -14.0, (void *)font, "Practica 8");
	//renderBitmapCharacter(-11, 10.5, -14, (void *)font, "Texturas");
	glEnable(GL_TEXTURE_2D);

	glutSwapBuffers();

}

void animacion()
{
	/*if (temp) {
		rot_pez = 180;
		mov_pez += 0.015;
	}
	if (!temp) {
		rot_pez = 0;
		mov_pez -= 0.015;
	}

	if (mov_pez <= -0.3 || mov_pez >= 0.3) {
		temp = !temp;
	}*/

	if (animPuerta) {
		if(rotPuerta < 80) {
			rotPuerta += 1.5;
		}
	}

	if (animBruja) {
		rotBruja1 += 1.5;
		if (rotBruja1 > 30) {
			animBruja = !animBruja;
		}
	}

	if (!animBruja) {
		rotBruja1 -= 1.5;
		if (rotBruja1 < -30) {
			animBruja = !animBruja;
		}
	}

	if (animCatrin) {
		rotCatrin += 1.0;
		if (rotCatrin > 15) {
			animCatrin = !animCatrin;
		}
	}

	if (!animCatrin) {
		rotCatrin -= 1.0;
		if (rotCatrin < -15) {
			animCatrin = !animCatrin;
		}
	}

	if (animBrazo) {
		movBrazoDer += 1.5;
		if (movBrazoDer > 45) {
			animBrazo = !animBrazo;
		}
	}

	if (!animBrazo) {
		movBrazoDer -= 1.5;
		if (movBrazoDer < 0) {
			animBrazo = !animBrazo;
		}
	}

	////////////// ANIMACION FANTASMA ///////////////////

	if (animFantasma) {
		movFantasma = 0.3*sin(2*x);
		x += 0.007;
		rotFantasma = 180;
		rotFantasma2 = 0;

		if (x > 4.0) {
			animFantasma = !animFantasma;
		}

		random += 1;
		if (random >= 500) {
			random = -500;
		}
	}

	if (!animFantasma) {
		movFantasma = 0.3*sin(2*x);
		x -= 0.007;
		rotFantasma = 0;
		rotFantasma2 = 180;

		if (x < 0.0) {
			animFantasma = !animFantasma;
		}

		random += 1;
		if (random >= 500) {
			random = -500;
		}
	}

	////////////// ANIMACION SKULL ///////////////////

	if (play)
	{

		if (i_curr_steps >= i_max_steps) //end of animation between frames?
		{
			playIndex++;
			if (playIndex > FrameIndex - 2)	//end of total animation?
			{
				printf("termina anim\n");
				playIndex = 0;
				play = false;
			}
			else //Next frame interpolations
			{
				i_curr_steps = 0; //Reset counter
								  //Interpolation
				KeyFrame[playIndex].incIzq = (KeyFrame[playIndex + 1].rotIzq - KeyFrame[playIndex].rotIzq) / i_max_steps;
				KeyFrame[playIndex].incDer = (KeyFrame[playIndex + 1].rotDer - KeyFrame[playIndex].rotDer) / i_max_steps;
				KeyFrame[playIndex].incSkull = (KeyFrame[playIndex + 1].rotSkull - KeyFrame[playIndex].rotSkull) / i_max_steps;
			}
		}
		else
		{	//Draw information
			rotIzq += KeyFrame[playIndex].incIzq;
			rotDer += KeyFrame[playIndex].incDer;
			rotSkull += KeyFrame[playIndex].incSkull;
			i_curr_steps++;
		}

	}

	frame++;
	time = glutGet(GLUT_ELAPSED_TIME);
	if (time - timebase > 1000) {
		sprintf(s, "FPS:%4.2f", frame*1000.0 / (time - timebase));
		timebase = time;
		frame = 0;
	}

	glutPostRedisplay();
}

void reshape(int width, int height)   // Creamos funcion Reshape
{
	if (height == 0)										// Prevenir division entre cero
	{
		height = 1;
	}

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista

	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

/*void animacion()
{
	text_izq-= 0.01;
	text_der-= 0.01;
	if(text_izq<-1)
		text_izq=0;
	if(text_der<0)
		text_der=1;

	glutPostRedisplay();
}*/

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {

	case 'c':
	case 'C':
		if (camera == 1) {
			camera = 2;
		}
		else {
			if (camera == 2) {
				camera = 3;
			}
			else {
				camera = 1;
			}
		}
		break;

	case 'w':   //Movimientos de camara
	case 'W':
		if (camera == 1) {
			objCamera.Move_Camera(CAMERASPEED + 0.05);
		}
		else {
			if (camera == 2) {
				objCamera2.Move_Camera(CAMERASPEED + 0.05);
			}
			else {
				objCamera3.Move_Camera(CAMERASPEED + 0.05);
			}
		}
		break;

	case 's':
	case 'S':
		if (camera == 1) {
			objCamera.Move_Camera(-(CAMERASPEED + 0.05));
		}
		else {
			if (camera == 2) {
				objCamera2.Move_Camera(-(CAMERASPEED + 0.05));
			}
			else {
				objCamera3.Move_Camera(-(CAMERASPEED + 0.05));
			}
		}
		break;

	case 'a':
	case 'A':
		if (camera == 1) {
			objCamera.Strafe_Camera(-(CAMERASPEED + 0.1));
		}
		else {
			if (camera == 2) {
				objCamera2.Strafe_Camera(-(CAMERASPEED + 0.1));
			}
			else {
				objCamera3.Strafe_Camera(-(CAMERASPEED + 0.1));
			}
		}
		break;

	case 'd':
	case 'D':
		if (camera == 1) {
			objCamera.Strafe_Camera(CAMERASPEED + 0.1);
		}
		else {
			if (camera == 2) {
				objCamera2.Strafe_Camera(CAMERASPEED + 0.1);
			}
			else {
				objCamera3.Strafe_Camera(CAMERASPEED + 0.1);
			}
		}
		break;

	case 'k':
	case 'K':
		if (FrameIndex < MAX_FRAMES)
		{
			printf("frameindex %d\n", FrameIndex);

			KeyFrame[FrameIndex].rotIzq = rotIzq;
			KeyFrame[FrameIndex].rotDer = rotDer;
			KeyFrame[FrameIndex].rotSkull = rotSkull;
			FrameIndex++;
		}

		break;

	case 'l':
	case 'L':
		if (play == false && (FrameIndex > 1))
		{
			animPuerta = 1;

			rotIzq = KeyFrame[0].rotIzq;
			rotDer = KeyFrame[0].rotDer;
			rotDer = KeyFrame[0].rotSkull;

			//First Interpolation
			KeyFrame[playIndex].incIzq = (KeyFrame[playIndex + 1].rotIzq - KeyFrame[playIndex].rotIzq) / i_max_steps;		//100 frames
			KeyFrame[playIndex].incDer = (KeyFrame[playIndex + 1].rotDer - KeyFrame[playIndex].rotDer) / i_max_steps;		//100 frames
			KeyFrame[playIndex].incSkull = (KeyFrame[playIndex + 1].rotSkull - KeyFrame[playIndex].rotSkull) / i_max_steps;		//100 frames

			play = true;
			playIndex = 0;
			i_curr_steps = 0;
		}
		else
		{
			animPuerta = 1;
			play = false;
		}
		break;

	/*case 'h':
		rotPuerta++;
		break;

	case 'H':
		rotPuerta--;
		break;*/

	case 'h':
		rotDer++;
		break;

	case 'H':
		rotDer--;
		break;

	case 'j':
		rotIzq++;
		break;

	case 'J':
		rotIzq--;
		break;

	case 'g':
		rotSkull++;
		break;

	case 'G':
		rotSkull--;
		break;

	default:
		break;
	}
	glutPostRedisplay();
}

void arrow_keys(int a_keys, int x, int y)  // Funcion para manejo de teclas especiales (arrow keys)
{
	switch (a_keys) {
	case GLUT_KEY_PAGE_UP:
		if (camera == 1) {
			objCamera.UpDown_Camera(CAMERASPEED);
		}
		else {
			if (camera == 2) {
				objCamera2.UpDown_Camera(CAMERASPEED);
			}
			else {
				objCamera3.UpDown_Camera(CAMERASPEED);
			}
		}
		break;

	case GLUT_KEY_PAGE_DOWN:
		if (camera == 1) {
			objCamera.UpDown_Camera(-CAMERASPEED);
		}
		else {
			if (camera == 2) {
				objCamera2.UpDown_Camera(-CAMERASPEED);
			}
			else {
				objCamera3.UpDown_Camera(-CAMERASPEED);
			}
		}
		break;

	case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		if (camera == 1) {
			g_lookupdown -= 1.0f;
		}
		else {
			if (camera == 2) {
				g_lookupdown2 -= 1.0f;
			}
			else {
				g_lookupdown3 -= 1.0f;
			}
		}
		break;

	case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		if (camera == 1) {
			g_lookupdown += 1.0f;
		}
		else {
			if (camera == 2) {
				g_lookupdown2 += 1.0f;
			}
			else {
				g_lookupdown3 += 1.0f;
			}
		}
		break;

	case GLUT_KEY_LEFT:
		if (camera == 1) {
			objCamera.Rotate_View(-CAMERASPEED);
		}
		else {
			if (camera == 2) {
				objCamera2.Rotate_View(-CAMERASPEED);
			}
			else {
				objCamera3.Rotate_View(-CAMERASPEED);
			}
		}
		break;

	case GLUT_KEY_RIGHT:
		if (camera == 1) {
			objCamera.Rotate_View(CAMERASPEED);
		}
		else {
			if (camera == 2) {
				objCamera2.Rotate_View(CAMERASPEED);
			}
			else {
				objCamera3.Rotate_View(CAMERASPEED);
			}
		}
		break;

	default:
		break;
	}
	glutPostRedisplay();
}


int main(int argc, char** argv)   // Main Function
{
	PlaySound(TEXT("llorona.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

	glutInit(&argc, argv); // Inicializamos OpenGL
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
	glutInitWindowSize(500, 500);	// Tamaño de la Ventana
	glutInitWindowPosition(0, 0);	//Posicion de la Ventana
	glutCreateWindow("Casa Embrujada"); // Nombre de la Ventana
	//glutFullScreen     ( );         // Full Screen
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutIdleFunc(animacion);
	glutMainLoop();          // 

	return 0;
}