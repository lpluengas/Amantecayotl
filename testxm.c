#include "TestU01.h"

//Example PRNG: Xorshift 32
static unsigned int y= 2463534242U;

unsigned int xorshift(void){
	y ^= (y << 13);
	y ^= (y >> 17);
	return y ^= (y << 5);
}

int  main(){
	//int n=pow(2, 26);// stream of 2^26 bits
	//Create TestU01 PRNG object for our generator
	unif01_Gen* gen = unif01_CreateExternGenBits("Xorshift 32", xorshift);
	//Run the tests.
	//bbattery_Alphabit (gen, n, 0, 32);
	//bbattery_Rabbit (gen, n);
	//bbattery_pseudoDIEHARD (gen);
	//Run the tests.
	bbattery_SmallCrush(gen);
	//bbattery_Crush(gen);
	//bbattery_BigCrush(gen);

	//Clean up.
	unif01_DeleteExternGenBits(gen);
	return 0;
}
