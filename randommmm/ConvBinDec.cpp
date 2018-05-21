#include <iostream>
using namespace std;

int binario(int valor){
    if(valor == 0)
        return 0;
    return binario(valor / 2)*10 + valor % 2;
}

int funcaoHash(int id){
    int resto;
    resto = (id % 16);
	cout << "resto = " << resto <<endl;
    return binario(resto);
}

int main (){
	int n;
	cin >> n;
	
	cout <<"binario = " << funcaoHash(n);

	return 0;
}
