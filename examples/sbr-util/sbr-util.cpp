#include <fstream>
#include <cstdio>

#include "SBR/SBR.h"

int main(int argc, char** argv){

	if(argc < 2){
		printf("Usage: sbr-util path/to/sbr/file\n");
		return -1;
	}

	std::ifstream sbrFile(argv[1]);
	if(sbrFile.is_open()){

		char buffer[SBR_RAW_SIZE];
		sbrFile.read(buffer, SBR_RAW_SIZE);
		SBR sbr;
		if(sbr_parse(buffer, SBR_RAW_SIZE, &sbr) == 0){

			char id[3] = {0};
			id[0] = sbr.identifier[0];
			id[1] = sbr.identifier[1];

			printf("%-10s%-25s\n", "ID", id);
			printf("%-10s%-25s%-12s%-12s%-14s%-8s%-8s\n", "VALID", "Name", "Size(B)", "Offset", "Checksum", "Type", "Flags");

			for(int i = 0; i < SBR_MAX_NUM_SECTIONS; i++){
				const char* valid = "false";
				if(sbr_section_is_valid(&sbr.sections[i])){
					valid = "true";
				}

				printf("%-10s%-25s%-12d%-12d0x%08X    %-8d%-8d\n",
					valid, sbr.sections[i].name, sbr.sections[i].size, sbr.sections[i].offset,
					sbr.sections[i].checksum, sbr.sections[i].type, sbr.sections[i].flags);
			}

		} else {
			printf("Couldn't parse SBR structure\n");
			return -1;
		}

	} else {
		printf("Couldn't open file: %s\n", argv[1]);
		return -1;
	}

	return 0;
}
