#ifndef ROMAN_CLUSTERS_H
#define ROMAN_CLUSTERS_H

typedef struct RomanCluster {
	int value;
	char letters[3];
	int length;
} RomanCluster;

static const RomanCluster ROMAN_CLUSTERS[] = {
	{ 1000, "M", 1 },
	{ 900, "CM", 2 },
	{ 500, "D", 1 },
	{ 400, "CD", 2 },
	{ 100, "C", 1 },
	{ 90, "XC", 2 },
	{ 50, "L", 1 },
	{ 40, "XL", 2 },
	{ 10, "X", 1 },
	{ 9, "IX", 2},
	{ 5, "V", 1 },
	{ 4, "IV", 2 },
	{ 1, "I", 1 }
};
static const int ROMAN_CLUSTERS_LENGTH = sizeof(ROMAN_CLUSTERS) / sizeof(RomanCluster);

#endif
