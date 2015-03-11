#include "base64.hh"

#include <string>

namespace
{

const char* base64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                     "abcdefghijklmnopqrstuvwxyz"
                     "0123456789"
                     "+/";

}

namespace crypto
{

// ---------------------------------------------------------------------

std::string toBase64( const ByteArray& bytes )
{
  std::string result;
  auto numBytes = bytes.size();

  for( decltype(numBytes) i = 0; i < numBytes; i += 3 )
  {
    Byte a = bytes[i];
    Byte b = i+1 < numBytes ? bytes[i+1] : 0;
    Byte c = i+2 < numBytes ? bytes[i+2] : 0;

    unsigned int j = ((a & 0xFC) >> 2);
    unsigned int k = ((a & 0x03) << 4) + ((b & 0xF0) >> 4);
    unsigned int l = ((b & 0x0F) << 2) + ((c & 0xC0) >> 6);
    unsigned int m = (c & 0x3F);

    result.push_back( base64[j] );
    result.push_back( base64[k] );

    if( i+1 < numBytes )
      result.push_back( base64[l] );
    else
      result.push_back( '=' );

    if( i+2 < numBytes )
      result.push_back( base64[m] );
    else
      result.push_back( '=' );
  }

  return result;
}

// ---------------------------------------------------------------------

}
