#ifndef CRYPTO_BASE64_HH__
#define CRYPTO_BASE64_HH__

#include <common/types.hh>

#include <string>

namespace crypto
{

/**
  Converts a given byte array to a Base64-encoded string. The conversion will
  use a default Base64 index, consisting of A-Z, a-z, 0-9, +, and /. Surplus
  bytes will be padded with =.
*/

std::string toBase64( const ByteArray& bytes );

/** Converts a given Base64-encoded string to the corresponding byte array. */
ByteArray fromBase64( const std::string& string );

}

#endif
