#include <iostream>
using namespace std;
int main (void)
{
    char continuar, nova_operacao;
    float num;
    char op;
    float resultado, resultado_anterior = 0;  // Resultado inicial
    bool primeira_operacao = true;  // Flag para controlar a primeira operação

    do
    {
        cout << "Digite os numeros e operadores separados por espaco.\n";
        cout << "Exemplo: 2 + 3 * 4 - 5\n";
        cout << "Pressione Enter para finalizar: ";

        while (true) {
            if (primeira_operacao) {
                // Na primeira operação, pede os dois números e o operador
                cin >> num;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    if (cin.peek() == '\n') break;
                    cout << "Por favor, insira apenas numeros! Tente novamente: ";
                    continue;
                }
                resultado = num;  // Primeiro número é o resultado inicial
                resultado_anterior = num;  // Também inicializa o resultado anterior
            }

            // Verifica se há mais entrada (operador)
            if (cin.peek() == '\n') {
                cout << "\nDeseja continuar a operacao? (s/n): ";
                cin >> continuar;
                while (continuar != 's' && continuar != 'S' && continuar != 'n' && continuar != 'N')
                {
                    cout << "Opcao invalida! Use apenas s ou n: ";
                    cin >> continuar;
                }
                if (continuar == 'n' || continuar == 'N') {
                    cout << "\nDeseja fazer uma nova operacao? (s/n): ";
                    cin >> nova_operacao;
                    while (nova_operacao != 's' && nova_operacao != 'S' && nova_operacao != 'n' && nova_operacao != 'N')
                    {
                        cout << "Opcao invalida! Use apenas s ou n: ";
                        cin >> nova_operacao;
                    }
                    if (nova_operacao == 'n' || nova_operacao == 'N') {
                        cout << "\nPrograma encerrado. Obrigado por usar a calculadora!\n";
                        return 0;
                    }
                    resultado = 0;
                    resultado_anterior = 0;
                    primeira_operacao = true;
                    cout << "\nDigite os numeros e operadores separados por espaco.\n";
                    cout << "Exemplo: 2 + 3 * 4 - 5\n";
                    cout << "Pressione Enter para finalizar: ";
                    continue;
                }

            }
            cin >> op;

            // Valida o operador
            if (op != '+' && op != '-' && op != '*' && op != '/') {
                cout << "Operador invalido! Use apenas +, -, * ou /: ";
                continue;
            }

            // Lê o próximo número
            cin >> num;
            if (cin.fail()) {
                cout << "Por favor, insira apenas numeros! Tente novamente: ";
                cin.clear();
                cin.ignore(10000, '\n');
                continue;
            }

            // Calcula o resultado parcial
            switch (op) {
                case '+': 
                    resultado += num;
                    break;
                case '-':
                    resultado -= num;
                    break;
                case '*':
                    resultado *= num;
                    break;
                case '/':
                    if (num == 0.0) {
                        cout << "ERRO: DIVISAO POR ZERO!" << endl;
                        break;
                    }
                    resultado /= num;
                    break;
            }

            // Mostra o resultado parcial
            cout << "Resultado parcial: " << resultado_anterior << " " << op << " " << num << " = " << resultado << endl;
            resultado_anterior = resultado;
            primeira_operacao = false;  // Após a primeira operação, muda para false
        }

        cout << "\nResultado final: " << resultado << endl;
    } while (true);

    return 0;
}