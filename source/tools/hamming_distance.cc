#include "hamming_distance.hh"

#include <algorithm>

namespace
{

unsigned int hammingDistance( crypto::Byte s, crypto::Byte t )
{
  auto b            = s xor t;
  unsigned int bits = 0;

  while(b)
  {
    ++bits;
    b = b & (b - 1);
  }

  return bits;
}

}

namespace crypto
{

unsigned int hammingDistance( const ByteArray& s, const ByteArray& t )
{
  auto sSize          = s.size();
  auto tSize          = t.size();
  unsigned int result = 0;

  for( decltype(tSize) i = 0; i < std::min(sSize, tSize); i++)
    result += ::hammingDistance( s[i], t[i] );

  result += 8 * ( std::max(sSize, tSize) - std::min(sSize, tSize) );
  return result;
}

}
