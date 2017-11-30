#include "capa.hpp"
#include "algoritmode.hpp"
//#include <ctime>
using namespace std;
int main(){
srand(5);
vector<double> sal;
vector<double> pez1;
vector<vector<double> > pez;
vector<int> topologia={4,4};
int elementos=33; 

vector<double> bl; vector<double> bu;
for(int i=0;i<33;i++){
  bl.push_back(0.0);
  bu.push_back(1.0);
}
EvolucionDif entrenamiento=EvolucionDif(20,20); //tamanio poblacion, generaciones
//entrenamiento.Algoritmo(bl,bu,1.3,0.7);
entrenamiento.IniciaPoblacion(bl,bu);
entrenamiento.Mutacion(1.3,bl,bu);
entrenamiento.Cruza(0.7);
entrenamiento.Seleccion();
entrenamiento.Elmejor();
cout<<"Su programa ha terminado"<<endl;
return 0;}
