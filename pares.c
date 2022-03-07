void algoritmo1(int *values, int N) {

      int i, j = 0; // a
      int tmp; 
      for (i = 0; i < N; i++) {  // 1) (2a+b)(n) +a+b 
        //loop executado N vezes
         for (j = 0; j < N; j++) { // (2a+b)(n)+a+b
         //loop executado N vezes
          if (values[j] > values[j+1]) {  // (a+b)
          tmp = values[j+1]; // 2a
          values[j+1] = values[j]; //2a
          values[j] = tmp; //a
          }
      }
      }         
}

/* 

    f(n) = a + (2a+b)(n)+a+b + n*((2a+b)(n)+a+b + n*(a+b+2a+2a+a) )
    = n2(2a+b + 6a+b ) + n(2a+b + a+b) + 2a+b
    = n2(8a+2b) + n(3a+2b) +2a + b

*/