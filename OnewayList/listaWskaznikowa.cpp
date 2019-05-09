#include <iostream>
using namespace std;


typedef int element;
typedef  struct cell
{
    element element;
    cell *next;
} ;



class Lista
{
    protected:
        cell *header; // głowa listy
    public:
        Lista(){    //konstruktor
           header = new cell;    
           header->next=NULL;
        }
       // ~Lista();  //destruktor
        void Insert(element x, cell * p){ // wstawia element x na pozycję next komórki o wskaźniku p
                                                         // (lub w przypadku pustej listy tworzy komórkę z elementem x w miejscu głowy listy)
            cell* tmp;
            if(p==NULL) {
                
                header->element=x;
               
            }

            else{
            tmp=p->next;
            p->next=new cell;
            p->next->element=x;
            p->next->next=tmp;
            }

        }                                                 
        void Delete(cell * p){ // usuwa komórkę z pozycji next komórki o wskaźniku p
        
        cell* tmp;
        tmp=p->next;
        p->next=p->next->next;
        delete tmp;

        }
        element Retrieve(cell * p){ // zwraca element komórki o wskaźniku p
           if(p==NULL) {cout << "cos jest nie tak"<<endl; return -1;}
           else{
                return p->element;
           }

          
        
        }
        
        cell * Locate(element x){ // zwraca wskaźnik do pierwszej komórki z elementem x
            if(header->next==NULL) {

                 if(x==header->element) return header;
                 else cout<<"nie znaleziono elemetu"<<endl;

            }
            cell* tmp;
            tmp=header;

            while(tmp->next!=NULL){ 
                if(tmp->next->element==x) return tmp;
            tmp =  tmp->next;
                  }
                  return tmp; // zwraca ENDL

        }
        cell * First(){ // zwraca wskaźnik do pierwszej komórki na liście

          return header;

        }

        cell * Next(cell * p){ // zwraca wskaźnik do kolejnej komórki po komórce o wskaźniku p
        
         return p->next;
        
        }
        cell * Previous(cell * p){ // zwraca wskaźnik do komórki poprzedzającej komórkę o wskaźniku p
            if(p==NULL) cout << "cos jest nie tak"<<endl;
            if(p!=header){   
            cell* tmp;
            tmp=header;
            
            while(tmp->next!=p) tmp=tmp->next;
            
            return tmp;
            } else return NULL;
        }
        cell * Last(){ // zwraca wskaźnik do ostatniej komórki na liście

            if(header->next==NULL) return header;
            cell* tmp;
            tmp=header;
            while(tmp->next!=NULL)     tmp = tmp->next;      
            return tmp;
        }


        void print(){ // wyświetla wszystkie elementy listy

         cell* tmp;
         tmp=header;

             while(tmp!=NULL){
                
                 cout<< tmp->element <<endl;
                 tmp=tmp->next;
             }
        }

        void Reverse(){

         cell * p= Last();
          cell *temp=NULL;
          temp=p;
          while(header->next!=NULL){
            p->next=Previous(p);
            p=Previous(p);
          }

          header=temp;

        }

        

void l_reverse()
{
  cell * aktualny, * temp;
  if(header)
  {
    temp = header;
    while(temp->next)
    {
      aktualny = temp->next;
      temp->next = aktualny->next;
      aktualny->next = header;
      header = aktualny;
    } 
  }
}




};




int main(){

    Lista l;
  
    cell* wsk=NULL; // or null
    cell* wsk2=NULL;
    int x;
   l.Insert(2,wsk);
      l.Insert(4,l.First());

   l.Insert(32,l.First());
   l.Insert(89,l.First());
     l.Insert(8,l.First());
       l.Insert(7,l.First());
         l.Insert(6,l.First());
           l.Insert(5,l.First());
  // l.Delete(l.Last());

 //   wsk=l.Last();
    cout<< "cokolwiek" <<endl;
  //  wsk2=l.Previous(wsk);
    l.print();
  //  x=l.Retrieve(wsk);
   // cout<< x << endl;
  cout<< "Tu odwroce"<< endl;
  l.Reverse();

 // l.l_reverse();
  l.print();
    return 0;
}