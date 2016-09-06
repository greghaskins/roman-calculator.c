#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#include "roman_convert_to_int.h"
#include "roman_convert_from_int.h"
#include "roman_clusters.h"

static const int ERROR = -1;

static bool starts_with(const char *str, RomanCluster cluster);
static bool converts_back_to_same_numeral(int value, const char *expected_numeral);

int roman_convert_to_int(const char *numeral)
{
	if (!numeral) return ERROR;

	const char *original_numeral = numeral;
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

	if (converts_back_to_same_numeral(total, original_numeral))
	{
		return total;
	}
	return ERROR;
}

static bool starts_with(const char *str, RomanCluster cluster)
{
	return strncmp(str, cluster.letters, cluster.length) == 0;
}

static bool converts_back_to_same_numeral(int value, const char *expected_numeral)
{
	char *numeral = roman_convert_from_int(value);
	bool equal = strcmp(numeral, expected_numeral) == 0;
	free(numeral);
	return equal;
}
