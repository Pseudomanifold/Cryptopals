#ifndef CRYPTO_FREQUENCY_ANALYSIS_HH__
#define CRYPTO_FREQUENCY_ANALYSIS_HH__

#include <common/types.hh>

#include <map>
#include <string>
#include <vector>

namespace crypto
{

/**
  Performs frequency analysis on a given byte array. The function assumes that
  the bytes represent valid 8-bit characters. Upon ending, this function will
  only return charactes from A-Z and 0-9 with their relative frequencies.
*/

std::map<char, double> eightBitFrequencies( const ByteArray& bytes );

/**
  Convenience function for returning a sorted vector of 8-bit characters along
  with their relative frequency in the text.
*/

std::vector< std::pair<char, double> > sortedEightBitFrequencies( const ByteArray& bytes );

}

#endif
