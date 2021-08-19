#include "SBR/SBR.h"

#include <array>

int main() {

    SBR_SECTION section;

    std::array<SBR_COMPRESSION, 4> compressions = {SBR_NO_COMPRESSION, SBR_COMPRESSION_ZLIB, SBR_COMPRESSION_GZ, SBR_COMPRESSION_XZ};
    for(int i = 0; i < compressions.size(); i++){
        sbr_section_set_compression(&section, compressions[i]);
        if(compressions[i] != sbr_section_get_compression(&section)){
            return -1;
        }
    }

    for(int i = compressions.size() - 1; i >= 0; i--){
        sbr_section_set_compression(&section, compressions[i]);
        if(compressions[i] != sbr_section_get_compression(&section)){
            return -1;
        }
    }

    return 0;

}