#include "break_repeating_key_xor.hh"
#include "decrypt_single_byte_xor.hh"
#include "hamming_distance.hh"

#include <iostream>

#include <algorithm>
#include <map>
#include <vector>

namespace
{

std::map<unsigned int, double> estimateKeySize( const crypto::ByteArray& bytes,
                                                unsigned int k,
                                                unsigned int K )
{
  std::map<unsigned int, double> distances;

  for( unsigned int i = k; i <= K; i++ )
  {
    crypto::ByteArray s( bytes.begin(),       bytes.begin() +   i );
    crypto::ByteArray t( bytes.begin() +   i, bytes.begin() + 2*i );
    crypto::ByteArray u( bytes.begin() + 2*i, bytes.begin() + 3*i );
    crypto::ByteArray v( bytes.begin() + 3*i, bytes.begin() + 4*i );

    auto d1 = crypto::hammingDistance(s,t);
    auto d2 = crypto::hammingDistance(t,u);
    auto d3 = crypto::hammingDistance(u,v);

    distances[i] = ((d1+d2+d3)/3.0)/(8.0*i);
  }

  return distances;
}

}

namespace crypto
{

// ---------------------------------------------------------------------

ByteArray breakRepeatingKeyXOR( const ByteArray& bytes,
                                unsigned int k,
                                unsigned int K )
{
  ByteArray result;

  auto distances = estimateKeySize( bytes, k, K );

  std::vector<unsigned int> keySizes( K-k+1 );
  std::iota( keySizes.begin(), keySizes.end(), k );

  std::sort( keySizes.begin(), keySizes.end(),
             [&] ( unsigned int k1, unsigned int k2 )
             {
               return distances.at(k1) < distances.at(k2);
             } );

  if( keySizes.size() > 4 )
    keySizes.erase( keySizes.begin() + 4, keySizes.end() );

  for( auto&& keySize : keySizes )
  {
    std::vector<ByteArray> blocks;
    blocks.reserve( bytes.size() / keySize );

    for( unsigned int i = 0; i < bytes.size() / keySize + 1; i++ )
    {
      ByteArray block;

      std::copy_n( bytes.begin() + i * keySize,
                   std::min( keySize, static_cast<unsigned int>( bytes.size() - i * keySize ) ),
                   std::back_inserter( block ) );

      blocks.push_back( block );
    }

    std::vector<ByteArray> transposedBlocks;
    transposedBlocks.reserve( keySize );

    for( unsigned int i = 0; i < keySize; i++ )
    {
      ByteArray transposedBlock;

      for( auto&& block : blocks )
        if( i < block.size() )
          transposedBlock.push_back( block.at(i) );

      transposedBlocks.push_back( transposedBlock );
    }

    ByteArray keyBytes;
    keyBytes.reserve( keySize );

    for( auto&& transposedBlock : transposedBlocks )
    {
      auto tuple = decryptSingleByteXOR( transposedBlock );
      auto byte  = std::get<0>( tuple );

      keyBytes.push_back( byte );
    }

    std::cout << "Cracked key: *";

    for( auto&& byte : keyBytes )
      std::cout << static_cast<char>( byte );

    std::cout << "\n";
  }

  return result;
}

// ---------------------------------------------------------------------

}
