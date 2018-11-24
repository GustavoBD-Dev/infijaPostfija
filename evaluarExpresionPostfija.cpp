#include <iostream>
#include <stdlib.h>
#include <string>
#include <conio.h>
#include <stack>
#include <vector>
#include <bits/stdc++.h>
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
//NODO para la Pila final al evaluar la expresion
struct NodoPF {
    float dato;
    NodoPF *siguiente;
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

    NodoL *evaluador = NULL;

void evaluarExpresion(NodoL *&, NodoPF *&);
void agregarPilaLista(NodoPF *&, float);
char sacarPilaLista(NodoPF *&);

bool isNumber(char);
bool isOperator(char);

int prioridadInfija(char);
int prioridadPila(char);
//FUNCION PRINCIPAL
int main(){
    NodoP *pila = NULL;	//Inicializamos pila
    NodoL *Lista = NULL; // se crea un puntero y se iguala a NULL
        NodoPF *pilaFin = NULL; // pila para evaluar la expresion


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
        cout << "\nElemento: " << exp[i] << " insertado correctamente." << endl;
        cout << "PILA: " ;  mostrarNodos(pila);
        cout << "LISTA: ";    mostrarlista(Lista);
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
	//mostrarlista(Lista);
	cout << "///" ; evaluarExpresion(Lista, pilaFin);
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
	while(actual!=NULL){
		cout<<" "<<actual->dato<<" ";
		actual=actual->siguiente;
	}
	cout<<"\n";
	//system("pause");
}

void evaluarExpresion(NodoL *&Lista, NodoPF *&pilaFin){
    float num1, num2, result, number;
    char a;
    mostrarlista(Lista);
    cout << endl;
    system("pause");
    actual = inicio;
    do{
        if(isNumber(actual->dato)){
            number = float((actual->dato)-'0');
            cout << "\n\t" << actual->dato << " : is number..." << endl;
            agregarPilaLista(pilaFin, number);
        }else /*(isOperator(actual->dato))*/{
            cout << "\n\t" << actual->dato << " : is operator..." << endl;
            num2 = sacarPilaLista(pilaFin);
            num1 = sacarPilaLista(pilaFin);

            switch(actual->dato){
              case '+':
                       result = num1+num2;
                       cout << "suma: " << num1 << " + " << num2 << endl;
                       agregarPilaLista(pilaFin, result);
                       break;
              case '-':
                       result = num1-num2;
                       cout << "resta: " << num1 << " - " << num2 << endl;
                       agregarPilaLista(pilaFin, result);
                       break;
              case '*':
                       result = num1*num2;
                       cout << "multiplicacion: " << num1 << " * " << num2 << endl;
                       agregarPilaLista(pilaFin, result);
                       break;
              case '/':
                       result = num1/num2;
                       cout << "division: " << num1 << " / " << num2 << endl;
                       agregarPilaLista(pilaFin, result);
                       break;
            }//fin de switch
        }//fin de else
        actual = actual->siguiente;
    }while(actual != NULL);//fin de while
    //mostrar ultimo dato de la pila
    cout << "\n\nResultado:  " << pilaFin->dato << endl;

}
bool isNumber(char data){
    string numbers= "1234567890";
    for(char n:numbers)
    {
        if(data==n) return true;
    }
    return false;
}
bool isOperator(char data){
    string operators= "+-*/";
    for(char n:operators)
    {
        if(data==n) return true;
    }
    return false;
}

void agregarPilaLista(NodoPF *&pilaFin,float n){
	NodoPF *nuevoNodo = new NodoPF();
	nuevoNodo->dato = n;
	nuevoNodo->siguiente = pilaFin;
	pilaFin = nuevoNodo;
	cout << "Se ha agregado " << n << " a la pila correctamente. " << endl;
}
char sacarPilaLista(NodoPF *&pilaFin){
    float n;
    NodoPF *aux = pilaFin;
    n=pilaFin->dato;
    aux=pilaFin;
    pilaFin=pilaFin->siguiente;
    cout << "Se ha extraido " << n << " de la pila correctamente. " << endl;
    delete(aux);
    return n;
}

