SET( CONVERSIONS_SRC
  base64.cc
  bytes.cc
  hex.cc
)

ADD_LIBRARY( conversions ${CONVERSIONS_SRC} )
