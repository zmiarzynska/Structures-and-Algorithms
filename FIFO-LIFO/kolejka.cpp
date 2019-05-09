#include <iostream>
using namespace std;


typedef int element;
typedef  struct cell
{
    element element;
    cell *next;
} ;




class Kolejka
{
    protected:
        cell *header; // głowa listy
        cell *rear;
    public:
        Kolejka(){    //konstruktor
           header = new cell;    
           header->next=NULL;
        }


    bool Empty()
	{	
	return(header->next==NULL);
	}

    void put(element x){

         cell* tmp=new cell;
            if(header->next==NULL) {
                
                header->element=x;
                rear=header;
            }

            else{
            tmp->element=x;   
            tmp->next=NULL;
            rear->next=tmp;
            rear=tmp;
            }

          cout<< "Wstawilem do kolejki: "<<tmp->element<<endl;
    }

    element get(){
         cout<<"Czy pusty"<< Empty()<<endl;
         if(!Empty()){
             cell* tmp;
             tmp=header;
             header=header->next;
             element x=tmp->element;
             delete tmp;
             return x;

         }
        
    }

    element front(){

        if(!Empty()){
             
             return header->element;

         }



    }

    void makenull(){

        cell* tmp;
		while(header->next!=NULL){
			tmp=header;
			header=header->next;
			delete tmp;
		}
		delete header;



    }       

   


};


int main(){

   
Kolejka k;
  
    cell* wsk=NULL; // or null
    cell* wsk2=NULL;
    int x;
   k.put(2);
   
element costam;
 costam=k.get();
 
 cout<<costam<< "  <- z kolejki" <<endl;

    return 0;
}