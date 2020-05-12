
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;

// global const int
const int COLS = 3;  // The number of columns in the array
const int MIN = 1;  // The value of the smallest number
const int MAX = 9;  // The value of the largest number

// functions
bool isMagicSquare(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkRange(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size, int min, int max);
bool checkUnique(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkRowSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size);
bool checkColSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size);
bool checkDiagSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size);
void fillArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
void showArray(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size);
// minecradt crafting table
int main()
{
    string name = "Christopher Duong"; // my name
    string date = "5/10/20"; //date due
    
    int magicArrayRow1[COLS], magicArrayRow2[COLS], magicArrayRow3[COLS];
    char yes = 'y';//character to continue if the user wants
    
    do {//loop to see if user wants to continue
        fillArray(magicArrayRow1, magicArrayRow2, magicArrayRow3, COLS); // ask for fillArray function
        showArray(magicArrayRow1, magicArrayRow2, magicArrayRow3, COLS); // ask for showArray function
        if (isMagicSquare(magicArrayRow1, magicArrayRow2, magicArrayRow3, COLS))
        {// displayed when paramenteres fit
            cout << "This is a Lo Shu magic square." << endl;
        }
        else //message displayed when perameters do not fit
            cout << "This is not a Lo Shu magic square." << endl;
        // do you want to play again?
        cout<< endl << endl << "Do you want to try again? ";
        cin >> yes;
        
    } while (yes == 'y' || yes == 'Y');
    cout << "PROGRAMMER: " << name << endl; //my name
    cout << "CMSC140 Project: " << '5' << endl; //assignement number
    cout << "Due Date: " << date << endl; //assignement due date
}
// Getting 3 inputs for wach array
void fillArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size)
{// repeating for the 3 inputs that will be filled
    int rowNumber = 0;
    for (int colNumber = 0; colNumber < size; colNumber++)
    {
        cout << "Enter the number for row " << rowNumber << " and for column " << colNumber << " : ";
        cin >> arrayRow1[colNumber];
    }
    rowNumber++; // increases by 1
    for (int colNumber = 0; colNumber < size; colNumber++)
    {
        cout << "Enter the number for row " << rowNumber<< " and for column " << colNumber << " : ";
        cin >> arrayRow2[colNumber];
    }
    rowNumber++; // increases by 1
    for (int colNumber = 0; colNumber < size; colNumber++)
    {
        cout << "Enter the number for row " << rowNumber<< " and for column " << colNumber << " : ";
        cin >> arrayRow3[colNumber];
    }
}// Display the 3 integer input for rows and collums
void showArray(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size)
{
    int rowNumber = 0;
    for (int colNumber = 0; colNumber < size; colNumber++)
    {
        cout << arrayrow1[colNumber] << " ";
    }
    cout << endl;
    rowNumber++; // Increment by 1
    for (int colNumber = 0; colNumber < size; colNumber++)
    {
        cout << arrayrow2[colNumber] << " ";
    }
    cout << endl;
    rowNumber++; // Increment by 1 one more time
    for (int colNumber = 0; colNumber < size; colNumber++)
    {
        cout << arrayrow3[colNumber] << " ";
    }
    cout << endl;
}// making sure it between 1 & 9
bool checkRange(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size, int min, int max)
{
    bool check = true; // it will go through if true
    // going through parameters in the function
    for (int colNumber = 0; colNumber < COLS; colNumber++)
    {
        // checks the value
        if (arrayRow1[colNumber] < min || arrayRow1[colNumber] > max)
        {// wont go through if paramenter not met
            check = false;
        }
        else if (arrayRow2[colNumber] < min || arrayRow2[colNumber] > max)
        {// wont go through if paramenter not met
            check = false; // wont go through if paramenter not met
        }
        else if (arrayRow3[colNumber] < min || arrayRow3[colNumber] > max)
        {// wont go through if paramenter not met
            check = false;
        }
    }
    return check;
}// check if all 3 inputs are unique
bool checkUnique(int arryRow1[], int arryRow2[], int arryRow3[], int size)
{
    int i = 0, a = 0, b = 0;
    bool check = true;
        if ((arryRow1[i] == arryRow2[a]) && (arryRow2[a] == arryRow3[b]))
        {
            if (i > 1)
            {
                check = false;
            }// will increase by 1
            //twas experimenting and this works suprisingly
            i++, a++ , b++;
        }// will increase by 1
        else if (arryRow1[i] < arryRow2[a])
            i++;
        else if (arryRow2[a] < arryRow3[b])
            a++;
        else
            b++;
    return check;
}//checks if the values are equal
bool checkRowSum(int arryrow1[], int arryrow2[], int arryrow3[], int size)
{
    bool check = true; // goes through if true
    // checks sum value of row1
    int sumofRow1 = arryrow1[0] + arryrow1[1] + arryrow1[2];
    // checks sum value of row2
    int sumofRow2 = arryrow2[0] + arryrow2[1] + arryrow2[2];
    // checks sum value of row 3
    int sumofRow3 = arryrow3[0] + arryrow3[1] + arryrow3[2];
    // validates row if even
    if ((sumofRow1 != sumofRow2)||(sumofRow1 != sumofRow3)||(sumofRow2 != sumofRow3))
    {// will not process if false
        check = false;
    }
    return check;
}// check to see if they are even
bool checkColSum(int arryrow1[], int arryrow2[], int arryrow3[], int size)
{ // if paramaeters match it wll proceed
    bool check = true;
    // sum values of column1
    int sumofCol1 = (arryrow1[0]+arryrow2[0]+arryrow3[0]);
    // sum values of column2
    int sumofCol2 = (arryrow1[1]+arryrow2[1]+arryrow3[1]);
    // sum values of column3
    int sumofCol3 = (arryrow1[2]+arryrow2[2]+arryrow3[2]);
    // checks if the columns are equal or not
    if ((sumofCol1 != sumofCol2)||(sumofCol1 != sumofCol3)||(sumofCol2 != sumofCol3))
    {// will not proceed
        check = false;
    }
    return check;
}// Check if the sum of the diagonals are equal
bool checkDiagSum(int arryrow1[], int arryrow2[], int arryrow3[], int size)
{//will go through if correct parameters are met
    bool status = true;
    // total sum of the values of diagl1 and diag2
    int sumofDiag1 = (arryrow1[0] + arryrow2[1] + arryrow3[2]);
    int sumofDiag2 = (arryrow1[2] + arryrow2[1] + arryrow3[0]);
    // total sum if the sum of the columns is not equal
    if (sumofDiag1 != sumofDiag2)
    {// will not go through if paparemeters are not met
        status = false;
    }
    return status;
}
// validates if its a magic square
bool isMagicSquare(int arryRow1[], int arryRow2[], int arryRow3[], int size)
{// function checking arrays if they are correct
    bool check = false;
    bool inRange = checkRange(arryRow1, arryRow2, arryRow3, size, MIN, MAX);
    bool unique = checkUnique(arryRow1, arryRow2, arryRow3, size);
    bool rowEqual = checkRowSum(arryRow1, arryRow2, arryRow3, size);
    bool colEqual = checkColSum(arryRow1, arryRow2, arryRow3, size);
    bool diagEqual = checkDiagSum(arryRow1, arryRow2, arryRow3, size);
    // final validation
    if (inRange && unique && rowEqual && colEqual && diagEqual)
    {// will let it proceed if true
        check = true;
    }
    return check;
}
