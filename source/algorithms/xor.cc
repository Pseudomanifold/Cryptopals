#include "xor.hh"

#include <stdexcept>

namespace crypto
{

// ---------------------------------------------------------------------

ByteArray fixedXOR( const ByteArray& s, const ByteArray& t )
{
  if( s.size() != t.size() )
    throw std::runtime_error( "Byte array size must not differ" );

  ByteArray result;
  result.reserve( s.size() );

  for( decltype( s.size() ) i = 0; i < s.size(); i++ )
    result.push_back( s[i] xor t[i] );

  return result;
}

// ---------------------------------------------------------------------

}
