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

int inputBV(int *array, int arraysize){
    int TypeN;
    if(scanf("%i",&TypeN) == 1){
      if (TypeN == 1){
      printf("Enter numbers of the array:\n");
      inputarray(array, arraysize);
      return 0;
      }else{
        std::fill(array, array+arraysize, 0);
        return 1;
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

int filter(int *arrayx, int xsize , int *arraya, int asize, int *arrayb, int bsize, int N, int *BV_A, int BV_Asize, int *BV_B, int BV_Bsize, int BV_FLAG, int ENDX, long *Output)
{   
    int arrayY[10];
    int arrayF[10];
    int Result[N+10];
    std::fill(Result, Result+N+10, 0);
    int Y=0;
    int F=0;
    int r,e;
    
    for (r=0; r<N+1; r++) {
        if ((N+1>xsize && BV_FLAG) !=0){
          //throw std::runtime_error("Stepsize >> arrayx");
          return 1;
        }
        for (e=0; e<=r; e++){
          if (e>asize-1 || ((r-e)<0 || (r-e)>=xsize)){
            if (e>BV_Bsize-1){
            Y+=0;}else{  
          Y+=0 + BV_B[e];
          }
          }else{
            if (e>BV_Bsize-1){ 
            Y+=arraya[e]*arrayx[r-e];}else{  
          Y+=arraya[e]*arrayx[r-e] + BV_B[e];
          }
          }
          if (e>bsize || (r-e-1) < 0){
            if (e>BV_Asize-1){
              F+=0;}else{
          F+=0 + BV_A[e];
          }
          }else{
            if (e>BV_Asize-1){ 
            F+=arrayb[e]*Result[r-e-1];
            }else{
          F+=arrayb[e]*Result[r-e-1] + BV_A[e];
          }
          }
        }
        arrayY[r]=Y+ENDX;
        arrayF[r]=F;
        Result[r]=arrayY[r]+arrayF[r];
        Y=0;
        F=0;
    }
*Output=Result[N];
return 0;
}


int main(int argc, const char * argv[]) {
    int xsize = 10;
    int arrayx[xsize]={1,4,3,5,6}; 
    int asize = 10;
    int arraya[asize]={1,3,-2,4};
    int bsize = 10;
    int arrayb[bsize]={4,-2,3};
    int i;
    int N = 2;
    int TypeN;

    int BV_Asize=asize-1;
    int BV_Bsize=bsize-1;
    int BV_A[BV_Asize]; 
    int BV_B[BV_Bsize];
    int ENDX, BV_AC , BV_BC, BV_FLAG;

    long Output;

    printf ("Use Beginning Values?\n");
    if(scanf("%i",&TypeN) == 1){
    if (TypeN == 0){
      BV_FLAG=0;
      std::fill(BV_A, BV_A+BV_Asize, 0);
      std::fill(BV_B, BV_B+BV_Bsize, 0);
    }else{
    BV_FLAG=1;
    printf("Enter values of BV_A?\n");
    BV_AC=inputBV(BV_A,BV_Asize);

    printf("Enter values of BV_B?\n");
    BV_BC=inputBV(BV_B,BV_Bsize);
    }
    }
    else {
       throw std::invalid_argument("Input is not an integer"); 
    }

    printf("Enter endvalue: ");
        if(scanf("%i",&ENDX) == 1){
    }
    else{
        throw std::invalid_argument("Input is not an integer"); 
    }
    
    printf("While answering the questions answer 1 if yes and 0 if no\n");

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

    printf("Enter step you want to see: ");
    if(scanf("%i",&N) == 1){
    }
    else{
        throw std::invalid_argument("Input is not an integer"); 
    }
    
    if (filter(arrayx, xsize, arraya, asize, arrayb, bsize, N, BV_A, BV_Asize, BV_B, BV_Bsize, BV_FLAG, ENDX, &Output) == 1){
    printf("Error occured : code 1\n");
    }else{
    printf("Ok!\n");
    }

    printf("Result : [ %d ] ",Output);
    
return 0;
}
