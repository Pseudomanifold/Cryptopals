#ifndef CRYPTO_XOR_HH__
#define CRYPTO_XOR_HH__

#include <common/types.hh>

namespace crypto
{

/**
  Fixed XOR-encryption for two byte arrays of equal length.
*/

ByteArray fixedXOR( const ByteArray& s, const ByteArray& t );

}

#endif
