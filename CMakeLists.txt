CMAKE_MINIMUM_REQUIRED( VERSION 2.8.11 )
PROJECT( CryptoPals )

SET( CMAKE_CXX_FLAGS "-std=c++11" )

ADD_EXECUTABLE( test_conversions test_conversions.cc )
