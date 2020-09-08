#include <iostream>
#include <vector>
//Código de Vinícius Brito

typedef std::vector<int> vec;

class vetor{
    private:
        vec v;
        vec somap;

    public:
        vetor(vec V){
            v=V;
            int n=v.size( );
            somap.resize(n+1, 0);
            for(int i=1; i<=n; i++) somap[i]=somap[i-1]+v[i-1];
        }
        long soma();
        bool buscabinaria(int a);
        void somaprefixos();
        vetor operator -(){
            int n=v.size();
            vec x(n);
            for(int i=0; i<n; i++) x[i]=-v[i];
            return vetor(x);
        }
};

long vetor::soma(){
    int n=v.size();
    return somap[n];
}

void vetor::somaprefixos(){
    std::cout << "Vetor de soma de prefixos: ";
    for(int i=1; i<=v.size(); i++) std::cout << somap[i] << " ";
    std::cout << std::endl;
}

bool vetor::buscabinaria(int a){
    int b=0, e=v.size( )-1;
    while(e>=b){
        int m=(e+b)/2;
        if(v[m]==a) return true;
        if(v[m]<a) b=m+1;
        else e=m-1;
    }
    return false;
}

int main(void){
    vec x={1, 2, 3, 4, 5};
    vetor vet(x);
    std::cout << "Soma dos elementos do vetor = " << (-vet).soma() << std::endl;
    vet.somaprefixos();
    int t=3;
    std::cout << (vet.buscabinaria(t) ? "A" : "Nao a") << "chei um " << t;
}
