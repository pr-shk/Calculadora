#include <iostream>
using namespace std;
int main (void)
{
    float var1, var2;
    char op, continuar;
    bool valido;

    do
    {
        valido = true;
        cout << " ENTRE COM A SUA EXPRESSAO (num operador num). Ex: 2 + 3 => ";
        do{
            // Validação do primeiro número
            do {
                valido = true;
                cin >> var1;
                if (cin.fail()) {
                    cout << "Por favor, insira apenas numeros para o primeiro valor: ";
                    cin.clear();
                    cin.ignore(10000, '\n');
                    valido = false;
                }
            } while (!valido);

            // Validação do operador
            do {
                valido = true;
                cin >> op;
                if (op != '+' && op != '-' && op != '*' && op != '/') {
                    cout << "Operador invalido! Use apenas +, -, * ou /: ";
                    valido = false;
                }
            } while (!valido);

            // Validação do segundo número
            //do {
                valido = true;
                cin >> var2;
                if (cin.fail()) {
                    cout << "Por favor, insira apenas numeros para o segundo valor: ";
                    cin.clear();
                    cin.ignore(10000, '\n');
                    valido = false;
                }
            //} while (!valido);
        } while (!valido);
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
        while (continuar != 's' && continuar != 'S' && continuar != 'n' && continuar != 'N')
        {
            cout << "Opcao invalida! Use apenas s ou n: ";
            cin >> continuar;
        }
    } while (continuar == 's' || continuar == 'S');

    cout << "\nPrograma encerrado. Obrigado por usar a calculadora!\n";
    return 0;
}