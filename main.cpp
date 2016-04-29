#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
using namespace std;
ifstream fileR;
ofstream fileW;

struct registroFijo{
    char nombre [11];
    char genero;
    int edad;
};

struct registroVariable{
    char *nombre;
    char genero[1];
    int edad;
};

registroFijo regF;
registroVariable regV;

void leerVariable(int numReg){
    fileR.open("Variable.txt");
    int pos=0;
    for(int i=0; i<numReg;i++){
        int tam;
        fileR >> tam;
        regV.nombre=(char*)malloc(tam*sizeof(char));
        fileR.read(regV.nombre,tam);
        fileR >> tam;
        fileR.read(regV.genero,1);
        fileR >> regV.edad;
        pos=fileR.tellg();
        fileR.seekg((pos+1));
        cout << "Nombre : " << regV.nombre << "\nGenero: " << regV.genero << "\nEdad: " << regV.edad << " \n\n";
    }
    fileR.close();
}

void escribirVariable(string nombre, char genero, int edad){
    fileW.open("Variable.txt",std::ios::app);
    fileW << nombre.size();
    fileW << nombre;
    fileW << 1;
    fileW << genero;
    fileW << edad;
    fileW << "/";
    fileW.close();
}

void leerFijo(int numReg){
    fileR.open("Fijo.txt");
    for(int i=0; i<numReg;i++){
        fileR.read(regF.nombre,10);
        fileR >> regF.genero;
        fileR >> regF.edad;
        cout << "Nombre : " << regF.nombre << "\nGenero: " << regF.genero << "\nEdad: " << regF.edad << " \n\n";
    }
    fileR.close();
}

void escribirFijo(struct registroFijo regFP){
    fileW.open("Fijo.txt",std::ios::app);
    fileW << regFP.nombre;
    fileW << regFP.genero;
    fileW << regFP.edad;
    fileW.close();
}

int main(){
    leerVariable(2);
    escribirVariable("Pacheco",'M',22);
    leerFijo(2);
    registroFijo regFPM{"Pachecoxxx",'M',22};
    escribirFijo(regFPM);
}
