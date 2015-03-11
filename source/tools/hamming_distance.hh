#ifndef CRYPTO_HAMMING_DISTANCE_HH__
#define CRYPTO_HAMMING_DISTANCE_HH__

#include <common/types.hh>

namespace crypto
{

/** Calculates the Hamming distance between two bytes arrays. */
unsigned int hammingDistance( const ByteArray& s, const ByteArray& t );

}

#endif
