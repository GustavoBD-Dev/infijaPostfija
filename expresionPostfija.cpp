#include<iostream>
#include<cstdlib>
#include<stdio.h>
#include<string.h>
using namespace std;
struct nodo {
       char palabra;
       struct nodo *sgte;
       };
typedef struct nodo *Ptrpila;
typedef struct nodo *Tlista;

void push(Ptrpila &,char);
char pop(Ptrpila &);
void agregar_atras(Tlista &,char);
int  prioridad_infija(char );
int  prioridad_pila(char );
void imprimir( Tlista &);

int main(void){
        Ptrpila p=NULL;
        Ptrpila M=NULL;
        Tlista lista=NULL;
        char c,x;
        string cad;
        cout<<"EXPRESION POSTFIJA\n\n";
        cout<<"INGRESE EXPRESION:";
        getline(cin, cad);

        for(int i=0;i<cad.length();i++)
        {

            if((cad[i]>=49&&cad[i]<=57)||(cad[i]>=97&&cad[i]<=122))//validado para numeros de 1-9 y letras
                agregar_atras(lista,cad[i]);
            if(cad[i]=='+'||cad[i]=='-'||cad[i]=='*'||cad[i]=='/'||cad[i]=='('||cad[i]=='^')
            {   if(p==NULL)
                    push(p,cad[i]);
                else
                {
                    if(prioridad_infija(cad[i])>prioridad_pila(p->palabra))//compara prioridad de operadores
                        push(p,cad[i]);
                    else
                    {   if(prioridad_infija(cad[i])==prioridad_pila(p->palabra))
                          {
                            c=pop(p);
                            agregar_atras(lista,c);
                            push(p,cad[i]);
                          }
                        else
                          {
                            c=pop(p);
                            agregar_atras(lista,c);
                          }
                    }
                }
            }
            if(cad[i]==')')
               {
                while(p->palabra!='('&&p!=NULL)//desempilamos y agregamos a lista
                   {
                       c=pop(p);
                       agregar_atras(lista,c);
                    }
                if(p->palabra=='(')
                        c=pop(p);
                }
        }
        while(p!=NULL)//si es que la pila aun no esta nula pasamos los operadores a lista
            {
                c=pop(p);
                agregar_atras(lista,c);
            }

        imprimir(lista);
        system("pause");
        return 0;
}
void push(Ptrpila &p,char a){
    Ptrpila q=new struct nodo;
    q->palabra=a;
    q->sgte=p;
    p=q;
}
char pop(Ptrpila &p){
    int n;
    Ptrpila aux;

    n=p->palabra;
    aux=p;
    p=p->sgte;
    delete(aux);
    return n;

}
void agregar_atras(Tlista &lista,char a){
    Tlista t, q = new(struct nodo);
    q->palabra  = a;
    q->sgte = NULL;
    if(lista==NULL){
        lista = q;
    }else{
        t = lista;
        while(t->sgte!=NULL){
            t = t->sgte;
        }
        t->sgte = q;
    }
}

int prioridad_infija(char a){
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

int prioridad_pila(char a){
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

void imprimir( Tlista &lista){
    Ptrpila aux;
    aux=lista;

    if(lista!=NULL)
     {    cout<<"\t\nNOTACION POSTFIJA\n\n";
          while(aux!=NULL)
          {    cout<<aux->palabra;
               aux = aux->sgte;
          }
      }
      cout<<endl<<endl;
}


//https://github.com/Jose9820/Infijo-a-Postfijo/blob/master/arbol%20de%20expresiones.cpp

