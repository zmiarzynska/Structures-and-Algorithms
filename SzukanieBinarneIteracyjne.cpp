#include<iostream>
#include<cstdlib>
using namespace std;

long long tab[1000000]; //tablica z posortowanymi elementami


int szukaj(int lewy, int prawy, long szukana) 
{
     if(lewy>prawy)
       return -1;
       
	 int sr = (lewy+prawy)/2;
     
	 if(szukana == tab[sr])
	  	return sr;
    
    if(szukana < tab[sr])
        return szukaj(lewy,sr-1,szukana); 
    else
        return szukaj(sr+1,prawy,szukana); 
}


