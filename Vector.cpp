#include "Vector.h"
#include <iostream>
using namespace std;

///Vector

Vector::Vector(int el, int nr)
{
    this->dim=el;
    this->v=new int[dim];
	for(int i=0;i<dim;i++)
		v[i]=nr;
}

Vector::Vector(const Vector& Obj)
{
    this->dim=Obj.dim;
    this->v=new int[dim];
	for(int i=0;i<dim;i++)
		v[i]=Obj.v[i];
}

Vector::~Vector()
{
	dim=0;
	delete[]v;
}

Vector& Vector::operator=(const Vector& Obj)
{
	if (this == &Obj)
    {
		return *this;
	}
	dim=Obj.dim;
	delete[]v;
	v=new int[dim];
	for(int i=0;i<dim;i++)
		v[i]=Obj.v[i];
	return *this;
}

void Vector::reactualizare(int new_dim, int nr)
{
	dim=new_dim;
	delete[]v;
	v=new int[dim];
	for(int i=0;i<dim;i++)
		v[i]=nr;
}

istream& operator>>(istream& in, Vector& Obj)
{
	delete[]Obj.v;
	in>>Obj.dim;
	Obj.v=new int[Obj.dim];
	for(int i=0;i<Obj.dim;i++)
		in>>Obj.v[i];
	return in;
}

ostream& operator<<(ostream& out, const Vector& Obj)
{
	for(int i=0;i<Obj.dim;i++)
		out<<Obj.v[i]<<' ';
	return out;
}

///Vector_de_vectori

Vector_de_vectori::Vector_de_vectori(int el, int nr)
{
    this->dim=el;
    this->v=new Vector[dim];

	for(int i=0;i<dim;i++)
		v[i]=nr;
}


Vector_de_vectori::Vector_de_vectori(const Vector_de_vectori& Obj)
{
    this->dim=Obj.dim;
    this->v=new Vector[dim];
	for(int i=0;i<dim;i++)
		v[i]=Obj.v[i];
}

Vector_de_vectori::~Vector_de_vectori()
{
	dim=0;
	delete[]v;
}

Vector_de_vectori& Vector_de_vectori::operator=(const Vector_de_vectori& Obj)
{
	if (this == &Obj) {
		return *this;
	}
	dim=Obj.dim;
	delete[]v;
	v=new Vector[dim];
	for(int i=0;i<dim;i++)
		v[i]=Obj.v[i];
	return *this;
}

int Vector_de_vectori::get_dim()
{
	return dim;
}

int*** Vector_de_vectori::matrice()
{
	int*** mat=new int**[dim];
	mat[0]=new int*[dim];
	for(int i=0;i<dim;i++)
    {
		mat[0][i]=new int[dim];
		for(int j=0;j<v[i].dim;j++)
			mat[0][i][j]=v[i].v[j];
		for(int j=v[i].dim;j<dim;j++)
			mat[0][i][j]=0;
	}
	return mat;
}

istream& operator>>(istream& in, Vector_de_vectori& Obj)
{
	delete[]Obj.v;
	in>>Obj.dim;
	Obj.v=new Vector[Obj.dim];
	for(int i=0;i<Obj.dim;i++)
		in>>Obj.v[i];
	return in;
}

ostream& operator<<(ostream& out, const Vector_de_vectori& Obj)
{
	for(int i=0;i<Obj.dim;i++)
		out<<Obj.v[i]<<endl;
	return out;
}

