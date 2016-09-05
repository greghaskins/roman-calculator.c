#include "roman_clusters.h"

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

static const RomanCluster *LARGEST_CLUSTER = &ROMAN_CLUSTERS[0];
static const RomanCluster *SMALLEST_CLUSTER = &ROMAN_CLUSTERS[sizeof(ROMAN_CLUSTERS) / sizeof(RomanCluster) - 1];

const RomanCluster *roman_cluster_largest(void)
{
	return LARGEST_CLUSTER;
}

const RomanCluster *roman_cluster_next_smaller(const RomanCluster *cluster)
{
	return cluster < SMALLEST_CLUSTER ? cluster + 1 : 0;
}
