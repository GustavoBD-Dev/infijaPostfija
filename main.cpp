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
char sacarPila(NodoP *&);
void mostrarPila(NodoP *);
void mostrarNodos(NodoP *&);
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
    char precedenciaPila;
	char dato, c;
	string exp;
	cout << "INSERTA LA EXPRESION: ";
	//cin.ignore();//limpiar el buffer
    getline(cin, exp);//se inserta la expresion
    //exp = pI + exp + pF;
	cout << "\nEXPRESION INFIJA: " << exp << "\n";
	for(int i=0; i<exp.length(); i++){
        //si se encuentra un operador se va a la pila
        //si se encuentra un operando se va a la lista
        switch(exp[i]){
            case '+':
                if(pila == NULL){//es el primer caracter
                    agregarPila(pila,exp[i]);
                }else{
                    if(prioridadInfija(exp[i]) > prioridadPila(pila->dato)){//prioridad de operadores
                        agregarPila(pila, exp[i]);
                    }else{
                        if(prioridadInfija(exp[i]) == prioridadPila(pila->dato)){
                            //vaciar nuestra pila hasta llegar al final o un operado de menor jerarquia
                          //  while(prioridadInfija(exp[i]) < prioridadPila(pila->dato)){
                                c = sacarPila(pila);//sacamos el elemento anterior de la pila
                                insertarLista(Lista,c);
                                agregarPila(pila, exp[i]);
                          //  }
                        }else{
                            c = sacarPila(pila);//sacamos el elemento anterior de la pila
                            insertarLista(Lista,c);
                            agregarPila(pila, exp[i]);
                        }
                    }
                }//fin de else
                break;
            case '-':
                if(pila == NULL){//es el primer caracter
                    agregarPila(pila,exp[i]);
                }else{
                    if(prioridadInfija(exp[i]) > prioridadPila(pila->dato)){//prioridad de operadores
                        agregarPila(pila, exp[i]);
                    }else{
                        if(prioridadInfija(exp[i]) == prioridadPila(pila->dato)){
                            //vaciar nuestra pila hasta llegar al final o un operado de menor jerarquia
                           // while(prioridadInfija(exp[i]) < prioridadPila(pila->dato)){
                                c = sacarPila(pila);//sacamos el elemento anterior de la pila
                                insertarLista(Lista,c);
                                agregarPila(pila, exp[i]);
                         //   }
                        }else{
                            c = sacarPila(pila);//sacamos el elemento anterior de la pila
                            insertarLista(Lista,c);
                            agregarPila(pila, exp[i]);
                        }
                    }
                }//fin de else
                break;
            case '/':
                if(pila == NULL){//es el primer caracter
                    agregarPila(pila,exp[i]);
                }else{
                    if(prioridadInfija(exp[i]) > prioridadPila(pila->dato)){//prioridad de operadores
                        agregarPila(pila, exp[i]);
                    }else{
                        if(prioridadInfija(exp[i]) == prioridadPila(pila->dato)){
                            //vaciar nuestra pila hasta llegar al final o un operado de menor jerarquia
                           // while(prioridadInfija(exp[i]) < prioridadPila(pila->dato)){
                                c = sacarPila(pila);//sacamos el elemento anterior de la pila
                                insertarLista(Lista,c);
                                agregarPila(pila, exp[i]);
                           // }
                        }else{
                            c = sacarPila(pila);//sacamos el elemento anterior de la pila
                            insertarLista(Lista,c);
                            agregarPila(pila, exp[i]);
                        }
                    }
                }//fin de else
                break;
            case '*':
                if(pila == NULL){//es el primer caracter
                    agregarPila(pila,exp[i]);
                }else{
                    if(prioridadInfija(exp[i]) > prioridadPila(pila->dato)){//prioridad de operadores
                        agregarPila(pila, exp[i]);
                    }else{
                        if(prioridadInfija(exp[i]) == prioridadPila(pila->dato)){
                            //vaciar nuestra pila hasta llegar al final o un operado de menor jerarquia
                                c = sacarPila(pila);//sacamos el elemento anterior de la pila
                                insertarLista(Lista,c);
                                agregarPila(pila, exp[i]);
                        }else{
                            c = sacarPila(pila);//sacamos el elemento anterior de la pila
                            insertarLista(Lista,c);
                            agregarPila(pila, exp[i]);
                        }
                    }
                }//fin de else
                break;
            case '^':
                if(pila == NULL){//es el primer caracter
                    agregarPila(pila,exp[i]);
                }else{
                    if(prioridadInfija(exp[i]) > prioridadPila(pila->dato)){//prioridad de operadores
                        agregarPila(pila, exp[i]);
                    }else{
                        if(prioridadInfija(exp[i]) == prioridadPila(pila->dato)){
                            //vaciar nuestra pila hasta llegar al final o un operado de menor jerarquia
                                c = sacarPila(pila);//sacamos el elemento anterior de la pila
                                insertarLista(Lista,c);
                                agregarPila(pila, exp[i]);
                        }else{
                            c = sacarPila(pila);//sacamos el elemento anterior de la pila
                            insertarLista(Lista,c);
                            agregarPila(pila, exp[i]);
                        }
                    }
                }//fin de else
                break;
            case '(':
                if(pila == NULL){//es el primer caracter
                    agregarPila(pila,exp[i]);
                }else{
                    if(prioridadInfija(exp[i]) > prioridadPila(pila->dato)){//prioridad de operadores
                        agregarPila(pila, exp[i]);
                    }else{
                        if(prioridadInfija(exp[i]) == prioridadPila(pila->dato)){
                            //vaciar nuestra pila hasta llegar al final o un operado de menor jerarquia
                                c = sacarPila(pila);//sacamos el elemento anterior de la pila
                                insertarLista(Lista,c);
                                agregarPila(pila, exp[i]);
                        }else{
                            c = sacarPila(pila);//sacamos el elemento anterior de la pila
                            insertarLista(Lista,c);
                            agregarPila(pila, exp[i]);
                        }
                    }
                }//fin de else
                break;
            case ')':
                while((pila->dato != '(') && (pila != NULL)){
                    c = sacarPila(pila);
                    insertarLista(Lista, c);

                }
                if(pila->dato == '('){
                    c = sacarPila(pila);
                }
                break;
            default:
                insertarLista(Lista, exp[i]);
                break;
        }// fin de switch
        cout << "Elemento: " << exp[i] << " insertado correctamente. " << endl;
        cout << "PILA: " ;mostrarNodos(pila);
	}//fin del ciclo for

	//VACIAMOS EL ULTIMO ELEMENTO DE LA PILA
	while(pila != NULL){
        c = sacarPila(pila);
        insertarLista(Lista, c);
	}
	//MOSTRANDO ELEMENTOS DE LA PILA
	cout << endl;
	cout << "-----------------------------------------" << endl;
	cout << "\nEXPRESION POSTFIJA: ";
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
char sacarPila(NodoP *&pila){
    int n;
    NodoP *aux = pila;
    n=pila->dato;
    aux=pila;
    pila=pila->siguiente;
    delete(aux);
    return n;
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
    //char dato;
    while(pila != NULL){
		cout<<aux->dato;
            aux = aux->siguiente;
	}
	cout << endl;
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
void mostrarNodos(NodoP *&pila){
    NodoP *actual = new NodoP();
    actual = pila;
	cout<<" \nMostrar\n ";
	while(actual!=NULL){
		cout<<" "<<actual->dato<<" ";
		actual=actual->siguiente;
	}
	cout<<"\n";
	system("pause");
}

