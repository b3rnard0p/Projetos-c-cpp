#include <iostream>
#include <cmath>

using namespace std;

#include "Metodos.h"

int main() {
    int escolha;
    double a, b, c, x, resultado;
    char operador1, operador2;
    char raizOnde = 'n';

    cout << "Escolha o tipo de função:" << endl;
    cout << "1 - Função Afim (Ax + B)" << endl;
    cout << "2 - Função Quadrática (Ax^2 + Bx + C)" << endl;
    cout << "3 - Função Exponencial (Ae^(Ax))" << endl;
    cout << "Opção: ";
    cin >> escolha;

    if (escolha == 1) {
        cout << "Digite o valor de 'a': ";
        cin >> a;
        cout << "Digite o valor de 'b': ";
        cin >> b;
        cout << "Digite o valor de 'x': ";
        cin >> x;

        cout << "Escolha o operador 1 (+, -, *, /): ";
        cin >> operador1;
        cout << "Onde deseja colocar a raiz? (a, b, x do b, n para nenhum lugar): ";
        cin >> raizOnde;

       resultado = calcularLimiteAfim(a, b, x, operador1, raizOnde);
    } else if (escolha == 2) {
        cout << "Digite o valor de 'a': ";
        cin >> a;
        cout << "Digite o valor de 'b': ";
        cin >> b;
        cout << "Digite o valor de 'c': ";
        cin >> c;
        cout << "Digite o valor de 'x': ";
        cin >> x;
        cout << "Escolha o operador 1 (+, -, *, /): ";
        cin >> operador1;
        cout << "Escolha o operador 2 (+, -, *, /): ";
        cin >> operador2;
        cout << "Onde deseja colocar a raiz? (a, b, c, x, n para nenhum lugar): ";
        cin >> raizOnde;

        resultado = calcularLimiteQuadratica(a, b, c, x, operador1, operador2, raizOnde);

        if (std::isnan(resultado) || std::isinf(resultado)) {
            cout << "O limite resulta em uma indeterminação. Tentando resolver usando a fórmula de Bhaskara..." << endl;
            calcularBhaskara(a, b, c, x);
        }
    } else if (escolha == 3) {
        cout << "Digite o valor de 'A': ";
        cin >> a;
        cout << "Digite o valor de 'x': ";
        cin >> x;

        resultado = calcularLimiteExponencial(a, x);
    } else {
        cout << "Escolha inválida." << endl;
        return 1;
    }

    if (std::isnan(resultado) || std::isinf(resultado)) {
        cout << "O limite resulta em uma indeterminação." << endl;
    } else {
        cout << "Resultado do limite: " << resultado << endl;
    }
}

    return 0;
}
