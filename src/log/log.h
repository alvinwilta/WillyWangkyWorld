/* File : log.h */
#ifndef _log_H
#define _log_H

#include "../point/point.h"
#include "../mesinkata/mesinkata.h"
#include "boolean.h"

typedef struct {
	Kata state; /* string (50 char) */
	POINT posisi; /* point */
	Kata nama; /* nama wahana/ nama upgrade */
} Log;

/* *** Notasi Akses: Selektor LOG *** */
#define state(log) (log).state.TabKata
#define posisi(log) (log).posisi
#define nama(log) (log).nama.TabKata

#endif