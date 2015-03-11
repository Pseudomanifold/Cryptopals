#ifndef CRYPTO_HEX_HH__
#define CRYPTO_HEX_HH__

#include <common/types.hh>

#include <string>

namespace crypto
{

/**
  Converts a single hexadecimal character to its corresponding byte. Throws an
  exception if the character is not a valid hex character.
*/

Byte toByte( char c );

/**
  Converts two hexadecimal characters to their corresponding bytes.  This is
  useful for converting a string that represents a hexadecimal number, for
  example.
*/

Byte toByte( char high, char low );

/**
  Converts a string consisting of hexadecimal characters to an array of bytes.
  If the string does not contain valid hexadecimal characters, an exception
  will be thrown.
*/

ByteArray hexToBytes( const std::string& s );

}

#endif
