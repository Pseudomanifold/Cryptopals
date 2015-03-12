#ifndef CRYPTO_DECRYPT_SINGLE_BYTE_XOR_HH__
#define CRYPTO_DECRYPT_SINGLE_BYTE_XOR_HH__

#include <common/types.hh>

#include <string>
#include <tuple>

namespace crypto
{

/**
  Given a hex-encoded string that is supposed to be XOR'd against a single
  character, finds the key and decrypts the message.
*/

std::tuple<Byte, unsigned int, std::string> decryptSingleByteXOR( const std::string& s );

/**
  Given a byte array that is supposed to be XOR'd against a single byte, finds
  the key and decrypts the message.
*/

std::tuple<Byte, unsigned int, std::string> decryptSingleByteXOR( const ByteArray& bytes );

}

#endif
