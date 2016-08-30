#include <string.h>

#include "roman_convert_to_int.h"
#include "roman_clusters.c"

static const int ERROR = -1;


int roman_convert_to_int(const char *numeral)
{
	if (!numeral) return ERROR;

	int total = 0;
	for (int cluster_index = 0; cluster_index < ROMAN_CLUSTERS_LENGTH; cluster_index++)
	{
		const RomanCluster cluster = ROMAN_CLUSTERS[cluster_index];
		const int cluster_length = strlen(cluster.letters);
		while (strncmp(numeral, cluster.letters, cluster_length) == 0)
		{
			total += cluster.value;
			numeral += cluster_length;
		}
	}

	return *numeral ? ERROR : total;
}

