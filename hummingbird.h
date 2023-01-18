#include "quantum.h"

// readability
#define ___ KC_NO

#define LAYOUT_hummingbird( \
         K00, K01, K02, K03, K04,    K05, K06, K07, K08, K09, \
         K10, K11, K12, K13, K14,    K15, K16, K17, K18, K19, \
              K20, K21, K22,              K27, K28, K29,      \
                        K23, K24,    K25, K26                 \
    )                                        \
    {                                        \
        { K00,   K02,   K04,   K06,   K08 }, \
        { K01,   K03,   K05,   K07,   K09 }, \
        { K10,   K12,   K14,   K16,   K18 }, \
        { K11,   K13,   K15,   K17,   K19 }, \
        { K20,   K22,   K24,   K28,   K26 }, \
        { K21,   K23,   K27,   K29,   K25 } \
    }
