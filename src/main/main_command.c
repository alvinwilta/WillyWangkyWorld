#include "mesinkata.h"
#include "mesinkar.h"
#include "../wahana/wahana.h"
#include "../matriks/matriks.h"
#include "../graph/graph.h"
#include "../queue/queue.h"
#include "../stack/stack.h"
#include "../array/array.h"
#include "../point/point.h"

void MasukOffice(){
    Kata perintahoffice;
    readSCANF(&perintahoffice);
    if (IsKataSama(perintahoffice, "Details")){
        /*Tampilkan List Wahana*/
        /*Pilih Detail Wahana*/
    }else if (IsKataSama(perintahoffice, "Report")){
        /*Tampilkan List Wahana*/
        /*Pilih Report Wahana*/
    }else{/*exit*/
        main_menu();
    }
}

