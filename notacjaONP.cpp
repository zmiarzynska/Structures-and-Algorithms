#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cctype>
#define N 20

using namespace std;

typedef char element;
typedef  struct cell
{
    element element;
    cell *next;
    string hello;
} ;


class Stos
{
    public:
       
        cell * top; // głowa stosu
        Stos(){
			top=NULL;
		}  //konstruktor

        void Push(element x){
                cell *nowyElement=new cell;
                nowyElement->element=x;
                nowyElement->next=top;
                top=nowyElement;
	    }

        void Push(string x){
                cell *nowyElement=new cell;
                nowyElement->hello=x;
                nowyElement->next=top;
                top=nowyElement;
	    }

        void Pop(){
            if(top!=NULL){
                cell *temp;
                temp=top;
                top=top->next;
                delete temp;
            }
		
	   }
		
		
        void Print(){ // wyświetla wszystkie elementy listy

			cell *current;
			current=top;
			while(current!=NULL) {
				cout<<current->element;//<<endl;
				current=current->next;
			}

		}

        bool Empty(){
            if(top!=NULL){
                return false;
            }
            else return true;
        }

        element whatTop(){
            //if(top!=NULL){
                return top->element;
            //}
            
        }
        string whatTop(string a){
                return top->hello;
            
        }
        

};


class Konwersja{
    public:

char wejscie[100];
    Konwersja(){
      
    }

/*int p(char c){ // wersja 
  switch(c){
    case '+'     : return 0;
    case '-'     : return 1;
    case '*'     : return 0;
    case '/'     : return 2;
    case '^'     : return 3;
  }
  return 0;
}*/

int priorytet(char c){
    int p=0;
  switch(c){
    case '+'     : p=1;break;
    case '-'     : p=1;break;
    case '*'     : p=2;break;
    case '/'     : p=2;break;
    case '^'     : p=3;break;
  }
  return p;
}
char priorytetZONP(char c){
    int p='0';
  switch(c){
    case '+'     : p='1'; break;
    case '-'     : p='1'; break;
    case '*'     : p='2'; break;
    case '/'     : p='2'; break;
    case '^'     : p='3'; break;
    default: p='5'; break;
  }
  return p;
}
void infixToONP(){
     cout<<"Wpisz wyrazenie w zwyklej notacji\n";
     int i=0;
     char temp;
     Stos s;

      ///string wejscie;
     // getline( cin, wejscie );

        cin >> wejscie;
     

            do{
                
                if(!isspace(wejscie[i])){
                    switch(wejscie[i]){
                    case ' ': ; break; 
                    case '(': s.Push('('); break; 
                    case ')':
                        while(s.whatTop()!='('){
					          cout<<s.whatTop();
					          s.Pop();
				             }
				        s.Pop();
				        break;
                    case '^':
                    case '*':
                    case '/':
                    case '+':
                    case '-':
                        while(!s.Empty()){
                            if( priorytet(wejscie[i])>priorytet(s.whatTop()) || priorytet(wejscie[i])==3) break;
                            cout<<s.whatTop();
                            s.Pop();
                        }
                        s.Push(wejscie[i]);
                        break;
                    default: cout<<wejscie[i]; break;  
                }
                  
                } cout<<' ';
            i++;
            }while(wejscie[i]!='=');

        
           if(!s.Empty()){
                do{
                  cout<<s.whatTop()<<' ';
                  s.Pop();
                }while(!s.Empty());
            }
        }

    void ONPtoInfix(){
        cout<<"Wpisz wyrazenie w odwrotnej notacji polskiej\n";
     int j=0; 
    string element1,element2;
    char priorytet1,priorytet2;
    string wyrazenie;
    string doStringa;
     Stos s;
     Stos sPriorytetow; 
        cin >> wejscie;
 
        do{
             wyrazenie="";
             switch(wejscie[j]){
                case ' ': ; break; 
                case '^':
                case '*':
                case '/':
                case '+':
                case '-': 
                
            
                    element1=s.whatTop("hello");                
                    s.Pop();                 
                    element2=s.whatTop("hello");              
                    s.Pop();               
                    priorytet1=sPriorytetow.whatTop();                  
                    sPriorytetow.Pop();                
                    priorytet2=sPriorytetow.whatTop();                 
                    sPriorytetow.Pop();                 
                    if(priorytet1<=priorytetZONP(wejscie[j])){                   
                        element1="("+element1+")";
                    }                 
                    if(priorytet2<priorytetZONP(wejscie[j])){            
                        element2="("+element2+")";
                        }                        
                    wyrazenie=element2+wejscie[j]+element1;                  
                    s.Push(wyrazenie);                
                    sPriorytetow.Push(priorytetZONP(wejscie[j]));                
                    break;
                default:        
               
                    doStringa=wejscie[j];
                    s.Push(doStringa);                
                    sPriorytetow.Push(priorytetZONP(wejscie[j]));       
                 
                    break;
        }                    
            j++;
            }while(wejscie[j]!='=');
      
     cout<<wyrazenie<<"\n";
    }    
};


int main(){

  
   Konwersja konwer;
   int wpisz;
   cout<< "1 - Zamiana na odwrotna notacje polska \n";

   cout<< "2 - Zamiana z odwrotnej notacji polskiej \n";

   cin>>wpisz;
   

   if(wpisz==1){
   konwer.infixToONP();
   }
   if(wpisz==2){
    konwer.ONPtoInfix();
   } 
    return 0;
}