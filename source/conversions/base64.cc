#include "base64.hh"

#include <stdexcept>
#include <string>

namespace
{

const char* base64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                     "abcdefghijklmnopqrstuvwxyz"
                     "0123456789"
                     "+/";

crypto::Byte index( char c )
{
  for( unsigned int i = 0; i < 64; i++ )
    if( base64[i] == c )
      return static_cast<crypto::Byte>(i);

  return 0;
}

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

ByteArray fromBase64( const std::string& string )
{
  if( string.size() % 4 != 0 )
    throw std::runtime_error( "Input length must be divisible by four" );

  ByteArray bytes;

  for( decltype( string.size() ) i = 0; i < string.size(); i += 4 )
  {
    Byte a = index(string[i]  );
    Byte b = index(string[i+1]);
    Byte c = index(string[i+2]);
    Byte d = index(string[i+3]);

    Byte j = ( (a       ) << 2) + ( (b & 0x30) >> 4);
    Byte k = ( (b & 0x3F) << 4) + ( (c & 0x3C) >> 2);
    Byte l = ( (c & 0x03) << 6) + ( (d & 0x3F) );

    bytes.push_back(j);
    bytes.push_back(k);
    bytes.push_back(l);
  }

  return bytes;
}

// ---------------------------------------------------------------------

}
