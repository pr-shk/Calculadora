#include <iostream>

using namespace std;

int main (void)
{
    float var1, var2;
    char op ;



    cout << " ENTRE COM A SUA EXPRESSAO (num operador num). Ex: 2 + 3 => ";
    cin >> var1 >> op >> var2; /* le a expressao */
    switch (op)
    {
    case '+':
        cout << "Resultado : " << var1 + var2 << endl;
    break;
    case '-':
        cout << "Resultado : " << var1 - var2 << endl;
    break;
    case '*':
        cout << "Resultado : " << var1 * var2 << endl;
    break;
    case '/':
        if (var2 == 0.0)
            cout << "ERRO : DIVISAO POR ZERO ! ";
        else
            cout << "Resultado : " << var1 / var2 << endl;
    break;
    default:
        cout << "ERRO: operador invalido. \n";

} /* FIM DO BLOCO DO SWITCH */

cout << "\n\n";
system("pause");
}// fim main