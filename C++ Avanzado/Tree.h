#pragma once

#include <iostream>

using namespace std;

typedef struct Nodo_1{
    char cadena[256];
    float decimal;
    int numero;
    Nodo_1 *der;
    Nodo_1 *izq;
}T;

class Tree{

private:
public:
    Tree(){
    }
    void insertarNodoLastName(T **arbol,char cadena[]){
        if(*arbol==NULL){
            T *aux = new T;
            for(int i=0;i<256;i++){
                aux->cadena[i] = cadena[i];
            }
            aux->decimal=0.0;
            aux->numero=0;
            aux->izq = NULL;
            aux->der = NULL;
            *arbol = aux;
        }
        else{
            if(comparar((*arbol)->cadena,cadena)){
                insertarNodoLastName(&(*arbol)->izq,cadena);
            }
            else{
                insertarNodoLastName(&(*arbol)->der,cadena);
            }
        }
    }
    void insertarNodoFirstName(T **arbol,char cadena[]){
        if(*arbol==NULL){
            T *aux = new T;
            for(int i=0;i<256;i++){
                aux->cadena[i] = cadena[i];
            }
            aux->decimal=0.0;
            aux->numero=0;
            aux->izq = NULL;
            aux->der = NULL;
            *arbol = aux;
        }
        else{
            if(comparar((*arbol)->cadena,cadena)){
                insertarNodoFirstName(&(*arbol)->izq,cadena);
            }
            else{
                insertarNodoFirstName(&(*arbol)->der,cadena);
            }
        }
    }
    void insertarNodoWeight(T **arbol,float weight){
        if(*arbol==NULL){
            T *aux = new T;
            for(int i=0;i<256;i++){
                aux->cadena[i] = '\0';
            }
            aux->decimal=weight;
            aux->numero=0;
            aux->izq = NULL;
            aux->der = NULL;
            *arbol = aux;
        }
        else{
            if(weight<=(*arbol)->decimal){
                insertarNodoWeight(&(*arbol)->izq,weight);
            }
            else{
                insertarNodoWeight(&(*arbol)->der,weight);
            }
        }
    }
    void insertarNodoHeight(T **arbol,float height){
        if(*arbol==NULL){
            T *aux = new T;
            for(int i=0;i<256;i++){
                aux->cadena[i] = '\0';
            }
            aux->decimal=height;
            aux->numero=0;
            aux->izq = NULL;
            aux->der = NULL;
            *arbol = aux;
        }
        else{
            if(height<=(*arbol)->decimal){
                insertarNodoHeight(&(*arbol)->izq,height);
            }
            else{
                insertarNodoHeight(&(*arbol)->der,height);
            }
        }
    }
    void insertarNodoAge(T **arbol,int age){
        if(*arbol==NULL){
            T *aux = new T;
            for(int i=0;i<256;i++){
                aux->cadena[i] = '\0';
            }
            aux->decimal=0;
            aux->numero=age;
            aux->izq = NULL;
            aux->der = NULL;
            *arbol = aux;
        }
        else{
            if(age<=(*arbol)->numero){
                insertarNodoAge(&(*arbol)->izq,age);
            }
            else{
                insertarNodoAge(&(*arbol)->der,age);
            }
        }
    }
    bool comparar(char p1[], char p2[]){
        for(int i=0;i<256;i++){
            if(p1[i]>p2[i]){
                return true;
            }
            else if(p1[i]<p2[i]){
                return false;
            }
        }
        return true;
    }
    void inorden(T *a){
        if(a!=NULL){
            inorden(a->izq);
            printf("%s ",a->cadena);
            inorden(a->der);
        }
    }
    void inordenf(T *a){
        if(a!=NULL){
            inordenf(a->izq);
            cout<<a->decimal<<" ";
            inordenf(a->der);
        }
    }
    void inordeni(T *a){
        if(a!=NULL){
            inordeni(a->izq);
            cout<<a->numero<<" ";
            inordeni(a->der);
        }
    }
};