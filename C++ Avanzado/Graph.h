#pragma once

#include <iostream>
#include "Tree.h"

using namespace std;

enum Nodos {ONE,TWO,THREE,FOUR,FIVE};

typedef struct Nodo{
    Nodos id;
    T *raiz;
    Nodo *sig;
    Nodo *ady;
}G;

class Graph{
private:
    Tree tre;
    void insertarNodoGrafo(G **grafo,Nodos id){
        G *nodo_aux = new G;
        G *aux = new G;
        aux->id=id;
        aux->raiz=NULL;
        aux->sig=NULL;
        aux->ady=NULL;
        if(*grafo==NULL){
            *grafo=aux;
        }
        else{
            nodo_aux=*grafo;
            while(nodo_aux->sig!=NULL){
                nodo_aux = nodo_aux->sig;
            }
            nodo_aux->sig=aux;
        }
    }
    void insertarArista(G **grafo,Nodos n,Nodos m, T **raiz){
        if(*grafo==NULL){
        }
        else if((*grafo)->id==n){
            G *nodo_aux = new G;
            G *aux = new G;
            aux->id=m;
            aux->raiz=*raiz;
            aux->sig=NULL;
            aux->ady=NULL;
            nodo_aux=(*grafo);
            while(nodo_aux->ady!=NULL){
                nodo_aux=nodo_aux->ady;
            }
            nodo_aux->ady=aux;
        }
        else{
            insertarArista(&(*grafo)->sig,n,m,raiz);
        }
    }
    void mostrarGrafito(G **grafo){
        if(*grafo==NULL){
        }
        else{
            G *nodo_aux_sig = new G;
            G *nodo_aux_ady = new G;
            nodo_aux_ady=(*grafo);
            if(nodo_aux_ady->id==ONE){
                cout<<1;
            }
            else if(nodo_aux_ady->id==TWO){
                cout<<2;
            }
            else if(nodo_aux_ady->id==THREE){
                cout<<3;
            }
            else if(nodo_aux_ady->id==FOUR){
                cout<<4;
            }
            else if(nodo_aux_ady->id==FIVE){
                cout<<5;
            }

            cout<<" ";
            while(nodo_aux_ady->ady!=NULL){
                nodo_aux_ady=nodo_aux_ady->ady;
                if(nodo_aux_ady->id==ONE){
                    cout<<1;
                }
                else if(nodo_aux_ady->id==TWO){
                    cout<<2;
                }
                else if(nodo_aux_ady->id==THREE){
                    cout<<3;
                }
                else if(nodo_aux_ady->id==FOUR){
                    cout<<4;
                }
                else if(nodo_aux_ady->id==FIVE){
                    cout<<5;
                }
                cout<<" ";
            }
            cout<<endl;
            mostrarGrafito(&(*grafo)->sig);
        }
    }
public:
    G *inicio;
    Graph(){
        inicio=NULL;
    }
    void crear(){
        insertarNodoGrafo(&inicio,ONE);
        insertarNodoGrafo(&inicio,TWO);
        insertarNodoGrafo(&inicio,THREE);
        insertarNodoGrafo(&inicio,FOUR);
        insertarNodoGrafo(&inicio,FIVE);

    }
    T** buscarArbol(G **grafo,Nodos id){
        if(grafo==NULL){
            return NULL;
        }
        else if((*grafo)->id==id){
            return &((*grafo)->raiz);
        }
        else{
            return buscarArbol(&((*grafo)->sig), id);
        }
    }
    void recorrer(){
        insertarArista(&inicio,ONE,TWO,buscarArbol(&inicio,TWO));
        insertarArista(&inicio,ONE,FOUR,buscarArbol(&inicio,FOUR));
        insertarArista(&inicio,ONE,FIVE,buscarArbol(&inicio,FIVE));
        insertarArista(&inicio,TWO,ONE,buscarArbol(&inicio,ONE));
        insertarArista(&inicio,TWO,THREE,buscarArbol(&inicio,THREE));
        insertarArista(&inicio,TWO,FIVE,buscarArbol(&inicio,FIVE));
        insertarArista(&inicio,THREE,TWO,buscarArbol(&inicio,TWO));
        insertarArista(&inicio,THREE,FOUR,buscarArbol(&inicio,FOUR));
        insertarArista(&inicio,THREE,FIVE,buscarArbol(&inicio,FIVE));
        insertarArista(&inicio,FOUR,ONE,buscarArbol(&inicio,ONE));
        insertarArista(&inicio,FOUR,THREE,buscarArbol(&inicio,THREE));
        insertarArista(&inicio,FOUR,FIVE,buscarArbol(&inicio,FIVE));
        insertarArista(&inicio,FIVE,ONE,buscarArbol(&inicio,ONE));
        insertarArista(&inicio,FIVE,TWO,buscarArbol(&inicio,TWO));
        insertarArista(&inicio,FIVE,THREE,buscarArbol(&inicio,THREE));
        insertarArista(&inicio,FIVE,FOUR,buscarArbol(&inicio,FOUR));
        recorrerAux(&inicio,0);
    }
    void recorrerAux(G** grafo,int cont){
        if((*grafo)==NULL){
        }
        else{
            cont++;
            cout<<"Se encuentra en el NODO "<<cont<<endl;
            G* ptemp=(*grafo);
            int contAux=0;
            while(ptemp!=NULL){
                if(ptemp->id==ONE){
                    if(contAux==1){
                        cout<<"NODO 1"<<endl;
                    }
                    tre.inorden(ptemp->raiz);
                }
                else if(ptemp->id==TWO){
                    if(contAux==1){
                        cout<<"NODO 2"<<endl;
                    }
                    tre.inordenf(ptemp->raiz);
                }
                else if(ptemp->id==THREE){
                    if(contAux==1){
                        cout<<"NODO 3"<<endl;
                    }
                    tre.inordenf(ptemp->raiz);
                }
                else if(ptemp->id==FOUR){
                    if(contAux==1){
                        cout<<"NODO 4"<<endl;
                    }
                    tre.inorden(ptemp->raiz);
                }
                else if(ptemp->id==FIVE){
                    if(contAux==1){
                        cout<<"NODO 5"<<endl;
                    }
                    tre.inordeni(ptemp->raiz);
                }
                cout<<endl;
                if(contAux==0){
                    cout<<"Este nodo esta enlazado con los siguientes nodos: "<<endl;
                    contAux=1;
                }
                ptemp=ptemp->ady;
            }
            cout<<endl;
            recorrerAux(&((*grafo)->sig),cont);
        }
    }
};