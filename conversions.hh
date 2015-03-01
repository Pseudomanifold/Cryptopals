#ifndef CONVERSIONS_HH__
#define CONVERSIONS_HH__

#include <string>

unsigned int hexToDec( char c )
{
  if( '0' <= c && c <= '9' )
    return c - '0';
  else if( 'A' <= c && c <= 'F' )
    return c - 'A' + 10;
  else
    return c - 'a' + 10;
}

const char* base64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                     "abcdefghijklmnopqrstuvwxyz"
                     "0123456789"
                     "+/";

std::string toBase64( const char* bytes, unsigned int numBytes )
{
  std::string result;

  for( unsigned int i = 0; i < numBytes; i += 3 )
  {
    char a = bytes[i];
    char b = i+1 < numBytes ? bytes[i+1] : '\0';
    char c = i+2 < numBytes ? bytes[i+2] : '\0';

    unsigned int j = ((a & 0xFC) >> 2);
    unsigned int k = ((a & 0x03) << 4) + ((b & 0xF0) >> 4);
    unsigned int l = ((b & 0x0F) << 2) + ((c & 0xC0) >> 6);
    unsigned int m = (c & 0x3F);

    result.push_back(base64[j]);
    result.push_back(base64[k]);

    if( i+1 < numBytes )
      result.push_back(base64[l]);
    else
      result.push_back('=');

    if( i+2 < numBytes )
      result.push_back(base64[m]);
    else
      result.push_back('=');
  }

  return result;
}

#endif
