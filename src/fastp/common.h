#ifndef COMMON_H
#define COMMON_H

#define FASTP_VER "1.0.1"

#define _DEBUG false

#ifndef _WIN32
	typedef long int64;
	typedef unsigned long uint64;
#else
	typedef long long int64;
	typedef unsigned long long uint64;
#endif

typedef int int32;
typedef unsigned int uint32;

typedef short int16;
typedef unsigned short uint16;

typedef char int8;
typedef unsigned char uint8;

const char ATCG_BASES[] = {'A', 'T', 'C', 'G'};

#pragma pack(2) 


#pragma pack() 


// how many reads one pack has
static const int PACK_SIZE = 256;

// if one pack is produced, but not consumed, it will be kept in the memory
// this number limit the number of in memory packs
// if the number of in memory packs is full, the producer thread should sleep
static const int PACK_IN_MEM_LIMIT = 128;


// different filtering results, bigger number means worse
// if r1 and r2 are both failed, then the bigger one of the two results will be recorded
// we reserve some gaps for future types to be added
static const int PASS_FILTER = 0;
static const int FAIL_POLY_X = 4;
static const int FAIL_OVERLAP = 8;
static const int FAIL_N_BASE = 12;
static const int FAIL_LENGTH = 16;
static const int FAIL_TOO_LONG = 17;
static const int FAIL_QUALITY = 20;
static const int FAIL_COMPLEXITY = 24;

// how many types in total we support
static const int FILTER_RESULT_TYPES = 32;

const static char* FAILED_TYPES[FILTER_RESULT_TYPES] = {
	"passed", "", "", "",
	"failed_polyx_filter", "", "", "",
	"failed_bad_overlap", "", "", "",
	"failed_too_many_n_bases", "", "", "",
	"failed_too_short", "failed_too_long", "", "",
	"failed_quality_filter", "", "", "",
	"failed_low_complexity", "", "", "",
	"", "", "", ""
};

#endif /* COMMON_H */
