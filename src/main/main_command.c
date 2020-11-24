#include "main_command.h"
#include <stdio.h>
#include <stdlib.h>

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

