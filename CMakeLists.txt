CMAKE_MINIMUM_REQUIRED( VERSION 2.8.11 )
PROJECT( CryptoPals )

SET( CMAKE_CXX_FLAGS "-Wall -Wextra -std=c++11" )

ADD_EXECUTABLE( test_conversions test_conversions.cc )
ADD_EXECUTABLE( test_xor         test_xor.cc )

ADD_EXECUTABLE( decrypt decrypt.cc )
