#include <stdio.h>
#include <time.h>
#include <algorithm>
#define tempo ((double)(t1 - t0)/CLOCKS_PER_SEC)
#define n 10000
//Código de Vinícius Brito

void bubblesort(int v[], int b, int e){
    for(int ultimo=e; ultimo>b; ultimo--){
        for(int i=1; i<ultimo; i++){
            if(v[i]>v[i+1]){
                int aux=v[i];
                v[i]=v[i+1];
                v[i+1]=aux;
            }
        }
    }
}
 
void reset(int v[]){
    for(int i=1; i<=n; i++) v[i]=n+1-i;
}
 
void Merge(int v[], int b, int e){
    int aux[n], p1, p2, p;
    int m=(b+e)/2;
    p1=p=b;
    p2=m+1;
    while(p1<=m && p2<=e){
        if(v[p1]<v[p2]) aux[p++]=v[p1++];
        else aux[p++]=v[p2++];
    }
    while(p1<=m){
        aux[p++]=v[p1++];
    }
    while(p2<=e){
        aux[p++]=v[p2++];
    }
    for(int i=b; i<=e; i++) v[i]=aux[i];
}
 
void mergesort(int v[], int b, int e){
    if(e>b){
        int m=(b+e)/2;
        mergesort(v, b, m);
        mergesort(v, m+1, e);
        Merge(v, b, e);
    }
}
 
int buscabinaria(int v[], int b, int e, int a){
    if(e>=b){
        int m=(b+e)/2;
        if(v[m]==a) return m;
        if(v[m]<a) return buscabinaria(v, m+1, e, a);
        return buscabinaria(v, b, m-1, a);
    }
    return -1;
}
 
int v[n];
 
int main( ){
    reset(v);
    clock_t t0=clock( );
    std::sort(v+1, v+n+1);
    clock_t t1=clock( );
    printf("--------------------\nComparando ordenacao\n--------------------");
    printf("\nTempo gasto pelo sort pronto: %.5f s", tempo);
    reset(v);
    t0=clock( );
    bubblesort(v, 1, n);
    t1=clock( );
    printf("\nTempo gasto pelo bubblesort implementado: %.5f s", tempo);
    reset(v);
    t0=clock( );
    mergesort(v, 1, n);
    t1=clock( );
    printf("\nTempo gasto pelo mergesort implementado: %.5f s", tempo);
    printf("\n--------------------\nComparando busca\n--------------------");
    int pos=-1;
    t0=clock( );
    for(int a=n/2; a<=2*n; a++){
        for(int i=1; i<=n; i++) if(v[i]==a) pos=i;
    }
    t1=clock( );
    printf("\nTempo gasto pelas buscas elemento-a-elemento: %.6f s", tempo);
    t0=clock( );
    for(int a=n/2; a<=2*n; a++)
        pos=buscabinaria(v, 1, n, a);
    t1=clock( );
    printf("\nTempo gasto pelas buscas binarias: %.6f s", tempo);
    return 0;
}
