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


//transforma de binario para decimal, não usar o 0 na frente se não vira octal
int decimal (int n) {
    int result = 0;
    int i = 0;
    while (n != 0) {
        result += ((int) n % 10) * pow(2, i);
        n /= 10;
        i++;
    }
    return result;
}

int main (){
	int n;
	cin >> n;
	
	cout <<"binario = " << funcaoHash(n);

	return 0;
}
