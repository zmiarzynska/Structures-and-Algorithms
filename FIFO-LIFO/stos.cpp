#include <iostream>
using namespace std;


typedef int element;
typedef  struct cell
{
    element element;
    cell *next;
} ;


class Stos
{
    protected:
        cell * header; // głowa listy
    public:
        Stos(){
			header=NULL;
		}  //konstruktor




protected: 
		 void Insert(int x, cell * p){		 // wstawia element x na pozycję next komórki o wskaźniku p
                                                         // (lub w przypadku pustej listy tworzy komórkę z elementem x w miejscu głowy listy)
		   if(header==NULL){

			header=new cell;
			header->element=x;
			header->next=NULL;
		   }	
			else
		   {	
			cell *temp;
			temp=p->next;
			p->next=new cell;
			p->next->element=x;	
			p->next->next=temp;
		   }  

		}

		// usuwa komórkę z pozycji next komórki o wskaźniku p
	 	void Delete(cell * p){ 
			cell *temp;
			temp=p->next;
			p->next=p->next->next;
			delete temp;		
		}

		// zwraca element komórki o wskaźniku p
        int Retrieve(cell * p){

			return p->element;

		} 

		// zwraca wskaźnik do pierwszej komórki z elementem x
        cell * Locate(int x){
			
			cell *temp;
			temp=header;
			while(temp!=NULL){
				if(temp->element==x) return temp;
				temp=temp->next;
			}

			return temp;
		}


		// zwraca wskaźnik do pierwszej komórki na liście
        cell * First(){

			return header;

		}
		// zwraca wskaźnik do kolejnej komórki po komórce o wskaźniku p
        cell * Next(cell * p){

			return p->next;

		}
		// zwraca wskaźnik do komórki poprzedzającej komórkę o wskaźniku p
        cell * Previous(cell * p){

			cell *current;
			current=header;
			while((current->next)!=p){
				current=current->next;
			}

			return current;


		}


		// zwraca wskaźnik do ostatniej komórki na liście
        cell * Last(){
			if(header==NULL) return header;
			cell *current;
			current=header;
			while(current->next!=NULL){
				current=current->next;
			}
			return current;

		}
		// wyświetla wszystkie elementy listy
		public:
        void print(){ 

			cell *current;
			current=header;
			while(current!=NULL) {
				cout<<current->element<<endl;
				current=current->next;
			}

		}
	

	int top(){
		return Retrieve(Last());
	}
	void pop(){
		Delete(Previous(Last()));
	}
	void push(int x){
		Insert(x,Last());
	}







};




int main(){


	Stos j;
	
	j.push(3);

	cout<<j.top()<<endl;
	j.push(2);
	cout<<j.top()<<endl;
	j.push(5);
	cout<<j.top()<<endl;
	j.pop();
	cout<<j.top()<<endl;
	





return 0;
}
