//**************************************************************************
// Práctica 1 usando objetos
//**************************************************************************

#include "objetos_B3.h"


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
//**** usando vertex_array ****
glPointSize(grosor);
glColor3f(r,g,b);

glEnableClientState(GL_VERTEX_ARRAY);
glVertexPointer(3,GL_FLOAT,0,&vertices[0]);
glDrawArrays(GL_POINTS,0,vertices.size());

/*int i;
glPointSize(grosor);
glColor3f(r,g,b);
glBegin(GL_POINTS);
for (i=0;i<vertices.size();i++){
	glVertex3fv((GLfloat *) &vertices[i]);
	}
glEnd();*/
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
//**** usando vertex_array ****
glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
glLineWidth(grosor);
glColor3f(r,g,b);

glEnableClientState(GL_VERTEX_ARRAY);
glVertexPointer(3,GL_FLOAT,0,&vertices[0]);
glDrawElements(GL_TRIANGLES,caras.size()*3,GL_UNSIGNED_INT,&caras[0]);

/*int i;
glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
glLineWidth(grosor);
glColor3f(r,g,b);
glBegin(GL_TRIANGLES);
for (i=0;i<caras.size();i++){
	glVertex3fv((GLfloat *) &vertices[caras[i]._0]);
	glVertex3fv((GLfloat *) &vertices[caras[i]._1]);
	glVertex3fv((GLfloat *) &vertices[caras[i]._2]);
	}
glEnd();*/
}

//*************************************************************************
// dibujar en modo sólido
//*************************************************************************

void _triangulos3D::draw_solido(float r, float g, float b)
{
int i;

glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
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
// dibujar en modo sólido con apariencia de ajedrez
//*************************************************************************

void _triangulos3D::draw_solido_ajedrez(float r1, float g1, float b1, float r2, float g2, float b2)
{
int i;
glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
glBegin(GL_TRIANGLES);
for (i=0;i<caras.size();i++){
	if (i%2==0) glColor3f(r1,g1,b1);
	else glColor3f(r2,g2,b2);
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
vertices[0].x=-tam;vertices[0].y=-tam;vertices[0].z=tam;
vertices[1].x=tam;vertices[1].y=-tam;vertices[1].z=tam;
vertices[2].x=tam;vertices[2].y=tam;vertices[2].z=tam;
vertices[3].x=-tam;vertices[3].y=tam;vertices[3].z=tam;
vertices[4].x=-tam;vertices[4].y=-tam;vertices[4].z=-tam;
vertices[5].x=tam;vertices[5].y=-tam;vertices[5].z=-tam;
vertices[6].x=tam;vertices[6].y=tam;vertices[6].z=-tam;
vertices[7].x=-tam;vertices[7].y=tam;vertices[7].z=-tam;

// triangulos
caras.resize(12);
caras[0]._0=0;caras[0]._1=1;caras[0]._2=3;
caras[1]._0=3;caras[1]._1=1;caras[1]._2=2;
caras[2]._0=1;caras[2]._1=5;caras[2]._2=2;
caras[3]._0=5;caras[3]._1=6;caras[3]._2=2;
caras[4]._0=5;caras[4]._1=4;caras[4]._2=6;
caras[5]._0=4;caras[5]._1=7;caras[5]._2=6;
caras[6]._0=0;caras[6]._1=7;caras[6]._2=4;
caras[7]._0=0;caras[7]._1=3;caras[7]._2=7;
caras[8]._0=3;caras[8]._1=2;caras[8]._2=7;
caras[9]._0=2;caras[9]._1=6;caras[9]._2=7;
caras[10]._0=0;caras[10]._1=1;caras[10]._2=4;
caras[11]._0=1;caras[11]._1=5;caras[11]._2=4;
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

_triangulo::_triangulo(float tam)
{

	//vertices
	vertices.resize(8);
	vertices[0].x=-tam;vertices[0].y=-tam;vertices[0].z=tam;
	vertices[1].x=tam;vertices[1].y=-tam;vertices[1].z=tam;
	vertices[2].x=tam;vertices[2].y=tam;vertices[2].z=tam;
	vertices[3].x=-tam;vertices[3].y=tam;vertices[3].z=tam;
	vertices[4].x=-tam;vertices[4].y=-tam;vertices[4].z=-tam;
	vertices[5].x=tam;vertices[5].y=-tam;vertices[5].z=-tam;

	// triangulos
	caras.resize(12);
	//FRONTAL
	caras[0]._0=0;caras[0]._1=1;caras[0]._2=3;
	caras[1]._0=3;caras[1]._1=1;caras[1]._2=2;

	caras[2]._0=1;caras[2]._1=5;caras[2]._2=2;
	caras[3]._0=0;caras[3]._1=3;caras[3]._2=4;

	caras[4]._0=5;caras[4]._1=2;caras[4]._2=3;
	caras[5]._0=4;caras[5]._1=5;caras[5]._2=3;

}

//*************************************************************************
// clase objeto ply
//*************************************************************************


_objeto_ply::_objeto_ply()
{
   // leer lista de coordenadas de vértices y lista de indices de vértices

}



int _objeto_ply::parametros(char *archivo)
{
int n_ver,n_car;

vector<float> ver_ply ;
vector<int>   car_ply ;

_file_ply::read(archivo, ver_ply, car_ply );

n_ver=ver_ply.size()/3;
n_car=car_ply.size()/3;

printf("Number of vertices=%d\nNumber of faces=%d\n", n_ver, n_car);

//if (n_ver<3 || n_car<1){
//	printf("Error %d %d\n",__FILE__,__LINE__);
//	exit(-1);
//	}

vertices.resize(n_ver);
caras.resize(n_car);

_vertex3f ver_aux;
_vertex3i car_aux;

for (int i=0;i<n_ver;i++)
	{ver_aux.x=ver_ply[i*3];
	 ver_aux.y=ver_ply[i*3+1];
	 ver_aux.z=ver_ply[i*3+2];
	 vertices[i]=ver_aux;
	}

for (int i=0;i<n_car;i++)
	{car_aux.x=car_ply[i*3];
	 car_aux.y=car_ply[i*3+1];
	 car_aux.z=car_ply[i*3+2];
	 caras[i]=car_aux;
	}

return(0);
}


//************************************************************************
// objeto por revolucion
//************************************************************************

_rotacion::_rotacion()
{

}


void _rotacion::parametros(vector<_vertex3f> perfil, int num, int tapa)
{
int i,j;
_vertex3f vertice_aux;
_vertex3i cara_aux;
int num_aux;

// tratamiento de los vértice

num_aux=perfil.size();
vertices.resize(num_aux*num);
for (j=0;j<num;j++)
  {for (i=0;i<num_aux;i++)
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

for (j=0;j<num;j++)
  {for (i=0;i<num_aux-1;i++)
     {cara_aux._0=i+((j+1)%num)*num_aux;
      cara_aux._1=i+1+((j+1)%num)*num_aux;
      cara_aux._2=i+1+j*num_aux;
      caras.push_back(cara_aux);

      cara_aux._0=i+1+j*num_aux;
      cara_aux._1=i+j*num_aux;
      cara_aux._2=i+((j+1)%num)*num_aux;
      caras.push_back(cara_aux);
     }
  }

 // tapa inferior
if (fabs(perfil[0].x)>0.0 && tapa==1)
  {
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
 if (fabs(perfil[num_aux-1].x)>0.0 && tapa==1)
  {
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

//************************************************************************
// objeto articulado: tanque
//************************************************************************

_chasis::_chasis()
{
// perfil para un cilindro
vector<_vertex3f> perfil;
_vertex3f aux;
aux.x=0.107;aux.y=-0.5;aux.z=0.0;
perfil.push_back(aux);
aux.x=0.107;aux.y=0.5;aux.z=0.0;
perfil.push_back(aux);
rodamiento.parametros(perfil,12,1);
altura=0.22;
};

void _chasis::draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor)
{
glPushMatrix();
glScalef(1.0,0.22,0.95);
base.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
glPopMatrix();

glPushMatrix();
glRotatef(90.0,1,0,0);
rodamiento.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
glPopMatrix();

glPushMatrix();
glTranslatef(-0.25,0.0,0.0);
glRotatef(90.0,1,0,0);
rodamiento.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
glPopMatrix();

glPushMatrix();
glTranslatef(-0.5,0.0,0.0);
glRotatef(90.0,1,0,0);
rodamiento.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
glPopMatrix();

glPushMatrix();
glTranslatef(0.25,0.0,0.0);
glRotatef(90.0,1,0,0);
rodamiento.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
glPopMatrix();

glPushMatrix();
glTranslatef(0.5,0.0,0.0);
glRotatef(90.0,1,0,0);
rodamiento.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
glPopMatrix();
}

//************************************************************************

_torreta::_torreta()
{
altura=0.18;
anchura=0.65;
};

void _torreta::draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor)
{
glPushMatrix();
glScalef(0.65,0.18,0.6);
base.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
glPopMatrix();

glPushMatrix();
glTranslatef(-0.325,0,0);
glRotatef(90.0,0,0,1);
glScalef(0.18,0.16,0.6);
parte_trasera.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
glPopMatrix();
}

//************************************************************************

_tubo::_tubo()
{
// perfil para un cilindro
vector<_vertex3f> perfil;
_vertex3f aux;
aux.x=0.04;aux.y=-0.4;aux.z=0.0;
perfil.push_back(aux);
aux.x=0.04;aux.y=0.4;aux.z=0.0;
perfil.push_back(aux);
tubo_abierto.parametros(perfil,12,0);
};

void _tubo::draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor)
{

glPushMatrix();
glTranslatef(0.4,0,0);
glRotatef(90.0,0,0,1);
tubo_abierto.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
glPopMatrix();

}


//************************************************************************

_tanque::_tanque()
{
giro_tubo=2.0;
giro_torreta=0.0;
giro_tubo_min=-9;
giro_tubo_max=20;
};

void _tanque::draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor)
{
glPushMatrix();
chasis.draw(modo, r1, g1, b1, r2, g2, b2, grosor);

glRotatef(giro_torreta,0,1,0);
glPushMatrix();
glTranslatef(0.0,(chasis.altura+torreta.altura)/2.0,0.0);
torreta.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
glPopMatrix();

glPushMatrix();
glTranslatef(torreta.anchura/2.0,(chasis.altura+torreta.altura)/2.0,0.0);
glRotatef(giro_tubo,0,0,1);
tubo.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
glPopMatrix();
glPopMatrix();

};

_coraza_exterior::_coraza_exterior(){

};

void _coraza_exterior::draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor){

	glPushMatrix();
	glScalef(22,5,16);
	baseinterior.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
	glPopMatrix();

}

_oruga_horizontal::_oruga_horizontal(){

};

void _oruga_horizontal::draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor){

	glPushMatrix();
	glScalef(22,1,2);
	base.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
	glPopMatrix();

}

_oruga_vertical::_oruga_vertical(){

};

void _oruga_vertical::draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor){

	glPushMatrix();
	glScalef(1,6,2);
	base.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
	glPopMatrix();

}

_ruedas_tank::_ruedas_tank(){
_vertex3f aux;
vector<_vertex3f> perfil2;
aux.x=1.0; aux.y=-1.0; aux.z=0.0;
perfil2.push_back(aux);
aux.x=1.0; aux.y=1.0; aux.z=0.0;
perfil2.push_back(aux);
cilindro_rueda.parametros(perfil2,20,1);
};

void _ruedas_tank::draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor){

	glPushMatrix();
	glScalef(1,2,1);
	glRotatef(90.0,1,0,0);
	cilindro_rueda.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
	glPopMatrix();

}

_oruga_completa::_oruga_completa(){

};

void _oruga_completa::draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor){

	////////////oruga horizontal
	glPushMatrix();
	glTranslatef(0,2.5,0);
	oruga_horizontal_1.draw(modo, r1, g1, b1, r2, g2, b2, grosor);  ///////parte de arriba
	glPopMatrix();
//////////////////////////
	glPushMatrix();
	glTranslatef(0,-2.5,0);
	oruga_horizontal_2.draw(modo, r1, g1, b1, r2, g2, b2, grosor);  //////parte de abajo
	glPopMatrix();

	//////////////////oruga vertical

	glPushMatrix();
	glTranslatef(-11.5,0,0);
	oruga_vertical_1.draw(modo, r1, g1, b1, r2, g2, b2, grosor);  //////izquierda
	glPopMatrix();


	////////////////

	glPushMatrix();
	glTranslatef(11.5,0,0);
	oruga_vertical_2.draw(modo, r1, g1, b1, r2, g2, b2, grosor);  //////derecha
	glPopMatrix();

	/////////////ruedas oruga

	glPushMatrix();
	glTranslatef(-10,0,0);
	ruedas_tank_1.draw(modo, r1, g1, b1, r2, g2, b2, grosor);  /////izquierda
	glPopMatrix();
	//////////////////////////////////////////////////
	glPushMatrix();
	glTranslatef(10,0,0);
	ruedas_tank_1.draw(modo, r1, g1, b1, r2, g2, b2, grosor);  /////derecha
	glPopMatrix();
	////////////////////////

	glPushMatrix();
	glTranslatef(-8,0,0);
	ruedas_tank_1.draw(modo, r1, g1, b1, r2, g2, b2, grosor);  /////izquierda
	glPopMatrix();

	glPushMatrix();
	glTranslatef(8,0,0);
	ruedas_tank_1.draw(modo, r1, g1, b1, r2, g2, b2, grosor);  /////izquierda
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-6,0,0);
	ruedas_tank_1.draw(modo, r1, g1, b1, r2, g2, b2, grosor);  /////izquierda
	glPopMatrix();

	glPushMatrix();
	glTranslatef(6,0,0);
	ruedas_tank_1.draw(modo, r1, g1, b1, r2, g2, b2, grosor);  /////izquierda
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-4,0,0);
	ruedas_tank_1.draw(modo, r1, g1, b1, r2, g2, b2, grosor);  /////izquierda
	glPopMatrix();

	glPushMatrix();
	glTranslatef(4,0,0);
	ruedas_tank_1.draw(modo, r1, g1, b1, r2, g2, b2, grosor);  /////izquierda
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2,0,0);
	ruedas_tank_1.draw(modo, r1, g1, b1, r2, g2, b2, grosor);  /////izquierda
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2,0,0);
	ruedas_tank_1.draw(modo, r1, g1, b1, r2, g2, b2, grosor);  /////izquierda
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,0,0);
	ruedas_tank_1.draw(modo, r1, g1, b1, r2, g2, b2, grosor);  /////izquierda
	glPopMatrix();


}


_coraza_inclinada::_coraza_inclinada(){

};

void _coraza_inclinada::draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor){

	glPushMatrix();
	glScalef(7,5,16);
	glRotatef(90.0,0,1,0);
	corazainclinada.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
	glPopMatrix();

}


parte_exterior::parte_exterior(){

};

void parte_exterior::draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor){
	glPushMatrix();
	glScalef(3,3,16);

	exterior.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
	glPopMatrix();

}

_parte_central::_parte_central(){

};

void _parte_central::draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor){
	glPushMatrix();
	glScalef(11.5,5,16);
	//glRotatef(90.0,0,1,0);
	central.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
	glPopMatrix();

}




/////////////////////////////

_base_tanque_inferior::_base_tanque_inferior(){

};

void _base_tanque_inferior::draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor){

	glPushMatrix();
	glTranslatef(-7,7,0);
	inclinacion1.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,2,0);
	coraza.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,0,9);
	oruga_derecha.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,0,-9);
	oruga_izquierda.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(9.5,6,0);
	exterior1.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(2.25,7,0);
	central.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
	glPopMatrix();

}




/////////////CAÑON SEGUNDARIO


_canon_segundario::_canon_segundario(){
_vertex3f aux;
vector<_vertex3f> perfil2;
aux.x=1.0; aux.y=-1.0; aux.z=0.0;
perfil2.push_back(aux);
aux.x=1.0; aux.y=1.0; aux.z=0.0;
perfil2.push_back(aux);
cilindro_canon.parametros(perfil2,20,0);
};

void _canon_segundario::draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor){

	glPushMatrix();

	glTranslatef(-3,0,0);
	glRotatef(90.0,0,0,1);
	glScalef(0.5,3,0.5);

	cilindro_canon.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
	glPopMatrix();

}



/////////////////TORRETA SEGUNDARIA ARRIBA
_torreta_segundaria::_torreta_segundaria(){
_vertex3f aux;
vector<_vertex3f> perfil2;
aux.x=1.0; aux.y=-1.0; aux.z=0.0;
perfil2.push_back(aux);
aux.x=1.0; aux.y=1.0; aux.z=0.0;
perfil2.push_back(aux);
cilindro_torreta_segundaria.parametros(perfil2,20,1);
};

void _torreta_segundaria::draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor){

	glPushMatrix();
	glScalef(2,1,2);
	cilindro_torreta_segundaria.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
	glPopMatrix();

}


////////////////////TORRETA PRINCIPAL

_torreta_principal::_torreta_principal(){
_vertex3f aux;
vector<_vertex3f> perfil2;
aux.x=1.0; aux.y=-1.0; aux.z=0.0;
perfil2.push_back(aux);
aux.x=1.0; aux.y=1.0; aux.z=0.0;
perfil2.push_back(aux);
cilindro_torreta_principal.parametros(perfil2,20,1);
};

void _torreta_principal::draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor){

	glPushMatrix();
	glScalef(3,2.5,3);
	cilindro_torreta_principal.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
	glPopMatrix();

}

_tanque_final::_tanque_final(){

};

void _tanque_final::draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor){

	glPushMatrix();
	//////////////////////////////////////////////////////////////////////////////////////////////////////
	glTranslatef(2,10,0);

				glPushMatrix();

							glRotatef(zeta,0,1,0);
							//glTranslatef(0,3.5,0);
							torreta_montada.draw(modo, r1, g1, b1, r2, g2, b2, grosor); /////torreta_ principal la de abajo

							glPushMatrix();

												glRotatef(beta,0,1,0);
												glTranslatef(0,3.5,0); //prueba
												//glTranslatef(-1.9,0,0);
												segunda_torreta.draw(modo, r1, g1, b1, r2, g2, b2, grosor); //// torreta de ARRIBA

                        glTranslatef(-1.7,0,0); //prueba
												glPushMatrix();
																		glRotatef(alfa,0,0,1);

																		canon_segun.draw(modo, r1, g1, b1, r2, g2, b2, grosor);  //////canón SEGUNDARIO
												glPopMatrix();

							glPopMatrix();





				glPopMatrix();



	/////////////////////////////////////////////////////////////////////////////////////////////////////////

	glPopMatrix();

	glPushMatrix();
	base_del_tanque.draw(modo, r1, g1, b1, r2, g2, b2, grosor); ////////base del tanque
	glPopMatrix();

}
