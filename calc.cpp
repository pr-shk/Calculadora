#include <iostream>
using namespace std;
int main (void)
{
    float var1, var2;
    char op, continuar;

    do
    {
        cout << " ENTRE COM A SUA EXPRESSAO (num operador num). Ex: 2 + 3 => ";
        cin >> var1 >> op >> var2; /* le a expressao */
        
        // Validação do operador
        while (op != '+' && op != '-' && op != '*' && op != '/') {
            cout << "Operador invalido! Use apenas +, -, * ou /: ";
            cin >> var1 >> op >> var2;
        }

        switch (op)
            {
                case '+': 
                    cout << "Resultado : " << var1 << op << var2 << " = " << var1 + var2 << endl;
                break;
                case '-':
                    cout << "Resultado : " << var1 << op << var2 << " = " << var1 - var2 << endl;
                break;
                case '*':
                    cout << "Resultado : " << var1 << op << var2 << " = " << var1 * var2 << endl;
                break;
                case '/':
                    if (var2 == 0.0)
                        cout << "ERRO : DIVISAO POR ZERO ! ";
                    else
                        cout << "Resultado : " << var1 << op << var2 << " = " << var1 / var2 << endl;
                break;
            } /* FIM DO BLOCO DO SWITCH */

        cout << "\nDeseja fazer outra operacao? (s/n): ";
        cin >> continuar;
    } while (continuar == 's' || continuar == 'S');

    cout << "\nPrograma encerrado. Obrigado por usar a calculadora!\n";
    return 0;
}