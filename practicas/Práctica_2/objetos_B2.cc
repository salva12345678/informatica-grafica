//**************************************************************************
// Práctica 1 usando objetos
//**************************************************************************

#include "objetos_B2.h"
#include "file_ply_stl.hpp"
#include <algorithm>

//*************************************************************************
// _puntos3D
//*************************************************************************

_puntos3D::_puntos3D()
{
}

//*************************************************************************
// dibujar puntos
//*************************************************************************

void _puntos3D::draw_puntos(float r, float g, float b, int grosor)
{
int i;
glPointSize(grosor);
glColor3f(r,g,b);
glBegin(GL_POINTS);
for (i=0;i<vertices.size();i++){
	glVertex3fv((GLfloat *) &vertices[i]);
	}
glEnd();
}


//*************************************************************************
// _triangulos3D
//*************************************************************************

_triangulos3D::_triangulos3D()
{
}


//*************************************************************************
// dibujar en modo arista
//*************************************************************************

void _triangulos3D::draw_aristas(float r, float g, float b, int grosor)
{
int i;
glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
glLineWidth(grosor);
glColor3f(r,g,b);
glBegin(GL_TRIANGLES);
for (i=0;i<caras.size();i++){
	glVertex3fv((GLfloat *) &vertices[caras[i]._0]);
	glVertex3fv((GLfloat *) &vertices[caras[i]._1]);
	glVertex3fv((GLfloat *) &vertices[caras[i]._2]);
	}
glEnd();
}

//*************************************************************************
// dibujar en modo sólido
//*************************************************************************

void _triangulos3D::draw_solido(float r, float g, float b)
{

		glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
		//glLineWidth(grosor);
		glColor3f(r,g,b);
		glBegin(GL_TRIANGLES);
		for (int i=0;i<caras.size();i++){
			glVertex3fv((GLfloat *) &vertices[caras[i]._0]);
			glVertex3fv((GLfloat *) &vertices[caras[i]._1]);
			glVertex3fv((GLfloat *) &vertices[caras[i]._2]);
			}
		glEnd();


}

//*************************************************************************
// dibujar en modo sólido con apariencia de ajedrez
//*************************************************************************

void _triangulos3D::draw_solido_ajedrez(float r1, float g1, float b1, float r2, float g2, float b2)
{

		glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);



		glBegin(GL_TRIANGLES);
			for (int i=0;i<caras.size();i++){

				if(i%2==0){
					glColor3f(r1,g1,b1);
				}
				else{
					glColor3f(r2,g2,b2);
				}

				glVertex3fv((GLfloat *) &vertices[caras[i]._0]);
				glVertex3fv((GLfloat *) &vertices[caras[i]._1]);
				glVertex3fv((GLfloat *) &vertices[caras[i]._2]);

			}
		glEnd();
}

//*************************************************************************
// dibujar con distintos modos
//*************************************************************************

void _triangulos3D::draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor)
{
switch (modo){
	case POINTS:draw_puntos(r1, g1, b1, grosor);break;
	case EDGES:draw_aristas(r1, g1, b1, grosor);break;
	case SOLID_CHESS:draw_solido_ajedrez(r1, g1, b1, r2, g2, b2);break;
	case SOLID:draw_solido(r1, g1, b1);break;
	}
}

//*************************************************************************
// clase cubo
//*************************************************************************

_cubo::_cubo(float tam)
{
	//vertices
	vertices.resize(8);
	//parte de abajo
	vertices[0].x=-tam;vertices[0].y=0;vertices[0].z=tam;
	vertices[1].x=tam;vertices[1].y=0;vertices[1].z=tam;
	vertices[2].x=tam;vertices[2].y=0;vertices[2].z=-tam;
	vertices[3].x=-tam;vertices[3].y=0;vertices[3].z=-tam;
	//parte de arriba
	vertices[4].x=-tam;vertices[4].y=2*tam;vertices[4].z=tam;
	vertices[5].x=tam;vertices[5].y=2*tam;vertices[5].z=tam;
	vertices[6].x=tam;vertices[6].y=2*tam;vertices[6].z=-tam;
	vertices[7].x=-tam;vertices[7].y=2*tam;vertices[7].z=-tam;



	caras.resize(12);

	//tapa de enfrente

	caras[0]._0=0;caras[0]._1=1;caras[0]._2=5;
	caras[1]._0=0;caras[1]._1=5;caras[1]._2=4;

	//tapa de la izquierda

	caras[2]._0=0;caras[2]._1=7;caras[2]._2=3;
	caras[3]._0=0;caras[3]._1=4;caras[3]._2=7;


	//tapa de atras

	caras[4]._0=3;caras[4]._1=7;caras[4]._2=6;
	caras[5]._0=3;caras[5]._1=6;caras[5]._2=2;


	//tapa de derecha

	caras[6]._0=1;caras[6]._1=2;caras[6]._2=6;
	caras[7]._0=1;caras[7]._1=6;caras[7]._2=5;

	//tapa de abajo
	caras[8]._0=0;caras[8]._1=2;caras[8]._2=1;
	caras[9]._0=0;caras[9]._1=3;caras[9]._2=2;

	//tapa de arriba

	caras[10]._0=4;caras[10]._1=5;caras[10]._2=6;
	caras[11]._0=4;caras[11]._1=6;caras[11]._2=7;


}


//*************************************************************************
// clase piramide
//*************************************************************************

_piramide::_piramide(float tam, float al)
{

//vertices
vertices.resize(5);
vertices[0].x=-tam;vertices[0].y=0;vertices[0].z=tam;
vertices[1].x=tam;vertices[1].y=0;vertices[1].z=tam;
vertices[2].x=tam;vertices[2].y=0;vertices[2].z=-tam;
vertices[3].x=-tam;vertices[3].y=0;vertices[3].z=-tam;
vertices[4].x=0;vertices[4].y=al;vertices[4].z=0;

caras.resize(6);
caras[0]._0=0;caras[0]._1=1;caras[0]._2=4;
caras[1]._0=1;caras[1]._1=2;caras[1]._2=4;
caras[2]._0=2;caras[2]._1=3;caras[2]._2=4;
caras[3]._0=3;caras[3]._1=0;caras[3]._2=4;
caras[4]._0=3;caras[4]._1=1;caras[4]._2=0;
caras[5]._0=3;caras[5]._1=2;caras[5]._2=1;
}

//*************************************************************************
// clase objeto ply
//*************************************************************************

_objeto_ply_revolucion::_objeto_ply_revolucion()
{
   // leer lista de coordenadas de vértices y lista de indices de vértices

}

int _objeto_ply_revolucion::parametros(char *archivo){
	int n_ver,n_car;



	vector<float> ver_ply ;
	vector<int>   car_ply ;

	_file_ply::read(archivo, ver_ply, car_ply );

  n_ver=ver_ply.size()/3;
	n_car=car_ply.size()/3;

	printf("Number of vertices=%d\nNumber of faces=%d\n", n_ver, n_car);

	vertices.resize(n_ver);
	caras.resize(n_car);
	int num =10;


	////////////////////////////////////////
	_vertex3f vertices_aux;
	_vertex3f perfil_aux;
	vector<_vertex3f> perfil;


	for(int i=0;i<ver_ply.size();i+=3){

		perfil_aux.x=ver_ply[i];
		perfil_aux.y=ver_ply[i+1];
		perfil_aux.z=ver_ply[i+2];
		perfil.push_back(perfil_aux);
	}
	caras.clear();
	vertices.clear();

	if(perfil[0].y > perfil[perfil.size()-1].y){
		reverse(perfil.begin(),perfil.end());
	}

	caras.clear();
	vertices.clear();
	int i,j;
	_vertex3f vertice_aux;
	_vertex3i cara_aux;
	int num_aux;

// tratamiento de los vértice

num_aux=perfil.size();
vertices.resize(num_aux*num);
for (j=0;j<num;j++){
	for (i=0;i<num_aux;i++){

			vertice_aux.x=perfil[i].x*cos(2.0*M_PI*j/(1.0*num))+
										perfil[i].z*sin(2.0*M_PI*j/(1.0*num));
			vertice_aux.z=-perfil[i].x*sin(2.0*M_PI*j/(1.0*num))+
										perfil[i].z*cos(2.0*M_PI*j/(1.0*num));
			vertice_aux.y=perfil[i].y;
			vertices[i+j*num_aux]=vertice_aux;
		 }
	}
//tratamiento de las caras
for(int j=0;j<num;j++){
	for(int i=0;i<num_aux-1;i++){

		cara_aux._0 = i+((j+1)%num)*num_aux;
		cara_aux._1 = i+1+((j+1)%num)*num_aux;
		cara_aux._2 = i+1+j*num_aux;
		caras.push_back(cara_aux);
		cara_aux._0 = i+1+j*num_aux;
		cara_aux._2 = i+j*num_aux;
		cara_aux._1 = i+((j+1)%num)*num_aux;
		caras.push_back(cara_aux);
	}
}

//tapa inferior
if (fabs(perfil[0].x)>0.0){

	vertice_aux.x=0;
	vertice_aux.y=perfil[0].y;
	vertice_aux.z=0;

	vertices.push_back(vertice_aux);


	for(int j = 0; j<num-1; j++){

			cara_aux._0 = vertices.size() - 1;
			cara_aux._1 = j * num_aux;
			cara_aux._2 = (j+1) * num_aux;
			caras.push_back(cara_aux);

	}

	//ultima cara
	cara_aux._0=vertices.size() - 1;
	cara_aux._1=(num-1) * num_aux;
	cara_aux._2=0;
	caras.push_back(cara_aux);


}

 // tapa superior
 if (fabs(perfil[num_aux-1].x)>0.0){
	 vertice_aux.x=0;
	 vertice_aux.y=perfil[num_aux-1].y;  //tengo el punto intermedio  //para el cono ponemos 1.
	 vertice_aux.z=0;
	 vertices.push_back(vertice_aux);

	 for(int j = 0; j<num-1; j++){
		cara_aux._0 = vertices.size() - 1;
		cara_aux._1 = j * num_aux + (num_aux-1);
		cara_aux._2 = (j+1) * num_aux + (num_aux -1);
		caras.push_back(cara_aux);
	 }

	 //ultima cara
		cara_aux._0 = vertices.size() - 1;
		cara_aux._1 = (num-1) * num_aux + (num_aux-1);
		cara_aux._2 = num_aux - 1;
		caras.push_back(cara_aux);

	}



	return(0);
}




_objeto_ply::_objeto_ply()
{
   // leer lista de coordenadas de vértices y lista de indices de vértices

}



int _objeto_ply::parametros(char *archivo){
	int n_ver,n_car;



	vector<float> ver_ply ;
	vector<int>   car_ply ;

	_file_ply::read(archivo, ver_ply, car_ply );

	n_ver=ver_ply.size()/3;
	n_car=car_ply.size()/3;

	printf("Number of vertices=%d\nNumber of faces=%d\n", n_ver, n_car);

	vertices.resize(n_ver);
	caras.resize(n_car);



	////////////////////////////////////////
	_vertex3f vertices_aux;

	caras.clear();
	vertices.clear();
	for(int i=0;i<ver_ply.size();i+=3){

		vertices_aux.x=ver_ply[i];
		vertices_aux.y=ver_ply[i+1];
		vertices_aux.z=ver_ply[i+2];
		vertices.push_back(vertices_aux);
	}

	_vertex3i cara_aux;



	for(int i=0;i<car_ply.size();i+=3){
		cara_aux._0=car_ply[i];
		cara_aux._2=car_ply[i+2];
		cara_aux._1=car_ply[i+1];

		caras.push_back(cara_aux);
	}


	return(0);
}

//************************************************************************
// objeto por revolucion
//************************************************************************

_rotacion::_rotacion(){

}


void _rotacion::parametros(vector<_vertex3f> perfil, int num){

	if(perfil[0].y > perfil[perfil.size()-1].y){
		reverse(perfil.begin(),perfil.end());
	}

	caras.clear();
	vertices.clear();
	int i,j;
	_vertex3f vertice_aux;
	_vertex3i cara_aux;
	int num_aux;

// tratamiento de los vértice

num_aux=perfil.size();
vertices.resize(num_aux*num);
for (j=0;j<num;j++){
	for (i=0;i<num_aux;i++){

      vertice_aux.x=perfil[i].x*cos(2.0*M_PI*j/(1.0*num))+
                    perfil[i].z*sin(2.0*M_PI*j/(1.0*num));
      vertice_aux.z=-perfil[i].x*sin(2.0*M_PI*j/(1.0*num))+
                    perfil[i].z*cos(2.0*M_PI*j/(1.0*num));
      vertice_aux.y=perfil[i].y;
      vertices[i+j*num_aux]=vertice_aux;
     }
  }
//tratamiento de las caras
for(int j=0;j<num;j++){
	for(int i=0;i<num_aux-1;i++){

		cara_aux._0 = i+((j+1)%num)*num_aux;
    cara_aux._1 = i+1+((j+1)%num)*num_aux;
    cara_aux._2 = i+1+j*num_aux;
    caras.push_back(cara_aux);
    cara_aux._0 = i+1+j*num_aux;
    cara_aux._2 = i+j*num_aux;
    cara_aux._1 = i+((j+1)%num)*num_aux;
    caras.push_back(cara_aux);
	}
}

//tapa inferior
if (fabs(perfil[0].x)>0.0){

	vertice_aux.x=0;
	vertice_aux.y=perfil[0].y;
	vertice_aux.z=0;

	vertices.push_back(vertice_aux);


	for(int j = 0; j<num-1; j++){

      cara_aux._0 = vertices.size() - 1;
      cara_aux._1 = j * num_aux;
      cara_aux._2 = (j+1) * num_aux;
      caras.push_back(cara_aux);

  }

	//ultima cara
	cara_aux._0=vertices.size() - 1;
	cara_aux._1=(num-1) * num_aux;
	cara_aux._2=0;
	caras.push_back(cara_aux);


}

 // tapa superior
 if (fabs(perfil[num_aux-1].x)>0.0){
	 vertice_aux.x=0;
	 vertice_aux.y=perfil[num_aux-1].y;  //tengo el punto intermedio  //para el cono ponemos 1.
	 vertice_aux.z=0;
	 vertices.push_back(vertice_aux);

	 for(int j = 0; j<num-1; j++){
		cara_aux._0 = vertices.size() - 1;
		cara_aux._1 = j * num_aux + (num_aux-1);
		cara_aux._2 = (j+1) * num_aux + (num_aux -1);
		caras.push_back(cara_aux);
   }

	 //ultima cara
	 	cara_aux._0 = vertices.size() - 1;
    cara_aux._1 = (num-1) * num_aux + (num_aux-1);
    cara_aux._2 = num_aux - 1;
    caras.push_back(cara_aux);

  }

}


_Cono::_Cono(){

}

void _Cono::parametros1(vector<_vertex3f> perfil,int altura,int num) {

	caras.clear();
	vertices.clear();

	int i,j;
	_vertex3f vertice_aux;
	_vertex3i cara_aux;
	int num_aux;

// tratamiento de los vértice

num_aux=perfil.size();
vertices.resize(num_aux*num);
for (j=0;j<num;j++){
	for (i=0;i<num_aux;i++){

      vertice_aux.x=perfil[i].x*cos(2.0*M_PI*j/(1.0*num))+
                    perfil[i].z*sin(2.0*M_PI*j/(1.0*num));
      vertice_aux.z=-perfil[i].x*sin(2.0*M_PI*j/(1.0*num))+
                    perfil[i].z*cos(2.0*M_PI*j/(1.0*num));
      vertice_aux.y=perfil[i].y;
      vertices[i+j*num_aux]=vertice_aux;
     }
  }

// tratamiento de las caras

for(int i=0;i<num;i++){

    for(int j=0;j<num_aux-1;j++){

        cara_aux._0 = j +((i+1)%num)*num_aux;
        cara_aux._1 = j+1+((i+1)%num)*num_aux;
        cara_aux._2 = j+1+i*num_aux;

        caras.push_back(cara_aux);
        cara_aux._0 = j+1+i*num_aux;
        cara_aux._1 = j+i*num_aux;
        cara_aux._2 = j+((i+1)%num)*num_aux;

        caras.push_back(cara_aux);
    }
}

//tapa inferior
if (fabs(perfil[0].x)>0.0){

	vertice_aux.x=0;
	vertice_aux.y=0;  //tengo el punto intermedio
	vertice_aux.z=0;

	vertices.push_back(vertice_aux);

	for(int j = 0; j<num-1; j++){

      cara_aux._0 = vertices.size() - 1;
      cara_aux._1 = j * num_aux;
      cara_aux._2 = (j+1) * num_aux;
      caras.push_back(cara_aux);

  }

	//ultima cara
	cara_aux._0=vertices.size() - 1;
	cara_aux._1=(num-1) * num_aux;
	cara_aux._2=0;
	caras.push_back(cara_aux);



	//punto de arriba

	vertice_aux.x=0;
	vertice_aux.y=altura;  //tengo el punto intermedio
	vertice_aux.z=0;
	vertices.push_back(vertice_aux);

	for(int j = 0; j<num-1; j++){

      cara_aux._0 = vertices.size() - 1;
      cara_aux._1 = j * num_aux;
      cara_aux._2 = (j+1) * num_aux;
      caras.push_back(cara_aux);

  }

	//ultima cara
	cara_aux._0=vertices.size() - 1;
	cara_aux._1=(num-1) * num_aux;
	cara_aux._2=0;
	caras.push_back(cara_aux);

}


}


_Esfera::_Esfera(){

}
void _Esfera::parametros2(int num, int numPerfil, int radio){

	caras.clear();
  vertices.clear();
    float angIni = M_PI/2, angCal = M_PI/(numPerfil-1);
    vector<_vertex3f> perfil;
    _vertex3f perfil_aux;
    int aux =numPerfil;
    for(int i = 0; i < aux; ++i){
            perfil_aux.x = radio * cos(angIni);
            perfil_aux.y = radio * sin(angIni);
            perfil_aux.z = 0;
            if(perfil_aux.x>0.0001)
                perfil.push_back(perfil_aux);
            else{
                numPerfil--;
            }
            angIni -= angCal;
				}


int i,j;
_vertex3f vertice_aux;
_vertex3i cara_aux;
int num_aux;
// tratamiento de los vértice

num_aux=perfil.size();
if(perfil[0].y>perfil[1].y)
    reverse(perfil.begin(),perfil.end());

vertices.resize(num_aux*num);
for (j=0;j<num;j++)
  {
        for (i=0;i<num_aux;i++)
     {
      vertice_aux.x=perfil[i].x*cos(2.0*M_PI*j/(1.0*num))+
                    perfil[i].z*sin(2.0*M_PI*j/(1.0*num));
      vertice_aux.z=-perfil[i].x*sin(2.0*M_PI*j/(1.0*num))+
                    perfil[i].z*cos(2.0*M_PI*j/(1.0*num));
      vertice_aux.y=perfil[i].y;
      vertices[i+j*num_aux]=vertice_aux;
     }
  }



// tratamiento de las caras

for(int i=0;i<num;i++){

    for(int j=0;j<num_aux-1;j++){

        cara_aux._0 = j +((i+1)%num)*num_aux;
        cara_aux._1 = j+1+((i+1)%num)*num_aux;
        cara_aux._2 = j+1+i*num_aux;

        caras.push_back(cara_aux);
        cara_aux._0 = j+1+i*num_aux;
        cara_aux._1 = j+i*num_aux;
        cara_aux._2 = j+((i+1)%num)*num_aux;

        caras.push_back(cara_aux);
    }
}

// tapa inferior

vector<_vertex3f> perfilaux(2);
vertice_aux.x=0;
vertice_aux.y=-radio;
vertice_aux.z=0;

vertices.push_back(vertice_aux);

for(int i=0;i<num-1;i++){
    cara_aux._0 = i*num_aux;
    cara_aux._1 = (i+1)*num_aux;
    cara_aux._2 = vertices.size()-1;

    caras.push_back(cara_aux);
}
cara_aux._0 = (num-1)*num_aux;
cara_aux._1 = vertices.size()-1;
cara_aux._2 = 0;

caras.push_back(cara_aux);

// tapa superior

vertice_aux.x=0;
vertice_aux.y=radio;
vertice_aux.z=0;

vertices.push_back(vertice_aux);

for(int i=0;i<num-1;i++){
    cara_aux._0 = i*num_aux+num_aux-1;

    cara_aux._1 = (i+1)*num_aux+num_aux-1;
    cara_aux._2 = vertices.size()-1;

    caras.push_back(cara_aux);
}
cara_aux._0 = (num-1)*num_aux+num_aux-1;
cara_aux._1 = vertices.size()-1;
cara_aux._2 = num_aux-1;

caras.push_back(cara_aux);


}
