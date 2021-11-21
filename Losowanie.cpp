#include <iostream>
#include  <fstream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <time.h>
using namespace std;
void Losuj(int zakres,ofstream& plik){
    int a;
    for(int i=0;i<10100000;i++){
        a=rand()%zakres;
        plik<<a;
        plik<<" ";

    }
}
int main(){
    ofstream plik1("losowezakres100.txt");
    Losuj(100,plik1);
    ofstream plik2("losowezakres1000.txt");
    Losuj(1000,plik2);
    ofstream plik3("losowezakres10000.txt");
    Losuj(10000,plik3);
    ofstream plik4("losowezakres100000.txt");
    Losuj(100000,plik4);
    return 0;
}
