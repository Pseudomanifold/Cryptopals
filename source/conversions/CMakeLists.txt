SET( CONVERSIONS_SRC
  base64.cc
  hex.cc
)

ADD_LIBRARY( conversions ${CONVERSIONS_SRC} )
