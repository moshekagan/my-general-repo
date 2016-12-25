#import <stdio.h>
#import <math.h>
#define TRUE		1
#define	FALSE		0

/* function declaration */
int isValidUserInput(int userInput);
void triangle();
void checkDigitId();
void rugsShop();
void squaredEquationSolver();
int isTriagular(int potentialTriangleNumber);
int isPositive(int num);
void printSquaredEquation(double a, double b, double c);
void solveTheSquaredEquation(double a, double b, double c);

int main()
{
	int userInput;

	do {
		printf("Choose 1 for triangle, 2 for ID, 3 for carpets, 4 for equation, -1 for exit\n");
		scanf("%d", &userInput);

		if (isValidUserInput(userInput) == TRUE)
		{
			// The user insert a good input, can continue with program :)
			switch (userInput)
			{
				case 1:
					triangle();
					break;
				case 2:
					checkDigitId();
					break;
				case 3:
					rugsShop();
					break;
				case 4:
					squaredEquationSolver();
					break;
			}
		}
		else
		{
			// Bad input, the user need to insert a new one
			printf("No such option!\n");
		}

	} while (userInput != -1); // if the user inserting -1 he want to leave

	return 0;
}

int isValidUserInput(int userInput)
{
	if ((0 < userInput && userInput < 5) || userInput == -1)
		return TRUE;
	else
		return FALSE;
}

void triangle()
{

	int left, right, isTri, index = 1, temp = 0;
    printf("Enter 2 numbers (left and right):\n");
    scanf("%d %d", &left, &right);
    if (left > 0 && right > 0 && left <= right)
    {
    // GOOD
        do
        {
            isTri = (index * (index + 1)) / 2;
            index++;

            if (isTri >= left && isTri <= right)
            {
                printf("%d\n", isTri);
                temp++;
            }
        } while (isTri <= right);
        if (temp == 0)
            printf("None\n");
    }
    else
    {
    // ERROR
    printf("Error input!\n");
    }
	// // This function will get from the user 2 numbers and will calculate all the
	// // triangles numbers between left to the rigth numbers
	//
	// int left, rigth;
	// int potentialTriangleNumber;
	// int doesWeFoundTriangleNumber = FALSE, saveThatWeFoundriagular = FALSE;
	//
	// printf("Enter 2 numbers (left and rigth):\n");
	// scanf("%d %d", &left, &rigth);
	//
	// if (isPositive(left) == TRUE && isPositive(rigth) == TRUE && left <= rigth)
	// {
	// 	// The user insert a GOOD inputs :)
	// 	for (potentialTriangleNumber = left ; potentialTriangleNumber <= rigth ; potentialTriangleNumber++)
	// 	{
	// 		doesWeFoundTriangleNumber = isTriagular(potentialTriangleNumber);
	// 		if (doesWeFoundTriangleNumber == TRUE)
	// 			saveThatWeFoundriagular = TRUE;
	// 	}
	//
	// 	if (saveThatWeFoundriagular == FALSE) // We didn't found any triangular between left to rigth
	// 		printf("None\n");
	// }
	// else
	// 	// The user insert a BAD inputs :(
	// 	printf("Error input!\n");
}

int isTriagular(int potentialTriangleNumber)
{
	// Checking if the number is a triangular
	// if it is triangular printing the number and return TRUE else return FALSE
	int index = 1, checkTriangleNumber;
	do {
		checkTriangleNumber = (index * (index + 1)) / 2;

		if (checkTriangleNumber == potentialTriangleNumber) // we found a triangular num :)
		{
			printf("%d\n", potentialTriangleNumber);
			return TRUE;
		}

		index++;
	} while(checkTriangleNumber <= potentialTriangleNumber);

	return FALSE; // We didn't found any triangular number :(
}

int isPositive(int num)
{
	if (num > 0)
		return TRUE;
	else
		return FALSE;
}

void checkDigitId()
{
	unsigned long int numid;
    int index, sum = 0, digit;

    scanf("%uld", &numid);
    digit = numid % 10;
    sum = sum + digit;
    numid = numid / 10;
    for (index = 0; index < 8; index++)
    {
        digit = numid % 10;
        if (index % 2 == 0)
        {
            digit = digit * 2;
            if (digit >= 10)
            {
                digit = (digit / 10) + (digit % 10);
                sum = sum + digit;
                numid = numid / 10;
            }
            else
            {
                sum = sum + digit;
                numid = numid / 10;
            }
        }
        else
        {
            sum = sum + digit;
            numid = numid / 10;
        }
    }
    if (sum % 10 == 0 && sum > 0)
        printf("Valid ID number\n");
    else
        printf("Invalid ID number\n");
}

void rugsShop()
{
	int width, i, j;
    scanf("%d", &width);
    if (width > 10 || width < 2)
        printf("Error input!\n");
    //first carpet
    if (width >= 2 && width <= 10)
    {
        for (i = 1; i <= width; i++)
        {
            for (j = 1; j <= width; j++)
            {
                if ((i + j) % 2 == 0)
                    printf("X");
                else
                    printf("O");
            }
            printf("\n");
        }
    }
    printf("\n");

    //second carpet
    if (width >= 2 && width <= 10)
    {
        for (i = 1; i <= (width + 1); i++)
        {
            for (j = 1; j <= width; j++)
            {
                if (i > j)
                    printf("O");
                else
                    printf("X");
            }
            printf("\n");
        }
    }


    //third carpet
    if ((width >= 2 && width <= 10) && (width % 2 == 0))
    {
        printf("\n");
        for (i = 1; i <= width; i++)
        {
            for (j = 1; j <= width; j++)
            {
                if (i <= (width / 2) && j <= (width / 2))
                    printf("X");
                else if (i <= (width / 2) && j > (width / 2))
                    printf("O");
                else if (i > (width / 2) && j <= (width / 2))
                    printf("O");
                else if (i > (width / 2) && j > (width / 2))
                    printf("X");
            }
            printf("\n");
        }
    }
}

void squaredEquationSolver()
{
	double a, b, c;

	printf("Enter three numbers:\n");
	scanf("%lf %lf %lf", &a, &b, &c);

	printSquaredEquation(a, b, c);

	solveTheSquaredEquation(a, b, c);
}

void printSquaredEquation(double a, double b, double c)
{
	// The function printing the Squared Equation to the console by the spec

	int isZero = TRUE;

	// Printing a
	if (a == 1){
		printf("x^2");
		isZero = FALSE;
	}
	else if (a == -1)
	{
		printf("-x^2");
		isZero = FALSE;
	}
	else if (a != 0)
	{
		printf("%gx^2", a);
		isZero = FALSE;
	}

	// Printing b
	if (b == 1){
		if (isZero == TRUE)
			printf("x");
		else
			printf("%cx", '+');
		isZero = FALSE;
	}
	else if (b == -1)
	{
		printf("-x");
		isZero = FALSE;
	}
	else if (b < 0)
	{
		printf("%gx", b);
		isZero = FALSE;
	}
	else if (b > 0)
	{
		if (isZero ==TRUE)
			printf("%gx", b);
		else
			printf("%c%gx", '+', b);
		isZero = FALSE;
	}

	// Printing c
	if (c < 0)
	{
		printf("%g", c);
		isZero = FALSE;
	}
	else if (c > 0)
	{
		if (isZero ==TRUE)
			printf("%g", c);
		else
			printf("%c%g", '+', c);
		isZero = FALSE;
	}

	if (isZero == TRUE)
		printf("0");

	printf(" = 0\n");
}

void solveTheSquaredEquation(double a, double b, double c)
{
	// The function will solve the Squared Equation nad will print the
	// resoult to the console by the spec

	double soulotion1, soulotion2;
	double realPart, imaginaryPart;

	if (a == 0) { // can't devided by 0!
		if (b == 0) // case that there is infinite solutions
			printf("Infinite solutions!\n");
		else // case that there is no soulotion
			printf("No solution!\n");
	} else {
		double determinant = pow(b, 2) - 4*a*c; // a^2 - 4*a*c (the clac unser the squert)

		if (determinant > 0) // case for real and different soulotions
	  {
		  // sqrt() function returns square root
		  soulotion1 = (-b + sqrt(determinant)) / (2*a);
		  soulotion2 = (-b - sqrt(determinant)) / (2*a);

		  printf("x1 = %.2lf\n", soulotion1);
			printf("x2 = %.2lf\n", soulotion2);
	  }
		else if (determinant == 0) // case for 1 real soulotion
		{
			soulotion1 = soulotion2 = -b / (2*a);
			printf("x1 = %.2lf\n", soulotion1);
		}
		else // (determinant < 0): case for no real soulotions
		{
			realPart = -b / (2*a);
			imaginaryPart = sqrt(-determinant) / (2*a);

			printf("x1 = %.2lf + %.2lfi\n", realPart, imaginaryPart);
			printf("x2 = %.2lf - %.2lfi\n", realPart, imaginaryPart);
		}
	}
}
