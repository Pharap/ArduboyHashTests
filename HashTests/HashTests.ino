#include "Hashing.h"

#include <Arduboy2.h>

Arduboy2 arduboy;

void setup()
{
	arduboy.begin();
}

void loop()
{
	if(!arduboy.nextFrame())
		return;

	char object[256] {};

	using namespace Hashing;

	//using Hash = SummationHash<int32_t>;
	//using Hash = SummationHash<uint32_t>;
	
	//using Hash = CSharpTupleHash<int32_t>;
	//using Hash = CSharpTupleHash<uint32_t>;

	//using Hash = Adler32;

	//using Hash = FNV32;
	//using Hash = FNV32a;
	
	//using Hash = KnuthHash;
	//using Hash = OneAtATimeHash;
	//using Hash = PartialOneAtATimeHash;

	//EEPROM::putWithHash<Hash>(0, object);

	arduboy.println(static_cast<int>(Hash::hash(object)));

	arduboy.display(true);
}