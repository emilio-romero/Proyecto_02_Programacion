#include "algoritmode.hpp"

/*Evolucion diferencial*/
//Constructores
EvolucionDif::EvolucionDif(int ts, int tt){
  individuos=ts;
  generaciones=tt;
}
EvolucionDif::~EvolucionDif(){

}
//Setters 
void EvolucionDif::set_datos(std::vector<double> entr, std::vector<double> dgt){
  dentrada=entr; 
  dground=dgt;
}

void EvolucionDif::set_red(std::vector<int> topo, int entr, int sali){
  arqred=topo; 
  inred=entr; 
  outred=sali;
}
//Getters

//Algoritmo 
void EvolucionDif::IniciaPoblacion(std::vector<double> bL, std::vector<double> bU){
  int n=bL.size();
  std::vector<double> aux;
  for(int i=0;i<individuos;i++){
    for(int j=0;j<n;j++){
      aux.push_back(randx()*(bU[j]-bL[j])+bL[j]);
    }
    poblacion.push_back(aux);
    aux.clear();
  }
}
void EvolucionDif::Mutacion(double F,std::vector<double> bL, std::vector<double> bU){
 std::vector<int> rs; 
 pmutada=poblacion; 
 int n=bL.size();
 for(int i=0;i<individuos;i++){
  rs=randperm();
  for(int j=0;j<n;j++){
    pmutada[i][j]=poblacion[rs[0]][j]+F*(poblacion[rs[1]][j]-poblacion[rs[2]][j]);
    if(pmutada[i][j]>bU[j] || pmutada[i][j]<bL[j]){
      pmutada[i][j]=randx()*(bU[j]-bL[j])+bL[j];
    }
  } 
 } 
}
void EvolucionDif::Cruza(double Cr){
  pcruzada=poblacion; 
  int n=poblacion[0].size();
  int rn; 
  for(int i=0;i<individuos;i++){
    for(int j=0;j<n;j++){
      rn=rand()%n;
      if(randx()<=Cr || rn==j){
        pcruzada[i][j]=pmutada[i][j];
      }
    }
  }
}
void EvolucionDif::Seleccion(){
  double xi,ui; 
  for(int i=0;i<individuos;i++){
    xi=fob(poblacion[i]);
    ui=fob(pcruzada[i]);
    #warning Seleccion: Revisar la comparacion de acuerdo a la fob
    if(ui>xi){
      poblacion[i]=pcruzada[i];
    }
  }
}
void EvolucionDif::Elmejor(){
  int b=0;
  double best=fob(poblacion[0]); 
  for(int i=1;i<individuos;i++){
    #warning Elmejor: Revisar la comparacion de acuerdo a la fob
    if(fob(poblacion[i])>best){
      b=i; 
      best=fob(poblacion[i]);
    }
  }
  mejor_individuo=poblacion[b];
}

double EvolucionDif::fob(std::vector<double> X){
  Rna prueba=Rna(arqred,inred,outred);
  prueba.cambiar_parametros(X); 
  int n=dentrada.size();
  std::vector<double> auxiliar;
  std::vector<double> me, mc;
  double tptn=0;
  for(int i=0;i<n;i++){
    auxiliar.push_back(dentrada[i]);
    prueba.Prealimentacion(auxiliar);
    me=prueba.get_salida();
    mc.push_back(dground[i]); 
    if(me[0]==mc[0]){
      tptn=tptn+1.0;
    }
    mc.clear();
    auxiliar.clear();
  }
  return(tptn/(double)n);
}

std::vector<double> EvolucionDif::Algoritmo(std::vector<double> bL,
std::vector<double> bU,double F,double Cr){
  IniciaPoblacion(bL,bU);
  for(int k=0;k<generaciones;k++){
    Mutacion(F,bL,bU);
    Cruza(Cr);
    Seleccion();
    Elmejor();
  }
  return(mejor_individuo);
}


/*Miscelanea*/
std::vector<int> EvolucionDif::randperm(){
  std::vector<int> aux; 
  aux.push_back(rand()%individuos);
  aux.push_back(aux[0]);
  aux.push_back(aux[0]);
  do{
    aux[1]=rand()%individuos;
    aux[2]=rand()%individuos;
  }while(aux[0]==aux[1] || aux[1]==aux[2] || aux[2]==aux[0]);
return(aux);
}




