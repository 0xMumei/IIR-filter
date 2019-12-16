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

void inputBV(int *array, int arraysize){
    int TypeN;
    if(scanf("%i",&TypeN) == 1){
      if (TypeN == 1){
      printf("Enter numbers of the array:\n");
      inputarray(array, arraysize);
      }else{
        std::fill(array, array+arraysize, 0);
      }
    }else{
      throw std::invalid_argument("Input is not an integer");
    }
}

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

void filter(int *arrayx, int xsize , int *arraya, int asize, int *arrayb, int bsize, int sizeofarr, int N, int *BV_A, int BV_Asize, int *BV_B, int BV_Bsize)
{   
    //Send needed N step to be printed on inputs of function -/- make it more universal
    //Move middle-step inside the function
    int arrayY[10];
    int arrayF[10];
    int Output[N+10];
    int Y=0;
    int F=0;
    int r;
    int e;
    //Add bool for choise will we use values x(-1)
    for (r=0; r<N+1; r++) {
        if (N+1>xsize){
          throw std::runtime_error("Stepsize >> arrayx");
        }
        for (e=0; e<=r; e++) {
            Y+=arraya[e]*arrayx[r-e] + BV_B[e]; //add 0-values as : a_0+arraya[e]*arrayx[r-e]
            //printf("%i*%i + ",arraya[e],arrayx[r-e]);
            if (r-e-1 >= 0) {
                F+=arrayb[e]*Output[r-e-1] + BV_A[e];//add 0-values just as : b_0+arrayb[e]*arrayA[r-e-1]
                //printf("%i*%i + ",arrayb[e],arrayA[r-e-1]);
                }
            if (r-e-1 < 0) {
                F+=arrayb[e]*0;
                //printf("%i*0 + ",arrayb[e]);
            }
        }
        arrayY[r]=Y;
        arrayF[r]=F;
        Output[r]=arrayY[r]+arrayF[r];
        //printf(" = %i\n",arrayA[r]);
        Y=0;
        F=0;
    }
printf("output : [%i] \n",Output[N]);
//Print only needed (N) value output of filter
}


int main(int argc, const char * argv[]) {
    int xsize = 10;
    int arrayx[xsize]={1,4,3,5,6}; //send size of array to func
    int asize = 10;
    int arraya[asize]={1,3,-2,4};
    int bsize = 10;
    int arrayb[bsize]={4,-2,3};
    int i;
    int N = 2;

    int TypeN;
    
    printf("While answering the questions answer 1 if yes and 0 if no\n");


    int BV_Asize=sizeof(arraya)/sizeof(int)-1;
    int BV_Bsize=sizeof(arrayb)/sizeof(int)-1;
    int BV_A[BV_Asize]; //This array should be size of (a-1) cuz we use all of the a values for 0-values
    int BV_B[BV_Bsize];
    int ENDX;
    
    printf("Enter values of BV_A?\n");
    inputBV(BV_A,BV_Asize);

    printf("Enter values of BV_B?\n");
    inputBV(BV_B,BV_Bsize);

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

    printf("Enter step you want to see:");
    if(scanf("%i",&N) == 1){
    }
    else{
        throw std::invalid_argument("Input is not an integer"); 
    }
    

    filter(arrayx, xsize, arraya, asize, arrayb, bsize, sizeof(arraya)/sizeof(int), N, BV_A, BV_Asize, BV_B, BV_Bsize);
    
return 0;
}
