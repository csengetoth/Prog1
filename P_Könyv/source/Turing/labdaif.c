#include <stdio.h>	//printf-et tartalmaza
#include <curses.h>	//curses.h szükséges a getmaxyx-hez, a WINDOW *-hoz, az initscr-hez, mvprintw-hez és a refresh-hez
#include <unistd.h>	//Ez az usleep-hez szükséges 

int
main ( void )
{
    WINDOW *ablak; //létrehozza az ablakot
    ablak = initscr ();	//ez határoza meg a ablak méretét majd át lesz adva a getmaxyx-nek

    int x = 0;
    int y = 0;

    int xnov = 1;
    int ynov = 1;

    int mx; //Az ablak magassága
    int my; //Az ablag szélessége

    for ( ;; ) {

        getmaxyx ( ablak, my , mx ); //az ablak méreteit atadja az my-nak és az mx-nek

        mvprintw ( y, x, "o" ); // kiírja a labdát

        refresh (); 	//tényleges kimenetet ad,  meg kell hívni hogy kimenetet kapjunk
        usleep ( 50000 ); // a labda sebességét határoza meg a program altatásával (az esetunkben 50000 microssecundum)
        clear();

        x = x + xnov;	//a labda vízszintes koordinatája
        y = y + ynov;	//a labda függőleges koordinatája

        if ( x>=mx-1 ) { 	// elerte-e a jobb oldalt?
            xnov = xnov * -1;
        }
        if ( x<=0 ) { 		// elerte-e a bal oldalt?
            xnov = xnov * -1;
        }
        if ( y<=0 ) { 		// elerte-e a tetejet?
            ynov = ynov * -1;
        }
        if ( y>=my-1 ) { 	// elerte-e a aljat?
            ynov = ynov * -1;
        }

    }
}
