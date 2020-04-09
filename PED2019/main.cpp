#include <iostream>
#include <string>
#include <ctime>

using namespace std;

struct estudiante{
    string nombre;
    string apellido;
    string carne;
    int numlista;
    float calificacion;
};

void menu();
void odd_even_sort(estudiante arreglo[],int n);
void distribution_sort(estudiante arreglo[],int n);
void count_sort(estudiante arreglo[], int n);
void mostrar(estudiante arreglo[],int n);

int main(){
    int n=0,opcion=0;
    string carne=" ";
    numeroEstudiantes:
    cout<<"Digite el numero de estudiantes que quiere ingresar: ";cin>>n;
    if(n<=0){
        cout<<"numero invalido"<<endl;
        goto numeroEstudiantes;
    }
    estudiante estudiantes[n];
    for(int i=0;i<n;i++){
        cout<<"ESTUDIANTE "<<i+1<<endl;
        cout<<"Digite el primer nombre del estudiante : ";cin>>estudiantes[i].nombre;
        estudiantes[i].nombre.at(0)=toupper(estudiantes[i].nombre.at(0));
        cout<<"Digite el primer apellido del estudiante : ";cin>>estudiantes[i].apellido;
        estudiantes[i].apellido.at(0)=toupper(estudiantes[i].apellido.at(0));
        numeroCarne:
        cout<<"Digite el carne del estudiante : ";cin>>estudiantes[i].carne;
        if(estudiantes[i].carne.length()!=8){
            cout<<"Numero de carne invalido"<<endl;
            goto numeroCarne;
        }
        for(int j=0;j<i;j++){
            if(estudiantes[i].carne==estudiantes[j].carne){
            cout<<"Numero de carne invalido"<<endl;
            goto numeroCarne;  
            }
        }
        numeroLista:
        cout<<"Digite el numero de lista del estudiante : ";cin>>estudiantes[i].numlista;
        for(int j=0;j<i;j++){
            if(estudiantes[i].numlista==estudiantes[j].numlista){
            cout<<"Numero de carne invalido"<<endl;
            goto numeroLista;  
            }
        }
        numeroCalificacion:
        cout<<"Digite la calificacion del estudiante : ";cin>>estudiantes[i].calificacion;
        if(estudiantes[i].calificacion>10 or estudiantes[i].calificacion<0){
            cout<<"calificacion invalida"<<endl;
            goto numeroCalificacion;
        }
    }

    do{
        menu();
        cout<<"Digite su opcion: ";cin>>opcion;cout<<endl;
        if(opcion==0){
        }
        else if(opcion==1){
            odd_even_sort(estudiantes,n);
        }
        else if(opcion==2){
            distribution_sort(estudiantes,n);
        }
        else if(opcion==3){
            count_sort(estudiantes,n);
        }
        else{
            cout<<"Opcion invalida"<<endl;
        }
    }while(opcion!=0);

    return 0;
}

void menu(){
    cout<<endl<<"MENU PRINCIPAL"<<endl<<endl;
    cout<<"1.Ordenar por apellido"<<endl;
    cout<<"2.Ordenar por numero de lista"<<endl;
    cout<<"3.Ordenar por calificacion"<<endl;
    cout<<"0.Salir"<<endl<<endl;
    return;
}

void odd_even_sort(estudiante arreglo[],int n){
    clock_t tiempo = clock();
    bool ordenado=false;
    while(!ordenado){
        ordenado=true;
        for(int i=0;i<n-1; i=i+2){
            if(arreglo[i].apellido>arreglo[i+1].apellido){
                arreglo[i].nombre.swap(arreglo[i+1].nombre);
                arreglo[i].apellido.swap(arreglo[i+1].apellido);
                arreglo[i].carne.swap(arreglo[i+1].carne);
                swap(arreglo[i].numlista,arreglo[i+1].numlista);
                swap(arreglo[i].calificacion,arreglo[i+1].calificacion);
                ordenado=false;
            }
        }
        for(int i=1;i<n-1; i=i+2){
            if(arreglo[i].apellido>arreglo[i+1].apellido){
                arreglo[i].nombre.swap(arreglo[i+1].nombre);
                arreglo[i].apellido.swap(arreglo[i+1].apellido);
                arreglo[i].carne.swap(arreglo[i+1].carne);
                swap(arreglo[i].numlista,arreglo[i+1].numlista);
                swap(arreglo[i].calificacion,arreglo[i+1].calificacion);
                ordenado=false;
            }
        }
    }
    tiempo=clock()-tiempo;
    cout<<"Tiempo: "<<(float)tiempo/CLOCKS_PER_SEC<<endl<<endl;
    mostrar(arreglo,n);
}

void distribution_sort(estudiante arreglo[],int n){
    clock_t tiempo = clock();
    estudiante arreglonuevo[n];
    int mayor=arreglo[0].numlista;
    int menor=arreglo[0].numlista;
    int rango=0;
    for(int i=0;i<n;i++){
        if(arreglo[i].numlista>mayor){
            mayor=arreglo[i].numlista;
        }
        else if(arreglo[i].numlista<menor){
            menor=arreglo[i].numlista;
        }
    }
    rango=mayor-menor+1;
    int arregloaux[rango];
    for(int i=0;i<rango;i++){
        arregloaux[i]=0;
    }
    for(int i=0;i<n;i++){
        arregloaux[arreglo[i].numlista-menor]++;
    }
    for(int i=1;i<rango;i++){
        arregloaux[i]+=arregloaux[i-1];
    }
    for(int i=0;i<n;i++){
        arreglonuevo[arregloaux[arreglo[i].numlista-menor]-1].numlista=arreglo[i].numlista;
        arreglonuevo[arregloaux[arreglo[i].numlista-menor]-1].nombre=arreglo[i].nombre;
        arreglonuevo[arregloaux[arreglo[i].numlista-menor]-1].apellido=arreglo[i].apellido;
        arreglonuevo[arregloaux[arreglo[i].numlista-menor]-1].carne=arreglo[i].carne;
        arreglonuevo[arregloaux[arreglo[i].numlista-menor]-1].calificacion=arreglo[i].calificacion;
        arregloaux[arreglo[i].numlista-menor]--;
    }
    tiempo=clock()-tiempo;
    cout<<"Tiempo: "<<(float)tiempo/CLOCKS_PER_SEC<<endl<<endl;
    mostrar(arreglonuevo,n);
}

void count_sort(estudiante arreglo[], int n){
    clock_t tiempo = clock();
    int aux=0;
    int b[n];
    estudiante c[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if((arreglo[j].calificacion<arreglo[i].calificacion and i!=j) or (arreglo[j].calificacion==arreglo[i].calificacion and i<j)){
                aux++;
            }
        }
        b[i]=aux;
        aux=0;
    }
    for(int i=0;i<n;i++){
        c[b[i]].numlista=arreglo[i].numlista;
        c[b[i]].nombre=arreglo[i].nombre;
        c[b[i]].apellido=arreglo[i].apellido;
        c[b[i]].carne=arreglo[i].carne;
        c[b[i]].calificacion=arreglo[i].calificacion;
    }
    tiempo=clock()-tiempo;
    cout<<"Tiempo: "<<(float)tiempo/CLOCKS_PER_SEC<<endl<<endl;
    mostrar(c,n);
}

void mostrar(estudiante arreglo[],int n){
    for(int i=0;i<n;i++){
        cout<<"ESTUDIANTE "<<"#"<<arreglo[i].numlista<<endl;
        cout<<"Nombre: "<<arreglo[i].nombre<<endl;
        cout<<"Apellido: "<<arreglo[i].apellido<<endl;
        cout<<"Carne: "<<arreglo[i].carne<<endl;
        cout<<"Calificacion: "<<arreglo[i].calificacion<<endl<<endl;
    }
}