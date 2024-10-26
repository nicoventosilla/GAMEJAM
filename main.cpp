#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

void ocultarCursor() // Funcion para ocultar el cursor
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

void gotoxy(int x, int y) // Funcion para posicionar el cursor en una coordenada
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(consoleHandle, coord);
}

void color(int color) // Funcion para cambiar el color de la letra
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(consoleHandle, color);
}

void dibujarCarro(int x, int y) // Funcion para dibujar un carro
{
    color(3);
    gotoxy(x, y);
    cout << "  _______";
    gotoxy(x, y + 1);
    cout << " /|_||_||\\";
    gotoxy(x, y + 2);
    cout << "(   _    _)";
    gotoxy(x, y + 3);
    cout << "=`(_)--(_)";
}

void borrarCarro(int x, int y) // Funcion para borrar un carro
{
    gotoxy(x, y);
    cout << "         ";
    gotoxy(x, y + 1);
    cout << "           ";
    gotoxy(x, y + 2);
    cout << "           ";
    gotoxy(x, y + 3);
    cout << "          ";
}

void pista()
{
    gotoxy(0, 0);
    cout << "PARTIDA                                                                         ";
    gotoxy(0, 1);
    cout << "                                                                                ";
    gotoxy(0, 2);
    cout << "                                                                                ";
    gotoxy(0, 3);
    cout << "                                                                                ";
    gotoxy(0, 4);
    cout << "                                                                                ";
    gotoxy(0, 5);
    cout << "--------------------------------------------------------------------------------";
    gotoxy(0, 6);
    cout << "                                                                                ";
    gotoxy(0, 7);
    cout << "                                                                                ";
    gotoxy(0, 8);
    cout << "                                                                                ";
    gotoxy(0, 9);
    cout << "                                                                                ";
    gotoxy(0, 10);
    cout << "--------------------------------------------------------------------------------";
}

void esperarTecla() // Funcion para esperar a que se presione una tecla
{
    cout << endl << "Presione <ESCAPE> para volver al menu principal" << endl;

    while (true)
    {
        if (_kbhit())
        {
            char tecla = _getch();
            if (tecla == 27) // 27 es el codigo ASCII del ESCAPE
            {
                break;
            }
        }
    }
}

void creditos()
{
    system("cls");

    cout << "-------------------";
    cout << "Creditos";
    cout << "-------------------" << endl;
    cout << "\"Aqui van los creditos\"" << endl;

    esperarTecla();
}


void salir()
{
    system("cls");

    cout << "Gracias por jugar!" << endl;
}

void carrera()
{
    system("cls");

    srand(time(0));

    pista();

    dibujarCarro(0, 1);
    dibujarCarro(0, 6);

    int x1 = 0, x2 = 0;

    while (x1 < 70 && x2 < 70)
    {
        borrarCarro(x1, 1);
        borrarCarro(x2, 6);

        x1 += rand() % 3;
        x2 += rand() % 3;

        dibujarCarro(x1, 1);
        dibujarCarro(x2, 6);

        Sleep(100);
    }

    if (x1 >= 70 && x2 >= 70)
    {
        gotoxy(0, 12);
        cout << "Empate!";
    }
    else if (x1 >= 70)
    {
        gotoxy(0, 12);
        cout << "Gana el carro 1!";
    }
    else
    {
        gotoxy(0, 12);
        cout << "Gana el carro 2!";
    }

    esperarTecla();
}

int main()
{
    ocultarCursor();

    while (true)
    {
        system("cls");

        gotoxy(10, 10);
        cout << "--------------------------";
        gotoxy(10, 11);
        cout << "SIMULADOR DE CARRERAS CCPL";
        gotoxy(10, 12);
        cout << "--------------------------" << endl;
        gotoxy(10, 13);
        cout << "[1] Jugar" << endl;
        gotoxy(10, 14);
        cout << "[2] Creditos" << endl;
        gotoxy(10, 15);
        cout << "[3] Salir" << endl;

        char tecla = _getch(); // Espera a que se presione una tecla

        switch (tecla)
        {
        case '1':
            carrera();
            break;
        case '2':
            creditos();
            break;
        case '3':
            salir();
            return 0; /// Termina el programa
        }
    }
    return 0;
}
