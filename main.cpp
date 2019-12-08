#include <iostream>

int inputarray(int *array, int arraysize){
  int i =0;
  for (i=0; i<arraysize; i++){
    if(scanf("%i",&array[i]) == 1){
    }
    else{
        throw std::invalid_argument("Input is not an integer"); 
    }
  }
  return 1;
};

int inputarraysize(){
  int arraysize;
  if(scanf("%i",&arraysize) == 1){
  }
  else{
    throw std::invalid_argument("Input is not an integer");
  }
  return arraysize;
};

int arrayswap(int *array,int arraysize){
  int i;
  int arraytemp[arraysize+1];
  for (i=0; i<(sizeof(array) / sizeof(int)); i++){
    arraytemp[i]=array[i];
  }
  for (i=(sizeof(array) / sizeof(int))+1; i<(arraysize+1); i++){
    arraytemp[i]=0;
  }
  return *arraytemp;
}

void filter(int *arrayx, int *arraya, int *arrayb, int *arrayY, int *arrayF, int *arrayA, int sizeofarr)
{
    int Y=0;
    int F=0;
    int r;
    int e;

    for (r=0; r<sizeofarr; r++) {
        for (e=0; e<=r; e++) {
            Y+=arraya[e]*arrayx[r-e];
            printf("%i*%i + ",arraya[e],arrayx[r-e]);
            if (r-e-1 >= 0) {
                F+=arrayb[e]*arrayA[r-e-1];
                printf("%i*%i + ",arrayb[e],arrayA[r-e-1]);
                }
            if (r-e-1 < 0) {
                F+=arrayb[e]*0;
                printf("%i*0 + ",arrayb[e]);
            }
        }
        arrayY[r]=Y;
        arrayF[r]=F;
        arrayA[r]=arrayY[r]+arrayF[r];
        printf(" = %i\n",arrayA[r]);
        Y=0;
        F=0;
    }
printf("output : [%i] [%i] [%i] [%i] [%i] [%i] [%i] [%i] [%i] [%i] \n",arrayA[0],arrayA[1],arrayA[2],arrayA[3],arrayA[4],arrayA[5],arrayA[6],arrayA[7],arrayA[8],arrayA[9]);
}


int main(int argc, const char * argv[]) {
    int arrayx[10]={1,4,3,5,6};
    int arraya[10]={1,3,-2,4};
    int arrayb[10]={4,-2,3};
    int arrayY[10];
    int arrayF[10];
    int arrayA[10]={0};
    int i;

    int TypeN;
    int BeginVsize=3;    
    
    printf("While answering the questions answer 1 if yes and 0 if no\n");

    printf("Enter BeginV size!\n");
    BeginVsize=inputarraysize();

    int BeginV[BeginVsize];
    
    printf("Enter BeginV values!\n");
    inputarray(BeginV, BeginVsize);

    if (sizeof(arrayx) < sizeof(arraya) + 1) {
    printf("Array X < Array A + 1, fill left with 0's?\n");
    scanf("%i", &TypeN);
    if (TypeN == 1){
        *arrayx=arrayswap(arrayx, sizeof(arraya)/sizeof(int));
    }
    else {
       throw std::invalid_argument("Invalid array size");
    }
    }//fill rest of the arrayx with 0's
    
    if (sizeof(arrayb) < sizeof(arraya)) {
    printf("Array B < Array X, fill left with 0's?\n");
    scanf("%i", &TypeN);
    if (TypeN == 1){
        *arrayb=arrayswap(arrayb, sizeof(arraya)/sizeof(int));
    }
    else {
        throw std::invalid_argument("Invalid array size");
    }
    }//fill rest of the arrayx with 0's

    for (i = 0; i<sizeof(BeginV)/sizeof(int); i++){
    if (BeginV[i] != 0){
        throw std::invalid_argument("BeginV values is not null");
    }
    }

    filter(arrayx, arraya, arrayb, arrayY, arrayF, arrayA, sizeof(arraya)/sizeof(int));
    
return 0;
}
