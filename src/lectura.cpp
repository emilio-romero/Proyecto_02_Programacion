#include "lectura.hpp"

std::vector<double> readPgm(std::string pfile){
std::string valor; 
std::vector<double> auxiliar;
std::ifstream mifile; 
mifile.open(pfile);
std::getline(mifile,valor,'\n');
if(valor.compare("P2")!=0) std::cout<<"Error: archivo no valido"<<std::endl;
int nc,nr,gs;
std::getline(mifile,valor,' ');
  nc=atoi(valor.c_str());
  std::cout<<nc<<"\n";
std::getline(mifile,valor,'\n');
  nr=atoi(valor.c_str());
  std::cout<<nr<<"\n";
std::getline(mifile,valor,'\n');
  gs=atoi(valor.c_str());
  std::cout<<gs<<"\n";
/*for(int i=0;i<nr;i++){
  for(int j=0;j<nc-1;j++){
    std::getline(mifile,valor,' ');
    auxiliar.push_back(atof(valor.c_str()));
  }
  std::getline(mifile,valor,'\n');
  auxiliar.push_back(atof(valor.c_str()));
}*/
double a; 
  while(mifile >> a){
    auxiliar.push_back(a);
  }
mifile.close();
return(auxiliar);

}

std::vector<double> readPgmgt(std::string pfile){
std::string valor; 
int val; 
std::vector<double> auxiliar;
std::ifstream mifile; 
mifile.open(pfile);
std::getline(mifile,valor,'\n');
if(valor.compare("P2")!=0) std::cout<<"Error: archivo no valido"<<std::endl;
int nc,nr,gs;
std::getline(mifile,valor,' ');
  nc=atoi(valor.c_str());
std::getline(mifile,valor,' ');
  nr=atoi(valor.c_str());
std::getline(mifile,valor,'\n');
  gs=atoi(valor.c_str());
/*for(int i=0;i<nr;i++){
  for(int j=0;j<nc-1;j++){
    std::getline(mifile,valor,' ');
    if(atof(valor.c_str())<2){
      auxiliar.push_back(-1.0);
    }
    else{
      auxiliar.push_back(1.0);
    }
  }
  std::getline(mifile,valor,'\n');
  if(atof(valor.c_str())<2){
    auxiliar.push_back(-1.0);
  }
  else{
    auxiliar.push_back(1.0);
  }
}*/

double a; 
  while(mifile >> a){
    if(a<2){
      auxiliar.push_back(-1.0);
    }
    else{
      auxiliar.push_back(1.0);
    }
  }
mifile.close();
return(auxiliar);
}

std::vector<std::vector<double> > cambia_tamanio(std::vector<double> actual){
std::vector<std::vector<double> > auxiliar; 
  std::vector<double> aux; 
for(int i=0;i<300;i++){
  for(int j=0;j<300;j++){
    aux.push_back(actual[i*300+j]);
  }
  auxiliar.push_back(aux);
  aux.clear();
}
return(auxiliar);
}

int writePgm(std::vector<std::vector<double> > laimagen, std::string nombre){
  std::ofstream ofs (nombre,std::ofstream::out);
  ofs<<"P2\n";
  ofs<<"300 300\n255\n"; 
  for(int i=0;i<300;i++){
    for(int j=0;j<300;j++){
      ofs<<laimagen[i][j];
      ofs<<' ';
    }
    ofs<<'\n';
  }

  ofs.close();
}

