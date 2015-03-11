#include "hex.hh"

#include <stdexcept>

namespace crypto
{

// ---------------------------------------------------------------------

Byte toByte( char c )
{
  bool valid =    ('0' <= c && c <= '9')
               || ('A' <= c && c <= 'F')
               || ('a' <= c && c <= 'f');

  if( !valid )
    throw std::domain_error( "Invalid hexadecimal character" );

  if( '0' <= c && c <= '9' )
    return Byte(c - '0');
  else if( 'A' <= c && c <= 'F' )
    return Byte(c - 'A' + 10);
  else
    return Byte(c - 'a' + 10);
}

// ---------------------------------------------------------------------

Byte toByte( char high, char low )
{
  Byte h = toByte( high );
  Byte l = toByte( low );

  return (h << 4) + l;
}

// ---------------------------------------------------------------------

ByteArray hexToBytes( const std::string& s )
{
  if( s.length() % 2 != 0 )
    throw std::runtime_error( "String must represent hexadecimal number" );

  ByteArray result;
  result.reserve( s.length() / 2 );

  for( decltype( s.length() ) i = 0; i < s.length(); i += 2 )
    result.push_back( toByte( s[i], s[i+1] ) );

  return result;
}

// ---------------------------------------------------------------------

}
