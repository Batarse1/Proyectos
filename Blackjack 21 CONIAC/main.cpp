#include <iostream>
#include <time.h>
#include <string>
#include <stdlib.h>

using namespace std;

//estructura de carta
struct card{
    int number;
    int value;
    string name;
    card *next;
};

//funciones
void randomCard(card *&start,card *&aux,card *&start_global, double **ptr);
void showCards(card *&start,int cont,int &total);
bool verification(card *&start,int number);
void globalCards(card *&start,card *&aux,int num);
void cardValue(card *&new_card,double **ptr);
void wtl(int number1, int number2,string name);
void playerone(card *&start,int sum,int &option);
void crupier(card *&start,int sum,int &option);
void as(card *&start,int &option);
void sum(card *&start,int &total);
void verificationas(card *&start,bool &as);
double Ricky(int c,double **ptr);
double Alessandro(int c,double **ptr);
void Daniel(string &pal);

int main() {
    //inicializar variables
    card *start_dealer=NULL;
    card *aux_dealer=NULL;
    card *start_player1=NULL;
    card *aux_player1=NULL;
    card *start_player2=NULL;
    card *aux_player2=NULL;
    card *start_global=NULL;
    card *aux_global=NULL;
    string player1;
    string player2;
    srand(time(NULL));
    int players=0,option=0,option1=0,option2=1,option3=0,totalP1=0,totalP2=0,totalD=0,totalasP1=0,totalasp2=0,totalasD=0;
    bool as1,as2,as3,as4;
    double totalofcards[]={52,4,4,4,4,4,4,4,4,4,16,4};
    double *ptr1=totalofcards;
    double **ptr2=&ptr1;
    //
    menu:
    cout<<"\n______________________________________________________________________________________________________________________________________________"<<endl;
    cout<< "\tBLACKJACK 21"<<endl<<endl;
    cout<< "1. Jugar"<<endl;
    cout<< "2. Reglas"<<endl;
    cout<< "3. Salir"<<endl;
    cout<<"______________________________________________________________________________________________________________________________________________"<<endl;
    cout<< "Elija una opción: ";
    cin >> option;
    if(option==1){
    }
    else if(option==2){
        rules:
        cout<<"\n______________________________________________________________________________________________________________________________________________"<<endl;
        cout<<"\t REGLAS DE JUEGO"<<endl;
        cout<<"1. El objetivo principal del juego es vencer la mano del crupier(dealer) sin pasarse de 21."<<endl;
        cout<<"2. Las cartas del 2 al 10 valen lo que indica el número en la cara de la carta. "<<endl;
        cout<<"   Las cartas con figuras valen 10, a excepción del AS, que vale 1 u 11."<<endl;
        cout<<"3. Una vez inicia el juego cada jugador recibe dos cartas, y el crupier una."<<endl;
        cout<<"   Si se obtiene 21 con las primeras dos cartas, es un BlackJack"<<endl;
        cout<<"4. Cada jugador tiene 2 opciones, Pedir Carta ó Plantarse. Si un jugador se pasa de 21, este pierde automáticamente. "<<endl;
        cout<<"5. El turno del crupier solo empieza después de todos los jugadores. Si posee 16 o menos, debe pedir carta. Si tiene 17 o mas, debe plantarse. "<<endl;
        cout<<"6. Si el crupier y el jugador poseen el mismo puntaje, entonces es empate."<<endl;
        cout<<"7. Si el crupier y el jugador se pasan de 21, la casa gana."<<endl;
        cout<<endl;
        cout<<"*Durante el juego las probabilidades de obtener 21 serán desplegadas en pantalla para cada jugador."<<endl;
        cout<<"______________________________________________________________________________________________________________________________________________"<<endl;
        cout<<"Presione (1) para regresar: ";
        cin>>option;
        if(option!=1){
            cout<<"La opcion digitada es incorrecta"<<endl;
            goto rules;
        }
        else{
            cout<<endl;
            goto menu;
        }
    }
    else if(option==3){
        goto end;
    }
    else{
        cout<<"La opcion digitada es incorrecta"<<endl<<endl;
        goto menu;
    }

    //Ingreso de jugadores
    numberOfPlayers:
    cout<<"Digite el número de jugadores: ";cin>>players;
    if(players<1 or players>2){
        cout<<"Ingreso un número de jugadores invalido (Puede ser 1 jugador o 2 jugadores)"<<endl;
        goto numberOfPlayers;
    }

    //1 jugador
    if(players==1){
        //Ingreso de nombre
        cin.clear();cin.ignore(1000,'\n');
        cout<<"Digite el nombre del jugador: ";getline(cin,player1);cout<<endl;
        Daniel(player1);
        //Informacion del Jugador
        cout<<player1<<endl;

        //Fabricar 2 cartas jugador
        randomCard(start_player1,aux_player1,start_global,ptr2);
        globalCards(start_global,aux_global,aux_player1->number);
        randomCard(start_player1,aux_player1,start_global,ptr2);
        globalCards(start_global,aux_global,aux_player1->number);

        //Mostar cartas y sumatoria jugador
        showCards(start_player1,0,totalP1);
        playerone(start_player1,totalP1,option1);
        totalP1=0;
        sum(start_player1,totalP1);
        as1=0;
        verificationas(start_player1,as1);
        if(as1==true){
            cout<<"Sumatoria considernando un as como 1: "<<totalP1-10<<endl;
            cout<<"Sumatoria considernando todos los as como 11: "<<totalP1<<endl<<endl;
        }
        else{
            cout<<"Sumatoria: "<<totalP1<<endl<<endl;
        }


        //Mostrar informacion del crupier
        cout<<"CRUPIER "<<endl;

        //Fabricar 1 carta crupier
        randomCard(start_dealer,aux_dealer,start_global,ptr2);
        globalCards(start_global,aux_global,aux_dealer->number);

        //Mostar cartas y sumatoria crupier
        showCards(start_dealer,0,totalD);
        as1=0;
        verificationas(start_dealer,as1);
        if(as1==true){
            cout<<"Sumatoria considernando un as como 1: "<<totalD-10<<endl;
            cout<<"Sumatoria considernando todos los as como 11: "<<totalD<<endl<<endl;
        }
        else{
            cout<<"Sumatoria: "<<totalD<<endl<<endl;
        }
        cout<<"______________________________________________________________________________________________________________________________________________"<<endl;
        as1=0;
        verificationas(start_player1,as1);
        if(totalP1==21){
        }
        else if(as1==true){
            if((totalP1-10)<21){
                cout<<"Probabilidad de sacar 21 en la siguiente jugada considerando un as como 1 -> "<<Ricky(totalP1-10,ptr2)<<endl;
                cout<<"Probabilidad de sacar 21 en la siguiente jugada considerando todos los as como 11 -> "<<Ricky(totalP1,ptr2)<<endl;
                cout<<"Probabilidad de pasarse de 21 en la siguiente jugada considerando un as como 1 -> "<<Alessandro(totalP1-10,ptr2)<<endl;
                cout<<"Probabilidad de pasarse de 21 en la siguiente jugada considerando todos los as como 11 -> "<<Alessandro(totalP1,ptr2)<<endl;
            }
            else if(totalP1){
                cout<<"Probabilidad de sacar 21 en la siguiente jugada -> "<<Ricky(totalP1,ptr2)<<"%"<<endl;
                cout<<"Probabilidad de pasarse de 21 en la siguiente jugada -> "<<Alessandro(totalP1,ptr2)<<"%"<<endl;
            }
        }
        else if(totalP1<21){
            cout<<"Probabilidad de sacar 21 en la siguiente jugada -> "<<Ricky(totalP1,ptr2)<<"%"<<endl;
            cout<<"Probabilidad de pasarse de 21 en la siguiente jugada -> "<<Alessandro(totalP1,ptr2)<<"%"<<endl;
        }
        //Verificacion 1
        if(option1!=2){
            option:
            cout<<"1.Pedir carta"<<endl;
            cout<<"2.Quedarse"<<endl;
            cin>>option1;cout<<endl;
            if(option1!=1 and option1!=2){
                cout<<"Opcion invalida (Digite 1 o 2)"<<endl;
                goto option;
            }
        }

        //Iteracion para que el jugador siga pidiendo cartas
        while(option1==1){
            //Fabricar 1 carta jugador
            randomCard(start_player1,aux_player1,start_global,ptr2);
            globalCards(start_global,aux_global,aux_player1->number);

            //Informacion del jugador
            cout<<player1<<endl;

            //Mostar cartas y sumatoria jugador
            totalP1=0;
            showCards(start_player1,0,totalP1);
            playerone(start_player1,totalP1,option1);
            totalP1=0;
            sum(start_player1,totalP1);
            as1=0;
            verificationas(start_player1,as1);
            if(as1==true){
                cout<<"Sumatoria considernando un as como 1: "<<totalP1-10<<endl;
                cout<<"Sumatoria considernando todos los as como 11: "<<totalP1<<endl<<endl;
            }
            else{
                cout<<"Sumatoria: "<<totalP1<<endl<<endl;
            }

            //Mostar cartas y sumatoria crupier
            cout<<"CRUPIER"<<endl;
            totalD=0;
            showCards(start_dealer,0,totalD);
            as1=0;
            verificationas(start_dealer,as1);
            if(as1==true){
                cout<<"Sumatoria considernando un as como 1: "<<totalD-10<<endl;
                cout<<"Sumatoria considernando todos los as como 11: "<<totalD<<endl<<endl;
            }
            else{
                cout<<"Sumatoria: "<<totalD<<endl<<endl;
            }
            cout<<"______________________________________________________________________________________________________________________________________________"<<endl;
            as1=0;
            verificationas(start_player1,as1);
            if(totalP1==21){
            }
            else if(as1==true){
                if((totalP1-10)<21){
                    cout<<"Probabilidad de sacar 21 en la siguiente jugada considerando un as como 1 -> "<<Ricky(totalP1-10,ptr2)<<"%"<<endl;
                    cout<<"Probabilidad de sacar 21 en la siguiente jugada considerando todos los as como 11 -> "<<Ricky(totalP1,ptr2)<<"%"<<endl;
                    cout<<"Probabilidad de pasarse de 21 en la siguiente jugada considerando un as como 1 -> "<<Alessandro(totalP1-10,ptr2)<<"%"<<endl;
                    cout<<"Probabilidad de pasarse de 21 en la siguiente jugada considerando todos los as como 11 -> "<<Alessandro(totalP1,ptr2)<<"%"<<endl;
                }
                else if(totalP1){
                    cout<<"Probabilidad de sacar 21 en la siguiente jugada -> "<<Ricky(totalP1,ptr2)<<"%"<<endl;
                    cout<<"Probabilidad de pasarse de 21 en la siguiente jugada -> "<<Alessandro(totalP1,ptr2)<<"%"<<endl;
                }
            }
            else if(totalP1<21){
                cout<<"Probabilidad de sacar 21 en la siguiente jugada -> "<<Ricky(totalP1,ptr2)<<"%"<<endl;
                cout<<"Probabilidad de pasarse de 21 en la siguiente jugada -> "<<Alessandro(totalP1,ptr2)<<"%"<<endl;
            }
            //Preguntar al jugador
            if(option1!=2){
                option1:
                cout<<"1.Pedir carta"<<endl;
                cout<<"2.Quedarse"<<endl;
                cin>>option1;cout<<endl;
                if(option1!=1 and option1!=2){
                    cout<<"Opcion invalida (Digite 1 o 2)";
                    goto option1;
                }
            }
        }
        //Mostrar informacion, cartas y sumatoria del jugador 1
        cout<<player1<<endl;
        totalP1=0;
        showCards(start_player1,0,totalP1);
        as1=0;
        verificationas(start_player1,as1);
        if(as1==true){
            cout<<"Sumatoria considernando un as como 1: "<<totalP1-10<<endl;
            cout<<"Sumatoria considernando todos los as como 11: "<<totalP1<<endl<<endl;
        }
        else{
            cout<<"Sumatoria: "<<totalP1<<endl<<endl;
        }

        //Mostrar informacion del crupier
        cout<<endl<<"CRUPIER"<<endl;

        //Fabricar 1 carta para crupier
        randomCard(start_dealer,aux_dealer,start_global,ptr2);
        globalCards(start_global,aux_global,aux_dealer->number);
        totalD=0;

        //Mostrar cartas y sumatoria del crupier
        showCards(start_dealer,0,totalD);
        crupier(start_dealer,totalD,option2);
        totalD=0;
        sum(start_dealer,totalD);
        as1=0;
        verificationas(start_dealer,as1);
        if(as1==true){
            cout<<"Sumatoria considernando un as como 1: "<<totalD-10<<endl;
            cout<<"Sumatoria considernando todos los as como 11: "<<totalD<<endl<<endl;
        }
        else{
            cout<<"Sumatoria: "<<totalD<<endl<<endl;
        }
        cout<<"______________________________________________________________________________________________________________________________________________"<<endl;
        as1=0;
        verificationas(start_dealer,as1);
        if(totalD==21){
        }
        else if(as1==true){
            if((totalD-10)<21){
                cout<<"Probabilidad de que el crupier saque 21 en la siguiente jugada considerando un as como 1 -> "<<Ricky(totalD-10,ptr2)<<"%"<<endl;
                cout<<"Probabilidad de que el crupier saque 21 en la siguiente jugada considerando todos los as como 11 -> "<<Ricky(totalD,ptr2)<<"%"<<endl;
                cout<<"Probabilidad de que el crupier se pase de 21 en la siguiente jugada considerando un as como 1 -> "<<Alessandro(totalD-10,ptr2)<<"%"<<endl;
                cout<<"Probabilidad de que el crupier se pase de 21 en la siguiente jugada considerando todos los as como 11 -> "<<Alessandro(totalD,ptr2)<<"%"<<endl<<endl;
            }
            else if(totalD){
                cout<<"Probabilidad de que el crupier saque 21 en la siguiente jugada -> "<<Ricky(totalD,ptr2)<<"%"<<endl;
                cout<<"Probabilidad de que el crupier se pase de 21 en la siguiente jugada -> "<<Alessandro(totalD,ptr2)<<"%"<<endl<<endl;
            }
        }
        else if(totalD<21){
            cout<<"Probabilidad de que el crupier saque 21 en la siguiente jugada -> "<<Ricky(totalD,ptr2)<<"%"<<endl;
            cout<<"Probabilidad de que el crupier se pase de 21 en la siguiente jugada -> "<<Alessandro(totalD,ptr2)<<"%"<<endl<<endl;
        }
        //Iteracion para que el dealer llegue hasta 17 o más
        while(option2==1 and totalP1<=21){
            cout<<player1<<endl;
            totalP1=0;
            showCards(start_player1,0,totalP1);
            as1=0;
            verificationas(start_player1,as1);
            if(as1==true){
                cout<<"Sumatoria considernando un as como 1: "<<totalP1-10<<endl;
                cout<<"Sumatoria considernando todos los as como 11: "<<totalP1<<endl<<endl;
            }
            else{
                cout<<"Sumatoria: "<<totalP1<<endl<<endl;
            }
            cout<<endl<<"CRUPIER"<<endl;
            randomCard(start_dealer,aux_dealer,start_global,ptr2);
            globalCards(start_global,aux_global,aux_dealer->number);
            totalD=0;
            showCards(start_dealer,0,totalD);
            crupier(start_dealer,totalD,option2);
            totalD=0;
            sum(start_dealer,totalD);
            as1=0;
            verificationas(start_dealer,as1);
            if(as1==true){
                cout<<"Sumatoria considernando un as como 1: "<<totalD-10<<endl;
                cout<<"Sumatoria considernando todos los as como 11: "<<totalD<<endl<<endl;
            }
            else{
                cout<<"Sumatoria: "<<totalD<<endl<<endl;
            }
            cout<<"______________________________________________________________________________________________________________________________________________"<<endl;
            as1=0;
            verificationas(start_dealer,as1);
            if(totalD==21){
            }
            else if(as1==true){
                if((totalD-10)<21){
                    cout<<"Probabilidad de que el crupier saque 21 en la siguiente jugada considerando un as como 1 -> "<<Ricky(totalD-10,ptr2)<<"%"<<endl;
                    cout<<"Probabilidad de que el crupier saque 21 en la siguiente jugada considerando todos los as como 11 -> "<<Ricky(totalD,ptr2)<<"%"<<endl;
                    cout<<"Probabilidad de que el crupier se pase de 21 en la siguiente jugada considerando un as como 1 -> "<<Alessandro(totalD-10,ptr2)<<"%"<<endl;
                    cout<<"Probabilidad de que el crupier se pase de 21 en la siguiente jugada considerando todos los as como 11 -> "<<Alessandro(totalD,ptr2)<<"%"<<endl<<endl;
                }
                else if(totalD){
                    cout<<"Probabilidad de que el crupier saque 21 en la siguiente jugada -> "<<Ricky(totalD,ptr2)<<"%"<<endl;
                    cout<<"Probabilidad de que el crupier se pase de 21 en la siguiente jugada -> "<<Alessandro(totalD,ptr2)<<"%"<<endl<<endl;
                }
            }
            else if(totalD<21){
                cout<<"Probabilidad de que el crupier saque 21 en la siguiente jugada -> "<<Ricky(totalD,ptr2)<<"%"<<endl;
                cout<<"Probabilidad de que el crupier se pase de 21 en la siguiente jugada -> "<<Alessandro(totalD,ptr2)<<"%"<<endl<<endl;
            }
        }
        //Resultados del juego
        wtl(totalP1,totalD,player1);
    }

        //2 jugadores
    else{
        //Ingreso de nombres
        cin.clear();cin.ignore(1000,'\n');
        cout<<"Digite el nombre del jugador 1: ";getline(cin,player1);
        cout<<"Digite el nombre del jugador 2: ";getline(cin,player2);cout<<endl;
        Daniel(player1);
        Daniel(player2);
        //Mostrar informacion de jugador 1
        cout<<player1<<endl;

        //Fabricar 2 cartas para el jugador 1
        randomCard(start_player1,aux_player1,start_global,ptr2);
        globalCards(start_global,aux_global,aux_player1->number);
        randomCard(start_player1,aux_player1,start_global,ptr2);
        globalCards(start_global,aux_global,aux_player1->number);

        //Mostrar cartas y sumatoria del jugador 1
        totalP1=0;
        showCards(start_player1,0,totalP1);
        playerone(start_player1,totalP1,option1);
        totalP1=0;
        sum(start_player1,totalP1);
        as1=0;
        verificationas(start_player1,as1);
        if(as1==true){
            cout<<"Sumatoria considernando un as como 1: "<<totalP1-10<<endl;
            cout<<"Sumatoria considernando todos los as como 11: "<<totalP1<<endl<<endl;
        }
        else{
            cout<<"Sumatoria: "<<totalP1<<endl<<endl;
        }

        //Mostrar informacion del jugador 2
        cout<<player2<<endl;

        //Fabricar 2 cartas para el jugador 2
        randomCard(start_player2,aux_player2,start_global,ptr2);
        globalCards(start_global,aux_global,aux_player2->number);
        randomCard(start_player2,aux_player2,start_global,ptr2);
        globalCards(start_global,aux_global,aux_player2->number);

        //Mostrar cartas y sumatoria del jugador 2
        totalP2=0;
        showCards(start_player2,0,totalP2);
        playerone(start_player2,totalP2,option3);
        totalP2=0;
        sum(start_player2,totalP2);
        as1=0;
        verificationas(start_player2,as1);
        if(as1==true){
            cout<<"Sumatoria considernando un as como 1: "<<totalP2-10<<endl;
            cout<<"Sumatoria considernando todos los as como 11: "<<totalP2<<endl<<endl;
        }
        else{
            cout<<"Sumatoria: "<<totalP2<<endl<<endl;
        }

        //Mostrar informacion del crupier
        cout<<endl<<"CRUPIER"<<endl;

        //Fabricar 1 carta para el crupier
        randomCard(start_dealer,aux_dealer,start_global,ptr2);
        globalCards(start_global,aux_global,aux_dealer->number);

        //Mostar carta y sumatoria del crupier
        totalD=0;
        showCards(start_dealer,0,totalD);
        as1=0;
        verificationas(start_dealer,as1);
        if(as1==true){
            cout<<"Sumatoria considernando un as como 1: "<<totalD-10<<endl;
            cout<<"Sumatoria considernando todos los as como 11: "<<totalD<<endl<<endl;
        }
        else{
            cout<<"Sumatoria: "<<totalD<<endl<<endl;
        }
        cout<<"______________________________________________________________________________________________________________________________________________"<<endl;
        if(option1!=2){
            cout<<player1<<endl;
            as1=0;
            verificationas(start_player1,as1);
            if(totalP1==21){
            }
            else if(as1==true){
                if((totalP1-10)<21){
                    cout<<"Probabilidad de sacar 21 en la siguiente jugada considerando un as como 1 -> "<<Ricky(totalP1-10,ptr2)<<"%"<<endl;
                    cout<<"Probabilidad de sacar 21 en la siguiente jugada considerando todos los as como 11 -> "<<Ricky(totalP1,ptr2)<<"%"<<endl;
                    cout<<"Probabilidad de pasarse de 21 en la siguiente jugada considerando un as como 1 -> "<<Alessandro(totalP1-10,ptr2)<<"%"<<endl;
                    cout<<"Probabilidad de pasarse de 21 en la siguiente jugada considerando todos los as como 11 -> "<<Alessandro(totalP1,ptr2)<<"%"<<endl;
                }
                else if(totalP1){
                    cout<<"Probabilidad de sacar 21 en la siguiente jugada -> "<<Ricky(totalP1,ptr2)<<"%"<<endl;
                    cout<<"Probabilidad de pasarse de 21 en la siguiente jugada -> "<<Alessandro(totalP1,ptr2)<<"%"<<endl;
                }
            }
            else if(totalP1<21){
                cout<<"Probabilidad de sacar 21 en la siguiente jugada -> "<<Ricky(totalP1,ptr2)<<"%"<<endl;
                cout<<"Probabilidad de pasarse de 21 en la siguiente jugada -> "<<Alessandro(totalP1,ptr2)<<"%"<<endl;
            }
            option5:
            cout<<"1.Pedir carta"<<endl;
            cout<<"2.Quedarse"<<endl;
            cin>>option1;cout<<endl;
            if(option1!=1 and option1!=2){
                cout<<"Opcion invalida (Digite 1 o 2)";
                goto option5;
            }
        }

        while(option1==1){
            cout<<player1<<endl;

            randomCard(start_player1,aux_player1,start_global,ptr2);
            globalCards(start_global,aux_global,aux_player1->number);

            totalP1=0;
            showCards(start_player1,0,totalP1);
            playerone(start_player1,totalP1,option1);
            totalP1=0;
            sum(start_player1,totalP1);
            as1=0;
            verificationas(start_player1,as1);
            if(as1==true){
                cout<<"Sumatoria considernando un as como 1: "<<totalP1-10<<endl;
                cout<<"Sumatoria considernando todos los as como 11: "<<totalP1<<endl<<endl;
            }
            else{
                cout<<"Sumatoria: "<<totalP1<<endl<<endl;
            }

            cout<<player2<<endl;
            totalP2=0;
            showCards(start_player2,0,totalP2);
            playerone(start_player2,totalP2,option3);
            totalP2=0;
            sum(start_player2,totalP2);
            as1=0;
            verificationas(start_player2,as1);
            if(as1==true){
                cout<<"Sumatoria considernando un as como 1: "<<totalP2-10<<endl;
                cout<<"Sumatoria considernando todos los as como 11: "<<totalP2<<endl<<endl;
            }
            else{
                cout<<"Sumatoria: "<<totalP2<<endl<<endl;
            }

            cout<<endl<<"CRUPIER"<<endl;
            totalD=0;
            showCards(start_dealer,0,totalD);
            as1=0;
            verificationas(start_dealer,as1);
            if(as1==true){
                cout<<"Sumatoria considernando un as como 1: "<<totalD-10<<endl;
                cout<<"Sumatoria considernando todos los as como 11: "<<totalD<<endl<<endl;
            }
            else{
                cout<<"Sumatoria: "<<totalD<<endl<<endl;
            }
            cout<<"______________________________________________________________________________________________________________________________________________"<<endl;
            if(option1!=2){
                cout<<player1<<endl;
                as1=0;
                verificationas(start_player1,as1);
                if(totalP1==21){
                }
                else if(as1==true){
                    if((totalP1-10)<21){
                        cout<<"Probabilidad de sacar 21 en la siguiente jugada considerando un as como 1 -> "<<Ricky(totalP1-10,ptr2)<<"%"<<endl;
                        cout<<"Probabilidad de sacar 21 en la siguiente jugada considerando todos los as como 11 -> "<<Ricky(totalP1,ptr2)<<"%"<<endl;
                        cout<<"Probabilidad de pasarse de 21 en la siguiente jugada considerando un as como 1 -> "<<Alessandro(totalP1-10,ptr2)<<"%"<<endl;
                        cout<<"Probabilidad de pasarse de 21 en la siguiente jugada considerando todos los as como 11 -> "<<Alessandro(totalP1,ptr2)<<"%"<<endl;
                    }
                    else if(totalP1){
                        cout<<"Probabilidad de sacar 21 en la siguiente jugada -> "<<Ricky(totalP1,ptr2)<<"%"<<endl;
                        cout<<"Probabilidad de pasarse de 21 en la siguiente jugada -> "<<Alessandro(totalP1,ptr2)<<"%"<<endl;
                    }
                }
                else if(totalP1<21){
                    cout<<"Probabilidad de sacar 21 en la siguiente jugada -> "<<Ricky(totalP1,ptr2)<<"%"<<endl;
                    cout<<"Probabilidad de pasarse de 21 en la siguiente jugada -> "<<Alessandro(totalP1,ptr2)<<"%"<<endl;
                }

                option6:
                cout<<"1.Pedir carta"<<endl;
                cout<<"2.Quedarse"<<endl;
                cin>>option1;cout<<endl;
                if(option1!=1 and option1!=2){
                    cout<<"Opcion invalida (Digite 1 o 2)";
                    goto option6;
                }
            }
        }
        if(option3!=2){
            cout<<player2<<endl;
            as1=0;
            verificationas(start_player2,as1);
            if(totalP2==21){
            }
            else if(as1==true){
                if((totalP2-10)<21){
                    cout<<"Probabilidad de sacar 21 en la siguiente jugada considerando un as como 1 -> "<<Ricky(totalP2-10,ptr2)<<"%"<<endl;
                    cout<<"Probabilidad de sacar 21 en la siguiente jugada considerando todos los as como 11 -> "<<Ricky(totalP2,ptr2)<<"%"<<endl;
                    cout<<"Probabilidad de pasarse de 21 en la siguiente jugada considerando un as como 1 -> "<<Alessandro(totalP2-10,ptr2)<<"%"<<endl;
                    cout<<"Probabilidad de pasarse de 21 en la siguiente jugada considerando todos los as como 11 -> "<<Alessandro(totalP2,ptr2)<<"%"<<endl;
                }
                else if(totalP2){
                    cout<<"Probabilidad de sacar 21 en la siguiente jugada -> "<<Ricky(totalP2,ptr2)<<"%"<<endl;
                    cout<<"Probabilidad de pasarse de 21 en la siguiente jugada -> "<<Alessandro(totalP2,ptr2)<<"%"<<endl;
                }
            }
            else if(totalP2<21){
                cout<<"Probabilidad de sacar 21 en la siguiente jugada -> "<<Ricky(totalP2,ptr2)<<"%"<<endl;
                cout<<"Probabilidad de pasarse de 21 en la siguiente jugada -> "<<Alessandro(totalP2,ptr2)<<"%"<<endl;
            }
            option8:
            cout<<"1.Pedir carta"<<endl;
            cout<<"2.Quedarse"<<endl;
            cin>>option3;cout<<endl;
            if(option3!=1 and option3!=2){
                cout<<"Opcion invalida (Digite 1 o 2)";
                goto option8;
            }
        }
        while(option3==1){
            cout<<player1<<endl;

            randomCard(start_player2,aux_player2,start_global,ptr2);
            globalCards(start_global,aux_global,aux_player2->number);

            totalP1=0;
            showCards(start_player1,0,totalP1);
            playerone(start_player1,totalP1,option1);
            totalP1=0;
            sum(start_player1,totalP1);
            as1=0;
            verificationas(start_player1,as1);
            if(as1==true){
                cout<<"Sumatoria considernando un as como 1: "<<totalP1-10<<endl;
                cout<<"Sumatoria considernando todos los as como 11: "<<totalP1<<endl<<endl;
            }
            else{
                cout<<"Sumatoria: "<<totalP1<<endl<<endl;
            }

            cout<<player2<<endl;
            totalP2=0;
            showCards(start_player2,0,totalP2);
            playerone(start_player2,totalP2,option3);
            totalP2=0;
            sum(start_player2,totalP2);
            as1=0;
            verificationas(start_player2,as1);
            if(as1==true){
                cout<<"Sumatoria considernando un as como 1: "<<totalP2-10<<endl;
                cout<<"Sumatoria considernando todos los as como 11: "<<totalP2<<endl<<endl;
            }
            else{
                cout<<"Sumatoria: "<<totalP2<<endl<<endl;
            }

            cout<<endl<<"CRUPIER"<<endl;
            totalD=0;
            showCards(start_dealer,0,totalD);
            as1=0;
            verificationas(start_dealer,as1);
            if(as1==true){
                cout<<"Sumatoria considernando un as como 1: "<<totalD-10<<endl;
                cout<<"Sumatoria considernando todos los as como 11: "<<totalD<<endl<<endl;
            }
            else{
                cout<<"Sumatoria: "<<totalD<<endl<<endl;
            }
            cout<<"______________________________________________________________________________________________________________________________________________"<<endl;
            cout<<player2<<endl;
            if(option3!=2){
                as1=0;
                verificationas(start_player2,as1);
                if(totalP2==21){
                }
                else if(as1==true){
                    if((totalP2-10)<21){
                        cout<<"Probabilidad de sacar 21 en la siguiente jugada considerando un as como 1 -> "<<Ricky(totalP2-10,ptr2)<<"%"<<endl;
                        cout<<"Probabilidad de sacar 21 en la siguiente jugada considerando todos los as como 11 -> "<<Ricky(totalP2,ptr2)<<"%"<<endl;
                        cout<<"Probabilidad de pasarse de 21 en la siguiente jugada considerando un as como 1 -> "<<Alessandro(totalP2-10,ptr2)<<"%"<<endl;
                        cout<<"Probabilidad de pasarse de 21 en la siguiente jugada considerando todos los as como 11 -> "<<Alessandro(totalP2,ptr2)<<"%"<<endl;
                    }
                    else if(totalP2){
                        cout<<"Probabilidad de sacar 21 en la siguiente jugada -> "<<Ricky(totalP2,ptr2)<<"%"<<endl;
                        cout<<"Probabilidad de pasarse de 21 en la siguiente jugada -> "<<Alessandro(totalP2,ptr2)<<"%"<<endl;
                    }
                }
                else if(totalP2<21){
                    cout<<"Probabilidad de sacar 21 en la siguiente jugada -> "<<Ricky(totalP2,ptr2)<<"%"<<endl;
                    cout<<"Probabilidad de pasarse de 21 en la siguiente jugada -> "<<Alessandro(totalP2,ptr2)<<"%"<<endl;
                }
                option9:
                cout<<"1.Pedir carta"<<endl;
                cout<<"2.Quedarse"<<endl;
                cin>>option3;cout<<endl;
                if(option3!=1 and option3!=2){
                    cout<<"Opcion invalida (Digite 1 o 2)";
                    goto option9;
                }
            }
        }
        cout<<player1<<endl;
        totalP1=0;
        showCards(start_player1,0,totalP1);
        as1=0;
        verificationas(start_player1,as1);
        if(as1==true){
            cout<<"Sumatoria considernando un as como 1: "<<totalP1-10<<endl;
            cout<<"Sumatoria considernando todos los as como 11: "<<totalP1<<endl<<endl;
        }
        else{
            cout<<"Sumatoria: "<<totalP1<<endl<<endl;
        }

        cout<<player2<<endl;
        totalP2=0;
        showCards(start_player2,0,totalP2);
        playerone(start_player2,totalP2,option3);
        totalP2=0;
        sum(start_player2,totalP2);
        as1=0;
        verificationas(start_player2,as1);
        if(as1==true){
            cout<<"Sumatoria considernando un as como 1: "<<totalP2-10<<endl;
            cout<<"Sumatoria considernando todos los as como 11: "<<totalP2<<endl<<endl;
        }
        else{
            cout<<"Sumatoria: "<<totalP2<<endl<<endl;
        }

        cout<<endl<<"CRUPIER"<<endl;
        randomCard(start_dealer,aux_dealer,start_global,ptr2);
        globalCards(start_global,aux_global,aux_dealer->number);
        totalD=0;
        showCards(start_dealer,0,totalD);
        crupier(start_dealer,totalD,option2);
        totalD=0;
        sum(start_dealer,totalD);
        as1=0;
        verificationas(start_dealer,as1);
        if(as1==true){
            cout<<"Sumatoria considernando un as como 1: "<<totalD-10<<endl;
            cout<<"Sumatoria considernando todos los as como 11: "<<totalD<<endl<<endl;
        }
        else{
            cout<<"Sumatoria: "<<totalD<<endl<<endl;
        }
        cout<<"______________________________________________________________________________________________________________________________________________"<<endl;
        as1=0;
        verificationas(start_dealer,as1);
        if(totalD==21){
        }
        else if(as1==true){
            if((totalD-10)<21){
                cout<<"Probabilidad de que el crupier saque 21 en la siguiente jugada considerando un as como 1 -> "<<Ricky(totalD-10,ptr2)<<"%"<<endl;
                cout<<"Probabilidad de que el crupier saque 21 en la siguiente jugada considerando todos los as como 11 -> "<<Ricky(totalD,ptr2)<<"%"<<endl;
                cout<<"Probabilidad de que el crupier se pase de 21 en la siguiente jugada considerando un as como 1 -> "<<Alessandro(totalD-10,ptr2)<<"%"<<endl;
                cout<<"Probabilidad de que el crupier se pase de 21 en la siguiente jugada considerando todos los as como 11 -> "<<Alessandro(totalD,ptr2)<<"%"<<endl<<endl;
            }
            else if(totalD){
                cout<<"Probabilidad de que el crupier saque 21 en la siguiente jugada -> "<<Ricky(totalD,ptr2)<<"%"<<endl;
                cout<<"Probabilidad de que el crupier se pase de 21 en la siguiente jugada -> "<<Alessandro(totalD,ptr2)<<"%"<<endl<<endl;
            }
        }
        else if(totalD<21){
            cout<<"Probabilidad de que el crupier saque 21 en la siguiente jugada -> "<<Ricky(totalD,ptr2)<<"%"<<endl;
            cout<<"Probabilidad de que el crupier se pase de 21 en la siguiente jugada -> "<<Alessandro(totalD,ptr2)<<"%"<<endl<<endl;
        }
        while(option2==1){
            cout<<player1<<endl;
            totalP1=0;
            showCards(start_player1,0,totalP1);
            as1=0;
            verificationas(start_player1,as1);
            if(as1==true){
                cout<<"Sumatoria considernando un as como 1: "<<totalP1-10<<endl;
                cout<<"Sumatoria considernando todos los as como 11: "<<totalP1<<endl<<endl;
            }
            else{
                cout<<"Sumatoria: "<<totalP1<<endl<<endl;
            }

            cout<<player2<<endl;
            totalP2=0;
            showCards(start_player2,0,totalP2);
            playerone(start_player2,totalP2,option3);
            totalP2=0;
            sum(start_player2,totalP2);
            as1=0;
            verificationas(start_player2,as1);
            if(as1==true){
                cout<<"Sumatoria considernando un as como 1: "<<totalP2-10<<endl;
                cout<<"Sumatoria considernando todos los as como 11: "<<totalP2<<endl<<endl;
            }
            else{
                cout<<"Sumatoria: "<<totalP2<<endl<<endl;
            }

            cout<<endl<<"CRUPIER"<<endl;
            randomCard(start_dealer,aux_dealer,start_global,ptr2);
            globalCards(start_global,aux_global,aux_dealer->number);
            totalD=0;
            showCards(start_dealer,0,totalD);
            crupier(start_dealer,totalD,option2);
            totalD=0;
            sum(start_dealer,totalD);
            as1=0;
            verificationas(start_dealer,as1);
            if(as1==true){
                cout<<"Sumatoria considernando un as como 1: "<<totalD-10<<endl;
                cout<<"Sumatoria considernando todos los as como 11: "<<totalD<<endl<<endl;
            }
            else{
                cout<<"Sumatoria: "<<totalD<<endl<<endl;
            }
            cout<<"______________________________________________________________________________________________________________________________________________"<<endl;
            as1=0;
            verificationas(start_dealer,as1);
            if(totalD==21){
            }
            else if(as1==true){
                if((totalD-10)<21){
                    cout<<"Probabilidad de que el crupier saque 21 en la siguiente jugada considerando un as como 1 -> "<<Ricky(totalD-10,ptr2)<<"%"<<endl;
                    cout<<"Probabilidad de que el crupier saque 21 en la siguiente jugada considerando todos los as como 11 -> "<<Ricky(totalD,ptr2)<<"%"<<endl;
                    cout<<"Probabilidad de que el crupier se pase de 21 en la siguiente jugada considerando un as como 1 -> "<<Alessandro(totalD-10,ptr2)<<"%"<<endl;
                    cout<<"Probabilidad de que el crupier se pase de 21 en la siguiente jugada considerando todos los as como 11 -> "<<Alessandro(totalD,ptr2)<<"%"<<endl<<endl;
                }
                else if(totalD){
                    cout<<"Probabilidad de que el crupier saque 21 en la siguiente jugada -> "<<Ricky(totalD,ptr2)<<"%"<<endl;
                    cout<<"Probabilidad de que el crupier se pase de 21 en la siguiente jugada -> "<<Alessandro(totalD,ptr2)<<"%"<<endl<<endl;
                }
            }
            else if(totalD<21){
                cout<<"Probabilidad de que el crupier saque 21 en la siguiente jugada -> "<<Ricky(totalD,ptr2)<<"%"<<endl;
                cout<<"Probabilidad de que el crupier se pase de 21 en la siguiente jugada -> "<<Alessandro(totalD,ptr2)<<"%"<<endl<<endl;
            }
        }
        cout<<"RESULTADO DE "<<player1<<endl;
        wtl(totalP1,totalD,player1);
        cout<<"RESULTADO DE "<<player2<<endl;
        wtl(totalP2,totalD,player2);
    }
    end:
    return 0;
}

//Cola
void randomCard(card *&start,card *&aux,card *&start_global, double **ptr){
    card *new_card=new card();
    verification:
    new_card->number=1+rand()%52;
    if(verification(start_global,new_card->number)){
        goto verification;
    }
    cardValue(new_card,ptr);
    new_card->next=NULL;
    if(start==NULL){
        start=new_card;
    }
    else{
        aux->next=new_card;
    }
    aux=new_card;
}

void globalCards(card *&start,card *&aux,int num){

    card *new_card=new card();
    new_card->number=num;
    new_card->next=NULL;
    if(start==NULL){
        start=new_card;
    }
    else{
        aux->next=new_card;
    }
    aux=new_card;
}

//imprimir cola
void showCards(card *&start,int cont,int &total){
    if(start==NULL){
        return;
    }
    else{
        cont++;
        cout<<"Carta "<<cont<<": "<<start->name<<endl;
        total+=start->value;
        return showCards(start->next,cont,total);
    }
}

void sum(card *&start,int &total){
    if(start==NULL){
        return;
    }
    else{
        total+=start->value;
        return sum(start->next,total);
    }
}

bool verification(card *&start,int number){
    if(start==NULL){
        return false;
    }
    else if(start->number==number){
        return true;
    }
    else{
        return verification(start->next,number);
    }
}

void cardValue(card *&new_card,double **ptr){
    if(new_card->number==1){
        new_card->name="As de Corazones valor: +11 o +1";
        new_card->value=11;
        *(*ptr+0)=*(*ptr+0)-1;
        *(*ptr+1)=*(*ptr+1)-1;
        *(*ptr+11)=*(*ptr+11)-1;
    }
    else if(new_card->number==2){
        new_card->name="2 de Corazones valor: +2";
        new_card->value=2;
        *(*ptr+0)=*(*ptr+0)-1;
        *(*ptr+2)=*(*ptr+2)-1;
    }
    else if(new_card->number==3){
        new_card->name="3 de Corazones valor: +3";
        new_card->value=3;
        *(*ptr+0)=*(*ptr+0)-1;
        *(*ptr+3)=*(*ptr+3)-1;
    }
    else if(new_card->number==4){
        new_card->name="4 de Corazones valor: +4";
        new_card->value=4;
        *(*ptr+0)=*(*ptr+0)-1;
        *(*ptr+4)=*(*ptr+4)-1;
    }
    else if(new_card->number==5){
        new_card->name="5 de Corazones valor: +5";
        new_card->value=5;
        *(*ptr+0)=*(*ptr+0)-1;
        *(*ptr+5)=*(*ptr+5)-1;
    }
    else if(new_card->number==6){
        new_card->name="6 de Corazones valor: +6";
        new_card->value=6;
        *(*ptr+0)=*(*ptr+0)-1;
        *(*ptr+6)=*(*ptr+6)-1;
    }
    else if(new_card->number==7){
        new_card->name="7 de Corazones valor: +7";
        new_card->value=7;
        *(*ptr+0)=*(*ptr+0)-1;
        *(*ptr+7)=*(*ptr+7)-1;
    }
    else if(new_card->number==8){
        new_card->name="8 de Corazones valor: +8";
        new_card->value=8;
        *(*ptr+0)=*(*ptr+0)-1;
        *(*ptr+8)=*(*ptr+8)-1;
    }
    else if(new_card->number==9){
        new_card->name="9 de Corazones valor: +9";
        new_card->value=9;
        *(*ptr+0)=*(*ptr+0)-1;
        *(*ptr+9)=*(*ptr+9)-1;
    }
    else if(new_card->number==10){
        new_card->name="10 de Corazones valor: +10";
        new_card->value=10;
        *(*ptr+0)=*(*ptr+0)-1;
        *(*ptr+10)=*(*ptr+10)-1;
    }
    else if(new_card->number==11){
        new_card->name="J de Corazones valor: +10";
        new_card->value=10;
        *(*ptr+0)=*(*ptr+0)-1;
        *(*ptr+10)=*(*ptr+10)-1;
    }
    else if(new_card->number==12){
        new_card->name="Q de Corazones valor: +10";
        new_card->value=10;
        *(*ptr+0)=*(*ptr+0)-1;
        *(*ptr+10)=*(*ptr+10)-1;
    }
    else if(new_card->number==13){
        new_card->name="K de Corazones valor: +10";
        new_card->value=10;
        *(*ptr+0)=*(*ptr+0)-1;
        *(*ptr+10)=*(*ptr+10)-1;
    }
    else if(new_card->number==14){
        new_card->name="As de Diamantes valor: +11 o +1";
        new_card->value=11;
        *(*ptr+0)=*(*ptr+0)-1;
        *(*ptr+1)=*(*ptr+1)-1;
        *(*ptr+11)=*(*ptr+11)-1;
    }
    else if(new_card->number==15){
        new_card->name="2 de Diamantes valor: +2";
        new_card->value=2;
        *(*ptr+0)=*(*ptr+0)-1;
        *(*ptr+2)=*(*ptr+2)-1;
    }
    else if(new_card->number==16){
        new_card->name="3 de Diamantes valor: +3";
        new_card->value=3;
        *(*ptr+0)=*(*ptr+0)-1;
        *(*ptr+3)=*(*ptr+3)-1;
    }
    else if(new_card->number==17){
        new_card->name="4 de Diamantes valor: +4";
        new_card->value=4;
        *(*ptr+0)=*(*ptr+0)-1;
        *(*ptr+4)=*(*ptr+4)-1;
    }
    else if(new_card->number==18){
        new_card->name="5 de Diamantes valor: +5";
        new_card->value=5;
        *(*ptr+0)=*(*ptr+0)-1;
        *(*ptr+5)=*(*ptr+5)-1;
    }
    else if(new_card->number==19){
        new_card->name="6 de Diamantes valor: +6";
        new_card->value=6;
        *(*ptr+0)=*(*ptr+0)-1;
        *(*ptr+6)=*(*ptr+6)-1;
    }
    else if(new_card->number==20){
        new_card->name="7 de Diamantes valor: +7";
        new_card->value=7;
        *(*ptr+0)=*(*ptr+0)-1;
        *(*ptr+7)=*(*ptr+7)-1;
    }
    else if(new_card->number==21){
        new_card->name="8 de Diamantes valor: +8";
        new_card->value=8;
        *(*ptr+0)=*(*ptr+0)-1;
        *(*ptr+8)=*(*ptr+8)-1;
    }
    else if(new_card->number==22){
        new_card->name="9 de Diamantes valor: +9";
        new_card->value=9;
        *(*ptr+0)=*(*ptr+0)-1;
        *(*ptr+9)=*(*ptr+9)-1;
    }
    else if(new_card->number==23){
        new_card->name="10 de Diamantes valor: +10";
        new_card->value=10;
        *(*ptr+0)=*(*ptr+0)-1;
        *(*ptr+10)=*(*ptr+10)-1;
    }
    else if(new_card->number==24){
        new_card->name="J de Diamantes valor: +10";
        new_card->value=10;
        *(*ptr+0)=*(*ptr+0)-1;
        *(*ptr+10)=*(*ptr+10)-1;
    }
    else if(new_card->number==25){
        new_card->name="Q de Diamantes valor: +10";
        new_card->value=10;
        *(*ptr+0)=*(*ptr+0)-1;
        *(*ptr+10)=*(*ptr+10)-1;
    }
    else if(new_card->number==26){
        new_card->name="K de Diamantes valor: +10";
        new_card->value=10;
        *(*ptr+0)=*(*ptr+0)-1;
        *(*ptr+10)=*(*ptr+10)-1;
    }
    else if(new_card->number==27){
        new_card->name="As de Picas valor: +11 o +1";
        new_card->value=11;
        *(*ptr+0)=*(*ptr+0)-1;
        *(*ptr+1)=*(*ptr+1)-1;
        *(*ptr+11)=*(*ptr+11)-1;
    }
    else if(new_card->number==28){
        new_card->name="2 de Picas valor: +2";
        new_card->value=2;
        *(*ptr+0)=*(*ptr+0)-1;
        *(*ptr+2)=*(*ptr+2)-1;
    }
    else if(new_card->number==29){
        new_card->name="3 de Picas valor: +3";
        new_card->value=3;
        *(*ptr+0)=*(*ptr+0)-1;
        *(*ptr+3)=*(*ptr+3)-1;
    }
    else if(new_card->number==30){
        new_card->name="4 de Picas valor: +4";
        new_card->value=4;
        *(*ptr+0)=*(*ptr+0)-1;
        *(*ptr+4)=*(*ptr+4)-1;
    }
    else if(new_card->number==31){
        new_card->name="5 de Picas valor: +5";
        new_card->value=5;
        *(*ptr+0)=*(*ptr+0)-1;
        *(*ptr+5)=*(*ptr+5)-1;
    }
    else if(new_card->number==32){
        new_card->name="6 de Picas valor: +6";
        new_card->value=6;
        *(*ptr+0)=*(*ptr+0)-1;
        *(*ptr+6)=*(*ptr+6)-1;
    }
    else if(new_card->number==33){
        new_card->name="7 de Picas valor: +7";
        new_card->value=7;
        *(*ptr+0)=*(*ptr+0)-1;
        *(*ptr+7)=*(*ptr+7)-1;
    }
    else if(new_card->number==34){
        new_card->name="8 de Picas valor: +8";
        new_card->value=8;
        *(*ptr+0)=*(*ptr+0)-1;
        *(*ptr+8)=*(*ptr+8)-1;
    }
    else if(new_card->number==35){
        new_card->name="9 de Picas valor: +9";
        new_card->value=9;
        *(*ptr+0)=*(*ptr+0)-1;
        *(*ptr+9)=*(*ptr+9)-1;
    }
    else if(new_card->number==36){
        new_card->name="10 de Picas valor: +10";
        new_card->value=10;
        *(*ptr+0)=*(*ptr+0)-1;
        *(*ptr+10)=*(*ptr+10)-1;
    }
    else if(new_card->number==37){
        new_card->name="J de Picas valor: +10";
        new_card->value=10;
        *(*ptr+0)=*(*ptr+0)-1;
        *(*ptr+10)=*(*ptr+10)-1;
    }
    else if(new_card->number==38){
        new_card->name="Q de Picas valor: +10";
        new_card->value=10;
        *(*ptr+0)=*(*ptr+0)-1;
        *(*ptr+10)=*(*ptr+10)-1;
    }
    else if(new_card->number==39){
        new_card->name="K de Picas valor: +10";
        new_card->value=10;
        *(*ptr+0)=*(*ptr+0)-1;
        *(*ptr+10)=*(*ptr+10)-1;
    }
    else if(new_card->number==40 ){
        new_card->name="As de Treboles valor: +11 o +1";
        new_card->value=11;
        *(*ptr+0)=*(*ptr+0)-1;
        *(*ptr+1)=*(*ptr+1)-1;
        *(*ptr+11)=*(*ptr+11)-1;
    }
    else if(new_card->number==41){
        new_card->name="2 de Treboles valor: +2";
        new_card->value=2;
        *(*ptr+0)=*(*ptr+0)-1;
        *(*ptr+2)=*(*ptr+2)-1;
    }
    else if(new_card->number==42){
        new_card->name="3 de Treboles valor: +3";
        new_card->value=3;
        *(*ptr+0)=*(*ptr+0)-1;
        *(*ptr+3)=*(*ptr+3)-1;
    }
    else if(new_card->number==43){
        new_card->name="4 de Treboles valor: +4";
        new_card->value=4;
        *(*ptr+0)=*(*ptr+0)-1;
        *(*ptr+4)=*(*ptr+4)-1;
    }
    else if(new_card->number==44){
        new_card->name="5 de Treboles valor: +5";
        new_card->value=5;
        *(*ptr+0)=*(*ptr+0)-1;
        *(*ptr+5)=*(*ptr+5)-1;
    }
    else if(new_card->number==45){
        new_card->name="6 de Treboles valor: +6";
        new_card->value=6;
        *(*ptr+0)=*(*ptr+0)-1;
        *(*ptr+6)=*(*ptr+6)-1;
    }
    else if(new_card->number==46){
        new_card->name="7 de Treboles valor: +7";
        new_card->value=7;
        *(*ptr+0)=*(*ptr+0)-1;
        *(*ptr+7)=*(*ptr+7)-1;
    }
    else if(new_card->number==47){
        new_card->name="8 de Treboles valor: +8";
        new_card->value=8;
        *(*ptr+0)=*(*ptr+0)-1;
        *(*ptr+8)=*(*ptr+8)-1;
    }
    else if(new_card->number==48){
        new_card->name="9 de Treboles valor: +9";
        new_card->value=9;
        *(*ptr+0)=*(*ptr+0)-1;
        *(*ptr+9)=*(*ptr+9)-1;
    }
    else if(new_card->number==49){
        new_card->name="10 de Treboles valor: +10";
        new_card->value=10;
        *(*ptr+0)=*(*ptr+0)-1;
        *(*ptr+10)=*(*ptr+10)-1;
    }
    else if(new_card->number==50){
        new_card->name="J de Treboles valor: +10";
        new_card->value=10;
        *(*ptr+0)=*(*ptr+0)-1;
        *(*ptr+10)=*(*ptr+10)-1;
    }
    else if(new_card->number==51){
        new_card->name="Q de Treboles valor: +10";
        new_card->value=10;
        *(*ptr+0)=*(*ptr+0)-1;
        *(*ptr+10)=*(*ptr+10)-1;
    }
    else if(new_card->number==52){
        new_card->name="K de Treboles valor: +10";
        new_card->value=10;
        *(*ptr+0)=*(*ptr+0)-1;
        *(*ptr+10)=*(*ptr+10)-1;
    }
    return;
}

void wtl(int number1, int number2,string name){
    if(number1==number2 and number1<22){
        cout<<"EMPATE"<<endl;
    }
    else if(number1==21){
        cout<<"Gano: "<<name<<endl;
    }
    else if(number2==21){
        cout<<"Gano: CRUPIER"<<endl;
    }
    else if(number1<21 and number2<21){
        if(number1>number2){
            cout<<"Gano: "<<name<<endl;
        }
        else{
            cout<<"Gano: CRUPIER"<<endl;
        }
    }
    else if(number1>21 and number2>21){
        cout<<"Gano: CRUPIER"<<endl;
    }
    else if(number1<21 and number2>21){
        cout<<"Gano: "<<name<<endl;
    }
    else if(number1>21 and number2<21){
        cout<<"Gano: CRUPIER"<<endl;
    }
}

void playerone(card *&start,int sum,int &option){
    if(sum==21){
        option=2;
    }
    else if(sum>21){
        as(start,option);
    }
}

void as(card *&start,int &option){
    if(start==NULL){
        option=2;
        return;
    }
    else if((start->number==40 or start->number==27 or start->number==14 or start->number==1) and start->value==11){
        start->value=1;
        return;
    }
    else{
        return as(start->next,option);
    }
}

void verificationas(card *&start,bool &as){
    if(start==NULL){
        return ;
    }
    else if((start->number==40 or start->number==27 or start->number==14 or start->number==1) and start->value==11){
        as=true;
        return ;
    }
    else{
        return verificationas(start->next,as);
    }
}

void crupier(card *&start,int sum,int &option){
    if(sum<=21){
        if(sum<17){
            option=1;
            return;
        }
        else{
            option=2;
        }
    }
    else{
        as(start,option);
        return;
    }
}

double Ricky(int c,double **ptr){
    int d=0,x=0,y=0;
    double probabilidad, probabilidad_independiente1;
    d=21-c;
    if(d>11 or d<0){
        return 0;
    }
    else{
        probabilidad_independiente1=(*(*ptr+d)/ *(*ptr+0));
        probabilidad=probabilidad+probabilidad_independiente1;
        probabilidad=probabilidad*100;
        return probabilidad;
    }
}

double Alessandro(int c,double **ptr){
    double d,aux,suma,total;
    d=21-c;
    if(c<=11){
        return 0;
    }
    else{
        for (int i=1; i<11;i++){
            if (i>d){
                suma=suma+(*(*ptr+i)/ *(*ptr+0));
            }
        }
        suma=suma*100;
        return suma;
    }
}

void Daniel(string &pal){
    for (int i=0;i< pal.length();i++){
        pal[i]=towupper(pal[i]);
    };
}
