#include <stdio.h>
#include "mesinkata.h"
#include "../boolean.h"

boolean EndKata;
Kata CKata;

static char configFilename[] = "config.conf";
static char savefileFilename[] = "savefile.dat";

static FILE * savefile;

void IgnoreBlank()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = MARK */
{
    while (CC != EOF && (CC==BLANK  || CC == NEWLINE)){
        ADV();
    }
}

void IgnoreBlankSCANF()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = MARK */
{
    while (CC != EOF && (CC==BLANK)){
        ADVSCANF();
    }
}

/*Berguna untuk membaca angka dari File*/
int readAngka(){
    int n = 0;
    IgnoreBlank();
    while (!EOP && CC != EOF && CC != BLANK && CC != NEWLINE) {
        n = n*10 + (CC-'0');
        ADV();
    }
    return n;
}

void readSCANF(Kata *input)
{
    STARTSCANF();
    IgnoreBlankSCANF();
    (*input).Length = 0;

    while((!EOP) && (CC!=NEWLINE))
    {
        (*input).TabKata[(*input).Length] = CC;
        ++(*input).Length;
        ADVSCANF();
    }
}

void readAngkaSCANF(int *X)
{
    int tmp;
    STARTSCANF();
    *X = 0;
    while(!EOP && CC!=NEWLINE)
    {
        tmp = CC - '0';
        *X = (*X)*10 + tmp; 
        ADVSCANF(); 
    }
}

void STARTKATA(){
    START();
    IgnoreBlank();
    if (CC==MARK){
        EndKata = true;
    }else{
        EndKata = false;
        SalinKata();
    }
}
/* I.S. : CC sembarang 
   F.S. : EndKata = true, dan CC = MARK; 
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

void ADVKATA(){
    IgnoreBlank();
    if(CC==MARK){
        EndKata = true;
    }else{
        SalinKata();
        IgnoreBlank();
    }
}
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.		  
   Proses : Akuisisi kata menggunakan procedure SalinKata */

void SalinKata(){
    int i = 0;
    IgnoreBlank();
    while ((CC!=MARK)&&(CC!=BLANK)){
        if (i<NMax){
            CKata.TabKata[i] = CC;
        }
        i++;
        ADV();
    }
    if (i<=NMax){
        CKata.Length = i;
    }else{
        CKata.Length=NMax;
    }
}
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

boolean IsKataSama(Kata K1, char * S){
    boolean found = true;
    int pjg, i;
    if (K1.Length != strlen(S)){
        return false;
    }else{
        i = 0;
        while ((i < pjg) && (found)){
            if (K1.TabKata[i] != S[i]){
                found = false;
            }else{
                i++;
            }
        }
    }
    return found;
}

int intstring(Kata K){
    int result = 0;
    int temp;
    for(int i = 0; i < K.Length; i++){
        temp = (int) K.TabKata[i] - '0';
        result = result * 10 + temp;
    }
    return result;
}

void printKata(Kata K)
{
    for(int i=0;i<K.Length;i++) printf("%c",K.TabKata[i]);
    printf("\n");
}

void readConfigFile(MATRIKS *M, buildingsArray *arr, graph *G, int * buildingCounter)
{
    // Start reading config file
    START(configFilename);
    IgnoreBlank();

    // Read map size
    IgnoreBlank();
    int row = readAngka();
    IgnoreBlank();
    int col = readAngka();
    printf("Map size: ");
    printf("%dx%d\n", row, col);
    
    // Initialize matriks
    MakeMATRIKS(row,col,M);

    // Read building count
    IgnoreBlank();
    int t = readAngka();
    *buildingCounter = t;
    printf("Building count: ");
    printf("%d\n", t);

    printf("Baca Wahana...\n");

    // Initialize array size
    MakeEmptyArray(arr,t);
    /*

    for(int i=1;i<=t;i++)
    {
        // Read building type
        IgnoreBlank();
        char buildingType = CC;
        ADV();

        // Construct buildings
        addressBuildings ptr = allocateBuilding();

        if(buildingType=='C')  makeCastle(ptr,0);
        else if(buildingType=='T') makeTower(ptr, 0);
        else if(buildingType=='F') makeFort(ptr, 0);
        else if(buildingType=='V') makeVillage(ptr, 0);

        // Read building coordinate
        IgnoreBlank();
        int buildingRow = readAngka();
        IgnoreBlank();
        int buildingCol = readAngka();
        
        // Construct and send to array
        Elmt(*arr, i) = makeBuildingCoord(ptr, buildingRow, buildingCol);
        Neff(*arr)++;
        insertStructure(M, Elmt(*arr,i));
        
    }
    */

    printf("Membuat graph...\n");
    // Initialize graph
    /*
    createGraph(G,t);

    for(int i=1;i<=t;i++)
    {
        for(int j=1;j<=t;j++)
        {
            IgnoreBlank();
            int connection = readAngka();
            if(connection) insertChild(G,i,j);
        }
    }
    */
    printf("Configuration file loaded!\n");
    // printGraph(*G);
}

void saveToFile(MATRIKS *M, buildingsArray *arr, graph *G, int turn, boolean ignore, boolean critical, boolean extraTurn, queue *Q1, queue *Q2, boolean criticalP1, boolean criticalP2, boolean isShieldActiveP1, boolean shieldActivatedP1, boolean isShieldActiveP2, boolean shieldActivatedP2, int counterShieldP1, int counterShieldP2, int lengthFlagAttack, int lengthFlagMove, int * arrFlagAttack, int * arrFlagMove)
{
    printf("Saving to ");
    printf("savefile.dat");
    printf("...");
    
    savefile = fopen(savefileFilename, "w");
    // Output map size
    fprintf(savefile,"%d %d\n", nRowEff(*M)-1, nColEff(*M)-1);

    // Output building count
    int t=MaxEl(*arr);
    fprintf(savefile,"%d\n", t);

    // Output all bulding with its state
    // Format : type rb cb owner level troops defense
    /*
    for(int i=1;i<=t;i++)
    {
        char type;
        if(type(*build(*Elmt(*arr,i)))==1) type='C';
        else if(type(*build(*Elmt(*arr,i)))==2) type='T';
        else if(type(*build(*Elmt(*arr,i)))==3) type='F';
        else if(type(*build(*Elmt(*arr,i)))==4) type='V';

        fprintf(savefile, "%c %d %d %d %d %d %d\n", type, row(*Elmt(*arr,i)), col(*Elmt(*arr,i)), owner(*build(*Elmt(*arr,i))), level(*build(*Elmt(*arr,i))), troops(*build(*Elmt(*arr,i))), defense(*build(*Elmt(*arr,i))));
    }
    */
    // Output graph representation in adjacency list form
    for(int i=1;i<=t;i++)
    {
        for(int j=1;j<=t;j++) fprintf(savefile, "%d ", isConnected(*G, i, j) ? 1 : 0);
        fprintf(savefile,"\n");
    }

    // Output for whose turn it is
    fprintf(savefile, "%d\n", turn);
    // Output ignore defense state
    fprintf(savefile, "%d\n", ignore);
    // Output ignore critical state
    fprintf(savefile, "%d\n", ignore);
    // Output extra turn state
    fprintf(savefile, "%d\n", extraTurn);
    // Output criticalP1
    fprintf(savefile, "%d\n", criticalP1);
    // Output criticalP2
    fprintf(savefile, "%d\n", criticalP2);
    // Output isShieldActiveP1
    fprintf(savefile, "%d\n", isShieldActiveP1);
    // Output shieldActivatedP1
    fprintf(savefile, "%d\n", shieldActivatedP1); 
    // Output isShieldActiveP2
    fprintf(savefile, "%d\n", isShieldActiveP2);
    // Output shieldActivatedP2
    fprintf(savefile, "%d\n", shieldActivatedP2);
    // Output counterShieldP1
    fprintf(savefile, "%d\n", counterShieldP1);
    // Output counterShieldP2
    fprintf(savefile, "%d\n", counterShieldP2);
    // Output skill queue for player 1
    if(isEmptyQueue(*Q1)) for(int i=1;i<=10;i++) fprintf(savefile,"0 ");
    else
    {
        int count=0;
        for(int i=Head(*Q1);count<10;i=(i%10)+1) {
            if((*Q1).T[i] == 1 || (*Q1).T[i] == 2 || (*Q1).T[i] == 3 || (*Q1).T[i] == 4 || (*Q1).T[i] == 5 || (*Q1).T[i] == 6 || (*Q1).T[i] == 7){
                fprintf(savefile, "%d ", (*Q1).T[i]);
            }
            else{
                fprintf(savefile, "0 ");
            }
            ++count;
        }
    }
    fprintf(savefile, "\n");
    
    // Output skill queue for player 2
    if(isEmptyQueue(*Q2)) for(int i=1;i<=10;i++) fprintf(savefile,"0 ");
    else
    {
        int count=0;
        for(int i=Head(*Q2);count<10;i=(i%10)+1) {
            if((*Q2).T[i] == 1 || (*Q2).T[i] == 2 || (*Q2).T[i] == 3 || (*Q2).T[i] == 4 || (*Q2).T[i] == 5 || (*Q2).T[i] == 6 || (*Q2).T[i] == 7){
                fprintf(savefile, "%d ", (*Q1).T[i]);
            }
            else{
                fprintf(savefile, "0 ");
            }
            ++count;
        }
    }
    fprintf(savefile, "\n");
    // Output buildings inside flagAttack
    fprintf(savefile, "%d\n", lengthFlagAttack);
    // Output flagAttack
    for(int i = 1; i <= lengthFlagAttack; i++){
        fprintf(savefile, "%d ", arrFlagAttack[i]);
    }
    fprintf(savefile, "\n");
    //Output buildings inside flagMove
    fprintf(savefile, "%d\n", lengthFlagMove);
    // Output flagMove
    for(int i = 1; i <= lengthFlagMove; i++){
        fprintf(savefile, "%d ", arrFlagMove[i]);
    }
    fprintf(savefile, "\n");
    // Close stream
    fclose(savefile);
}

// Load from file
void loadFromFile(matrix *M, buildingsArray *arr, graph *G, int *turn, boolean *ignore, boolean *critical, boolean *extraTurn, queue *Q1, queue *Q2, int *buildingCounter, boolean *criticalP1, boolean *criticalP2, boolean *isShieldActiveP1, boolean *shieldActivatedP1, boolean *isShieldActiveP2, boolean *shieldActivatedP2, int *counterShieldP1, int *counterShieldP2, int * lengthFlagAttack_, int * lengthFlagMove_, int ** arrFlagAttack, int ** arrFlagMove)
{
    // Start reading filename
    START(savefileFilename);
    IgnoreBlank();

    // Read map size
    IgnoreBlank();
    int row = readAngka();
    IgnoreBlank();
    int col = readAngka();

    // Initialize matrix
    createEmptyMatrix(row,col,M);

    // Read building count
    IgnoreBlank();
    int t = readAngka();
    *buildingCounter = t;

    colorPrint("Map size: ", BRIGHT);
    printf("%dx%d\n", row, col);
    colorPrint("Building count: ", BRIGHT);
    printf("%d\n", t);

    colorPrint("Reading building states...\n", BRIGHT);

    // Initialize array size
    MakeEmptyArray(arr,t);

    for(int i=1;i<=t;i++)
    {
        // Read building type
        IgnoreBlank();
        char buildingType = CC;
        ADV();

        // Construct buildings
        addressBuildings ptr = allocateBuilding();

        if(buildingType=='C')  makeCastle(ptr,0);
        else if(buildingType=='T') makeTower(ptr, 0);
        else if(buildingType=='F') makeFort(ptr, 0);
        else if(buildingType=='V') makeVillage(ptr, 0);

        // Read building coordinate
        IgnoreBlank();
        int buildingRow = readAngka();
        IgnoreBlank();
        int buildingCol = readAngka();
        
        //Read building owner
        IgnoreBlank();
        int buildingOwner = readAngka();
        owner(*ptr) = buildingOwner;

        //Read building level
        IgnoreBlank();
        int buildingLevel = readAngka();
        level(*ptr) = buildingLevel;

        //Read building troops
        IgnoreBlank();
        int buildingTroops = readAngka();
        troops(*ptr) = buildingTroops;

        //Read building defense state
        IgnoreBlank();
        int buildingDefense = readAngka();
        defense(*ptr) = buildingDefense;

        // Construct and send to array
        Elmt(*arr, i) = makeBuildingCoord(ptr, buildingRow, buildingCol);
        ++Neff(*arr);
        insertStructure(M, Elmt(*arr,i));
        
    }

    colorPrint("Building graph...\n", BRIGHT);
    // Initialize graph
    createGraph(G,t);

    for(int i=1;i<=t;i++)
    {
        for(int j=1;j<=t;j++)
        {
            IgnoreBlank();
            int connection = readAngka();
            if(connection) insertChild(G,i,j);
        }
    }

    // Read turn state
    IgnoreBlank();
    *turn = readAngka();
    // Read ignore state
    IgnoreBlank();
    *ignore = readAngka();
    // Read critical state
    IgnoreBlank();
    *critical = readAngka();
    // Read extra turn state
    IgnoreBlank();
    *extraTurn = readAngka();
    // Read critical P1
    *criticalP1 = readAngka();
    // Read critical P2
    *criticalP2 = readAngka();
    // Read isShieldActiveP1
    *isShieldActiveP1 = readAngka();
    // Read shieldActivatedP1
    *shieldActivatedP1 = readAngka();
    // Read isShieldActiveP2
    *isShieldActiveP2 = readAngka();
    // Read shieldActivatedP2
    *shieldActivatedP2 = readAngka();
    // Read counterShieldP1
    *counterShieldP1 = readAngka();
    // Read counterShieldP2
    *counterShieldP2 = readAngka();

    // Input to queue
    int tempHead = unDef;
    int tempTail = unDef;

    createQueue(Q1,10);
    int counter = 1;
    for(int i=1;i<=10;i++) 
    {
        IgnoreBlank();
        int tempSkill1 = readAngka();
        if(tempSkill1 != 0){
            Add(Q1, tempSkill1);
            tempHead = 1;
            tempTail = counter;
            counter++;
        }
    }
    Head(*Q1) = tempHead;
    Tail(*Q1) = tempTail;

    // Input to queue
    createQueue(Q2, 10);
    counter = 0;
    for(int i=1;i<=10;i++) 
    {
        IgnoreBlank();
        int tempSkill2 = readAngka();
        if(tempSkill2 != 0){
            tempHead = 1;
            tempTail = counter;
            counter++;
        }
    }
    Head(*Q2) = tempHead;
    Tail(*Q2) = tempTail;

    // Input to flagAttack
    int lengthFlagAttack = readAngka();
    *arrFlagAttack = (int *) malloc((lengthFlagAttack+1) * sizeof(int));
    for(int i = 1; i <= lengthFlagAttack; i++){
        IgnoreBlank();
        (*arrFlagAttack)[i] = readAngka();
    }
    // Input to flagMove
    int lengthFlagMove = readAngka();
    *arrFlagMove = (int *) malloc((lengthFlagMove+1) * sizeof(int));
    for(int i = 1; i <= lengthFlagMove; i++){
        IgnoreBlank();
        (*arrFlagMove)[i] = readAngka();
    }
    // Output
    *lengthFlagAttack_ = lengthFlagAttack;
    *lengthFlagMove_ = lengthFlagMove;
    colorPrint("Save file loaded, ready to play!\n", GREEN);
}