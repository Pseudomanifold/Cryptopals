#ifndef CRYPTO_DETECT_SINGLE_BYTE_XOR_HH__
#define CRYPTO_DETECT_SINGLE_BYTE_XOR_HH__

#include <string>
#include <utility>
#include <vector>

namespace crypto
{

/**
  Given a list of hexadecimal strings, detects the one that has been encrypted
  with a single-byte XOR cipher.
*/

std::pair<std::string, std::string> detectSingleByteXOR( const std::vector<std::string>& strings );

}

#endif
