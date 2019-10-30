#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
using namespace std;

class Vector
{
	int dim;
	int *v;
public:
	friend class Vector_de_vectori;
	Vector(int dim=0, int nr=0);
	Vector(const Vector&);
	~Vector();
	Vector& operator=(const Vector&);
	///Vector operator*(const Vector&);
	void reactualizare(int new_dim=0, int nr=0);
	friend istream& operator>>(istream&, Vector&);
	friend ostream& operator<<(ostream&, const Vector&);
};

class Vector_de_vectori
{
	int dim;
	Vector* v;
public:
    friend class citire_si_afisare;
	Vector_de_vectori(int dim=0, int nr=0);
	Vector_de_vectori(const Vector_de_vectori&);
	~Vector_de_vectori();
	Vector_de_vectori& operator=(const Vector_de_vectori&);
	int get_dim();
	int*** matrice();
	friend istream& operator>>(istream&, Vector_de_vectori&);
	friend ostream& operator<<(ostream&, const Vector_de_vectori&);
};

class citire_si_afisare
{
   int n;
public:
   void cit(int n, istream& in, Vector_de_vectori **v)
   {
       if(v[0]!=nullptr)
       {delete[]v[0];}
       v[0]=new Vector_de_vectori[n];
       for(int i=0;i<n;i++)
       {
           in>>v[0][i];
       }
   }
   void afis(int n, ostream& out, Vector_de_vectori *v)
   {
       for(int i=0;i<n;i++)
       {
           out<<v[i]<<endl;
       }
   }
};

#endif
