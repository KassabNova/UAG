#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "util.h"

void tiempoActual(void)
{
    time_t rawtime;
    struct tm * timeinfo;
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    printf ( "\n\rDia y fecha: %s", asctime (timeinfo) );

    return;
}

void menuSelect(void)
{
    int choice = 1;
    int loop = 0;
    int tecla;

    do
    {
        tecla = getch();
        if (tecla==13)
        {
            switch(choice)
            {
                case 1:
                {
                    break;
                }
                case 2:
                {
                    break;
                }
                case 3:
                {
                    break;
                }
                case 4:
                {
					Sleep(50);
					Creditos();
					return;
                }
                default:
                {
                    printf("\n\r%i",choice);
                    break;
                }
            }
        }
        switch(choice)
        {
            case 1:
            {

                if(tecla==80)
                {
                    clrscr();
                    menuCuerpoAbrir();
                    choice++;
                    break;
                }
                break;
            }
            case 2:
            {
                //printf("Opcion %d", choice);

                if(tecla==80)
                {
                    clrscr();
                    menuCuerpoModificar();
                    choice++;
                    break;
                }
                if(tecla==72)
                {
                    clrscr();
                    menuCuerpoRegistro();
                    choice--;
                    break;
                }
                break;
            }
            case 3:
            {
                //printf("Opcion %d", choice);
                if(tecla==80)
                {
                    clrscr();
                    menuCuerpoCerrar();
                    choice++;
                    break;
                }
                if(tecla==72)
                {
                    clrscr();
                    menuCuerpoAbrir();
                    choice--;
                    break;
                }
                break;
            }
            case 4:
            {
                //printf("Opcion %d", choice);
                if(tecla==72)
                {
                    clrscr();
                    menuCuerpoModificar();
                    choice--;
                }
                break;
            }
            default:
            {
                printf("error en algo");
                break;
            }
        }

    }while(loop==0);

    return;
}

// Cambia los colores si gustas

void menuTitulo(void)
{
    int count=0;
    int x=20, y=10;
    do
    {
		textcolor(RED);
		gotoxy(x,y);
		cprintf("  _      _____ _______ _______ _      ______   _____  ______ _______ _____ ");
		gotoxy(x,y+1);
		cprintf(" | |    |_   _|__   __|__   __| |    |  ____| |  __ \|  ____|__   __/ ____|");
		gotoxy(x,y+2);
		cprintf(" | |      | |    | |     | |  | |    | |__    | |__) | |__     | | | (___  ");
		gotoxy(x,y+3);
		cprintf(" | |      | |    | |     | |  | |    |  __|   |  ___/|  __|    | |  \___ \ ");
		gotoxy(x,y+4);
		cprintf(" | |____ _| |_   | |     | |  | |____| |____  | |    | |____   | |  ____) |");
		gotoxy(x,y+5);
		cprintf(" |______|_____|  |_|     |_|  |______|______| |_|    |______|  |_| |_____/ ");

		Sleep(200);
		textcolor(WHITE);
		clrscr();
		gotoxy(x,y);
		cprintf("  _      _____ _______ _______ _      ______   _____  ______ _______ _____ ");
		gotoxy(x,y+1);
		cprintf(" | |    |_   _|__   __|__   __| |    |  ____| |  __ \|  ____|__   __/ ____|");
		gotoxy(x,y+2);
		cprintf(" | |      | |    | |     | |  | |    | |__    | |__) | |__     | | | (___  ");
		gotoxy(x,y+3);
		cprintf(" | |      | |    | |     | |  | |    |  __|   |  ___/|  __|    | |  \___ \ ");
		gotoxy(x,y+4);
		cprintf(" | |____ _| |_   | |     | |  | |____| |____  | |    | |____   | |  ____) |");
		gotoxy(x,y+5);
		cprintf(" |______|_____|  |_|     |_|  |______|______| |_|    |______|  |_| |_____/ ");
		Sleep(200);
		count++;
    }while(count<3);
    return;
}


void menuCuerpoRegistro(void)
{
    int x=11, y=1;

    gotoxy(x,y++);
    textbackground(WHITE);
	textcolor(BLACK);
    cprintf(" _ ____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ ______ _ ");
    gotoxy(x,y++);
    cprintf("| |                        ____            _     _                                                | |");
    gotoxy(x,y++);
    cprintf("| |                       |  _ \\ ___  __ _(_)___| |_ _ __ __ _ _ __                               | |");
    gotoxy(x,y++);
    cprintf("| |                       | |_) / _ \\/ _` | / __| __| '__/ _` | '__|                              | |");
    gotoxy(x,y++);
    cprintf("| |                       |  _ |  __| (_| | \\__ | |_| | | (_| | |                                 | |");
    gotoxy(x,y++);
    cprintf("| |                       |_| \\_\\___|\\__, |_|___/\\__|_|  \\__,_|_|                                 | |");
    gotoxy(x,y++);
    cprintf("| |                                  |___/                                                        | |");
    gotoxy(x,y++);
    cprintf("|_|____ _____ _____ _____ _____ ______ _____ ___ _ ____ _____ _____ _____ _____ _____ _____ ______|_|");
    textbackground(BLACK);
	textcolor(WHITE);
    gotoxy(x,y++);
    cprintf("|_|____|_____|_____|_____|_____|______|_____|___| |____|_____|_____|_____|_____|_____|_____|______|_|");
    gotoxy(x,y++);
    cprintf("| |                                    _    _          _                                          | |");
    gotoxy(x,y++);
    cprintf("| |                                   / \\  | |__  _ __(_)_ __                                     | |");
    gotoxy(x,y++);
    cprintf("| |                                  / _ \\ | '_ \\| '__| | '__|                                    | |");
    gotoxy(x,y++);
    cprintf("| |                                 / ___ \\| |_) | |  | | |                                       | |");
    gotoxy(x,y++);
    cprintf("| |                                /_/   \\_|_.__/|_|  |_|_|                                       | |");
    gotoxy(x,y++);
    cprintf("|_|____ _____ _____ _____ _____ _____ _____ ___       __ _____ _____ _____ _____ _____ _____ _____|_|");
    gotoxy(x,y++);
    cprintf("|_|____|_____|_____|_____|_____|_____|_____|____|_|_____|_____|_____|_____|_____|_____|_____|_____|_|");
    gotoxy(x,y++);
    cprintf("| |                          __  __           _ _  __ _                                           | |");
    gotoxy(x,y++);
    cprintf("| |                         |  \\/  | ___   __| (_)/ _(_)__ __ _ _ __ _                            | |");
    gotoxy(x,y++);
    cprintf("| |                         | |\\/| |/ _ \\ / _` | | |_| |/ __/ _` | '__|                           | |");
    gotoxy(x,y++);
    cprintf("| |                         | |  | | (_) | (_| | |  _| | (_| (_| | |                              | |");
    gotoxy(x,y++);
    cprintf("| |                         |_|  |_|\\___/ \\__,_|_|_| |_|\\___\\__,_|_|                              | |");
    gotoxy(x,y++);
    cprintf("|_|____ _____ _____ _____ _____ ______ _____ ___ _ ____ _____ _____ _____ _____ _____ _____ ______|_|");
    gotoxy(x,y++);
	cprintf("|_|____|_____|_____|_____|_____|_____|_____|____|_|_____|_____|_____|_____|_____|_____|_____|_____|_|");
	gotoxy(x,y++);
    cprintf("| |                                 ____                                                          | |");
    gotoxy(x,y++);
    cprintf("| |                                / ___|___ _ __ _ __ __ _ _ __                                  | |");
    gotoxy(x,y++);
    cprintf("| |                               | |   / _ | '__| '__/ _` | '__|                                 | |");
    gotoxy(x,y++);
    cprintf("| |                               | |__|  __| |  | | | (_| | |                                    | |");
    gotoxy(x,y++);
    cprintf("| |                                \\____\\___|_|  |_|  \\__,_|_|                                    | |");
    gotoxy(x,y++);
    cprintf("|_|___ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _______|_|");
    gotoxy(x,y++);
    cprintf("|_|___|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_______|_|");


    return;
}

void menuCuerpoAbrir(void)
{
    int x=11, y=1;

    gotoxy(x,y++);
    cprintf(" _ ____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ ______ _ ");
    gotoxy(x,y++);
    cprintf("| |                        ____            _     _                                                | |");
    gotoxy(x,y++);
    cprintf("| |                       |  _ \\ ___  __ _(_)___| |_ _ __ __ _ _ __                               | |");
    gotoxy(x,y++);
    cprintf("| |                       | |_) / _ \\/ _` | / __| __| '__/ _` | '__|                              | |");
    gotoxy(x,y++);
    cprintf("| |                       |  _ |  __| (_| | \\__ | |_| | | (_| | |                                 | |");
    gotoxy(x,y++);
    cprintf("| |                       |_| \\_\\___|\\__, |_|___/\\__|_|  \\__,_|_|                                 | |");
    gotoxy(x,y++);
    cprintf("| |                                  |___/                                                        | |");
    gotoxy(x,y++);
    cprintf("|_|____ _____ _____ _____ _____ ______ _____ ___ _ ____ _____ _____ _____ _____ _____ _____ ______|_|");
    textbackground(WHITE);
	textcolor(BLACK);
    gotoxy(x,y++);
    cprintf("|_|____|_____|_____|_____|_____|______|_____|___| |____|_____|_____|_____|_____|_____|_____|______|_|");
    gotoxy(x,y++);
    cprintf("| |                                    _    _          _                                          | |");
    gotoxy(x,y++);
    cprintf("| |                                   / \\  | |__  _ __(_)_ __                                     | |");
    gotoxy(x,y++);
    cprintf("| |                                  / _ \\ | '_ \\| '__| | '__|                                    | |");
    gotoxy(x,y++);
    cprintf("| |                                 / ___ \\| |_) | |  | | |                                       | |");
    gotoxy(x,y++);
    cprintf("| |                                /_/   \\_|_.__/|_|  |_|_|                                       | |");
    gotoxy(x,y++);
    cprintf("|_|____ _____ _____ _____ _____ _____ _____ ___       __ _____ _____ _____ _____ _____ _____ _____|_|");
    textbackground(BLACK);
	textcolor(WHITE);
    gotoxy(x,y++);
    cprintf("|_|____|_____|_____|_____|_____|_____|_____|____|_|_____|_____|_____|_____|_____|_____|_____|_____|_|");
    gotoxy(x,y++);
    cprintf("| |                          __  __           _ _  __ _                                           | |");
    gotoxy(x,y++);
    cprintf("| |                         |  \\/  | ___   __| (_)/ _(_)__ __ _ _ __ _                            | |");
    gotoxy(x,y++);
    cprintf("| |                         | |\\/| |/ _ \\ / _` | | |_| |/ __/ _` | '__|                           | |");
    gotoxy(x,y++);
    cprintf("| |                         | |  | | (_) | (_| | |  _| | (_| (_| | |                              | |");
    gotoxy(x,y++);
    cprintf("| |                         |_|  |_|\\___/ \\__,_|_|_| |_|\\___\\__,_|_|                              | |");
    gotoxy(x,y++);
    cprintf("|_|____ _____ _____ _____ _____ ______ _____ ___ _ ____ _____ _____ _____ _____ _____ _____ ______|_|");
    gotoxy(x,y++);
	cprintf("|_|____|_____|_____|_____|_____|_____|_____|____|_|_____|_____|_____|_____|_____|_____|_____|_____|_|");
	gotoxy(x,y++);
    cprintf("| |                                 ____                                                          | |");
    gotoxy(x,y++);
    cprintf("| |                                / ___|___ _ __ _ __ __ _ _ __                                  | |");
    gotoxy(x,y++);
    cprintf("| |                               | |   / _ | '__| '__/ _` | '__|                                 | |");
    gotoxy(x,y++);
    cprintf("| |                               | |__|  __| |  | | | (_| | |                                    | |");
    gotoxy(x,y++);
    cprintf("| |                                \\____\\___|_|  |_|  \\__,_|_|                                    | |");
    gotoxy(x,y++);
    cprintf("|_|___ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _______|_|");
    gotoxy(x,y++);
    cprintf("|_|___|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_______|_|");


    return;
}

void menuCuerpoModificar(void)
{
    int x=11, y=1;

    gotoxy(x,y++);
    cprintf(" _ ____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ ______ _ ");
    gotoxy(x,y++);
    cprintf("| |                        ____            _     _                                                | |");
    gotoxy(x,y++);
    cprintf("| |                       |  _ \\ ___  __ _(_)___| |_ _ __ __ _ _ __                               | |");
    gotoxy(x,y++);
    cprintf("| |                       | |_) / _ \\/ _` | / __| __| '__/ _` | '__|                              | |");
    gotoxy(x,y++);
    cprintf("| |                       |  _ |  __| (_| | \\__ | |_| | | (_| | |                                 | |");
    gotoxy(x,y++);
    cprintf("| |                       |_| \\_\\___|\\__, |_|___/\\__|_|  \\__,_|_|                                 | |");
    gotoxy(x,y++);
    cprintf("| |                                  |___/                                                        | |");
    gotoxy(x,y++);
    cprintf("|_|____ _____ _____ _____ _____ ______ _____ ___ _ ____ _____ _____ _____ _____ _____ _____ ______|_|");
    gotoxy(x,y++);
    cprintf("|_|____|_____|_____|_____|_____|______|_____|___| |____|_____|_____|_____|_____|_____|_____|______|_|");
    gotoxy(x,y++);
    cprintf("| |                                    _    _          _                                          | |");
    gotoxy(x,y++);
    cprintf("| |                                   / \\  | |__  _ __(_)_ __                                     | |");
    gotoxy(x,y++);
    cprintf("| |                                  / _ \\ | '_ \\| '__| | '__|                                    | |");
    gotoxy(x,y++);
    cprintf("| |                                 / ___ \\| |_) | |  | | |                                       | |");
    gotoxy(x,y++);
    cprintf("| |                                /_/   \\_|_.__/|_|  |_|_|                                       | |");
    gotoxy(x,y++);
    cprintf("|_|____ _____ _____ _____ _____ _____ _____ ___       __ _____ _____ _____ _____ _____ _____ _____|_|");
    textbackground(WHITE);
	textcolor(BLACK);
    gotoxy(x,y++);
    cprintf("|_|____|_____|_____|_____|_____|_____|_____|____|_|_____|_____|_____|_____|_____|_____|_____|_____|_|");
    gotoxy(x,y++);
    cprintf("| |                          __  __           _ _  __ _                                           | |");
    gotoxy(x,y++);
    cprintf("| |                         |  \\/  | ___   __| (_)/ _(_)__ __ _ _ __ _                            | |");
    gotoxy(x,y++);
    cprintf("| |                         | |\\/| |/ _ \\ / _` | | |_| |/ __/ _` | '__|                           | |");
    gotoxy(x,y++);
    cprintf("| |                         | |  | | (_) | (_| | |  _| | (_| (_| | |                              | |");
    gotoxy(x,y++);
    cprintf("| |                         |_|  |_|\\___/ \\__,_|_|_| |_|\\___\\__,_|_|                              | |");
    gotoxy(x,y++);
    cprintf("|_|____ _____ _____ _____ _____ ______ _____ ___ _ ____ _____ _____ _____ _____ _____ _____ ______|_|");
    textbackground(BLACK);
	textcolor(WHITE);
    gotoxy(x,y++);
	cprintf("|_|____|_____|_____|_____|_____|_____|_____|____|_|_____|_____|_____|_____|_____|_____|_____|_____|_|");
	gotoxy(x,y++);
    cprintf("| |                                 ____                                                          | |");
    gotoxy(x,y++);
    cprintf("| |                                / ___|___ _ __ _ __ __ _ _ __                                  | |");
    gotoxy(x,y++);
    cprintf("| |                               | |   / _ | '__| '__/ _` | '__|                                 | |");
    gotoxy(x,y++);
    cprintf("| |                               | |__|  __| |  | | | (_| | |                                    | |");
    gotoxy(x,y++);
    cprintf("| |                                \\____\\___|_|  |_|  \\__,_|_|                                    | |");
    gotoxy(x,y++);
    cprintf("|_|___ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _______|_|");
    gotoxy(x,y++);
    cprintf("|_|___|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_______|_|");


    return;
}

void menuCuerpoCerrar(void)
{
    int x=11, y=1;

    gotoxy(x,y++);
    cprintf(" _ ____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ ______ _ ");
    gotoxy(x,y++);
    cprintf("| |                        ____            _     _                                                | |");
    gotoxy(x,y++);
    cprintf("| |                       |  _ \\ ___  __ _(_)___| |_ _ __ __ _ _ __                               | |");
    gotoxy(x,y++);
    cprintf("| |                       | |_) / _ \\/ _` | / __| __| '__/ _` | '__|                              | |");
    gotoxy(x,y++);
    cprintf("| |                       |  _ |  __| (_| | \\__ | |_| | | (_| | |                                 | |");
    gotoxy(x,y++);
    cprintf("| |                       |_| \\_\\___|\\__, |_|___/\\__|_|  \\__,_|_|                                 | |");
    gotoxy(x,y++);
    cprintf("| |                                  |___/                                                        | |");
    gotoxy(x,y++);
    cprintf("|_|____ _____ _____ _____ _____ ______ _____ ___ _ ____ _____ _____ _____ _____ _____ _____ ______|_|");
    gotoxy(x,y++);
    cprintf("|_|____|_____|_____|_____|_____|______|_____|___| |____|_____|_____|_____|_____|_____|_____|______|_|");
    gotoxy(x,y++);
    cprintf("| |                                    _    _          _                                          | |");
    gotoxy(x,y++);
    cprintf("| |                                   / \\  | |__  _ __(_)_ __                                     | |");
    gotoxy(x,y++);
    cprintf("| |                                  / _ \\ | '_ \\| '__| | '__|                                    | |");
    gotoxy(x,y++);
    cprintf("| |                                 / ___ \\| |_) | |  | | |                                       | |");
    gotoxy(x,y++);
    cprintf("| |                                /_/   \\_|_.__/|_|  |_|_|                                       | |");
    gotoxy(x,y++);
    cprintf("|_|____ _____ _____ _____ _____ _____ _____ ___       __ _____ _____ _____ _____ _____ _____ _____|_|");
    gotoxy(x,y++);
    cprintf("|_|____|_____|_____|_____|_____|_____|_____|____|_|_____|_____|_____|_____|_____|_____|_____|_____|_|");
    gotoxy(x,y++);
    cprintf("| |                          __  __           _ _  __ _                                           | |");
    gotoxy(x,y++);
    cprintf("| |                         |  \\/  | ___   __| (_)/ _(_)__ __ _ _ __ _                            | |");
    gotoxy(x,y++);
    cprintf("| |                         | |\\/| |/ _ \\ / _` | | |_| |/ __/ _` | '__|                           | |");
    gotoxy(x,y++);
    cprintf("| |                         | |  | | (_) | (_| | |  _| | (_| (_| | |                              | |");
    gotoxy(x,y++);
    cprintf("| |                         |_|  |_|\\___/ \\__,_|_|_| |_|\\___\\__,_|_|                              | |");
    gotoxy(x,y++);
    cprintf("|_|____ _____ _____ _____ _____ ______ _____ ___ _ ____ _____ _____ _____ _____ _____ _____ ______|_|");
    textbackground(WHITE);
	textcolor(BLACK);
    gotoxy(x,y++);
	cprintf("|_|____|_____|_____|_____|_____|_____|_____|____|_|_____|_____|_____|_____|_____|_____|_____|_____|_|");
	gotoxy(x,y++);
    cprintf("| |                                 ____                                                          | |");
    gotoxy(x,y++);
    cprintf("| |                                / ___|___ _ __ _ __ __ _ _ __                                  | |");
    gotoxy(x,y++);
    cprintf("| |                               | |   / _ | '__| '__/ _` | '__|                                 | |");
    gotoxy(x,y++);
    cprintf("| |                               | |__|  __| |  | | | (_| | |                                    | |");
    gotoxy(x,y++);
    cprintf("| |                                \\____\\___|_|  |_|  \\__,_|_|                                    | |");
    gotoxy(x,y++);
    cprintf("|_|___ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _______|_|");
    gotoxy(x,y++);
    cprintf("|_|___|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_______|_|");
    textbackground(BLACK);
	textcolor(WHITE);



    return;
}

void Creditos(void)
 {

	int y=25, x=30;
	char c;
	clrscr();
    do
    {
        if(y>=20)
        {
            c=WHITE;
        }
        else if(y<20 && y>=14)
        {
            c=LIGHTGRAY;
        }
        else if(y<14 && y>=6)
        {
            c=DARKGRAY;
        }
        else if(y<6 && y>=0)
        {
            c=BLACK;
        }
        textcolor(c);
        gotoxy(x+20,y-2);
        cprintf("REALIZADO POR:\n\r");
        gotoxy(x,y-1);
        cprintf("CARLOS KASSAB ANDRE -----------LUIS DANIEL CUEVAS GARCIA\n\r");
        gotoxy(x+10,y);
        cprintf("UNIVERSIDAD AUTONOMA DE GUADALAJARA");
        Sleep(200);
        textcolor(BLACK);
        gotoxy(x+20,y-2);
        cprintf("REALIZADO POR:\n\r");
        gotoxy(x,y-1);
        cprintf("CARLOS KASSAB ANDRE -----------LUIS DANIEL CUEVAS GARCIA\n\r");
        gotoxy(x+10,y);
        cprintf("UNIVERSIDAD AUTONOMA DE GUADALAJARA");

    }while(--y>1);
    return;
}
