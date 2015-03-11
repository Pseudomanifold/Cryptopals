#ifndef CRYPTO_BYTES_HH__
#define CRYPTO_BYTES_HH__

#include <common/types.hh>

#include <iterator>

namespace crypto
{

/**
  Converts a given range to an array of bytes. The underlying data type
  must be convertible to the byte data type for this to work.
*/

template <class InputIterator> ByteArray toBytes( InputIterator begin, InputIterator end )
{
  ByteArray bytes;
  bytes.reserve( std::distance( begin, end ) );

  for( auto it = begin; it != end; ++it )
    bytes.push_back( Byte( *it) );

  return bytes;
}

}

#endif
