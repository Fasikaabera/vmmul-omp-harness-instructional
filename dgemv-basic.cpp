const char* dgemv_desc = "Basic implementation of matrix-vector multiply.";

/*
 * This routine performs a dgemv operation
 * Y :=  A * X + Y
 * where A is n-by-n matrix stored in row-major format, and X and Y are n by 1 vectors.
 * On exit, A and X maintain their input values.
 */
void my_dgemv(int n, double* A, double* x, double* y) {
   // insert your code here: implementation of basic matrix multiply
   for (int i = 0; i < n; i++){
      double *row_A = A + i * n;
      double sum = 0.0;

      int j = 0;
      for (; j < n-4 ; j+= 4){
         sum += row_A[j] * x[j] + row_A[j+1] * x[j+1] + row_A[j+2] * x[j+2] + row_A[j+3] * x[j+3];
      }

      for (;j < n; j++){
         sum += row_A[j] * x[j];
      }
      y[i] += sum;
   }
}
