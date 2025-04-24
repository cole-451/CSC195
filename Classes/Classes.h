#pragma once
#include <string>

// declare classes inside the header, flesh them out in the .cpp file

class Media {
public:
	virtual void Read(std::ostream& ostream, std::istream& istream) { // virtual means that it can and will be overridden when specified
		istream.clear();
		ostream << "Enter name (Until further notice, do NOT put a space!): " << std::endl; // White spaces kill the program. Look into how to fix this.
		
		//getline(istream, title); // THIS JUST SKIPS THE INPUT.
		istream >> title; // stops at whitespace
		istream.clear();
		ostream << "What year was it created?" << std::endl;
		istream.clear();
		istream >> yearReleased; //gets possibly skipped.
		
	}
	virtual void Write(std::ostream& ostream) {
		ostream << "Title: " << getTitle() << std::endl;
		ostream << "Year Released: " << getYearReleased() << std::endl;
	}


std::string getTitle() {
	return title;
}
void setTitle(std::string title_input) {
	title = title_input;
}
unsigned short getYearReleased() {
	return yearReleased;
}
void setYearReleased(unsigned short yrReleased) {
	yearReleased = yrReleased;
}
	enum class type {
		VIDEO_GAME,
		MOVIE
	};
virtual enum type getType() = 0; // virtual with a "=0" makes it abstract


private:
	std::string title;
	unsigned short yearReleased = 0000;

};

class VideoGame : public Media{
public:
	char getESRB() {
		return ESRB;
	}
	void setESRB(char ESRB) {
		this->ESRB = ESRB;
	}
	void Read(std::ostream& ostream, std::istream& istream) override { //ostream and istream are commands used for input when you dont include iostream
		Media::Read(ostream, istream); // this is how you call to the superclass!
		ostream << "Enter ESRB: ";
		istream >> ESRB;
		istream.clear();
	}
	void Write(std::ostream& ostream) override {
		Media::Write(ostream);
		ostream << "ESRB Rating: " << getESRB() << std::endl;

	}
	 type getType() override { // help! why no work!!!
		 return Media::type::VIDEO_GAME;
	}
private:
	char ESRB = 'O';
};

class Movie : public Media {
public:
	char getMPAARating() {
		return MPAA_rating;
	}
	void setMPAARating(char MPAA_rating) {
		this->MPAA_rating = MPAA_rating;
	}
	void Read(std::ostream& ostream, std::istream& istream)override {
		Media::Read(ostream, istream);
		ostream << "Enter MPAA Rating: ";
		istream >> MPAA_rating;
		istream.clear();
	}
	void Write(std::ostream& ostream) {
		Media::Write(ostream);
		ostream << "MPAA Rating: "<< getMPAARating() << std::endl;
	}


	type getType() override { // help! why no work!!!
		return Media::type::MOVIE;
	}

private:
	char MPAA_rating = 'G';

};

