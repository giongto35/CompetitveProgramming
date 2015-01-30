/*
 * CTU Open Contest 2011
 *
 * Sample solution: Mortgage
 * Author: Jakub Cerny
 */

#include <stdio.h>
#include <math.h>

int main() {
	int X, Y, N;
	float r;

	char can_pay;
	double balance, mr;

	while ( scanf("%d %d %d %f", &X, &Y, &N, &r) == 4 ) {
		if (!X) break;

		mr = r/100/12; /* monthly interst rate in abs value */
		can_pay = 1;
		if (X*mr >= Y) {
			/* monthly payment is less or equal to interests */
			can_pay = 0;
		} else if (r < 0.001) {
			/* we got zero interest rate */
			if( Y* N*12 < X )
				can_pay = 0;
		}
		else {
			/* pay monthly payments and add interests at the end of each month */
			/* formula for balance after N years - just sum of geometric sequence and modification of this expression */
			balance = (X - Y/mr) * pow(1+mr, N*12) + Y/mr;
			if(balance > 0)  can_pay = 0;
		}

		if(can_pay)	printf("YES\n");
		else 		printf("NO\n");
	}
	return 0;
}
