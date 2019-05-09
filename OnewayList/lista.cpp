#define N 5
#include <iostream>


using namespace std;

 class Lista{
 int tab[N];
int last;

  public:
 Lista(){
   for(int i=0;i<=N;i++){
      tab[i]=0;
   
   }
      last=0;
 }

  int First(){


        return 0; 



  }


  int END(){

 
     return last+1;


  }


 int Next(int p){

      if(p<last)return p+1;
     
    
      return -1;
     
  }

  int Previous(int p){

  if(p<last)  return p+1;
	 
   return -1;
  }
  

  bool Insert(int x, int p){

        if(last==N || p>N) return false;
     int bufor;
     for(int i=p;i<last-2;i++){
          bufor=tab[p+1];
          tab[p+1]=tab[p];
          tab[p+2]=bufor;
        }  
    last++;
    tab[p]=x; 
    return true;

  }

 
   bool Delete(int p){
   
      if(p>last || p<0) return false;
    int bufor;

      for(int i=p;i<last-1;i++){

        tab[p]=tab[p+1];       

      } 

      last--;

   }

   int Locate(int x) {

    for(int i=0; i<=last;i++){

       if(tab[i]==x) return i;
    }
    return END();
   }

 int Retrieve(int p){

   if(p<=last || p>0) return tab[p];
 
   return -10000000;               
  }


  bool Usun(){

     for(int i=0;i<=last;i++){

             for(int j=i+1;j<=last;j++){
                   
                     if(tab[i]==tab[j]) { 
                       bool b=Delete(j);
                       return b;
                       }
              }
        }
       return false;
   }


};






int main(){

  Lista l;

//  cout << l.First()<<endl;
 //bool c=l.Insert(2,0);
  //cout <<c;



return 0;
}
