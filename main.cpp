#include <stdio.h>
#include "include/MiniFB_cpp.h"
#include "include/FreeImage.h"

// INGAME ENTITIES
// character model
class Submarine {
public:
	FIBITMAP* Fi_submarine;
	uint8_t SubmarineBits;
	int SubmarinePitch;

	// Constructor
	Submarine(FIBITMAP* fi_submarine, uint8_t submarineBits, int submarinePitch) {

	}

};

// obstacle entities
class Brick {
public:
	FIBITMAP* Fi_brick;
	uint8_t BrickBits;
	int BrickPitch;

	// Constructor
	Brick(FIBITMAP* fi_brick, uint8_t brickBits, int brickPitch) {

	}

};

class Seaweed {
public:
	FIBITMAP* Fi_seaweed;
	uint8_t SubmarineBits;
	int SubmarinePitch;

	// Constructor
	Seaweed(FIBITMAP* fi_seaweed, uint8_t seaweedBits, int seaweedPitch) {

	}

};


// hostile entities
class Shark {
public:
	FIBITMAP* Fi_shark;
	uint8_t SharkBits;
	int SharkPitch;

	// Constructor
	Shark(FIBITMAP* fi_shark, uint8_t sharkBits, int sharkPitch) {

	}

};

class Squid {
public:
	FIBITMAP* Fi_squid;
	uint8_t SquidBits;
	int SquidPitch;

	// Constructor
	Squid(FIBITMAP* fi_squid, uint8_t squidBits, int squidPitch) {

	}

};


// additional life entity
class Coral {
public:
	FIBITMAP* Fi_coral;
	uint8_t CoralBits;
	int CoralPitch;

	// Constructor
	Coral(FIBITMAP* fi_coral, uint8_t coralBits, int coralPitch) {

	}

};


// weapon entity
class Starfish {
public:
	FIBITMAP* Fi_starfish;
	uint8_t StarfishBits;
	int StarfishPitch;

	// Constructor
	Starfish(FIBITMAP* fi_starfish, uint8_t starfishBits, int starfishPitch) {

	}

};

int main() {
	printf("Hello world!");
	// Submarine submarine;
}
