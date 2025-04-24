#pragma once
#include <string>
namespace mathlib {
	template <class t>
	class Fraction {
	public:
		Fraction(t numerator, t denominator) {
			this->numerator = numerator;
			if (denominator == 0) {
				this->denominator = 1;
			}
			else {
				this->denominator = denominator;
			}
		}
		Fraction() {}




	int getGCD(int a, int b) {
		int temp = 0;
		while (b != 0) {
			temp = b;
			b = a % b;
			a = temp;
		}
		return temp;
	}
	Fraction<t> Simplify() {

		t gcd = getGCD(abs(this->numerator), abs(this->denominator));

		t simplifiedNumerator = this->numerator / gcd;
		t simplifiedDenominator = this->denominator / gcd;

		if (this->denominator < 0) {
			simplifiedNumerator = -simplifiedNumerator;
			simplifiedDenominator = -simplifiedDenominator;
		}
		return Fraction<t>(simplifiedNumerator, simplifiedDenominator);

	}


		//Arithmetic overloads: I have no idea how to fix these issues as of now. They cant take params...
		Fraction<t> operator +(Fraction<t> otherFraction) {
			t numerator = this->numerator + otherFraction->numerator;
			t denominator = this->denominator + otherFraction->denominator;
			return Fraction<t>(numerator, denominator);
		}
		Fraction<t> operator - (Fraction<t> otherFraction) {
			t numerator = this->numerator - otherFraction->numerator;
			t denominator = this->denominator - otherFraction->denominator;
			return Fraction<t>(numerator, denominator);
		}
		Fraction operator *(Fraction<t> otherFraction) {
			t numerator = this->numerator * otherFraction->numerator;
			t denominator = this->denominator * otherFraction->denominator;
			return Fraction<t>(numerator, denominator);
		}
		Fraction operator / (Fraction<t> otherFraction) {
			t numerator = this->numerator / otherFraction->numerator;
			t denominator = this->denominator / otherFraction->denominator;
			return Fraction<t>(numerator, denominator);
		}

		//Comparison overloads:
		bool operator ==(Fraction<t> otherFraction) {
			Simplify(this);
			Simplify(otherFraction);
				if (this->numerator == otherFraction->numerator && this->denominator == otherFraction->denominator) {
					return true;
				}
		}
		bool operator !=(Fraction<t> otherFraction) {
				Simplify(this);
				Simplify(otherFraction);
					if (this->numerator != otherFraction->numerator && this->denominator != otherFraction->denominator) {
						return true;
					}
		}
		bool operator <(Fraction<t> otherFraction) {
			Simplify(this);
			Simplify(otherFraction);
				if (this->numerator < otherFraction->numerator && this->denominator < otherFraction->denominator) {
					return true;
				}
		}
		bool operator >(Fraction<t> otherFraction) {
			Simplify(this);
			Simplify(otherFraction);
				if (this->numerator > otherFraction->numerator && this->denominator > otherFraction->denominator) {
					return true;
				}
		}
		bool operator <=(Fraction<t> otherFraction) {
			Simplify(this);
			Simplify(otherFraction);
				if (this->numerator <= otherFraction->numerator && this->denominator <= otherFraction->denominator) {
					return true;
				}
		}
		bool operator >=(Fraction<t> otherFraction) {
			Simplify(this);
			Simplify(otherFraction);
				if (this->numerator >= otherFraction->numerator && this->denominator >= otherFraction->denominator) {
					return true;
				}
		}
	//Streaming overloads
	friend std::ostream& operator << (std::ostream& output, Fraction<t> frac) {
		output << frac->numerator << "/" << frac->denominator;
		return output;
	}
	friend std::istream& operator >>(std::istream& input, Fraction<t> frac) {
		t fracNum = frac.numerator;
		t fracDem = frac.denominator;
		

		input.getline(fracNum, std::numeric_limits<std::streamsize>::max(), '/');
		input.getline(fracDem, std::numeric_limits<std::streamsize>::max(), ' ');
		//the .getline commands say that "no overloaded function can convert all argument types"
		input.ignore( std::numeric_limits<std::streamsize>::max(), '\n');
		return input;

		
	}
	float toFloat() {
		return float(this->numerator / this->denominator);
	}

	private:
		t numerator;
		t denominator;


	};





}