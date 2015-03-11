#ifndef CRYPTO_DECRYPT_SINGLE_BYTE_XOR_HH__
#define CRYPTO_DECRYPT_SINGLE_BYTE_XOR_HH__

#include <string>

namespace crypto
{

/**
  Given a hex-encoded string that is supposed to be XOR'd against a single
  character, finds the key and decrypts the message.
*/

std::string decryptSingleByteXOR( const std::string& s );

}

#endif
