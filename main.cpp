#include <iostream>
#include <stdlib.h>
#include <string>
#include <conio.h>
using namespace std;
//NODO para la Pila
struct NodoP {
    char dato;
    NodoP *siguiente;
};
//Nodo para la Lista
struct NodoL {
    char dato;
    NodoL *siguiente;
};
//prototipo de funcion para la pila
void agregarPila(NodoP *&,char);
void sacarPila(NodoP *&,char &);
void mostrarPila(NodoP *);
//prototipos de funcion para la lista
void insertarLista(NodoL *&, char);
void mostrarlista(NodoL *);
    NodoL *inicio = NULL, *aux = NULL;
    NodoL *actual = NULL,*anterior = NULL;

int prioridadInfija(char);
int prioridadPila(char);
//FUNCION PRINCIPAL
int main(){
    NodoP *pila = NULL;	//Inicializamos pila
    NodoL *Lista = NULL; // se crea un puntero y se iguala a NULL

	char dato;
	string exp;
	cout << "INSERTA LA EXPRESION: " << endl;
	//cin.ignore();//limpiar el buffer
    getline(cin, exp);//se inserta la expresion
	cout << "\n" << exp << "\n";
	for(int i=0; i<exp.length(); i++){
        //si se encuentra un operador se va a la pila
        //si se encuentra un operando se va a la lista
        switch(exp[i]){
            case '+':
                if(pila == NULL){//es el primer caracter
                    agregarPila(pila,exp[i]);
                } else if(prioridadInfija(exp[i] > prioridadPila(exp[i]))){//mayor precedencia
                    sacarPila(pila,exp[i-1]);//sacamos el elemento anterior de la pila
                    insertarLista(Lista, exp[i-1]);//lo insertamos en la lista
                    agregarPila(pila, exp[i]);//agregamos el caracter a la pila
                }else if(prioridadInfija(exp[i]) <= prioridadPila(exp[i])){//igual o menor precedencia
                    while(pila != NULL || prioridadInfija(exp[i]) > prioridadPila(exp[i])){//vaciar nuestra pila hasta llegar al final o un operado de menor jerarquia
                        sacarPila(pila,exp[i-1]);//sacamos el elemento anterior de la pila
                        if(prioridadInfija(exp[i-1]) <= prioridadPila(exp[i-1])){
                            sacarPila(pila, exp[i-2]);
                            insertarLista(Lista, exp[i-2]);//lo insertamos en la lista
                            agregarPila(pila, exp[i-2]);//agregamos el caracter a la pila
                        }
                    }
                }else{
                    agregarPila(pila, exp[i]);
                }
                break;
            case '-':
                if(pila == NULL){//es el primer caracter
                    agregarPila(pila,exp[i]);
                } else if(prioridadInfija(exp[i] > prioridadPila(exp[i]))){//mayor precedencia
                    sacarPila(pila,exp[i-1]);//sacamos el elemento anterior de la pila
                    insertarLista(Lista, exp[i-1]);//lo insertamos en la lista
                    agregarPila(pila, exp[i]);//agregamos el caracter a la pila
                }else if(prioridadInfija(exp[i]) <= prioridadPila(exp[i])){//igual o menor precedencia
                    while(pila != NULL || prioridadInfija(exp[i]) > prioridadPila(exp[i])){//vaciar nuestra pila hasta llegar al final o un operado de menor jerarquia
                        sacarPila(pila,exp[i-1]);//sacamos el elemento anterior de la pila
                        if(prioridadInfija(exp[i-1]) <= prioridadPila(exp[i-1])){
                            sacarPila(pila, exp[i-2]);
                            insertarLista(Lista, exp[i-2]);//lo insertamos en la lista
                            agregarPila(pila, exp[i-2]);//agregamos el caracter a la pila
                        }
                    }
                }else{
                    agregarPila(pila, exp[i]);
                }
                break;
            case '/':
                if(pila == NULL){//es el primer caracter
                    agregarPila(pila,exp[i]);
                } else if(prioridadInfija(exp[i] > prioridadPila(exp[i]))){//mayor precedencia
                    sacarPila(pila,exp[i-1]);//sacamos el elemento anterior de la pila
                    insertarLista(Lista, exp[i-1]);//lo insertamos en la lista
                    agregarPila(pila, exp[i]);//agregamos el caracter a la pila
                }else if(prioridadInfija(exp[i]) <= prioridadPila(exp[i])){//igual o menor precedencia
                    while(pila != NULL || prioridadInfija(exp[i]) > prioridadPila(exp[i])){//vaciar nuestra pila hasta llegar al final o un operado de menor jerarquia
                        sacarPila(pila,exp[i-1]);//sacamos el elemento anterior de la pila
                        if(prioridadInfija(exp[i-1]) <= prioridadPila(exp[i-1])){
                            sacarPila(pila, exp[i-2]);
                            insertarLista(Lista, exp[i-2]);//lo insertamos en la lista
                            agregarPila(pila, exp[i-2]);//agregamos el caracter a la pila
                        }
                    }
                }else{
                    agregarPila(pila, exp[i]);
                }
                break;
            case '*':
                if(pila == NULL){//es el primer caracter
                    agregarPila(pila,exp[i]);
                } else if(prioridadInfija(exp[i] > prioridadPila(exp[i]))){//mayor precedencia
                    sacarPila(pila,exp[i-1]);//sacamos el elemento anterior de la pila
                    insertarLista(Lista, exp[i-1]);//lo insertamos en la lista
                    agregarPila(pila, exp[i]);//agregamos el caracter a la pila
                }
                if(prioridadInfija(exp[i]) <= prioridadPila(exp[i])){//igual o menor precedencia
                    while(pila != NULL || prioridadInfija(exp[i]) > prioridadPila(exp[i])){//vaciar nuestra pila hasta llegar al final o un operado de menor jerarquia
                        sacarPila(pila,exp[i-1]);//sacamos el elemento anterior de la pila
                        if(prioridadInfija(exp[i-1]) <= prioridadPila(exp[i-1])){
                            sacarPila(pila, exp[i-2]);
                            insertarLista(Lista, exp[i-2]);//lo insertamos en la lista
                            agregarPila(pila, exp[i-2]);//agregamos el caracter a la pila
                        }
                    }
                }else{
                    agregarPila(pila, exp[i]);
                }
                break;
            default:
                insertarLista(Lista, exp[i]);
                break;
        }// fin de switch
        cout << "Elemento: " << exp[i] << " insertado correctamente. " << endl;
	}
	//MOSTRANDO ELEMENTOS DE LA PILA
    cout << "\nMostrando los elementos de la pila: ";
    mostrarPila(pila);
	cout << endl;
	cout << "\nmostrando lista: ";
	mostrarlista(Lista);
    getch();
	return 0;
}

void agregarPila(NodoP *&pila,char n){
	NodoP *nuevo_nodo = new NodoP();
	nuevo_nodo->dato = n;
	nuevo_nodo->siguiente = pila;
	pila = nuevo_nodo;
}
void sacarPila(NodoP *&pila,char &n){
	NodoP *aux = pila;
	n = aux->dato;
	pila = aux->siguiente;
	delete aux;
}
void insertarLista(NodoL *&Lista, char n){
    actual=inicio;
	if(actual==NULL){
			aux=new NodoL();
			aux->dato=n;
			aux->siguiente=NULL;
			inicio=aux;
	}else{
		while(actual->siguiente!=NULL){
			actual=actual->siguiente;
        }
		aux=new NodoL();
		aux->dato=n;
		aux->siguiente=NULL;
		actual->siguiente=aux;
	}
}
void mostrarlista(NodoL *Lista){
    actual=inicio;
	while(actual!=NULL){
		cout << actual->dato << " ";
		actual=actual->siguiente;
	}
	cout<<"\n";
}
void mostrarPila(NodoP *pila){
    char dato;
    while(pila != NULL){
		sacarPila(pila,dato);
		if(pila != NULL){
			cout << dato << " ";
		}
		else{
			cout<<dato;
		}
	}
}

int prioridadInfija(char a){
    if(a=='^')
        return 4;
    if( a=='*')
        return 2;
    if( a=='/')
        return 2;
    if( a=='+')
        return 1;
    if( a=='-')
        return 1;
    if(a=='(')
        return 5;
}
int prioridadPila(char a){
    if(a=='^')
        return 3;
    if( a=='*')
        return 2;
    if( a=='/')
        return 2;
    if( a=='+')
        return 1;
    if( a=='-')
        return 1;
    if(a=='(')
        return 0;
}

