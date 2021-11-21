#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>

using namespace std;
void insertSort(int tab[], int n){
    for(int i=1; i<n; i++){
        int x=tab[i];
        int j=i;
        while((x<tab[j-1])&&(j>0)){
            tab[j]=tab[j-1];
            j=j-1;
        }
        tab[j]=x;
    }
}
int main(){
    return 0;
}
