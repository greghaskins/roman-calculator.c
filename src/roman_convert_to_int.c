#include <string.h>
#include <stdbool.h>

#include "roman_convert_to_int.h"
#include "roman_clusters.c"

static const int ERROR = -1;

static bool starts_with(const char *str, RomanCluster cluster);

int roman_convert_to_int(const char *numeral)
{
	if (!numeral) return ERROR;

	int total = 0;
	for (int cluster_index = 0; cluster_index < ROMAN_CLUSTERS_LENGTH; cluster_index++)
	{
		const RomanCluster cluster = ROMAN_CLUSTERS[cluster_index];
		while (starts_with(numeral, cluster))
		{
			total += cluster.value;
			numeral += cluster.length;
		}
	}

	return *numeral ? ERROR : total;
}

static bool starts_with(const char *str, RomanCluster cluster)
{
	return strncmp(str, cluster.letters, cluster.length) == 0;
}
