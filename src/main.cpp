#include "capa.hpp"
//#include <ctime>
using namespace std;
int main(){
srand(5);
Capa micapa=Capa(5,3);
vector<double> pr1={2.1,4.3,5.4};
vector<double> pr2={.01,.1,.2,.3,.4,.5,.6,.7,.8,.9,.11,.22,.33,.44,.55,.2,.2,.2,.2,.2};
vector<double> pr3={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31};
vector<double> sal;
vector<double> pez1;
vector<vector<double> > pez;
cout<<"Neuronas: "<<micapa.get_neuronas()<<endl;
cout<<"Entradas: "<<micapa.get_entradas()<<endl;
micapa.calcula_salidas(pr1);


vector<int> topologia; 
topologia.push_back(3);
topologia.push_back(5);
Rna minet=Rna(topologia,1,1);
minet.Prealimentacion(pr1);
vector<double> salred;
salred=minet.get_parametros();
for(int i=0;i<32;i++){
  cout<<"Parametro "<<i<< " :"<<salred[i]<<endl;
}
minet.cambiar_parametros(pr3);
salred=minet.get_parametros();
for(int i=0;i<32;i++){
  cout<<"Parametro "<<i<< " :"<<salred[i]<<endl;
}
sal=micapa.get_salidas();
pez=micapa.get_pesos();
pez1=micapa.get_pesosinvec();

cout<<"Entra a cambiar pesos\n";
micapa.cambiar_pesos(pr2);
cout<<"Sale de cambiar pesos\n";
pez1=micapa.get_pesosinvec();
for(int i=0;i<5;i++){
  for(int j=0;j<4;j++){
    cout<<pez1[j*5+i]<<" ";
  }
  cout<<endl;
}
cout<<"Su programa ha terminado"<<endl;
return 0;}
