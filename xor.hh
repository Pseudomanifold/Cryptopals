std::string xorBuffers(const char* s, const char* t, unsigned int length)
{
  std::string result;

  for(unsigned int i = 0; i < length; i++)
    result.push_back( s[i] xor t[i] );

  return result;
}
