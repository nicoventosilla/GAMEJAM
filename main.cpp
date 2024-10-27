#include <iostream>
#include <windows.h>
#include <conio.h>
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
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); // Obtener el handle de la consola
    COORD coord; // Estructura que contiene las coordenadas
    coord.X = x; // Coordenada X
    coord.Y = y; // Coordenada Y
    SetConsoleCursorPosition(consoleHandle, coord); // Mover el cursor a la coordenada (x, y)
}

void color(int color) // Funcion para cambiar el color de la letra
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); // Obtener el handle de la consola
    SetConsoleTextAttribute(consoleHandle, color); // Cambiar el color de la letra
}

void Carro1(int x, int y) // Funcion para dibujar un carro
{
    color(3);
    gotoxy(x, y);
    cout << "  _______";
    gotoxy(x, y + 1);
    cout << " /|_||_||\\";
    gotoxy(x, y + 2);
    cout << "(   _    _)";
    gotoxy(x, y + 3);
    cout << " `(_)--(_)";
}

void Carro2(int x, int y) // Funcion para dibujar un carro
{
    color(4);
    gotoxy(x, y);
    cout << "  ______";
    gotoxy(x, y + 1);
    cout << " |   |  |_";
    gotoxy(x, y + 2);
    cout << " |___|__|_|";
    gotoxy(x, y + 3);
    cout << "  O    O";
}

void Carro3(int x, int y) // Funcion para dibujar un carro
{
    color(5);
    gotoxy(x, y);
    cout << "  ____";
    gotoxy(x, y + 1);
    cout << " /|_||\\___";
    gotoxy(x, y + 2);
    cout << "(   _    _|";
    gotoxy(x, y + 3);
    cout << " `-(_)-(_)";
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

void pistaInferior()
{
    gotoxy(0, 30);
    cout << "          ---------------------------------------------------------------------------------"; // 81 guiones
    gotoxy(0, 31);
    cout << "                                                                                          ";
    gotoxy(0, 32);
    cout << "    P                                                                                     ";
    gotoxy(0, 33);
    cout << "    A                                                                                     ";
    gotoxy(0, 34);
    cout << "    R                                                                                     ";
    gotoxy(0, 35);
    cout << "    T     ---------------------------------------------------------------------------------------------";
    // 93 guiones
    gotoxy(0, 36);
    cout << "    I                                                                                     ";
    gotoxy(0, 37);
    cout << "    D                                                                                     ";
    gotoxy(0, 38);
    cout << "    A                                                                                     ";
    gotoxy(0, 39);
    cout << "                                                                                          ";
    gotoxy(0, 40);
    cout <<
        "          ---------------------------------------------------------------------------------------------------------";
    // 105 guiones
}

void pistaSuperior()
{
    gotoxy(0, 0);
    cout <<
        "          ---------------------------------------------------------------------------------------------------------";
    // 105 guiones
    gotoxy(0, 1);
    cout << "                                                                                          ";
    gotoxy(0, 2);
    cout << "    M                                                                                     ";
    gotoxy(0, 3);
    cout << "                                                                                          ";
    gotoxy(0, 4);
    cout << "    E                                                                                     ";
    gotoxy(0, 5);
    cout << "          ---------------------------------------------------------------------------------------------";
    // 93 guiones
    gotoxy(0, 6);
    cout << "    T                                                                                     ";
    gotoxy(0, 7);
    cout << "                                                                                          ";
    gotoxy(0, 8);
    cout << "    A                                                                                     ";
    gotoxy(0, 9);
    cout << "                                                                                          ";
    gotoxy(0, 10);
    cout << "          ---------------------------------------------------------------------------------"; // 81 guiones
}

void pistaDerecha()
{
    for (int i = 29; i > 10; i--)
    {
        gotoxy(91, i);
        cout << "|";
    }

    for (int i = 34; i > 5; i--)
    {
        gotoxy(103, i);
        cout << "|";
    }

    for (int i = 39; i > 0; i--)
    {
        gotoxy(115, i);
        cout << "|";
    }
}

void pistas()
{
    pistaSuperior();
    pistaInferior();
    pistaDerecha();
}

void esperarTecla() // Funcion para esperar a que se presione una tecla
{
    gotoxy(25, 21);
    cout << "Presione <ESCAPE> para volver al menu principal" << endl;

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
    cout << "CREDITOS";
    cout << "-------------------" << endl;
    cout << "\"Aqui van los creditos\"" << endl;

    esperarTecla();
}


void salir()
{
    system("cls");

    cout << "GRACIAS POR JUGAR!" << endl;
}

void cuentaRegresiva(int numeroCarrera)
{
    color(7); // Cambiar el color de la letra a blanco
    for (int i = 3; i > 0; --i)
    {
        gotoxy(40, 20);
        cout << "LA CARRERA " << numeroCarrera << " COMIENZA EN: " << i;
        Sleep(1000); // Pausa de 1 segundo
    }

    gotoxy(40, 20);
    cout << "                           "; // Borrar el mensaje de cuenta regresiva
}

void carrera(int numeroCarrera)
{
    system("cls");

    pistas();

    int x1 = 10, y1 = 26;
    int x2 = 10, y2 = 31;
    int x3 = 10, y3 = 36;

    Carro1(x1, y1);
    Carro2(x2, y2);
    Carro3(x3, y3);

    cuentaRegresiva(numeroCarrera); // Llamada a la función de cuenta regresiva

    time_t tiempoInicio = time(0); // Guardar el tiempo de inicio

    while (true)
    {
        borrarCarro(x1, y1);
        borrarCarro(x2, y2);
        borrarCarro(x3, y3);

        int avance1 = rand() % 3 + 1; // Genera un número aleatorio entre 1 y 3
        int avance2 = rand() % 4 + 1; // Genera un número aleatorio entre 1 y 4
        int avance3 = rand() % 5 + 1; // Genera un número aleatorio entre 1 y 5

        // Movimiento del carro 1
        if (x1 < 80 && y1 == 26)
            x1 += avance1;
        else if (x1 >= 80 && y1 > 11)
            y1 -= avance1;
        else if (y1 <= 11 && x1 > 0)
            x1 -= avance1;

        // Asegurarse de que el carro 1 no salga de los límites
        if (x1 > 80) x1 = 80; // 80 es el límite derecho
        if (y1 < 11) y1 = 11; // 11 es el límite superior

        // Movimiento del carro 2
        if (x2 < 92 && y2 == 31)
            x2 += avance2;
        else if (x2 >= 92 && y2 > 6)
            y2 -= avance2;
        else if (y2 <= 6 && x2 > 0)
            x2 -= avance2;

        // Asegurarse de que el carro 2 no salga de los límites
        if (x2 > 92) x2 = 92;
        if (y2 < 6) y2 = 6;

        // Movimiento del carro 3
        if (x3 < 104 && y3 == 36)
            x3 += avance3;
        else if (x3 >= 104 && y3 > 1)
            y3 -= avance3;
        else if (y3 <= 1 && x3 > 0)
            x3 -= avance3;

        // Asegurarse de que el carro 3 no salga de los límites
        if (x3 > 104) x3 = 104;
        if (y3 < 1) y3 = 1;

        Carro1(x1, y1);
        Carro2(x2, y2);
        Carro3(x3, y3);

        color(7); // Cambiar el color de la letra a blanco

        // Calcular y mostrar el tiempo transcurrido
        time_t tiempoActual = time(0); // Obtener el tiempo actual
        int tiempoTranscurrido = difftime(tiempoActual, tiempoInicio); // Calcular el tiempo transcurrido
        gotoxy(0, 42);
        cout << "Tiempo transcurrido: " << tiempoTranscurrido << " segundos";

        Sleep(100);

        color(7); // Cambiar el color de la letra a blanco

        // Condición de victoria
        if (x1 <= 10 && y1 <= 11)
        {
            gotoxy(44, 22);
            cout << "Gana el carro 1!";
            break;
        }
        else if (x2 <= 10 && y2 <= 6)
        {
            gotoxy(44, 22);
            cout << "Gana el carro 2!";
            break;
        }
        else if (x3 <= 10 && y3 <= 1)
        {
            gotoxy(44, 22);
            cout << "Gana el carro 3!";
            break;
        }
    } // Fin del while
}

void multipleCarreras()
{
    int numCarreras = rand() % 6 + 5; // Genera un número aleatorio entre 5 y 10

    for (int i = 0; i < numCarreras; ++i)
    {
        system("cls");
        gotoxy(40, 20);
        cout << "CARRERA " << (i + 1) << " DE " << numCarreras;
        Sleep(3000); // Pausa de 4 segundos antes de iniciar la carrera

        carrera(i + 1); // Inicia la carrera y pasa el número de la carrera

        gotoxy(40, 19);
        cout << "Ganador de la carrera " << (i + 1) << ":";
        Sleep(4000); // Pausa de 4 segundos antes de la siguiente carrera
    }

    gotoxy(40, 20);
    cout << "Todas las carreras han terminado!";
    esperarTecla();
}

int main()
{
    srand(time(0));

    ocultarCursor();

    while (true)
    {
        system("cls");

        gotoxy(40, 17);
        cout << "--------------------------";
        gotoxy(40, 18);
        cout << "SIMULADOR DE CARRERAS CCPL";
        gotoxy(40, 19);
        cout << "--------------------------" << endl;
        gotoxy(40, 20);
        cout << "[1] Jugar" << endl;
        gotoxy(40, 21);
        cout << "[2] Creditos" << endl;
        gotoxy(40, 22);
        cout << "[3] Salir" << endl;

        char tecla = _getch(); // Espera a que se presione una tecla

        switch (tecla)
        {
        case '1':
            multipleCarreras(); // Inicia múltiples carreras
            break;
        case '2':
            creditos(); // Muestra los créditos
            break;
        case '3':
            salir();
            return 0; // Termina el programa
        }
    }

    return 0;
}
