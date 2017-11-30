#include "capa.hpp"
#include "algoritmode.hpp"
#include "lectura.hpp"
//#include <ctime>
using namespace std;
int main(){
srand(42);
vector<int> topologia={4,4};
int elementos=33; 
vector<double> datos=readPgm("1.pgm");
vector<double> comparacion=readPgmgt("1gt.pgm");
vector<double> entrenado;
vector<double> bl; vector<double> bu;
for(int i=0;i<33;i++){
  bl.push_back(0.0);
  bu.push_back(1.0);
}

EvolucionDif entrenamiento=EvolucionDif(10,10); //tamanio poblacion, generaciones
entrenamiento.set_datos(datos,comparacion);
entrenamiento.set_red(topologia,1,1);
cout<<"Entra a entrenar"<<endl;
entrenado=entrenamiento.Algoritmo(bl,bu,1.3,0.7);
cout<<"Termino de entrenar"<<endl;

Rna segmentador=Rna(topologia,1,1);
segmentador.cambiar_parametros(entrenado);
vector<double> nuevos=segmentador.segmentar(datos);
vector<vector<double> > mat=cambia_tamanio(nuevos); 

writePgm(mat,"rpuesda.pgm");

cout<<"Su programa ha terminado"<<endl;
return 0;}
