//**************************************************************************
// Práctica 1 usando objetos
//**************************************************************************

#include <vector>
#include <GL/gl.h>
#include "vertex.h"
#include <stdlib.h>
#include "file_ply_stl.hpp"

using namespace std;

const float AXIS_SIZE=5000;
typedef enum{POINTS,EDGES,SOLID_CHESS,SOLID} _modo;

//*************************************************************************
// clase punto
//*************************************************************************

class _puntos3D
{
public:


	_puntos3D();
void 	draw_puntos(float r, float g, float b, int grosor);

vector<_vertex3f> vertices;
};

//*************************************************************************
// clase triángulo
//*************************************************************************

class _triangulos3D: public _puntos3D
{
public:

	_triangulos3D();
void 	draw_aristas(float r, float g, float b, int grosor);
void  draw_solido(float r, float g, float b,bool pintarInteraccion=false, vector<bool> espintado={});
void 	draw_solido_ajedrez(float r1, float g1, float b1, float r2, float g2, float b2);
void 	draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor,bool pintarInteraccion=false,vector<bool> espintado ={});
vector<_vertex3i> caras;
};


//*************************************************************************
// clase cubo
//*************************************************************************

class _cubo: public _triangulos3D
{
public:
	vector<bool> espintado={false,false,false,false,false,false,false,false,false,false,false,false};
	_cubo(float tam=0.5);
};

class _triangulo: public _triangulos3D
{
public:

	_triangulo(float tam=0.5);
};


//*************************************************************************
// clase piramide
//*************************************************************************

class _piramide: public _triangulos3D
{
public:

	_piramide(float tam=0.5, float al=0.75);
};

//*************************************************************************
// clase objeto ply
//*************************************************************************

class _objeto_ply: public _triangulos3D
{
public:
   _objeto_ply();

int   parametros(char *archivo);
};

//************************************************************************
// objeto por revolución
//************************************************************************

class _rotacion: public _triangulos3D
{
public:
       _rotacion();
void  parametros(vector<_vertex3f> perfil1, int num1, int tapas);

vector<_vertex3f> perfil;
int num;
};


//************************************************************************
// objeto articulado: tanque
//************************************************************************

class _chasis: public _triangulos3D
{
public:
       _chasis();
void 	draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor,bool pintarInteraccion=false);

float altura;

protected:
_rotacion  rodamiento;
_cubo  base;
};

//************************************************************************

class _torreta: public _triangulos3D
{
public:
       _torreta();
void 	draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor,bool pintarInteraccion=false);

float altura;
float anchura;

protected:
_cubo  base;
_piramide parte_trasera;
};

//************************************************************************

class _tubo: public _triangulos3D
{
public:
       _tubo();
void 	draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor,bool pintarInteraccion=false);

protected:
_rotacion tubo_abierto; // caña del cañón
};

//************************************************************************

class _tanque: public _triangulos3D
{
public:
       _tanque();
void 	draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor,bool pintarInteraccion=false);

float giro_tubo;
float giro_torreta;

float giro_tubo_min;
float giro_tubo_max;

protected:
_chasis  chasis;
_torreta  torreta;
_tubo     tubo;
};



class _coraza_exterior: public _triangulos3D
{
public:
       _coraza_exterior();
       void 	draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor,bool pintarInteraccion=false);
			 bool pintar=false;
			 bool triangulopintado=false;

       _cubo  baseinterior;

};

class _oruga_horizontal: public _triangulos3D
{
public:
       _oruga_horizontal();
       void 	draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor,bool pintarInteraccion=false);
			 bool pintar=false;

       _cubo  base;

};

class _oruga_vertical: public _triangulos3D
{
public:
       _oruga_vertical();
       void 	draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor,bool pintarInteraccion=false);
			 bool pintar=false;

       _cubo  base;

};

class _ruedas_tank: public _triangulos3D
{
public:
       _ruedas_tank();
       void 	draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor,bool pintarInteraccion=false);
			 bool pintar=false;

       _rotacion cilindro_rueda;

};

class _oruga_completa: public _triangulos3D{

public:
       _oruga_completa();
       void 	draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor,bool pintarInteraccion=false);
			 bool pintar=false;

       _oruga_horizontal oruga_horizontal_1;
       _oruga_horizontal oruga_horizontal_2;
       _oruga_vertical oruga_vertical_1;
       _oruga_vertical oruga_vertical_2;
       _ruedas_tank ruedas_tank_1;

};


class _coraza_inclinada: public _triangulos3D{

public:
       _coraza_inclinada();
       void 	draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor,bool pintarInteraccion=false);
			 bool pintar=false;

      _triangulo corazainclinada;
};

class parte_exterior: public _triangulos3D{

public:
       parte_exterior();
       void 	draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor,bool pintarInteraccion=false);
			 bool pintar=false;

      _cubo exterior;
};


class _parte_central: public _triangulos3D{

public:
       _parte_central();
       void 	draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor,bool pintarInteraccion=false);
			 bool pintar=false;

      _cubo central;
};

class _base_tanque_inferior: public _triangulos3D{

public:
       _base_tanque_inferior();
       void 	draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor,bool pintarInteraccion=false);
			 bool pintar=false;

       _oruga_completa oruga_derecha;
       _oruga_completa oruga_izquierda;
       _coraza_exterior coraza;
			 _coraza_inclinada inclinacion1;
			 parte_exterior exterior1;
			 _parte_central central;
};


class _canon_segundario: public _triangulos3D
{
public:
       _canon_segundario();
       void 	draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor,bool pintarInteraccion=false);
			 float alfa=20; ///con esto gira
			 bool pintar=false;

       _rotacion cilindro_canon;
};




class _torreta_segundaria: public _triangulos3D
{
public:
       _torreta_segundaria();
       void 	draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor,bool pintarInteraccion=false);
			 float beta=90; ///con esto gira
			 bool pintar=false;

       _rotacion cilindro_torreta_segundaria;
			 _canon_segundario canon_segun;
};


class _torreta_principal: public _triangulos3D
{
public:
       _torreta_principal();
       void 	draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor,bool pintarInteraccion=false);
			 float zeta=0; ///con esto gira
			 bool pintar=false;

       _rotacion cilindro_torreta_principal;
			 _torreta_segundaria segunda_torreta;
			 _canon_segundario canon_segun;
};


class _tanque_final: public _triangulos3D
{
public:
       _tanque_final();
       void 	draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor,bool pintarInteraccion=false);
			 double alfa=0;
			 double beta=0;
			 double zeta=0;
			 int maximo_canon=15;
			 int minimo_canon=-15;
			 bool pintar=false;
			 double incr=0;//0.08;
			 _torreta_segundaria segunda_torreta;
			 _canon_segundario canon_segun;
			 _torreta_principal torreta_montada;
			 _base_tanque_inferior base_del_tanque;
};
