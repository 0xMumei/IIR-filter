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

void filter(int *arrayx, int *arraya, int *arrayb, int *arrayA, int sizeofarr, int N) //Use only needed input
{   
    //Send needed N step to be printed on inputs of function -/- make it more universal
    //Move middle-step inside the function
    int arrayY[10];
    int arrayF[10];
    int Y=0;
    int F=0;
    int r;
    int e;
    //Add bool for choise will we use values x(-1)
    for (r=0; r<sizeofarr; r++) {
        for (e=0; e<=r; e++) {
            Y+=arraya[e]*arrayx[r-e]; //add 0-values as : a_0+arraya[e]*arrayx[r-e]
            //printf("%i*%i + ",arraya[e],arrayx[r-e]);
            if (r-e-1 >= 0) {
                F+=arrayb[e]*arrayA[r-e-1];//add 0-values just as : b_0+arrayb[e]*arrayA[r-e-1]
                //printf("%i*%i + ",arrayb[e],arrayA[r-e-1]);
                }
            if (r-e-1 < 0) {
                F+=arrayb[e]*0;
                //printf("%i*0 + ",arrayb[e]);
            }
        }
        arrayY[r]=Y;
        arrayF[r]=F;
        arrayA[r]=arrayY[r]+arrayF[r];
        //printf(" = %i\n",arrayA[r]);
        Y=0;
        F=0;
    }
printf("output : [%i] \n",arrayA[N]);
//Print only needed (N) value output of filter
}


int main(int argc, const char * argv[]) {
    int arrayx[10]={1,4,3,5,6}; //send size of array to func
    int arraya[10]={1,3,-2,4};
    int arrayb[10]={4,-2,3};
    int arrayA[10]={0};
    int i;
    int N = 2;

    int TypeN;
    int BV_Asize=3;    
    
    printf("While answering the questions answer 1 if yes and 0 if no\n");

    printf("Enter BV_A size!\n");
    BV_Asize=inputarraysize();

    int BV_A[BV_Asize]; //This array should be size of (a-1) cuz we use all of the a values for 0-values
    
    if (sizeof(BV_A)>0){
    printf("Enter BV_A values!\n");
    inputarray(BV_A, BV_Asize);
    }

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

    for (i = 0; i<sizeof(BV_A)/sizeof(int); i++){
    if (BV_A[i] != 0){
        throw std::invalid_argument("BV_A values is not null");
    }
    }

    printf("Enter step you want to see:");
    if(scanf("%i",&N) == 1){
    }
    else{
        throw std::invalid_argument("Input is not an integer"); 
    }
    

    filter(arrayx, arraya, arrayb, arrayA, sizeof(arraya)/sizeof(int), N);
    
return 0;
}
