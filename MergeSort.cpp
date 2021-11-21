#include  <fstream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <time.h>
using namespace std;

void Merge(int tab[], int pocz, int sr, int kon){
    int i, j, q;
    int a[kon+1];
    for (i=pocz; i<=kon; i++){
        a[i]=tab[i];
    }
    i=pocz;
    j=sr+1;
    q=pocz;
    while(i<=sr && j<=kon){
        if(a[i]<a[j]){
            tab[q]=a[i];
            q++;
            i++;
        }
        else{
            tab[q]=a[j];
            q++;
            j++;
        }
    }
    while(i<=sr){
        tab[q]=a[i];
        q++;
        i++;
    }
    while(j<=kon){
        tab[q]=a[j];
        q++;
        j++;
    }
}
void mergeSort(int tab[], int pocz, int kon){
    int sr;
    if(pocz<kon){
        sr=(pocz+kon)/2;
        mergeSort(tab, pocz, sr);
        mergeSort(tab, sr+1, kon);
        Merge(tab, pocz, sr, kon);
    }
}
int main(){
    return 0;
}
