#include <iostream>
#include <cmath>

using namespace std;

// formato de punto flotante de 32 bits
// componentes de un número en punto flotante
struct FloatC {
    int signo;
    int exponente;
    float significando;
};

FloatC descomponer(float num) {
    FloatC comp;

    comp.signo = (num >= 0) ? 0 : 1;
    num = abs(num);
    comp.exponente = 0;
    while (num >= 2.0) {
        num /= 2.0;
        comp.exponente++;
    }
    while (num < 1.0) {
        num *= 2.0;
        comp.exponente--;
    }
    comp.significando = num - 1.0;

    return comp;
}

FloatC multiplicar(FloatC comp1, FloatC comp2) {
    FloatC resultado;

    resultado.exponente = comp1.exponente + comp2.exponente;
    resultado.significando = (comp1.significando + 1.0) * (comp2.significando + 1.0) - 1.0;

    if (comp1.signo == comp2.signo) {
        resultado.signo = 0;
    }
    else {
        resultado.signo = 1;
    }

    return resultado;
}

int main() {
    float num1 = 3.5;
    float num2 = 2.5;

    // Descomponemos los números en sus componentes
    FloatC comp1 = descomponer(num1);
    FloatC comp2 = descomponer(num2);

    // Realizamos la multiplicación
    FloatC resultado = multiplicar(comp1, comp2);

    float final_result = (resultado.signo == 1) ? -1 : 1;
    final_result = final_result * (resultado.significando + 1.0) * pow(2.0, resultado.exponente);

    cout << "El resultado de " << num1 << " x " << num2 << " es " << final_result << endl;

    return 0;
}
