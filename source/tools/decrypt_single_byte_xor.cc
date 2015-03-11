#include "decrypt_single_byte_xor.hh"

#include <algorithms/xor.hh>

#include <conversions/bytes.hh>
#include <conversions/hex.hh>

#include <algorithm>
#include <locale>

namespace
{

bool isPlainText( const std::string& s )
{
  for( auto&& c : s )
  {
    if( c < 32 && c != '\n' && c != '\r' && c != '\t' )
      return false;
  }

  return true;
}

unsigned int numPrintableCharacters( const std::string& s )
{
  return std::count_if( s.begin(), s.end(),
                        [] (char c)
                        {
                          return std::isalnum(c) || std::isspace(c);
                        } );
}

}

namespace crypto
{

// ---------------------------------------------------------------------

std::string decryptSingleByteXOR( const std::string& s )
{
  ByteArray bytes = hexToBytes(s);

  std::string candidate;
  unsigned int score = 0;

  for( unsigned short k = 0; k < 256; k ++)
  {
    ByteArray key( bytes.size(), Byte(k) );
    ByteArray result = fixedXOR( bytes, key );

    std::string str = toString( result );

    if( !isPlainText(str) )
      continue;

    unsigned int s = numPrintableCharacters(str);
    if( s > score )
    {
      score     = s;
      candidate = str;
    }
  }

  return candidate;
}

// ---------------------------------------------------------------------

}
