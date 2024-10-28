#include <iostream> // Para usar cout y cin
#include <windows.h> // Para usar las funciones de la consola
#include <conio.h> // Para usar _getch() y _kbhit()
#include <cstdlib> // Para usar srand() y rand()
#include <ctime> // Para usar time()

using namespace std; // Para no tener que escribir std::cout y std::cin

// Variables globales
int carrerasGanadasCarro1 = 0;
int carrerasGanadasCarro2 = 0;
int carrerasGanadasCarro3 = 0;

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

void MIKE(int x, int y) // Funcion para dibujar el carro MIKE
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

void MATE(int x, int y) // Funcion para dibujar el carro MATE
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

void SPIRIT(int x, int y) // Funcion para dibujar el SPIRIT
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

void pistaInferior() // Funcion para dibujar la pista inferior
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

void pistaSuperior() // Funcion para dibujar la pista superior
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

void pistaDerecha() // Funcion para dibujar la pista derecha
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

void pistas() // Funcion para dibujar las pistas
{
    pistaSuperior();
    pistaInferior();
    pistaDerecha();
}

void esperarTecla() // Funcion para esperar a que se presione una tecla
{
    gotoxy(0, 24);
    cout << "Presione <ESCAPE> para volver al menu principal" << endl;

    while (true)
    {
        if (_kbhit()) // Si se presiona una tecla
        {
            char tecla = _getch(); // Obtener la tecla presionada
            if (tecla == 27) // 27 es el codigo ASCII del ESCAPE
            {
                break; // Salir del bucle
            }
        }
    }
}

void creditos() // Funcion para mostrar los creditos
{
    system("cls"); // Limpiar la pantalla
    color(7); // Cambiar el color de la letra a blanco
    cout << "-----------------------------------------------------------------------------------" << endl;
    cout << "-----------------------------------------------------------------------------------" << endl;
    cout << "  ______     ______     ______     _____     __     ______   ______     ______     " << endl;
    cout << " /\\  ___\\   /\\  == \\   /\\  ___\\   /\\  __-.  /\\ \\   /\\__  _\\ /\\  __ \\   /\\  ___\\    " << endl;
    cout << " \\ \\ \\____  \\ \\  __<   \\ \\  __\\   \\ \\ \\/\\ \\ \\ \\ \\  \\/_/\\ \\/ \\ \\ \\/\\ \\  \\ \\___  \\   " << endl;
    cout << "  \\ \\_____\\  \\ \\_\\ \\_\\  \\ \\_____\\  \\ \\____-  \\ \\_\\    \\ \\_\\  \\ \\_____\\  \\/\\_____\\  " << endl;
    cout << "   \\/_____/   \\/_/ /_/   \\/_____/   \\/____/   \\/_/     \\/_/   \\/_____/   \\/_____/  " << endl;
    cout << "                                                                                   " << endl;
    cout << "                                                                                   " << endl;
    cout << "                          UPC CAMPUS SAN MIGUEL                                    " << endl;
    cout << "                     INTRODUCCION A LOS ALGORITMOS                                 " << endl;
    cout << "                             GAME JAM 2024                                         " << endl;
    cout << "                                                                                   " << endl;
    cout << "                             PROGRAMADORES                                         " << endl;
    cout << "                       Ventosilla Chelge Nicolas                                   " << endl;
    cout << "                          Ponce Wong Jarumi                                        " << endl;
    cout << "                         Celis Salinas Alvaro                                      " << endl;
    cout << "                                                                                   " << endl;
    cout << "                               DOCENTE                                             " << endl;
    cout << "                         Rojas Sihuay Diego                                        " << endl;
    cout << "                                                                                   " << endl;
    cout << "                                                                                   " << endl;
    cout << "-----------------------------------------------------------------------------------" << endl;
    cout << "-----------------------------------------------------------------------------------" << endl;
    esperarTecla(); // Esperar a que se presione una tecla
}

void salir()
{
    system("cls");

    color(7); // Cambiar el color de la letra a blanco

    cout << "--------------------------------------------------------------------------" << endl;
    cout << "--------------------------------------------------------------------------" << endl;
    cout << "    ____                         _                                        " << endl;
    cout << "   / ___|  _ __    __ _    ___  (_)   __ _   ___     _ __     ___    _ __ " << endl;
    cout << "  | |  _  | '__|  / _` |  / __| | |  / _` | / __|   | '_ \\   / _ \\  | '__|" << endl;
    cout << "  | |_| | | |    | (_| | | (__  | | | (_| | \\__ \\   | |_) | | (_) | | |   " << endl;
    cout << "   \\____| |_|     \\__,_|  \\___| |_|  \\__,_| |___/   | .__/   \\___/  |_|   " << endl;
    cout << "                                                    |_|                   " << endl;
    cout << "                                                                          " << endl;
    cout << "                     _                                                    " << endl;
    cout << "                    | |  _   _    __ _    __ _   _ __                     " << endl;
    cout << "                 _  | | | | | |  / _` |  / _` | | '__|                    " << endl;
    cout << "                | |_| | | |_| | | (_| | | (_| | | |                       " << endl;
    cout << "                 \\___/   \\__,_|  \\__, |  \\__,_| |_|                       " << endl;
    cout << "                                 |___/                                    " << endl;
    cout << "                                                                          " << endl;
    cout << "--------------------------------------------------------------------------" << endl;
    cout << "--------------------------------------------------------------------------" << endl;
    exit(0);
}

void cuentaRegresiva(int numeroCarrera) // Funcion para mostrar la cuenta regresiva
{
    color(7); // Cambiar el color de la letra a blanco
    for (int i = 3; i > 0; --i)
    {
        gotoxy(40, 20);
        cout << "LA CARRERA " << numeroCarrera << " COMIENZA EN: " << i; // Mostrar la cuenta regresiva
        Sleep(1000); // Pausa de 1 segundo
    }

    gotoxy(40, 20);
    cout << "                           "; // Borrar el mensaje de cuenta regresiva
}

void carrera(int numeroCarrera) // Funcion para simular la carrera
{
    system("cls"); // Limpiar la pantalla

    pistas(); // Dibujar las pistas

    // Coordenadas iniciales de los carros
    int x1 = 10, y1 = 26;
    int x2 = 10, y2 = 31;
    int x3 = 10, y3 = 36;

    // Dibujar los carros en sus posiciones iniciales
    MIKE(x1, y1);
    MATE(x2, y2);
    SPIRIT(x3, y3);

    cuentaRegresiva(numeroCarrera); // Mostrar la cuenta regresiva

    time_t tiempoInicio = time(0); // Guardar el tiempo de inicio

    while (true)
    {
        borrarCarro(x1, y1); // Borrar MIKE
        borrarCarro(x2, y2); // Borrar MATE
        borrarCarro(x3, y3); // Borrar SPIRIT

        int avance1 = rand() % 3 + 1; // Genera un número aleatorio entre 1 y 3
        int avance2 = rand() % 4 + 1; // Genera un número aleatorio entre 1 y 4
        int avance3 = rand() % 5 + 1; // Genera un número aleatorio entre 1 y 5

        // Movimiento de MIKE
        if (x1 < 80 && y1 == 26)
            x1 += avance1;
        else if (x1 >= 80 && y1 > 11)
            y1 -= avance1;
        else if (y1 <= 11 && x1 > 0)
            x1 -= avance1;

        // Asegurarse de que MIKE no salga de los límites
        if (x1 > 80) x1 = 80; // 80 es el límite derecho
        if (y1 < 11) y1 = 11; // 11 es el límite superior

        // Movimiento del MATE
        if (x2 < 92 && y2 == 31)
            x2 += avance2;
        else if (x2 >= 92 && y2 > 6)
            y2 -= avance2;
        else if (y2 <= 6 && x2 > 0)
            x2 -= avance2;

        // Asegurarse de que el MATE no salga de los límites
        if (x2 > 92) x2 = 92;
        if (y2 < 6) y2 = 6;

        // Movimiento del SPIRIT
        if (x3 < 104 && y3 == 36)
            x3 += avance3;
        else if (x3 >= 104 && y3 > 1)
            y3 -= avance3;
        else if (y3 <= 1 && x3 > 0)
            x3 -= avance3;

        // Asegurarse de que el SPIRIT no salga de los límites
        if (x3 > 104) x3 = 104;
        if (y3 < 1) y3 = 1;

        // Dibujar los carros en sus nuevas posiciones
        MIKE(x1, y1);
        MATE(x2, y2);
        SPIRIT(x3, y3);

        color(7); // Cambiar el color de la letra a blanco

        // Calcular y mostrar el tiempo transcurrido
        time_t tiempoActual = time(0); // Obtener el tiempo actual
        int tiempoTranscurrido = difftime(tiempoActual, tiempoInicio); // Calcular el tiempo transcurrido
        gotoxy(0, 42);
        cout << "Tiempo transcurrido: " << tiempoTranscurrido << " segundos";

        Sleep(100); // Pausa de 0.1 segundos

        color(7); // Cambiar el color de la letra a blanco

        // Condición de victoria
        if (x1 <= 10 && y1 <= 11)
        {
            gotoxy(44, 22);
            cout << "Gana MIKE!";
            carrerasGanadasCarro1++; // Incrementar el contador de carreras ganadas para el MIKE
            break;
        }
        else if (x2 <= 10 && y2 <= 6)
        {
            gotoxy(44, 22);
            cout << "Gana MATE!";
            carrerasGanadasCarro2++; // Incrementar el contador de carreras ganadas para el MATE
            break;
        }
        else if (x3 <= 10 && y3 <= 1)
        {
            gotoxy(44, 22);
            cout << "Gana SPIRIT!";
            carrerasGanadasCarro3++; // Incrementar el contador de carreras ganadas para el SPIRIT
            break;
        }
    } // Fin del while
}

void multiplesCarreras() // Funcion para simular múltiples carreras
{
    int numCarreras = rand() % 6 + 5; // Genera un número aleatorio entre 5 y 10

    for (int i = 0; i < numCarreras; ++i)
    {
        system("cls");
        gotoxy(40, 20);
        cout << "CARRERA " << (i + 1) << " DE " << numCarreras; // Mostrar el número de la carrera
        Sleep(2000); // Pausa de 2 segundos antes de iniciar la carrera

        carrera(i + 1); // Inicia la carrera y pasa el número de la carrera

        gotoxy(40, 19);
        cout << "Ganador de la carrera " << (i + 1) << ":";
        Sleep(4000); // Pausa de 4 segundos antes de la siguiente carrera
    }

    system("cls");

    color(7); // Cambiar el color de la letra a blanco

    gotoxy(40, 20);
    cout << "Todas las carreras han terminado!" << endl;

    // Mostrar los resultados
    gotoxy(40, 22);
    cout << "RANKING:" << endl;

    // Determinar primer, segundo y tercer lugar
    if (carrerasGanadasCarro1 >= carrerasGanadasCarro2 && carrerasGanadasCarro1 >= carrerasGanadasCarro3)
    {
        color(3);
        gotoxy(40, 25);
        cout << "Primer lugar";
        gotoxy(55, 25);
        cout << "MIKE";
        MIKE(65, 23);
        gotoxy(80, 25);
        cout << carrerasGanadasCarro1;

        if (carrerasGanadasCarro2 >= carrerasGanadasCarro3)
        {
            color(4);
            gotoxy(40, 29);
            cout << "Segundo lugar";
            gotoxy(55, 29);
            cout << "MATE";
            MATE(65, 27);
            gotoxy(80, 29);
            cout << carrerasGanadasCarro2;

            color(5);
            gotoxy(40, 33);
            cout << "Tercer lugar";
            gotoxy(55, 33);
            cout << "SPIRIT";
            SPIRIT(65, 31);
            gotoxy(80, 33);
            cout << carrerasGanadasCarro3;
        }
        else
        {
            color(5);
            gotoxy(40, 29);
            cout << "Segundo lugar";
            gotoxy(55, 29);
            cout << "SPIRIT";
            SPIRIT(65, 27);
            gotoxy(80, 29);
            cout << carrerasGanadasCarro3;

            color(4);
            gotoxy(40, 33);
            cout << "Tercer lugar";
            gotoxy(55, 33);
            cout << "MATE";
            MATE(65, 31);
            gotoxy(80, 33);
            cout << carrerasGanadasCarro2;
        }
    }
    else if (carrerasGanadasCarro2 >= carrerasGanadasCarro1 && carrerasGanadasCarro2 >= carrerasGanadasCarro3)
    {
        color(4);
        gotoxy(40, 25);
        cout << "Primer lugar";
        gotoxy(55, 25);
        cout << "MATE";
        MATE(65, 23);
        gotoxy(80, 25);
        cout << carrerasGanadasCarro2;

        if (carrerasGanadasCarro1 >= carrerasGanadasCarro3)
        {
            color(3);
            gotoxy(40, 29);
            cout << "Segundo lugar";
            gotoxy(55, 29);
            cout << "MIKE";
            MIKE(65, 27);
            gotoxy(80, 29);
            cout << carrerasGanadasCarro1;

            color(5);
            gotoxy(40, 33);
            cout << "Tercer lugar";
            gotoxy(55, 33);
            cout << "SPIRIT";
            SPIRIT(65, 31);
            gotoxy(80, 33);
            cout << carrerasGanadasCarro3;
        }
        else
        {
            color(5);
            gotoxy(40, 29);
            cout << "Segundo lugar";
            gotoxy(55, 29);
            cout << "SPIRIT";
            SPIRIT(65, 27);
            gotoxy(80, 29);
            cout << carrerasGanadasCarro3;

            color(3);
            gotoxy(40, 33);
            cout << "Tercer lugar";
            gotoxy(55, 33);
            cout << "MIKE";
            MIKE(65, 31);
            gotoxy(80, 33);
            cout << carrerasGanadasCarro1;
        }
    }
    else
    {
        color(5);
        gotoxy(40, 25);
        cout << "Primer lugar";
        gotoxy(55, 25);
        cout << "SPIRIT";
        SPIRIT(65, 23);
        gotoxy(80, 25);
        cout << carrerasGanadasCarro3;

        if (carrerasGanadasCarro1 >= carrerasGanadasCarro2)
        {
            color(3);
            gotoxy(40, 29);
            cout << "Segundo lugar";
            gotoxy(55, 29);
            cout << "MIKE";
            MIKE(65, 27);
            gotoxy(80, 29);
            cout << carrerasGanadasCarro1;

            color(4);
            gotoxy(40, 33);
            cout << "Tercer lugar";
            gotoxy(55, 33);
            cout << "MATE";
            MATE(65, 31);
            gotoxy(80, 33);
            cout << carrerasGanadasCarro2;
        }
        else
        {
            color(4);
            gotoxy(40, 29);
            cout << "Segundo lugar";
            gotoxy(55, 29);
            cout << "MATE";
            MATE(65, 27);
            gotoxy(80, 29);
            cout << carrerasGanadasCarro2;

            color(3);
            gotoxy(40, 33);
            cout << "Tercer lugar";
            gotoxy(55, 33);
            cout << "MIKE";
            MIKE(65, 31);
            gotoxy(80, 33);
            cout << carrerasGanadasCarro1;
        }
    }

    Sleep(7000); // Pausa de 7 segundos anter de terminar el programa

    salir(); // Salir del programa
}

int main()
{
    srand(time(0)); // Inicializar el generador de números aleatorios

    ocultarCursor(); // Ocultar el cursor

    while (true)
    {
        system("cls");

        color(7); // Cambiar el color de la letra a blanco
        gotoxy(40, 15);
        cout << "*******************************************";
        gotoxy(40, 16);
        cout << "*              MOTOR SIMULATOR            *";
        gotoxy(40, 17);
        cout << "*******************************************";
        gotoxy(40, 18);
        cout << "*                         _____           *";
        gotoxy(40, 19);
        cout << "*     1. Jugar        ___/__|__\\___      *";
        gotoxy(40, 20);
        cout << "*     2. Creditos     |  _     _    |     *";
        gotoxy(40, 21);
        cout << "*     3. Salir        -(_)-------(_)-     *";
        gotoxy(40, 22);
        cout << "*                                         *";
        gotoxy(40, 23);
        cout << "*******************************************";

        char tecla = _getch(); // Espera a que se presione una tecla

        switch (tecla)
        {
        case '1':
            multiplesCarreras(); // Inicia múltiples carreras
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
