#include <iostream>

using namespace std;

//#define DEBUG

struct request {
	int dividend; // number to divide
	int divisor; // number to divide by
};

struct result {
	int quotient;
	int remainder;
};

struct result divide(const struct request req) {
	struct result res;
	unsigned int dividend = req.dividend;
	int carry;

	/*
		LDA #$0F
		STA dividend
		LDA #$4
		STA divisor
		LDA #$0
		STA quotient
		LDX #$8
	*/
	int accum = 0, quotient = 0, counter = 32; // 32 bit integer

	/*
DLOOP:	ASL dividend
		ROL
	*/
	#ifdef DEBUG
	cout << "loop\tcarry\taccum\tnew acc\tquot\tdivend" << endl;
	#endif
	do {
		carry = dividend & 0x80000000 ? 1 : 0;
		dividend <<= 1;
		accum <<= 1;
		#ifdef DEBUG
		cout << counter << "\t" << carry << "\t" << accum << "\t";
		#endif
		accum += carry;
		#ifdef DEBUG
		cout << accum << "\t" << quotient << "\t" << dividend << endl;
		#endif
	/*
		CMP divisor
		PHP
		ROL quotient
		PLP
		BCC NOSBC
		SBC divisor
	*/
		quotient <<= 1;
		if(accum > req.divisor) {
			quotient++;
			accum -= req.divisor;
		}

	/*
NOSBC:	DEX
		BNE DLOOP
	*/
	} while(--counter > 0);
	/*
		STA remainder
		RTS
	*/
	res.quotient = quotient;
	res.remainder = accum;
	return res;
}

void disp(const struct request req, const struct result obj) {
	cout << req.dividend << " / " << req.divisor << " = " << obj.quotient << ", remainder = " << obj.remainder << endl;
}

int main() {
	struct request req {100, 9};
	struct result res = divide(req);
	disp(req, res);
	req.dividend = 1234567;
	req.divisor = 13;
	res = divide(req);
	disp(req,res);
	return 0;
}
