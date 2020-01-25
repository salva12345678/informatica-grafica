// Requiere ImageMagick Instalado

#include <CImg.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <string>
#include <vector>

const float AxisSize=10000;

using namespace cimg_library;
using namespace std;

/*** Declaracion de Variables ***/

GLuint textura_id, textura_id2;

GLfloat vertices[] = {
  //cara de arriba
    0,  5,  0,
    5,  5,  0,
    5,  5,  5,
    0,  5,  5,
//Cara de izquierda
    0,  5,  0,
    0,  5,  5,
    0,  0,  5,
    0,  0,  0,

    5,  5,  0,
    5,  0,  0,
    5,  0,  5,
    5,  5,  5,

    0,  5,  0,
    0,  0,  0,
    5,  0,  0,
    5,  5,  0,

    0,  5,  5,
    5,  5,  5,
    5,  0,  5,
    0,  0,  5,

    0,  0,  0,
    5,  0,  0,
    5,  0,  5,
    0,  0,  5
};

GLfloat texVertices[] = {
  /*  0.0,    0.0,  //esta en 2D
    0.5,    0.0,
    0.5,    0.5,
    0.0,    0.5,
*/
    



    0.5,    0.0,
    0.5,    0.5,
    1.0,    0.5,
    1.0,    0.0,

    0.5,    0.0,
    1.0,    0.0,
    0.5,    0.5,
    1.0,    0.5,

    0.0,    0.5,
    0.0,    1.0,
    0.5,    0.5,
    0.5,    1.0,

    0.0,    0.5,
    0.5,    0.5,
    0.5,    1.0,
    0.0,    1.0,

    0.5,    0.5,
    1.0,    0.5,
    1.0,    1.0,
    0.5,    1.0
};


GLfloat vertices2[] = {
    3,  7,  0,
    0,  7,  0,
    0,  5,  0,
    3,  5,  0
};

GLfloat texVertices2[] = {
    0.0,    0.0,
    1.0,    0.0,
    1.0,    1.0,
    0.0,    1.0
};



/*** Declaracion de Funciones ***/

float latitud = 0.0, longitud = 0.0, radio = 24;

void Init();

void OnDraw();

void SpecialKeys(int key,int x,int y);

void prepara_textura(char *file, GLuint *tex_id);

void dibuja(void);

void libera_textura(GLuint *tex_id);

/*** Funciones ***/

void Init(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("My World");
    glEnable(GL_DEPTH_TEST);
    //glEnable(GL_COLOR_MATERIAL);
    glMatrixMode(GL_PROJECTION);
    gluPerspective( 40.0, 800/600.0f, 0.1, 150);
    // Se cambia la imagen de la textura
    prepara_textura("./caja.jpg", &textura_id);
    prepara_textura("./blackfriday.png", &textura_id2);
}

void draw_axis(){
    glLineWidth(2);
    glBegin(GL_LINES);
        // Eje X
        glColor3f(1, 0, 0);
        glVertex3f(-AxisSize, 0, 0);
        glVertex3f(AxisSize, 0, 0);
        // Eje Y
        glColor3f(0, 1, 0);
        glVertex3f(0, -AxisSize, 0);
        glVertex3f(0, AxisSize, 0);
        // Eje Z
        glColor3f(0, 0, 1);
        glVertex3f(0, 0, -AxisSize);
        glVertex3f(0, 0, AxisSize);
    glEnd();
    glLineWidth(1);
    glColor3f(1, 1, 1);
}

void OnDraw(void){
    float observador[3];
    float phir,thetar;
    phir = latitud*M_PI/180.0;
    thetar = longitud*M_PI/180.0;
    observador[0] = radio*sin(thetar)*cos(phir);
    observador[1] = radio*sin(phir);
    observador[2] = radio*cos(phir)*cos(thetar);
    glClearColor(0.5, 0.5, 0.5, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(observador[0], observador[1], observador[2], 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    draw_axis();
    dibuja();
    glutSwapBuffers();
}


void SpecialKeys(int key,int x,int y) {
    switch (key){
        case GLUT_KEY_LEFT:
            longitud += 2.0;
            break;
        case GLUT_KEY_RIGHT:
            longitud -= 2.0;
            break;
        case GLUT_KEY_UP:
            latitud += 2.0;
            break;
        case GLUT_KEY_DOWN:
            latitud -= 2.0;
            break;
        case GLUT_KEY_PAGE_UP:
            radio += 1.0;
            break;
        case GLUT_KEY_PAGE_DOWN:
            radio -= 1.0;
            if(radio < 1)
                radio = 1;
            break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    Init(argc, argv);
    glutDisplayFunc(OnDraw);
    glutSpecialFunc(SpecialKeys);
    glutMainLoop();
    libera_textura(&textura_id);
    libera_textura(&textura_id2);
    return 0;
}

void prepara_textura(char *file, GLuint *tex_id){
    vector<unsigned char> data;
    CImg<unsigned char> image;
    image.load(file);
    for(long y = 0; y < image.height(); y ++)
        for(long x = 0; x < image.width(); x ++){
            unsigned char *r = image.data(x, y, 0, 0);
            unsigned char *g = image.data(x, y, 0, 1);
            unsigned char *b = image.data(x, y, 0, 2);
            data.push_back(*r);
            data.push_back(*g);
            data.push_back(*b);
        }
    glGenTextures(1, tex_id);
    glBindTexture(GL_TEXTURE_2D, *tex_id);
    //glActiveTexture(GL_TEXTURE0);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image.width(), image.height(), 0, GL_RGB, GL_UNSIGNED_BYTE, &data[0]);
}

void dibuja(void){
    glEnable(GL_TEXTURE_2D);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState (GL_TEXTURE_COORD_ARRAY_EXT);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, textura_id);
    glVertexPointer(3, GL_FLOAT, 0, vertices); //2 o 3 segun el numero de coordenadas
    glTexCoordPointer(2, GL_FLOAT, 0, texVertices);
    glDrawArrays(GL_QUADS, 0, 24); // 24 porque tenemos 24 vertices
    glBindTexture(GL_TEXTURE_2D, textura_id2);
    glVertexPointer(3, GL_FLOAT, 0, vertices2); //2 o 3 segun el numero de coordenadas
    glTexCoordPointer(2, GL_FLOAT, 0, texVertices2);
    glRotatef(25, 1, 0, 0);
    glDrawArrays(GL_QUADS, 0, 4); // 4 porque tenemos 4 vertices
    glDisableClientState(GL_VERTEX_ARRAY);
    glBindTexture(GL_TEXTURE_2D, 0);
    glDisable(GL_TEXTURE_2D);
}

void libera_textura(GLuint *tex_id){
    glDeleteTextures(1, tex_id);
}
