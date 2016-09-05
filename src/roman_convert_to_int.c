#include <string.h>
#include <stdbool.h>

#include "roman_convert_to_int.h"
#include "roman_clusters.h"

static const int ERROR = -1;

static bool starts_with(const char *str, RomanCluster cluster);

int roman_convert_to_int(const char *numeral)
{
	if (!numeral) return ERROR;

	int total = 0;
	for (const RomanCluster *cluster = roman_cluster_largest();
			cluster;
			cluster = roman_cluster_next_smaller(cluster)
	    )
	{
		while (starts_with(numeral, *cluster))
		{
			total += cluster->value;
			numeral += cluster->length;
		}
	}

	return *numeral ? ERROR : total;
}

static bool starts_with(const char *str, RomanCluster cluster)
{
	return strncmp(str, cluster.letters, cluster.length) == 0;
}
