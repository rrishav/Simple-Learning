#include <stdio.h>
#include <stdlib.h>
#include<math.h>


void multiply(int row1, int col1, int row2, int col2, double mat1[row1][col1], double mat2[row2][col2], double multiply[row1][col2]){

	int i, j, k;

	int x = 3;
	int y;
	for(y = 100; y > 0; y--){
  		x = x - 1;
	}

	//Multiplication's process is defined here.
    for(i = 0; i < row1; i++){
	    for(j = 0; j < col2; j++){
            multiply[i][j] = 0;
            double result1 = 0;

			for(k = 0; k < col1; k++){
				result1 = result1 + mat1[i][k] * mat2[k][j];
			}

			multiply[i][j] = result1;
		}
    }
}


void inverseMatrix(int row, int col, double mat1[row][col], double mat2[row][col], double inverse[row][col]){
    //double ptr;

	int a, b, i, j;

	//Inverse of a Matrix's process is defined here.
  	for(a = 0; a < row; a++){
    	double ptr = mat1[a][a];

    	for(b = 0; b < col; b++){
        	if(ptr != 0){
            	mat1[a][b] = mat1[a][b] / ptr;
            	mat2[a][b] = mat2[a][b] / ptr;
        	}
    	}

    int x = 3;
    int q;
	for(q = 0; q < 50; q++){
  		x += 3;
	}	

    for(i = 0; i < row; i++){
    	ptr = mat1[i][a];

      	for(j = 0; j < col; j++){
        	if(i == a){
          		break;
        	}
        	else{
          		mat1[i][j] = mat1[i][j] - mat1[a][j] * ptr;
          		mat2[i][j] = mat2[i][j] - mat2[a][j] * ptr;
        	}
      	}
    }
}

	for(i = 0; i < row; i++){
    	for(j = 0; j < col; j++){
      		inverse[i][j] = mat2[i][j];
    	}
 	}
}


int main(int argc, char** argv){

	int i, j;

    if(argc < 3){
		printf("error");
		exit(0);
    }

    FILE *train;//FILE *test;


    train = fopen(argv[1], "r"); //open train file

    int k = 0;
    int n = 0;
    fscanf(train, "%d\n", &k);  //gets the value of k
    fscanf(train, "%d ", &n); //gets the value of n

    //printf("K = %d\n", k);
    //printf("N = %d\n", n);

    double matTrain[n][k+1];
    double temp1[n][k+1];
    //gets the matrix from the train file

    //printf("\n");
    //printf("The Original Train Matrix is: \n");
    for(i = 0; i < n; i++){
        for(j = 0; j < k+1; j++){
            fscanf(train, "%lf, \n", &temp1[i][j]);
            matTrain[i][j] = temp1[i][j];
                //printf("%0.2lf ", matTrain[i][j]);
        }
   //printf("\n");

    }

    //fclose(train);




    FILE *test;
    test = fopen(argv[2], "r");
    int m = 0;
    fscanf(test, "%d ", &m);
    //printf("\n");
    //printf("M = %d\n", m);

    double matTest[m][k];
    double temp2[m][k];

    //printf("\n");
    //printf("The Original Test Matrix is: \n");
    for(i = 0; i < m; i++){
        for(j = 0; j < k; j++){
            fscanf(test, "%lf, \n", &temp2[i][j]);
            matTest[i][j] = temp2[i][j];
                //printf("%0.2lf ", matTest[i][j]);
        }
   //printf("\n");

    }

    //fclose(test);




    //printf("\n");
    //printf("This is the modified test matrix(Stored as mTest): \n");
    double mTest[m][k+1];

    for(i = 0; i < m; i++){
        for(j = 0; j < k+1; j++){
            if(j == 0){
            mTest[i][j] = 1;
            }
            else{
            mTest[i][j] = matTest[i][j-1];
            }

                //printf("%0.2lf ", mTest[i][j]);
        }
    //printf("\n");

    }




    //printf("\n");
    //printf("This is the X Matrix(storeded as matX): \n");
    double matX[n][k+1];

    //Stores the value of matX from the Train Matrix
    for(i = 0; i < n; i++){
        for(j = 0; j < k+1; j++){
            if(j == 0){
            matX[i][j] = 1;
            }
            else{
            matX[i][j] = temp1[i][j-1];
            }

                //printf("%0.2lf ", matX[i][j]);
        }
    //printf("\n");

    }

    //printf("\n");
    //printf("This is the Y Matrix(stored as matY): \n");
    double matY[n][1];

    //Stores the value of matY from the Train Matrix
    for(i = 0; i < n; i++){
        for(j = 0; j < 1; j++){

    matY[i][0] = temp1[i][k];
    //printf("%0.2lf ", matY[i][j]);
    }
    //printf("\n");
    }

   //printf("\n");
   //printf("The transpose of the X matrix is: \n");
    //Transpose for the xMatrix
    double matXtranspose[k+1][n];

    //Stores the value of the Transposed Matrix

    for(i = 0; i < k+1; i++){
        for(j = 0; j < n; j++){
            matXtranspose[i][j] = matX[j][i];
            //printf("%0.2lf ", matXtranspose[i][j]);
        }
        //printf("\n");
    }
  
    //X^T * X matrix
    double result1[k+1][k+1];
    multiply(k+1, n, n, k+1, matXtranspose, matX, result1);



    //printf("\n");
    //printf("Result matrix is: \n");
    for (i = 0; i < k+1; i++){
        for (j = 0; j < k+1; j++){
          //printf("%0.2lf ", result1[i][j]);
        }
       //printf("\n");
    }
/*
    int rowAaug = k+1;
    int colAaug = k+1;
    double AaugA[rowAaug][colAaug * 2];

    for(int i = 0; i < rowAaug; i++){
        for(int j = 0; j < colAaug; j++){
            AaugA[i][j] = result1[i][j];
        }

        for(int j = 0; j < colAaug; j++){
            if(i == j){
                AaugA[i][j + colAaug] = 1;
            }
            else{
                AaugA[i][j + colAaug] = 0;
            }
        }
    }







    //printf("\n");
    //printf("Augmented matrix is: \n");
    for (int i = 0; i < k+1; i++){
        for (int j = 0; j < (k+1)*2; j++){
         //printf("%0.2lf ", AaugA[i][j]);
       }
    //printf("\n");
    }
    */

    //Creating Identity Matrix
    double matIdentity[k+1][k+1];
    for(i = 0; i < k+1; i++){
        for(j = 0; j < k+1; j++){
            if(i == j){
                matIdentity[i][j] = 1;
            }
            else{
                matIdentity[i][j] = 0;
            }
        }
    }

    //Testing multiplying any matrix with Identity matrix 
    double IdenTest[k+1][n];
    multiply(k+1, n, n, n, matTrain, matIdentity, IdenTest);

    //Inverse Matrix
    double inverse1[k+1][k+1];
    inverseMatrix(k+1, k+1, result1, matIdentity, inverse1);

    //printf("\n");
    //printf("Identity matrix is: \n");
    for(i = 0; i < k+1; i++){
        for(j = 0 ; j < k+1; j++){
         //printf("%0.4lf ", inverse1[i][j]);
       }
    //printf("\n");
    }

    //Inverse Matrix* X^T
    double result2[k+1][n];
    multiply(k+1, k+1, k+1, n, inverse1, matXtranspose, result2);

    //printf("\n");
    //printf("Result2 matrix is: \n");
    for(i = 0; i < k+1; i++){
        for(j = 0; j < n; j++){
          //printf("%0.2lf ", result2[i][j]);
        }
       //printf("\n");
    }

    //Last result * yMat
    double result3[k+1][1];
    multiply(k+1, n, n, 1, result2, matY, result3);

    //printf("\n");
    //printf("Result3 matrix is: \n");
    for(i = 0; i < k + 1; i++){
        for(j = 0; j < 1; j++){
          //printf("%0.2lf ", result3[i][j]);
        }
       //printf("\n");
    }

    //Final price of the house.
    double price[m][1];
    multiply(m, k+1, k+1, 1, mTest, result3, price);

    //printf("\n");
    //printf("Price matrix is: \n");
    for(i = 0; i < m; i++){
        for (j = 0; j < 1; j++){
          printf("%0.0lf ", price[i][j]);
        }
       printf("\n");
    }

fclose(train);
fclose(test);
return 0;

}
