#include <iostream>
#include  <fstream>
#include <cstdlib>
#include <string>
#include <time.h>
using namespace std;

void zPliku(int t[],int n, ifstream &plik){
    int tmp=0;
    int a;
    int i=0;
    for(i;i<n;i++){
       plik >> a;
       t[i]= a;
    }

}

void insertSort(int tab[], int n){
    int licznik=0;
    for(int i=1; i<n; i++){
        int x=tab[i];
        int j=i;
        while((x<tab[j-1])&&(j>0)){
            tab[j]=tab[j-1];
            licznik++;
            j=j-1;
        }
        tab[j]=x;
        licznik++;
    }
    cout<<"Liczba krokow:"<<licznik;
}

int getNextGap(int gap)
{
    gap = (gap * 10) / 13;

    if (gap < 1)
        return 1;
    return gap;
}

void CombSort(int a[], int n)
{
    int licznik=0;
    int gap = n;
    bool swapped = true;

    while (gap != 1 || swapped == true) {
        gap = getNextGap(gap);
        swapped = false;

        for (int i = 0; i < n - gap; i++) {
            if (a[i] > a[i + gap]) {
                swap(a[i], a[i + gap]);
                swapped = true;
                licznik++;
            }
        }
    }
    cout<<"Liczba krokow:"<<licznik;
}






void Merge(int arr[], int l, int m, int r, int &licznik)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            licznik++;
            i++;
        }
        else
        {
            arr[k] = R[j];
            licznik++;
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        licznik++;
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        licznik++;
        j++;
        k++;
    }
}


void mergeeSort(int arr[], int l, int r, int &licznik)
{
    if (l < r)
    {
        int m = l+(r-l)/2;

        mergeeSort(arr, l, m, licznik);
        mergeeSort(arr, m+1, r, licznik);

        Merge(arr, l, m, r,licznik);
    }
}


void mergeSort(int arr[], int l, int r){
    int licznik=0;
    mergeeSort( arr,  l,  r,  licznik);
    cout<<"Liczba krokow:"<<licznik;
}




/*
void Merge(int tab[], int pocz, int sr, int kon, int &licznik){//licznikma byc na podany jako 0
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
            licznik++;
            q++;
            i++;
        }
        else{
            tab[q]=a[j];
            licznik++;
            q++;
            j++;
        }
    }
    while(i<=sr){
        tab[q]=a[i];
        licznik++;
        q++;
        i++;
    }
    while(j<=kon){
        tab[q]=a[j];
        licznik++;
        q++;
        j++;
    }
}
void mergeeSort(int tab[], int pocz, int kon, int &licznik){
    int sr;
    if(pocz<kon){
        sr=(pocz+kon)/2;
        mergeeSort(tab, pocz, sr,licznik);
        mergeeSort(tab, sr+1, kon,licznik);
        Merge(tab, pocz, sr, kon,licznik);
    }

}
void mergeSort(int tab[], int pocz, int kon){
    int licznik=0;
    mergeeSort( tab,  pocz,  kon,  licznik);
    cout<<"Liczba krokow:"<<licznik;
}
*/
int getMax(int arr[], int n, int &licznik)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void countSort(int arr[], int n, int exp, int &licznik)
{
    int output[n]; // output array
    int i, coun[10] = {0};
    for (i = 0; i < n; i++)
        coun[ (arr[i]/exp)%10 ]++;
    for (i = 1; i < 10; i++)
        coun[i] += coun[i - 1];
    for (i = n - 1; i >= 0; i--)
    {
        output[coun[ (arr[i]/exp)%10 ] - 1] = arr[i];
        coun[ (arr[i]/exp)%10 ]--;
    }
    for (i = 0; i < n; i++){
        arr[i] = output[i];
        licznik++;
    }
}

void radixsort(int arr[], int n)
{
    int licznik=0;
    int m = getMax(arr, n, licznik);
    for (int exp = 1; m/exp > 0; exp *= 10){
        countSort(arr, n, exp, licznik);
    }
    cout<<"Liczba krokow:"<<licznik;
}


void zadanie(string str,int opcja){

    clock_t b;
    ifstream plik(str);
    int t1[1000];
    zPliku(t1,1000,plik);
    plik.close();
    //for(int i=0;i<1000;i++){ //testowanie
    //    cout<<endl<<t1[i];
    //}


    ifstream plik1(str);
    int t2[11000];
    zPliku(t2,11000,plik1);
    plik1.close();

    ifstream plik2(str);
    int t3[21000];
    zPliku(t3,21000,plik2);
    plik2.close();

    ifstream plik3(str);
    int t4[31000];
    zPliku(t4,31000,plik3);
    plik3.close();

    ifstream plik4(str);
    int t5[41000];
    zPliku(t5,41000,plik4);
    plik4.close();

    ifstream plik5(str);
    int t6[51000];
    zPliku(t6,51000,plik5);
    plik5.close();

    ifstream plik6(str);
    int t7[61000];
    zPliku(t7,61000,plik6);
    plik6.close();

    ifstream plik7(str);
    int t8[71000];
    zPliku(t8,71000,plik7);
    plik7.close();

    ifstream plik8(str);
    int t9[81000];
    zPliku(t9,81000,plik8);
    plik8.close();

    ifstream plik9(str);
   // int t10[91000];
    //zPliku(t10,91000,plik9);
    plik9.close();

    ifstream plik10(str);
    //int t11[101000];
  //  zPliku(t11,101000,plik10);
    plik10.close();

    if(opcja==1){
        cout<<"1000 elementow"<<endl;
        b=clock();
        mergeSort(t1, 0, 1000-1);
        b=clock()-b;
        cout<<endl<<b<<"-czas sortowania"<<endl<<endl;


        cout<<"11000 elementow"<<endl;
        b=clock();
        mergeSort(t2, 0, 11000-1);
        b=clock()-b;
        cout<<endl<<b<<"-czas sortowania"<<endl<<endl;

        cout<<"21000 elementow"<<endl;
        b=clock();
        mergeSort(t3, 0, 21000-1);
        b=clock()-b;
        cout<<endl<<b<<"-czas sortowania"<<endl<<endl;

        cout<<"31000 elementow"<<endl;
        b=clock();
        mergeSort(t4, 0, 31000-1);
        b=clock()-b;
        cout<<endl<<b<<"-czas sortowania"<<endl<<endl;

        cout<<"41000 elementow"<<endl;
        b=clock();
        mergeSort(t5, 0, 41000-1);
        b=clock()-b;
        cout<<endl<<b<<"-czas sortowania"<<endl<<endl;

        cout<<"51000 elementow"<<endl;
        b=clock();
        mergeSort(t6, 0, 51000-1);
        b=clock()-b;
        cout<<endl<<b<<"-czas sortowania"<<endl<<endl;

        cout<<"61000 elementow"<<endl;
        b=clock();
        mergeSort(t7, 0, 61000-1);
        b=clock()-b;
        cout<<endl<<b<<"-czas sortowania"<<endl<<endl;


        cout<<"71000 elementow"<<endl;
        b=clock();
        mergeSort(t8, 0, 71000-1);
        b=clock()-b;
        cout<<endl<<b<<"-czas sortowania"<<endl<<endl;

        cout<<"81000 elementow"<<endl;
        b=clock();
        mergeSort(t9, 0, 81000-1);
        b=clock()-b;
        cout<<endl<<b<<"-czas sortowania"<<endl<<endl;
/*
        cout<<"91000 elementow"<<endl;
        b=clock();
        mergeSort(t10, 0, 91000-1);
        b=clock()-b;
        cout<<endl<<b<<"-czas sortowania"<<endl<<endl;

        cout<<"101000 elementow"<<endl;
        b=clock();
        mergeSort(t11, 0, 101000-1);
        b=clock()-b;
        cout<<endl<<b<<"-czas sortowania"<<endl<<endl;
*/
    }


    if(opcja==2){
        cout<<"1000 elementow"<<endl;
        b=clock();
        CombSort(t1, 1000);
        b=clock()-b;
        cout<<endl<<b<<"-czas sortowania"<<endl<<endl;


        cout<<"11000 elementow"<<endl;
        b=clock();
        CombSort(t2,11000);
        b=clock()-b;
        cout<<endl<<b<<"-czas sortowania"<<endl<<endl;

        cout<<"21000 elementow"<<endl;
        b=clock();
        CombSort(t3,21000);
        b=clock()-b;
        cout<<endl<<b<<"-czas sortowania"<<endl<<endl;

        cout<<"31000 elementow"<<endl;
        b=clock();
        CombSort(t4, 31000);
        b=clock()-b;
        cout<<endl<<b<<"-czas sortowania"<<endl<<endl;

        cout<<"41000 elementow"<<endl;
        b=clock();
        CombSort(t5,41000);
        b=clock()-b;
        cout<<endl<<b<<"-czas sortowania"<<endl<<endl;

        cout<<"51000 elementow"<<endl;
        b=clock();
        CombSort(t6,51000);
        b=clock()-b;
        cout<<endl<<b<<"-czas sortowania"<<endl<<endl;

        cout<<"61000 elementow"<<endl;
        b=clock();
        CombSort(t7,61000);
        b=clock()-b;
        cout<<endl<<b<<"-czas sortowania"<<endl<<endl;

        cout<<"71000 elementow"<<endl;
        b=clock();
        CombSort(t8,71000);
        b=clock()-b;
        cout<<endl<<b<<"-czas sortowania"<<endl<<endl;

        cout<<"81000 elementow"<<endl;
        b=clock();
        CombSort(t9,81000);
        b=clock()-b;
        cout<<endl<<b<<"-czas sortowania"<<endl<<endl;
/*
        cout<<"91000 elementow"<<endl;
        b=clock();
        CombSort(t10,91000);
        b=clock()-b;
        cout<<endl<<b<<"-czas sortowania"<<endl<<endl;

        cout<<"101000 elementow"<<endl;
        b=clock();
        CombSort(t11,101000);
        b=clock()-b;
        cout<<endl<<b<<"-czas sortowania"<<endl<<endl;
*/
    }


    if(opcja==3){
        cout<<"1000 elementow"<<endl;
        b=clock();
        radixsort(t1, 1000);
        b=clock()-b;
        cout<<endl<<b<<"-czas sortowania"<<endl<<endl;


        cout<<"11000 elementow"<<endl;
        b=clock();
        radixsort(t2,11000);
        b=clock()-b;
        cout<<endl<<b<<"-czas sortowania"<<endl<<endl;

        cout<<"21000 elementow"<<endl;
        b=clock();
        radixsort(t3,21000);
        b=clock()-b;
        cout<<endl<<b<<"-czas sortowania"<<endl<<endl;

        cout<<"31000 elementow"<<endl;
        b=clock();
        radixsort(t4, 31000);
        b=clock()-b;
        cout<<endl<<b<<"-czas sortowania"<<endl<<endl;

        cout<<"41000 elementow"<<endl;
        b=clock();
        radixsort(t5,41000);
        b=clock()-b;
        cout<<endl<<b<<"-czas sortowania"<<endl<<endl;

        cout<<"51000 elementow"<<endl;
        b=clock();
        radixsort(t6,51000);
        b=clock()-b;
        cout<<endl<<b<<"-czas sortowania"<<endl<<endl;

        cout<<"61000 elementow"<<endl;
        b=clock();
        radixsort(t7,61000);
        b=clock()-b;
        cout<<endl<<b<<"-czas sortowania"<<endl<<endl;

        cout<<"71000 elementow"<<endl;
        b=clock();
        radixsort(t8,71000);
        b=clock()-b;
        cout<<endl<<b<<"-czas sortowania"<<endl<<endl;

        cout<<"81000 elementow"<<endl;
        b=clock();
        radixsort(t9,81000);
        b=clock()-b;
        cout<<endl<<b<<"-czas sortowania"<<endl<<endl;
/*
        cout<<"91000 elementow"<<endl;
        b=clock();
        radixsort(t10,91000);
        b=clock()-b;
        cout<<endl<<b<<"-czas sortowania"<<endl<<endl;

        cout<<"101000 elementow"<<endl;
        b=clock();
        radixsort(t11,101000);
        b=clock()-b;
        cout<<endl<<b<<"-czas sortowania"<<endl<<endl;
*/
    }

    if(opcja==4){
        cout<<"1000 elementow"<<endl;
        b=clock();
        insertSort(t1, 1000);
        b=clock()-b;
        cout<<endl<<b<<"-czas sortowania"<<endl<<endl;


        cout<<"11000 elementow"<<endl;
        b=clock();
        insertSort(t2,11000);
        b=clock()-b;
        cout<<endl<<b<<"-czas sortowania"<<endl<<endl;

        cout<<"21000 elementow"<<endl;
        b=clock();
        insertSort(t3,21000);
        b=clock()-b;
        cout<<endl<<b<<"-czas sortowania"<<endl<<endl;

        cout<<"31000 elementow"<<endl;
        b=clock();
        insertSort(t4, 31000);
        b=clock()-b;
        cout<<endl<<b<<"-czas sortowania"<<endl<<endl;

        cout<<"41000 elementow"<<endl;
        b=clock();
        insertSort(t5,41000);
        b=clock()-b;
        cout<<endl<<b<<"-czas sortowania"<<endl<<endl;

        cout<<"51000 elementow"<<endl;
        b=clock();
        insertSort(t6,51000);
        b=clock()-b;
        cout<<endl<<b<<"-czas sortowania"<<endl<<endl;

        cout<<"61000 elementow"<<endl;
        b=clock();
        insertSort(t7,61000);
        b=clock()-b;
        cout<<endl<<b<<"-czas sortowania"<<endl<<endl;

        cout<<"71000 elementow"<<endl;
        b=clock();
        insertSort(t8,71000);
        b=clock()-b;
        cout<<endl<<b<<"-czas sortowania"<<endl<<endl;

        cout<<"81000 elementow"<<endl;
        b=clock();
        insertSort(t9,81000);
        b=clock()-b;
        cout<<endl<<b<<"-czas sortowania"<<endl<<endl;
/*
        cout<<"91000 elementow"<<endl;
        b=clock();
        insertSort(t10,91000);
        b=clock()-b;
        cout<<endl<<b<<"-czas sortowania"<<endl<<endl;

        cout<<"101000 elementow"<<endl;
        b=clock();
        insertSort(t11,101000);
        b=clock()-b;
        cout<<endl<<b<<"-czas sortowania"<<endl<<endl;
*/
    }

}


int main(){
   /* int tab[]={2,33,122,3333,332423,44,556,2,333,1};
    CombSort(tab,10);
    for(int i=0;i<10;i++){
        cout<<","<<tab[i];
    }
*/

    string p1="losowezakres100.txt";
    string p2="losowezakres1000.txt";
    string p3="losowezakres10000.txt";
    string p4="losowezakres100000.txt";
/*
    ifstream plik(p1);
    int t1[1000];
    zPliku(t1,1000,plik);
    plik.close();
    for(int i=0;i<1000;i++){
        cout<<endl<<t1[i];
    }
    cout<<endl<<t1[0];


    cout<<"Zakres 0-100:"<<endl;
    cout<<"Merge sort:"<<endl;
    zadanie(p1,1);
    cout<<endl<<"Grzebieniowe:"<<endl;
    zadanie(p1,2);
    cout<<endl<<"Pozycyjne:"<<endl;
    zadanie(p1,3);
    cout<<endl<<"Przez wstawianie:"<<endl;
    zadanie(p1,4);

    cout<<"Zakres 0-1000:"<<endl;
    cout<<"Merge sort:"<<endl;
    zadanie(p2,1);
    cout<<endl<<"Grzebieniowe:"<<endl;
    zadanie(p2,2);
    cout<<endl<<"Pozycyjne:"<<endl;
    zadanie(p2,3);
    cout<<endl<<"Przez wstawianie:"<<endl;
    zadanie(p2,4);

    cout<<"Zakres 0-10000:"<<endl;
    cout<<"Merge sort:"<<endl;
    zadanie(p3,1);
    cout<<endl<<"Grzebieniowe:"<<endl;
    zadanie(p3,2);
    cout<<endl<<"Pozycyjne:"<<endl;
    zadanie(p3,3);
    cout<<endl<<"Przez wstawianie:"<<endl;
    zadanie(p3,4);

*/
    cout<<"Zakres 0-100000:"<<endl;
    cout<<"Merge sort:"<<endl;
    zadanie(p4,1);
    cout<<endl<<"Grzebieniowe:"<<endl;
    zadanie(p4,2);
    cout<<endl<<"Pozycyjne:"<<endl;
    zadanie(p4,3);
    cout<<endl<<"Przez wstawianie:"<<endl;
    zadanie(p4,4);

    return 0;
}
