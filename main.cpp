#include <iostream>
#include <fstream>
#include "Vector.h"
using namespace std;
ifstream f("date.in");

int main()
{
    int n;
    citire_si_afisare C;
    Vector_de_vectori *p=nullptr;
    f>>n;
    C.cit(n,f,&p);
    cout<<"Cele"<<" "<<n<<" "<<"elemente sunt:"<<endl;
    cout<<endl;
    C.afis(n,cout,p);
	return 0;
}
