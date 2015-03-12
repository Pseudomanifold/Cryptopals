#ifndef CRYPTO_BREAK_REPEATING_KEY_XOR_HH__
#define CRYPTO_BREAK_REPEATING_KEY_XOR_HH__

#include <common/types.hh>

namespace crypto
{

/**
  Given an encrypted array of bytes, breaks a repeating-key XOR cipher. This
  only requires hazy knowledge about the minimum and maximum key length.
*/

ByteArray breakRepeatingKeyXOR( const ByteArray& bytes,
                                unsigned int k,
                                unsigned int K );

}

#endif
