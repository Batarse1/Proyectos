#pragma once

#include <iostream>
#include "Graph.h"
#include "Tree.h"

using namespace std;

class Interaction{
private:
    Graph gr;
    Tree tr;
    int numero_personas=0;
    int age=0;
    float weight=0.0;
    float height=0.0;
    char first_name[256];
    char last_name[256];
public:
    Interaction(){
    }
    void inicio(){
        gr.crear();
        bool verificar=false;
        while(verificar==false){
            verificar=true;
            cout<<"Digite el numero de personas:";
            cin>>numero_personas;
            if(numero_personas<0){
                verificar=false;
                cout<<"Numero de personas erroneo, ingrese otro dato"<<endl;
            }
        }
        for(int i=0;i<numero_personas;i++){
            insertar_nodo_last_name();
            insertar_nodo_weight();
            insertar_nodo_Height();
            insertar_nodo_first_name();
            insertar_nodo_ages();
        }
    }
    void insertar_nodo_last_name(){
        bool verificar=false;
        while(verificar==false){
            verificar=true;
            cout<<"Digite el primer apellido:";
            for(int i=0;i<256;i++){
                last_name[i]='\0';
            }
            scanf("%s",last_name);
            for(int i=0;i<256;i++){
                if(last_name[i]=='\0'){
                }
                else if(last_name[i]>='a' and last_name[i]<='z'){
                }
                else if(last_name[i]>='A' and last_name[i]<='Z'){
                }
                else{
                    cout<<"El apellido ingresado no es posible, ingrese otro"<<endl;
                    verificar=false;
                }
            }
        }
        tr.insertarNodoLastName(gr.buscarArbol(&gr.inicio,ONE),last_name);
    }
    void insertar_nodo_weight(){
        bool verificar=false;
        while(verificar==false){
            verificar=true;
            cout<<"Digite el peso en lb:";
            cin>>weight;
            if(weight<=0 or weight>=2000){
                cout<<"El peso ingresado no es posible, ingrese otro"<<endl;
                verificar=false;
            }
        }
        tr.insertarNodoWeight(gr.buscarArbol(&gr.inicio,TWO),weight);
    }
    void insertar_nodo_Height(){
        bool verificar=false;
        while(verificar==false){
            verificar=true;
            cout<<"Digite la altura en mt:";
            cin>>height;
            if(height<=0 or height>=3){
                cout<<"La altura ingresada no es posible, ingrese otra"<<endl;
                verificar=false;
            }
        }
        tr.insertarNodoHeight(gr.buscarArbol(&gr.inicio,THREE),height);
    }
    void insertar_nodo_first_name(){
        bool verificar=false;
        while(verificar==false){
            verificar=true;
            cout<<"Digite el primer nombre:";
            for(int i=0;i<256;i++){
                first_name[i]='\0';
            }
            scanf("%s",first_name);
            for(int i=0;i<256;i++){
                if(first_name[i]=='\0'){
                }
                else if(first_name[i]>='a' and first_name[i]<='z'){
                }
                else if(first_name[i]>='A' and first_name[i]<='Z'){
                }
                else{
                    cout<<"El nombre ingresado no es posible, ingrese otro"<<endl;
                    verificar=false;
                }
            }
        }
        tr.insertarNodoFirstName(gr.buscarArbol(&gr.inicio,FOUR),first_name);
    }
    void insertar_nodo_ages(){
        bool verificar=false;
        while(verificar==false){
            verificar=true;
            cout<<"Digite la edad en anios:";
            cin>>age;
            if(age<=0 or age>=150){
                cout<<"La edad ingresada no es posible, ingrese otra"<<endl;
                verificar=false;
            }
        }
        tr.insertarNodoAge(gr.buscarArbol(&gr.inicio,FIVE),age);
    }
    void final(){
        gr.recorrer();
    }
};