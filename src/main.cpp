#include "capa.hpp"
//#include <ctime>
using namespace std;
int main(){
srand(5);
Capa micapa=Capa(5,3);
vector<double> pr1={2.1,4.3,5.4};
vector<double> pr2={.01,.1,.2,.3,.4,.5,.6,.7,.8,.9,.11,.22,.33,.44,.55,.2,.2,.2,.2,.2};
vector<double> sal;
vector<double> pez1;
vector<vector<double> > pez;
micapa.calcula_salidas(pr1);


vector<int> topologia; 
topologia.push_back(3);
topologia.push_back(5);
Rna minet=Rna(topologia,1,1);
minet.Prealimentacion(pr1);
vector<double> salred;
salred=minet.get_salida();
cout<<"Salida de red: "<<salred[0]<<endl;
sal=micapa.get_salidas();
pez=micapa.get_pesos();
pez1=micapa.get_pesosinvec();
cout<<"Neuronas: "<<micapa.get_neuronas()<<endl;
cout<<"Entradas: "<<micapa.get_entradas()<<endl;
for(int i=0;i<5;i++){
cout<<sal[i]<<endl;
}

for(int i=0;i<5;i++){
  for(int j=0;j<4;j++){
    cout<<pez[i][j]<<" ";
    //cout<<pez1[j*5+i]<<" ";
  }
  cout<<endl;
}
cout<<"Entra a cambiar pesos\n";
micapa.cambiar_pesos(pr2);
cout<<"Sale de cambiar pesos\n";
pez1=micapa.get_pesosinvec();
for(int i=0;i<5;i++){
  for(int j=0;j<4;j++){
    cout<<pez1[j*5+i]<<" ";
  }
  cout<<endl;
}cout<<"Su programa ha terminado"<<endl;
return 0;}
