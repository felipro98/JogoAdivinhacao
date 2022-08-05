#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    cout << "***********************\n";
    cout << "* Jogo da Adivinha��o *\n";
    cout << "***********************\n";

    cout << "Escolha a dificuldade:\n";
    cout << "F�cil (F), M�dio (M), Dif�cil (D)\n";

    char dificuldade;
    cin >> dificuldade;

    int numero_tentativas;

    if (dificuldade == 'F')
    {
        numero_tentativas = 15;
    }
    else if (dificuldade == 'M')
    {
        numero_tentativas = 10;
    }
    else
    {
        numero_tentativas = 5;
    }

    srand(time(NULL));
    int numero_secreto = rand() % 100;

    bool nao_acertou = true;
    int tentativas = 0;

    double pontos = 1000.0;

    for (tentativas = 1; tentativas <= numero_tentativas; tentativas++)
    {
        int chute;
        cout << "Tentativa " << tentativas << endl;
        cout << "Chute um n�mero: ";
        cin >> chute;

        double pontos_perdidos = abs(chute - numero_secreto) / 2.0;
        pontos = pontos - pontos_perdidos;

        cout << "Seu chute � " << chute << endl;

        if (chute == numero_secreto)
        {
            cout << "Acertou!\n";
            nao_acertou = false;
            break;

        }
        else if (chute > numero_secreto)
        {
            cout << "Seu chute foi maior!\n";
        }
        else
        {
            cout << "Seu chute foi menor!\n";
        }
    }
    cout << "Fim de jogo!" << endl;
    if (nao_acertou)
    {
        cout << "Voc� perdeu! Tente novamente!" << endl;
    }
    else
    {
        cout << "Voc� terminou o jogo com " << tentativas << " tentativas.\n";
        cout.precision(2);
        cout << fixed;
        cout << "Sua pontua��o foi de " << pontos << " pontos.\n";
    }
}