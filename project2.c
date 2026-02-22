/*
* project2.c
* Wyatt Loo
* ECE 160
* 11/24/25
* Description and Purpose
* The program first creates a struct, and all of the variables required for this program are declared in this struct.
* Stage of the program:
* stage 1 - Prompt user to obtain input for datafile name and order of polynomial
* stage 2 - Open data file and save data into a user-define structured containing x-data and y-data
* stage 3 - Create a struct containing all of the declared variables required to solve the program.
* stage 4 - Create a 2-Dimensional Array to store all x-data points and y-data points within the data file.
* stage 5 - Display error messages if the file is not found in the local directory, or if the program is unable to read the data.
* stage 6 - Compute all of the summations for the Least-Squares technique (N, ∑x, ∑x^2, ∑y, ∑xy).
* stage 7 - Create an augmented matrix for the computed summations.
* stage 8 - Apply the Gauss Jordan Method to solve the 2x2 matrix, and find the polynomial coefficients for y = a + bx.
* stage 9 - Display the line of best-fit linear equation, along with the proper coefficients
* stage 10 - Create a new file titled “OuputASCII.csv”, and write the results into that output file
* stage 11 - For the output files, create a table with columns for the x and y values in the test-file, as well as a column for the y-calc. The y-calc is found by plugging in the x-data points into the line of best-fit equation
* stage 12 - close all open files
* Version 1: 
* A data file is created (fp)
* This data file reads the (x, y) data pairs provided by two different files to find the line of best-fit. 
* The program asks the user to enter the polynomial order (1-4). This creates 4 equations a coefficients that the program computes.
* The program then asks the user to enter the name of the data file they want to get their (x,y) data from.
* The program accumulates the required summations, and data points needed to create an augmented array
* Displays the total number of data points (x,y) lines read from the file
* Displays both the left and right side of the matrix
* Depending on the which polynomial order (k) was selected, the size of the augmented matrix will be depending, and the Gauss-Jordan method will be used to solve the matrix
* Displays the row reduced (RREF) augmented matrix
* Use the coefficients found in the solved matrix to display the best-fit least-squares equation 
* Version 2: 
* A data file is created (fp)
* This data file reads the (x, y) data pairs provided by two different files to find the line of best-fit. 
* The program asks the user to enter the polynomial order (1-4). This creates 4 equations a coefficients that the program computes.
* The program then asks the user to enter the name of the data file they want to get their (x,y) data from.
* The program accumulates the required summations, and data points needed to create an augmented array
* Displays the total number of data points (x,y) lines read from the file
* Displays both the left and right side of the matrix
* Depending on the which polynomial order (k) was selected, the size of the augmented matrix will be depending, and the Gauss-Jordan method will be used to solve the matrix
* Swap rows when a11, a22, a33, or a44 are equal to 0 to prevent division by 0
* Print an error message saying the program cannot proceed when the last division-by-0 check is 0
* Displays the row reduced (RREF) augmented matrix
* Use the coefficients found in the solved matrix to display the best-fit least-squares equation
* Version 3 (With output file)
A data file is created (fp)
* This data file reads the (x, y) data pairs provided by two different files to find the line of best-fit. 
* The program asks the user to enter the polynomial order (1-4). This creates 4 equations a coefficients that the program computes.
* The program then asks the user to enter the name of the data file they want to get their (x,y) data from.
* The program accumulates the required summations, and data points needed to create an augmented array
* Displays the total number of data points (x,y) lines read from the file
* Displays both the left and right side of the matrix
* Depending on the which polynomial order (k) was selected, the size of the augmented matrix will be depending, and the Gauss-Jordan method will be used to solve the matrix
* Swap rows when a11, a22, a33, or a44 are equal to 0 to prevent division by 0
* Print an error message saying the program cannot proceed when the last division-by-0 check is 0
* Displays the row reduced (RREF) augmented matrix
* Use the coefficients found in the solved matrix to display the best-fit least-squares equation
* Output file:
* The program asks the user to enter name of the output file the user wants to save their results to
* A second file is created to put the results of the program into
* A table is created with the columns: x, y, and ycalc. The ycalc column is solved by plugging the x-column values into the best-fit Least-Sqaures equation
* Displays the polynomial order (1-4)
* The program will display the best-fit least-squares equation depending on the polynomial order (1-4)
* Close both the test file and output file.
*
* pseudocode
* struct calculations (containing all declared variables)
* main function
	* create a file *fp
	* declare variables
		* int c = 0
		* char fileName[100]
		* int poly
		* double a[50][2]
		* int j, i
	* ask for user input for the polynomial order (1-4)
	* store input into ‘poly’
	* ask for name of the data file
	* store input into ‘fileName’
	* attempt to open the file
	* while fscanf reads the data file
		* c + 1
	* if ‘fp’ doesn’t exist
		* display error message
	* display total data points (x,y) from file
	* assign calculations struct the name “augmentedArray”
	* for i = 0 to c
		* calculate all of the summations required
	* if ‘poly’ equals 1
		* declare double kOne[2][3], b[2][3], and d[2][3]
		* put all summations into 2 x 2 matrix
		* display matrix ‘A’ and ‘B’ of the augmented matrix
		* Use the gauss-jordan steps to solve the augmented matrix
		* Display solved matrix
		* for i = 0 to c
			* ycalc[i] = a0 + a[i][0] * a1
		* display best-fit least squares equation
	* if ‘poly’ equals 2
		* declare double kTwo[3][4], e[3][4], and f[3][4], g[3][4]
		* put all summations into 3 x 3 matrix
		* display matrix ‘A’ and ‘B’ of the augmented matrix
		* Use the gauss-jordan steps to solve the augmented matrix
		* Display solved matrix
		* for i = 0 to c
			* ycalc[i] = a0 + a[i][0] * a1 + (a[i][0])^2 * a2
		* display best-fit least squares equation
	* if ‘poly’ equals 3
		* declare double kThree[4][5], h[4][5], and k[4][5], l[4][5], m[4][5]
		* put all summations into 4 x 4 matrix
		* display matrix ‘A’ and ‘B’ of the augmented matrix
		* Use the gauss-jordan steps to solve the augmented matrix
		* Display solved matrix
		* for i = 0 to c
			* ycalc[i] = a0 + a[i][0] * a1 + (a[i][0])^2 * a2 + (a[i][0])^3 * a3
		* display best-fit least squares equation
	* if ‘poly’ equals 4
		* declare double kFour[5][6], n[5][6], o[5][6], p[5][6], q[5][6], r[5][6]
		* put all summations into 5 x 5 matrix
		* display matrix ‘A’ and ‘B’ of the augmented matrix
		* Use the gauss-jordan steps to solve the augmented matrix
		* Display solved matrix
		* for i = 0 to c
			* ycalc[i] = a0 + a[i][0] * a1 + (a[i][0])^2 * a2 + (a[i][0])^3 * a3 + (a[i][0])^4 *          a4
		* display best-fit least squares equation
	* create a file *fp2
	* declare char outputFile[12]
	* ask for user input of ‘outputFile’
	* store user input in ‘outputFile’
	* open ‘outputFile’
	* if fp2 doesn’t exist
		* display error message
	* if the user typed “out1.csv”
		* display results into “out1.csv”
		* display a table with columns: x, y, and ycalc
		* for i = 0 to c
			* display (x,y) data points from the test file as well as the ycalc
		* display ‘poly’
		* if poly = 1
			* display best-fit least-squares equation for k = 1
		* if poly = 2
			* display best-fit least-squares equation for k = 2
		* if poly = 3
			* display best-fit least-squares equation for k = 3
		* if poly = 4
			* display best-fit least-squares equation for k = 4
		* display “end of output file”
	* if the user typed “out2a.csv”
		* display results into “out1.csv”
		* display a table with columns: x, y, and ycalc
		* for i = 0 to c
			* display (x,y) data points from the test file as well as the ycalc
		* display ‘poly’
		* if poly = 1
			* display best-fit least-squares equation for k = 1
		* if poly = 2
			* display best-fit least-squares equation for k = 2
		* if poly = 3
			* display best-fit least-squares equation for k = 3
		* if poly = 4
			* display best-fit least-squares equation for k = 4
		* display “end of output file”
	* if the user typed “out2b.csv”
		* display results into “out1.csv”
		* display a table with columns: x, y, and ycalc
		* for i = 0 to c
			* display (x,y) data points from the test file as well as the ycalc
		* display ‘poly’
		* if poly = 1
			* display best-fit least-squares equation for k = 1
		* if poly = 2
			* display best-fit least-squares equation for k = 2
		* if poly = 3
			* display best-fit least-squares equation for k = 3
		* if poly = 4
			* display best-fit least-squares equation for k = 4
		* display “end of output file”
	* close fp and fp2 files
	* end of program

*/

#include <stdio.h>
#include <string.h>
#include <math.h>

/* struct calculations created, containing all declared variables */
struct calculations {
    double n;
    double sumX;
    double sumX2;
    double sumX3;
    double sumX4;
    double sumX5;
    double sumX6;
    double sumX7;
    double sumX8;
    double sumY;
    double sumXY;
    double sumX2Y;
    double sumX3Y;
    double sumX4Y;
    double a0;
    double a1;
    double a2;
    double a3;
    double a4;
    double yCalc[50];
    double temp;
};

int main() {
    FILE *fp;
    /* int c is variable for number of rows in data set */
    int c = 0;
    char fileName[100];
    int poly;
    double a[50][2];
    int j;
    int i;



    /* Ask for user input for the polynomial order (1-4) */
    printf("Enter the polynomial order (1-4): ");
    scanf("%i", &poly);



    /* Asks for the name of the data file */
    printf("Enter name of the data file: ");
    scanf("%s", fileName);

    /* Attempt to open file */
    fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("Error reading file\n");
        return 1;
    } else {
        printf("\nFile successfully opened...\n\n");
    }

    /* Print line being read */
    while (fscanf(fp, " %lf, %lf" ,&a[c][0], &a[c][1]) == 2) {
        c++;
    }

    /* total data points (x,y) read from file */
    printf("Total data points (x,y) read from file: %i\n", c);


    /* assign calculations struct a name */
    struct calculations augmentedArray = {0};

    /* calculate terms and summations */
    augmentedArray.n = c;
    for (i = 0; i < c; i++) {
        augmentedArray.sumX += a[i][0];
        augmentedArray.sumX2 += a[i][0] * a[i][0];
        augmentedArray.sumX3 += a[i][0] * a[i][0] * a[i][0];
        augmentedArray.sumX4 += pow(a[i][0], 4);
        augmentedArray.sumX5 += pow(a[i][0], 5);
        augmentedArray.sumX6 += pow(a[i][0], 6);
        augmentedArray.sumX7 += pow(a[i][0], 7);
        augmentedArray.sumX8 += pow(a[i][0], 8);
        augmentedArray.sumY += a[i][1];
        augmentedArray.sumXY += a[i][0] * a[i][1];
        augmentedArray.sumX2Y += a[i][0] * a[i][0] * a[i][1];
        augmentedArray.sumX3Y += a[i][0] * a[i][0] * a[i][0] * a[i][1];
        augmentedArray.sumX4Y += a[i][0] * a[i][0] * a[i][0] * a[i][0] * a[i][1];
    }
        

    /* If you chose k = 1, create a 2 x 2 matrix */
    if (poly == 1) {
        printf("The polynomial is y = a0 + a1x\n\n");
        
        /* create a 2 x 2 matrix */
        double kOne[2][3];
        double b[2][3];
        double d[2][3];

        kOne[0][0] = augmentedArray.n;
        kOne[0][1] = augmentedArray.sumX;
        kOne[0][2] = augmentedArray.sumY;
        kOne[1][0] = augmentedArray.sumX;
        kOne[1][1] = augmentedArray.sumX2;
        kOne[1][2] = augmentedArray.sumXY;

        /* display matrix 'A' of the matrix */
        printf("The coefficients (square) matrix 'A' is 2 x 2 with values:\n");
        for (i = 0; i < 2; i++) {
            printf("[ ");
            for (j = 0; j < 2; j++) {
                printf("%.3lf ", kOne[i][j]);
            }
            printf("]\n");
        }

        printf("\n");

        /* display matrix 'B' of the matrix */
        printf("The constants (column) Matrix 'B' is 2 x 1\n");
        for (i = 0; i < 2; i++) {
            printf("[ %.3lf ]\n", kOne[i][2]);
        }

        printf("\n");

        /* if a11 = 0, swap rows*/
        if (kOne[0][0] == 0) {
            for (j = 0; j < 3; j++) {
                augmentedArray.temp = kOne[0][j];
                kOne[0][j] = kOne[1][j];
                kOne[1][j] = augmentedArray.temp;
            }
        }
        /* step 1: divide first row by a11 */
        for (j = 0; j < 3; j++) {
            b[0][j] = kOne[0][j] / kOne[0][0];
        }
        /* step 2: R2 = R2 - a21(R1) */
        for (j = 0; j < 3; j++) {
            b[1][j] = kOne[1][j] - kOne[1][0] * b[0][j];
        }
        /* if a22 is zero, you cannot proceed, display error message */
        if (b[1][1] == 0) {
            printf("Error: a22 = 0, cannot proceed.\n");
            return 1;
        }
        /* step 3: divide second row by a22 */
        for (j = 0; j < 3; j++) {
            d[1][j] = b[1][j] / b[1][1];
        }
        /* step 4: R1 = R1 - a12(R2) */
        for (j = 0; j < 3; j++) {
            d[0][j] = b[0][j] - b[0][1] * d[1][j];
        }

        /* display matrix */
        printf("The row reduced (RREF) augmented matrix is:\n");
        for (i = 0; i < 2; i++) {
            printf("[ ");
            for (j = 0; j < 2; j++) {
                printf("%.3lf ", d[i][j]);
            }
            printf("| %.6lf ]\n", d[i][2]);
        }

        augmentedArray.a0 = d[0][2];
        augmentedArray.a1 = d[1][2];

        /* calculating yCalc for output file */
        for (i = 0; i < c; i++) {
            augmentedArray.yCalc[i] = augmentedArray.a0 + a[i][0] * augmentedArray.a1;
        }

        
        printf("\nThe best-fit Least-Squares equation is:\n%.5lfx^0 + %.5lfx^1\n", augmentedArray.a0, augmentedArray.a1);
    }

    /* If you chose k = 2, create a 3 x 3 matrix */
    if (poly == 2) {
        printf("The polynomial is y = a0 + a1x + a2x^2\n\n");

        /* create a 3 x 3 matrix */
        double kTwo[3][4];
        double e[3][4];
        double f[3][4];
        double g[3][4];

        kTwo[0][0] = augmentedArray.n;
        kTwo[0][1] = augmentedArray.sumX;
        kTwo[0][2] = augmentedArray.sumX2;
        kTwo[0][3] = augmentedArray.sumY;
        kTwo[1][0] = augmentedArray.sumX;
        kTwo[1][1] = augmentedArray.sumX2;
        kTwo[1][2] = augmentedArray.sumX3;
        kTwo[1][3] = augmentedArray.sumXY;
        kTwo[2][0] = augmentedArray.sumX2;
        kTwo[2][1] = augmentedArray.sumX3;
        kTwo[2][2] = augmentedArray.sumX4;
        kTwo[2][3] = augmentedArray.sumX2Y;

        /* display matrix 'A' of the matrix */
        printf("The coefficients (square) matrix 'A' is a 3 x 3 with values:\n");
        for (i = 0; i < 3; i++) {
            printf("[ ");
            for (j = 0; j < 3; j++) {
                printf("%.3lf ", kTwo[i][j]);
            }
            printf("]\n");
        }

        /* display matrix 'B' of the matrix */
        printf("\nThe constants (column) Matrix 'B' is a 3 x 1\n");
        for (i = 0; i < 3; i++) {
            printf("[ %.3lf ]\n", kTwo[i][3]);
        }

        /* if a11 = 0, swap row 1 with row 2 */
        if (kTwo[0][0] == 0) {
            for (j = 0; j < 4; j++) {
                augmentedArray.temp = kTwo[0][j];
                kTwo[0][j] = kTwo[1][j];
                kTwo[1][j] = augmentedArray.temp;
            }
        }
        /* step 1: R1 = R1 / a11 */
        for (j = 0; j < 4; j++) {
            e[0][j] = kTwo[0][j] / kTwo[0][0];
        }
        /* step 2: R2 = R2 - a21(R1) */
        for (j = 0; j < 4; j++) {
            e[1][j] = kTwo[1][j] - kTwo[1][0] * e[0][j];
        }
        /* step 3: R3 = R3 - a31(R1) */
        for (j = 0; j < 4; j++) {
            e[2][j] = kTwo[2][j] - kTwo[2][0] * e[0][j];
        }
        /* if a22 = 0, swap row 2 with row 3 */
        if (e[1][1] == 0) {
            for (j = 0; j < 4; j++) {
                augmentedArray.temp = e[1][j];
                e[1][j] = e[2][j];
                e[2][j] = augmentedArray.temp;
            }
        }
        /* step 4: R2 = R2 / a22 */
        for (j = 0; j < 4; j++) {
            f[1][j] = e[1][j] / e[1][1];
        }
        /* step 5: R3 = R3 - a32(R2) */
        for (j = 0; j < 4; j++) {
            f[2][j] = e[2][j] - e[2][1] * f[1][j];
        }
        /* step 6: R1 = R1 - a12(R2) */
        for (j = 0; j < 4; j++) {
            f[0][j] = e[0][j] - e[0][1] * f[1][j];
        }
        /* if a33 = 0, cannot proceed further. Error message */
        if (f[2][2] == 0) {
            printf("Error: a33 = 0, cannot proceed.\n");
            return 1;
        }
        /* step 7: R3 = R3 / a33 */
        for (j = 0; j < 4; j++) {
            g[2][j] = f[2][j] / f[2][2];
        }
        /* step 8: R2 = R2 - a23(R3)*/
        for (j = 0; j < 4; j++) {
            g[1][j] = f[1][j] - f[1][2] * g[2][j];
        }
        /* step 9: R1 = R1 - a12(R3) */
        for (j = 0; j < 4; j++) {
            g[0][j] = f[0][j] - f[0][2] * g[2][j];
        }
        
        /* display array */
        printf("\nThe row reduced (RREF) augmented matrix is:\n");
        for (i = 0; i < 3; i++) {
            printf("[ ");
            for (j = 0; j < 3; j++) {
                printf("%.3lf ", g[i][j]);
            }
            printf("| %.6lf ]", g[i][3]);
            printf("\n");
        }

        augmentedArray.a0 = g[0][3];
        augmentedArray.a1 = g[1][3];
        augmentedArray.a2 = g[2][3];

        /* calculating yCalc for output file */
        for (i = 0; i < c; i++) {
            augmentedArray.yCalc[i] = augmentedArray.a0 + a[i][0] * augmentedArray.a1 + pow(a[i][0], 2) * augmentedArray.a2;
        }

        printf("\n");
        printf("The best-fit least squares equation is:\n%.4lf + %.4lfx + %.4lfx^2\n", augmentedArray.a0, augmentedArray.a1, augmentedArray.a2);
    }

    /* If you chose k = 3, create a 4 x 4 matrix */
    if (poly == 3) {
        printf("The polynomial is y = a0 + a1x + a2x^2 + a3x^3\n\n");

        /* create 4 x 4 matrix */
        double kThree[4][5];
        double h[4][5];
        double k[4][5];
        double l[4][5];
        double m[4][5];

        kThree[0][0] = augmentedArray.n;
        kThree[0][1] = augmentedArray.sumX;
        kThree[0][2] = augmentedArray.sumX2;
        kThree[0][3] = augmentedArray.sumX3;
        kThree[0][4] = augmentedArray.sumY;
        kThree[1][0] = augmentedArray.sumX;
        kThree[1][1] = augmentedArray.sumX2;
        kThree[1][2] = augmentedArray.sumX3;
        kThree[1][3] = augmentedArray.sumX4;
        kThree[1][4] = augmentedArray.sumXY;
        kThree[2][0] = augmentedArray.sumX2;
        kThree[2][1] = augmentedArray.sumX3;
        kThree[2][2] = augmentedArray.sumX4;
        kThree[2][3] = augmentedArray.sumX5;
        kThree[2][4] = augmentedArray.sumX2Y;
        kThree[3][0] = augmentedArray.sumX3;
        kThree[3][1] = augmentedArray.sumX4;
        kThree[3][2] = augmentedArray.sumX5;
        kThree[3][3] = augmentedArray.sumX6;
        kThree[3][4] = augmentedArray.sumX3Y;

        /* Display matrix 'A' of the matrix */
        printf("The coefficients (sqaure) matrix 'A' is 4x4 with values:\n");
        for(i = 0; i < 4; i++) {
            printf("[ ");
            for (j = 0; j < 4; j++) {
                printf("%.3lf ", kThree[i][j]);
            }
            printf("]\n");
        }
        printf("\n");

        /* Display matrix 'B' of the matrix */
        printf("The constants (column) Matrix 'B' is 4x1\n");
        for (i = 0; i < 4; i++) {
            printf("[ %.3lf ]\n", kThree[i][4]);
        }

        printf("\n");
        
        /* if a11 = 0, swap row 1 with row 2 */
        if (kThree[0][0] == 0) {
            for (j = 0; j < 5; j++) {
                augmentedArray.temp = kThree[0][j];
                kThree[0][j] = kThree[1][j];
                kThree[1][j] = augmentedArray.temp;
            }
        }
        /* step 1: divide row 1 by 6 */
        for (j = 0; j < 5; j++) {
            h[0][j] = kThree[0][j] / kThree[0][0];
        }
        /* step 2: R2 = R2 - R2[0](R1) */
        for (j = 0; j < 5; j++) {
            h[1][j] = kThree[1][j] - kThree[1][0] * h[0][j];
        }
        /* step 3: R3 = R3 - R3[0](R1) */
        for (j = 0; j < 5; j++) {
            h[2][j] = kThree[2][j] - kThree[2][0] * h[0][j];
        }
        /* step 4: R4 = R4 - R4[0](R1) */
        for (j = 0; j < 5; j++) {
            h[3][j] = kThree[3][j] - kThree[3][0] * h[0][j];
        }
        /* if a22 = 0, swap row 2 with row 3 */
        if (h[1][1] == 0) {
            for (j = 0; j < 5; j++) {
                augmentedArray.temp = h[1][j];
            h[1][j] = h[2][j];
            h[2][j] = augmentedArray.temp;
            } 
        }
        /* step 5: divide row 2 by R2[1] */
        for (j = 0; j < 5; j++) {
            k[1][j] = h[1][j] / h[1][1];
        }
        /* step 6: R1 = R1 - R1[1](R2) */
        for (j = 0; j < 5; j++) {
            k[0][j] = h[0][j] - h[0][1] * k[1][j];
        }
        /* step 7: R3 = R3 - R3[1](R2) */
        for (j = 0; j < 5; j++) {
            k[2][j] = h[2][j] - h[2][1] * k[1][j];
        }
        /* step 8: R4 = R4 - R4[1](R2) */
        for (j = 0; j < 5; j++) {
            k[3][j] = h[3][j] - h[3][1] * k[1][j];
        }
        /* if a33 = 0, swap row 3 with row 4 */
        if (k[2][2] == 0) {
            for (j = 0; j < 5; j++) {
                augmentedArray.temp = k[2][j];
                k[2][j] = k[3][j];
                k[3][j] = augmentedArray.temp;
            }
        }
        /* step 9: divide row 3 by R3[2] */
        for (j = 0; j < 5; j++) {
            l[2][j] = k[2][j] / k[2][2];
        }
        /* step 10: R1 = R1 - R1[2](R3) */
        for (j = 0; j < 5; j++) {
            l[0][j] = k[0][j] - k[0][2] * l[2][j];
        }
        /* step 11: R2 = R2 - R2[2](R3) */
        for (j = 0; j < 5; j++) {
            l[1][j] = k[1][j] - k[1][2] * l[2][j];
        }
        /* step 12: R4 = R4 - R4[2](R3) */
        for (j = 0; j < 5; j++) {
            l[3][j] = k[3][j] - k[3][2] * l[2][j];
        }
        /* if a44 = 0, cannot proceed further. Print error message */
        if (l[3][3] == 0) {
            printf("Error: a44 = 0, cannot proceed.\n");
            return 1;
        }
        /* step 13: divide row 4 by R4[3] */
        for (j = 0; j < 5; j++) {
            m[3][j] = l[3][j] / l[3][3];
        }
        /* step 14: R1 = R1 - R1[3](R4) */
        for (j = 0; j < 5; j++) {
            m[0][j] = l[0][j] - l[0][3] * m[3][j];
        }
        /* step 15: R2 = R2 - R2[3](R4) */
        for (j = 0; j < 5; j++) {
            m[1][j] = l[1][j] - l[1][3] * m[3][j];
        }
        /* step 16: R3 = R3 - R3[3](R4) */
        for (j = 0; j < 5; j++) {
            m[2][j] = l[2][j] - l[2][3] * m[3][j];
        }

        /* display array */
        printf("The row reduced (RREF) augmented matrix is:\n");
        for (i = 0; i < 4; i++) {
            printf("[ ");
            for (j = 0; j < 4; j++) {
                printf("%.3lf ", m[i][j]);
            }
            printf("| %.6lf ]", m[i][4]);
            printf("\n");
        }

        printf("\n");

        augmentedArray.a0 = m[0][4];
        augmentedArray.a1 = m[1][4];
        augmentedArray.a2 = m[2][4];
        augmentedArray.a3 = m[3][4];

        /* calculating yCalc for output file */
        for (i = 0; i < c; i++) {
            augmentedArray.yCalc[i] = augmentedArray.a0 + a[i][0] * augmentedArray.a1 + pow(a[i][0], 2) * augmentedArray.a2 + pow(a[i][0], 3) * augmentedArray.a3;
        }

        printf("The linear least-squares best fit to data is:\n");
        printf("y = %.5lfx^0 + %.5lfx^1 + %.5lfx^2 + %.5lfx^3\n", augmentedArray.a0, augmentedArray.a1, augmentedArray.a2, augmentedArray.a3);
    }

    

    /* If you chose k = 4, create a 5 x 5 matrix */
    if (poly == 4) {
        printf("The polynomial is y = a0 + a1x + a2x^2 + a3x^3 + a4x^4\n\n");

        /* create a 5 x 6 matrix */
        double kFour[5][6];
        double n[5][6];
        double o[5][6];
        double p[5][6];
        double q[5][6];
        double r[5][6];

        kFour[0][0] = augmentedArray.n;
        kFour[0][1] = augmentedArray.sumX;
        kFour[0][2] = augmentedArray.sumX2;
        kFour[0][3] = augmentedArray.sumX3;
        kFour[0][4] = augmentedArray.sumX4;
        kFour[0][5] = augmentedArray.sumY;
        kFour[1][0] = augmentedArray.sumX;
        kFour[1][1] = augmentedArray.sumX2;
        kFour[1][2] = augmentedArray.sumX3;
        kFour[1][3] = augmentedArray.sumX4;
        kFour[1][4] = augmentedArray.sumX5;
        kFour[1][5] = augmentedArray.sumXY;
        kFour[2][0] = augmentedArray.sumX2;
        kFour[2][1] = augmentedArray.sumX3;
        kFour[2][2] = augmentedArray.sumX4;
        kFour[2][3] = augmentedArray.sumX5;
        kFour[2][4] = augmentedArray.sumX6;
        kFour[2][5] = augmentedArray.sumX2Y;
        kFour[3][0] = augmentedArray.sumX3;
        kFour[3][1] = augmentedArray.sumX4;
        kFour[3][2] = augmentedArray.sumX5;
        kFour[3][3] = augmentedArray.sumX6;
        kFour[3][4] = augmentedArray.sumX7;
        kFour[3][5] = augmentedArray.sumX3Y;
        kFour[4][0] = augmentedArray.sumX4;
        kFour[4][1] = augmentedArray.sumX5;
        kFour[4][2] = augmentedArray.sumX6;
        kFour[4][3] = augmentedArray.sumX7;
        kFour[4][4] = augmentedArray.sumX8;
        kFour[4][5] = augmentedArray.sumX4Y;

        /* display matrix 'A' of the matrix */
        printf("The coefficients (sqaure) matrix 'A' is 4 x 4 with values:\n");
        for (i = 0; i < 5; i++) {
            printf("[ ");
            for (j = 0; j < 5; j++) {
                printf("%.3lf ", kFour[i][j]);
            }
            printf("]\n");
        }

        printf("\n\n");

        /* display matrix 'B' of the matrix */
        printf("The constants (column) Matrix 'B' is 5 x 1\n");
        for (i = 0; i < 5; i++) {
            printf("[ %.3lf ]\n", kFour[i][5]);
        }

        printf("\n");
        
        /* if a11 = 0, swap row 1 with row 2 */
        if (kFour[0][0] == 0) {
            for (j = 0; j < 6; j++) {
                augmentedArray.temp = kFour[0][j];
                kFour[0][j] = kFour[1][j];
                kFour[1][j] = augmentedArray.temp;
            }
        }
        /* step 1: divide Row 1 by R1[0] */
        for (j = 0; j < 6; j++) {
            n[0][j] = kFour[0][j] / kFour[0][0];
        }
        /* step 2: R2 = R2 - R2[0](R1) */
        for (j = 0; j < 6; j++) {
            n[1][j] = kFour[1][j] - kFour[1][0] * n[0][j];
        }
        /* step 3: R3 = R3 - R3[0](R1) */
        for (j = 0; j < 6; j++) {
            n[2][j] = kFour[2][j] - kFour[2][0] * n[0][j];
        }
        /* step 4: R4 = R4 - R4[0](R1) */
        for (j = 0; j < 6; j++) {
            n[3][j] = kFour[3][j] - kFour[3][0] * n[0][j];
        }
        /* step 5: R5 = R5 - R5[0](R1) */
        for (j = 0; j < 6; j++) {
            n[4][j] = kFour[4][j] - kFour[4][0] * n[0][j];
        }
        /* if a22 = 0, swap row 2 with row 3 */
        if (n[1][1] == 0) {
            for (j = 0; j < 6; j++) {
                augmentedArray.temp = n[1][j];
                n[1][j] = n[2][j];
                n[2][j] = augmentedArray.temp;
            }
        }
        /* step 6: divide Row 2 by R2[1] */
        for (j = 0; j < 6; j++) {
            o[1][j] = n[1][j] / n[1][1];
        }
        /* step 7: R3 = R3 - R3[1](R2) */
        for (j = 0; j < 6; j++) {
            o[2][j] = n[2][j] - n[2][1] * o[1][j];
        }
        /* step 8: R4 = R4 - R4[1](R2) */
        for (j = 0; j < 6; j++) {
            o[3][j] = n[3][j] - n[3][1] * o[1][j];
        }
        /* step 9: R5 = R5 - R5[1](R2) */
        for (j = 0; j < 6; j++) {
            o[4][j] = n[4][j] - n[4][1] * o[1][j];
        }
        /* step 10: R1 = R1 - R1[1](R2) */
        for (j = 0; j < 6; j++) {
            o[0][j] = n[0][j] - n[0][1] * o[1][j];
        }
        /* if a33 = 0, swap row 3 with row 4 */
        if (o[2][2] == 0) {
            for (j = 0; j < 6; j++) {
                augmentedArray.temp = o[2][j];
                o[2][j] = o[3][j];
                o[3][j] = augmentedArray.temp;
            }
        }
        /* step 11: divide row 3 by R3[2] */
        for (j = 0; j < 6; j++) {
            p[2][j] = o[2][j] / o[2][2];
        }
        /* step 12: R4 = R4 - R4[2](R3) */
        for (j = 0; j < 6; j++) {
            p[3][j] = o[3][j] - o[3][2] * p[2][j];
        }
        /* step 13: R5 = R5 - R5[2](R3) */
        for (j = 0; j < 6; j++) {
            p[4][j] = o[4][j] - o[4][2] * p[2][j];
        }
        /* step 14: R1 = R1 - R1[2](R3) */
        for (j = 0; j < 6; j++) {
            p[0][j] = o[0][j] - o[0][2] * p[2][j];
        }
        /* step 15: R2 = R2 - R2[2](R3) */
        for (j = 0; j < 6; j++) {
            p[1][j] = o[1][j] - o[1][2] * p[2][j];
        }
        /* if a44 = 0, swap row 4 with row 5 */
        if (p[3][3] == 0) {
            for (j = 0; j < 6; j++) {
                augmentedArray.temp = p[3][j];
                p[3][j] = p[4][j];
                p[4][j] = augmentedArray.temp;
            }
        }
        /* step 16: divide row 4 by R4[3] */
        for (j = 0; j < 6; j++) {
            q[3][j] = p[3][j] / p[3][3];
        }
        /* step 17: R5 = R5 - R5[3](R4) */
        for (j = 0; j < 6; j++) {
            q[4][j] = p[4][j] - p[4][3] * q[3][j];
        }
        /* step 18: R1 = R1 - R1[3](R4) */
        for (j = 0; j < 6; j++) {
            q[0][j] = p[0][j] - p[0][3] * q[3][j];
        }
        /* step 19: R2 = R2 - R2[3](R4) */
        for (j = 0; j < 6; j++) {
            q[1][j] = p[1][j] - p[1][3] * q[3][j];
        }
        /* step 20: R3 = R3 - R3[3](R4) */
        for (j = 0; j < 6; j++) {
            q[2][j] = p[2][j] - p[2][3] * q[3][j];
        }
        /* if a55 = 0, cannot proceed. Print error message */
        if (q[4][4] == 0) {
            printf("Error: a55 = 0. Cannot proceed.\n");
            return 1;
        }
        /* step 21: divide row 5 by R5[4] */
        for (j = 0; j < 6; j++) {
            r[4][j] = q[4][j] / q[4][4];
        }
        /* step 22: R1 = R1 - R1[4](R5) */
        for (j = 0; j < 6; j++) {
            r[0][j] = q[0][j] - q[0][4] * r[4][j];
        }
        /* step 23: R2 = R2 - R2[4](R5) */
        for (j = 0; j < 6; j++) {
            r[1][j] = q[1][j] - q[1][4] * r[4][j];
        }
        /* step 24: R3 = R3 - R3[4](R5) */
        for (j = 0; j < 6; j++) {
            r[2][j] = q[2][j] - q[2][4] * r[4][j];
        }
        /* step 25: R4 = R4 - R4[4](R5) */
        for (j = 0; j < 6; j++) {
            r[3][j] = q[3][j] - q[3][4] * r[4][j];
        }

        /* display array */
        printf("The row reduced (RREF) augmented matrix is:\n");
        for (i = 0; i < 5; i++) {
            printf("[ ");
            for (j = 0; j < 5; j++) {
                printf("%.3lf ", r[i][j]);
            }
            printf("| %.6lf ]", r[i][5]);
            printf("\n");
        }

        augmentedArray.a0 = r[0][5];
        augmentedArray.a1 = r[1][5];
        augmentedArray.a2 = r[2][5];
        augmentedArray.a3 = r[3][5];
        augmentedArray.a4 = r[4][5];

        /* calculating yCalc for output file */
        for (i = 0; i < c; i++) {
            augmentedArray.yCalc[i] = augmentedArray.a0 + a[i][0] * augmentedArray.a1 + pow(a[i][0], 2) * augmentedArray.a2 + pow(a[i][0], 3) * augmentedArray.a3 + pow(a[i][0], 4) * augmentedArray.a4;
        }

        printf("\n");
        printf("The best-fit Least-Squares equation is:\n");
        printf("y = %.5lfx^0 + %.5lfx^1 + %.5lfx^2 + %.5lfx^3 + %.5lfx^4\n", augmentedArray.a0, augmentedArray.a1, augmentedArray.a2, augmentedArray.a3, augmentedArray.a4);
    }

    /* enter which output file you want your data to be placed */
    FILE *fp2;
    char outputFile[12];

    printf("\nName of output file saved results data: ");
    scanf("%s", outputFile);
    /* open file */
    fp2 = fopen(outputFile, "w");
    if (fp2 == NULL) {
        printf("Error: cannot write to %s", outputFile);
        return 1;
    }

    /* if "out1.csv" is typed, then..... */
    if (strcmp(outputFile, "out1.csv") == 0) {
        printf("Data has been successfully put into out1.csv\n\n");

        /* print results and data into output file */
        fprintf(fp2, "Results Output file from Project 2 - ECE160\n");
        fprintf(fp2, "===========================================\n");
        fprintf(fp2, "Input file read:  %s\n", fileName);
        fprintf(fp2, "Original data series (x,y) and generated fit are given below\n\n\n");
        /* table */
        fprintf(fp2, "x           y           ycalc     \n");
        fprintf(fp2, "=========  =========  =========\n");
        for (i = 0; i < c; i++) {
            fprintf(fp2, "%.6lf, %.6lf,   %.6lf\n", a[i][0], a[i][1], augmentedArray.yCalc[i]);
        }
        fprintf(fp2, "\nPolynomial order chosen for fit: %i\n", poly);
        fprintf(fp2, "\nThe best-fit Least-Squares equation is: \n");
        if (poly == 1) {
            fprintf(fp2, "y = %.5lfx^0 + %.5lfx^1\n", augmentedArray.a0, augmentedArray.a1);
        }
        if (poly == 2) {
            fprintf(fp2, "y = %.5lfx^0 + %.5lfx^1 + %.5lfx^2\n", augmentedArray.a0, augmentedArray.a1, augmentedArray.a2);
        }
        if (poly == 3) {
            fprintf(fp2, "y = %.5lfx^0 + %.5lfx^1 + %.5lfx^2 + %.5lfx^3\n", augmentedArray.a0, augmentedArray.a1, augmentedArray.a2, augmentedArray.a3);
        }
        if (poly == 4) {
            fprintf(fp2, "y = %.5lfx^0 + %.5lfx^1 + %.5lfx^2 + %.5lfx^3 + %.5lfx^4\n", augmentedArray.a0, augmentedArray.a1, augmentedArray.a2, augmentedArray.a3, augmentedArray.a4);
        }
        fprintf(fp2, "\nEnd of output file.\n");

    } else if (strcmp(outputFile, "out2a.csv") == 0) {
        printf("Data has been successfully put into out2a.csv\n\n");

        /* print results and data into output file */
        fprintf(fp2, "Results Output file from Project 2 - ECE160\n");
        fprintf(fp2, "===========================================\n");
        fprintf(fp2, "Input file read:  %s\n", fileName);
        fprintf(fp2, "Original data series (x,y) and generated fit are given below\n\n\n");
        /* table */
        fprintf(fp2, "x,          y,          ycalc,     \n");
        fprintf(fp2, "=========  =========  =========\n");
        for (i = 0; i < c; i++) {
            fprintf(fp2, "%.6lf, %.6lf,   %.6lf\n", a[i][0], a[i][1], augmentedArray.yCalc[i]);
        }
        fprintf(fp2, "\nPolynomial order chosen for fit: %i\n", poly);
        fprintf(fp2, "\nThe best-fit Least-Squares equation is: \n");
        if (poly == 1) {
            fprintf(fp2, "y = %.5lfx^0 + %.5lfx^1\n", augmentedArray.a0, augmentedArray.a1);
        }
        if (poly == 2) {
            fprintf(fp2, "y = %.5lfx^0 + %.5lfx^1 + %.5lfx^2\n", augmentedArray.a0, augmentedArray.a1, augmentedArray.a2);
        }
        if (poly == 3) {
            fprintf(fp2, "y = %.5lfx^0 + %.5lfx^1 + %.5lfx^2 + %.5lfx^3\n", augmentedArray.a0, augmentedArray.a1, augmentedArray.a2, augmentedArray.a3);
        }
        if (poly == 4) {
            fprintf(fp2, "y = %.5lfx^0 + %.5lfx^1 + %.5lfx^2 + %.5lfx^3 + %.5lfx^4\n", augmentedArray.a0, augmentedArray.a1, augmentedArray.a2, augmentedArray.a3, augmentedArray.a4);
        }
        fprintf(fp2, "\nEnd of output file.\n");
    } else if (strcmp(outputFile, "out2b.csv") == 0) {
        printf("Data has been successfully put into out2b.csv");

        /* print results and data into output file */
        fprintf(fp2, "Results Output file from Project 2 - ECE160\n");
        fprintf(fp2, "===========================================\n");
        fprintf(fp2, "Input file read:  %s\n", fileName);
        fprintf(fp2, "Original data series (x,y) and generated fit are given below\n\n\n");
        /* table */
        fprintf(fp2, "x           y           ycalc     \n");
        fprintf(fp2, "=========  =========  =========\n");
        for (i = 0; i < c; i++) {
            fprintf(fp2, "%.6lf, %.6lf,    %.6lf\n", a[i][0], a[i][1], augmentedArray.yCalc[i]);
        }
        fprintf(fp2, "\nPolynomial order chosen for fit: %i\n", poly);
        fprintf(fp2, "\nThe best-fit Least-Squares equation is: \n");
        if (poly == 1) {
            fprintf(fp2, "y = %.5lfx^0 + %.5lfx^1\n", augmentedArray.a0, augmentedArray.a1);
        }
        if (poly == 2) {
            fprintf(fp2, "y = %.5lfx^0 + %.5lfx^1 + %.5lfx^2\n", augmentedArray.a0, augmentedArray.a1, augmentedArray.a2);
        }
        if (poly == 3) {
            fprintf(fp2, "y = %.5lfx^0 + %.5lfx^1 + %.5lfx^2 + %.5lfx^3\n", augmentedArray.a0, augmentedArray.a1, augmentedArray.a2, augmentedArray.a3);
        }
        if (poly == 4) {
            fprintf(fp2, "y = %.5lfx^0 + %.5lfx^1 + %.5lfx^2 + %.5lfx^3 + %.5lfx^4\n", augmentedArray.a0, augmentedArray.a1, augmentedArray.a2, augmentedArray.a3, augmentedArray.a4);
        }
        fprintf(fp2, "\nEnd of output file.\n");
    } else {
        printf("Error: file is not recognized");
    }

    /* close files */
    fclose(fp);
    fclose(fp2);

    return 0;
}