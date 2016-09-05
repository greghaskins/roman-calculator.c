#include "roman_clusters.h"

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
