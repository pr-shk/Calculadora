#include <iostream>
#include "messages.h"
using namespace std;

/*
// Estrutura para armazenar as mensagens em diferentes idiomas
struct Messages {
    const char* enter_numbers; //1
    const char* example; //2
    //const char* press_enter;
    const char* numbers_only; //3
    const char* continue_operation; //4
    const char* invalid_option; //5
    const char* new_operation; //6
    const char* program_finished; //7
    const char* invalid_operator; //8
    const char* division_zero; //9
    const char* partial_result; //10
    const char* final_result; //11
    const char* enter_operator; //12
};

// Mensagens em português
const Messages PT = {
    "Digite os numeros e operadores separados por espaco.\n", //1
    "Exemplo: 2 + 3 * 4 - 5\n", //2
    //"Pressione Enter para finalizar: ",
    "Por favor, insira apenas numeros! Tente novamente: ", //3
    "\nDeseja continuar a operacao? (s/n): ", //4
    "Opcao invalida! Use apenas s ou n: ", //5
    "\nDeseja fazer uma nova operacao? (s/n): ", //6
    "\nPrograma encerrado. Obrigado por usar a calculadora!\n", //7
    "Operador invalido! Use apenas +, -, * ou /: ", //8
    "ERRO: DIVISAO POR ZERO!", //9
    "Resultado parcial: ", //10
    "\nResultado final: ", //11
    "Digite o operador e o numero: " //12
};

// Mensagens em inglês
const Messages EN = {
    "Enter numbers and operators separated by space.\n", //1
    "Example: 2 + 3 * 4 - 5\n", //2
    //"Press Enter to finish: ",
    "Please enter only numbers! Try again: ", //3
    "\nDo you want to continue the operation? (y/n): ", //4
    "Invalid option! Use only y or n: ", //5
    "\nDo you want to start a new operation? (y/n): ", //6
    "\nProgram finished. Thank you for using the calculator!\n", //7
    "Invalid operator! Use only +, -, * or /: ", //8
    "ERROR: DIVISION BY ZERO!", //9
    "Partial result: ", //10
    "\nFinal result: ", //11
    "Enter the operator and number: " //12
};
*/

int main (void)
{
    //#include "messages.h"


    char continuar, nova_operacao;
    float num;
    char op;
    float resultado, resultado_anterior = 0;
    bool primeira_operacao = true;
    char idioma;
    const Messages* msg;

    // Seleção do idioma
    do {
        cout << "Choose language / Escolha o idioma / Elija el idioma:\n";
        cout << "1 - English / Ingles / Ingles\n";
        cout << "2 - Portugues / Portugues / Portugues\n";
        cout << "3 - Espanol / Espanhol / Espanol\n";
        cout << "Choose / Escolha / Elija (1/2/3): ";
        cin >> idioma;
    } while (idioma != '1' && idioma != '2' && idioma != '3');

    msg = (idioma == '1') ? &EN : (idioma == '2') ? &PT : &ES;

    do
    {
        cout << msg->enter_numbers;
        cout << msg->example;
        //cout << msg->press_enter;

        while (true) {
            if (primeira_operacao) {
                cin >> num;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    if (cin.peek() == '\n') break;
                    cout << msg->numbers_only;
                    continue;
                }
                resultado = num;
                resultado_anterior = num;
            }

            if (cin.peek() == '\n') {
                cout << msg->continue_operation;
                cin >> continuar;
                while (continuar != 's' && continuar != 'S' && continuar != 'n' && continuar != 'N' &&
                       continuar != 'y' && continuar != 'Y' && continuar != 'n' && continuar != 'N')
                {
                    cout << msg->invalid_option;
                    cin >> continuar;
                }
                if (continuar == 'n' || continuar == 'N') {
                    cout << msg->new_operation;
                    cin >> nova_operacao;
                    while (nova_operacao != 's' && nova_operacao != 'S' && nova_operacao != 'n' && nova_operacao != 'N' &&
                           nova_operacao != 'y' && nova_operacao != 'Y' && nova_operacao != 'n' && nova_operacao != 'N')
                    {
                        cout << msg->invalid_option;
                        cin >> nova_operacao;
                    }
                    if (nova_operacao == 'n' || nova_operacao == 'N') {
                        cout << msg->program_finished;
                        cout << msg->final_result << resultado << endl;
                        system("pause");
                        return 0;
                    }
                    resultado = 0;
                    resultado_anterior = 0;
                    primeira_operacao = true;
                    cout << msg->enter_numbers;
                    cout << msg->example;
                    //cout << msg->press_enter;
                    continue;
                }
                //cout << msg->enter_operator;
                //continue;
            }
            cin >> op;

            if (op != '+' && op != '-' && op != '*' && op != '/') {
                cout << msg->invalid_operator;
                continue;
            }

            cin >> num;
            if (cin.fail()) {
                cout << msg->numbers_only;
                cin.clear();
                cin.ignore(10000, '\n');
                continue;
            }

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
                        cout << msg->division_zero << endl;
                        break;
                    }
                    resultado /= num;
                    break;
            }

            cout << msg->partial_result << resultado_anterior << " " << op << " " << num << " = " << resultado << endl;
            resultado_anterior = resultado;
            primeira_operacao = false;
        }

    } while (true);
    return 0;
}