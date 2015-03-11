SET( ALGORITHMS_SRC
  xor.cc
)

ADD_LIBRARY( algorithms ${ALGORITHMS_SRC} )
TARGET_LINK_LIBRARIES( algorithms common )
