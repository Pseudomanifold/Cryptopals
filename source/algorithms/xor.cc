#include "xor.hh"

#include <conversions/bytes.hh>

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

ByteArray repeatingKeyXOR( const ByteArray& bytes, const ByteArray& key )
{
  auto numBytes  = bytes.size();
  auto keyLength = key.size();

  ByteArray result;
  result.reserve( bytes.size() );

  for( decltype( bytes.size() ) i = 0; i < numBytes; i++ )
    result.push_back( bytes[i] xor key[i % keyLength] );

  return result;
}

// ---------------------------------------------------------------------

ByteArray repeatingKeyXOR( const ByteArray& bytes, const std::string& key )
{
  return repeatingKeyXOR( bytes, toBytes( key.begin(), key.end() ) );
}

// ---------------------------------------------------------------------

}
