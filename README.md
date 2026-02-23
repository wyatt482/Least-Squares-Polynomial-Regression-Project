# Least-Squares-Polynomial-Regression-Project
C program that performs least-squares polynomial regression (orders 1-4) using Gauss-Jordan elimination and outputs results into a CSV file.


## How it Works
1. User inputs the data file and the name of the data file.
2. Program reads (x,y) data from the file.
3. Program uses summations to create an augmented matrix
5. Gauss-Jordan elimination reduces the matrix to Reduced Row Echelon Form (RREF)
6. Outputs coefficients of the best-fit least squares equation
7. Results are written into an output CSV file.


## Example Data file
test1.csv

-3.000,0.9
-2.00,0.8
-1.000,0.4
-0.200,0.2
1.000,0.1
3.000,0


## Example Output
./project2
Enter the polynomial order (1-4): 3
Enter name of the data file: test1.csv

File successfully opened...

Total data points (x,y) read from file: 6
The polynomial is y = a0 + a1x + a2x^2 + a3x^3

The coefficients (sqaure) matrix 'A' is 4x4 with values:
[ 6.000 -2.200 24.040 -8.008 ]
[ -2.200 24.040 -8.008 180.002 ]
[ 24.040 -8.008 180.002 -32.000 ]
[ -8.008 180.002 -32.000 1524.000 ]

The constants (column) Matrix 'B' is 4x1
[ 2.400 ]
[ -4.640 ]
[ 11.808 ]
[ -31.002 ]

The row reduced (RREF) augmented matrix is:
[ 1.000 0.000 0.000 0.000 | 0.218077 ]
[ 0.000 1.000 0.000 0.000 | -0.210641 ]
[ 0.000 0.000 1.000 0.000 | 0.028219 ]
[ 0.000 0.000 0.000 1.000 | 0.006275 ]

The linear least-squares best fit to data is:
y = 0.21808x^0 + -0.21064x^1 + 0.02822x^2 + 0.00628x^3

Name of output file saved results data: out2a.csv
Data has been successfully put into out2a.csv


## Example Output File Format
out2a.csv

Results Output file from Project 2 - ECE160
===========================================
Input file read:  test1.csv
Original data series (x,y) and generated fit are given below


x,          y,          ycalc,     
=========  =========  =========
-3.000000, 0.900000,   0.934537
-2.000000, 0.800000,   0.702032
-1.000000, 0.400000,   0.450662
-0.200000, 0.200000,   0.261284
1.000000, 0.100000,   0.041930
3.000000, 0.000000,   0.009555

Polynomial order chosen for fit: 3

The best-fit Least-Squares equation is: 
y = 0.21808x^0 + -0.21064x^1 + 0.02822x^2 + 0.00628x^3

End of output file.


## Compilation
gcc -o project2 project2.c -lm

## Run
./project2
