#pragma once
#include <string>
#include <iostream>
#include <sstream>
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




	int getGCD(t a, t b) {
		t temp = 0;
		while (b != 0) {
			temp = b;
			b = a % b;
			a = temp;
		}
		return temp;
	}
	float toFloat() const {
		return float((this->numerator + 0.0f) / (this->denominator + 0.0f)); // floats show up as integers unless i do some dirty casting
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
		Fraction<t> operator +(const Fraction<t>& otherFraction) {
			t numerator = this->numerator + otherFraction.numerator;
			t denominator = this->denominator + otherFraction.denominator;
			return Fraction<t>(numerator, denominator);
		}
		Fraction<t> operator - (const Fraction<t>& otherFraction) {
			t numerator = this->numerator - otherFraction.numerator;
			t denominator = this->denominator - otherFraction.denominator;
			return Fraction<t>(numerator, denominator);
		}
		Fraction operator *(const Fraction<t>& otherFraction) {
			t numerator = this->numerator * otherFraction.numerator;
			t denominator = this->denominator * otherFraction.denominator;
			return Fraction<t>(numerator, denominator);
		}
		Fraction operator / (const Fraction<t>& otherFraction) {
			t numerator = this->numerator / otherFraction.numerator;
			t denominator = this->denominator / otherFraction.denominator;
			return Fraction<t>(numerator, denominator);
		}

		//Comparison overloads:
		bool operator ==(const Fraction<t>& otherFraction) const {
			return this->toFloat() == otherFraction.toFloat();
		}
		bool operator !=(const Fraction<t>& otherFraction) const {
			return this->toFloat() != otherFraction.toFloat();
		}
		bool operator <(const Fraction<t>& otherFraction) const {
			return this->toFloat() < otherFraction.toFloat();
		}
		bool operator >(const Fraction<t>& otherFraction) const {
			return this->toFloat() > otherFraction.toFloat();
		}
		bool operator <=(const Fraction<t>& otherFraction) const {
			return this->toFloat() <= otherFraction.toFloat();
		}
		bool operator >=(const Fraction<t>& otherFraction) const {
			return this->toFloat() >= otherFraction.toFloat();
		}
	//Streaming overloads
	friend std::ostream& operator << (std::ostream& output, Fraction<t> frac) {
		output << frac.numerator << "/" << frac.denominator;
		return output;
	}
	friend std::istream& operator >>(std::istream& input, Fraction<t>& frac) {
		t fracNum = frac.numerator;
		t fracDem = frac.denominator;

		std::string str;
		std::getline(input, str, '/');
		std::istringstream(str) >> frac.numerator;
		std::getline(input, str, '\n');
		std::istringstream(str) >> frac.denominator;

		//the .getline commands say that "no overloaded function can convert all argument types"
		return input;

		
	}

	private:
		t numerator;
		t denominator;


	};





}