#include <stdlib.h>
#include <stdio.h>
#include "../boolean.h"
#include "../point/point.h"
#include "../jam/jam.h"
#include "../array/array.h"
#include "player.h"

int main()
{
    JAM J;
    Hour(J) = 8;
    Minute(J) = 30;
    Second(J) = 0;
    POINT A;
    Absis(A) = 1;
    Ordinat(A) = 3;
    printf("A : <%f,%f>\n", Absis(A), Ordinat(A));

    Player P = NewPlayer(A, J, 500);
    printf("Money : %d\n", Money(&P));
    printf("JAM : %02d:%02d:%02d\n", Hour(Wkt(&P)), Minute(Wkt(&P)), Second(Wkt(&P)));
    Maju(&P);
    Maju(&P);
    Mundur(&P);
    Kanan(&P);
    Kanan(&P);
    Kiri(&P);
    printf("<%f,%f>\n", Absis(Pos(&P)), Ordinat(Pos(&P)));

    AddKayu(&P, 5);
    AddBatu(&P, 5);
    AddKaca(&P, 5);
    printf("Kayu: %d, batu: %d, kaca: %d\n", Elmt(Mat(&P), 0), Elmt(Mat(&P), 1), Elmt(Mat(&P), 2));
    printf("Money : %d\n", Money(&P));
    SubKayu(&P, 2);
    SubBatu(&P, 2);
    SubKaca(&P, 2);
    printf("Kayu: %d, batu: %d, kaca: %d\n", Elmt(Mat(&P), 0), Elmt(Mat(&P), 1), Elmt(Mat(&P), 2));
    printf("Money : %d\n", Money(&P));
    AddWaktu(&P, 140);
    printf("JAM : %02d:%02d:%02d\n", Hour(Wkt(&P)), Minute(Wkt(&P)), Second(Wkt(&P)));
    return 0;
}
