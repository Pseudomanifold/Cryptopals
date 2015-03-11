#ifndef CRYPTO_XOR_HH__
#define CRYPTO_XOR_HH__

#include <common/types.hh>

#include <string>

namespace crypto
{

/** Fixed XOR encryption for two byte arrays of equal length.  */
ByteArray fixedXOR( const ByteArray& s, const ByteArray& t );

/** Repeating-key XOR encryption for a given byte array */
ByteArray repeatingKeyXOR( const ByteArray& bytes, const ByteArray& key );
ByteArray repeatingKeyXOR( const ByteArray& bytes, const std::string& key );

}

#endif
