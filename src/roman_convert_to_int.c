#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#include "roman_convert_to_int.h"
#include "roman_convert_from_int.h"
#include "roman_clusters.h"

static const int ERROR = -1;

static int sum_of_cluster_values(const char *numeral);
static bool starts_with(const char *str, RomanCluster cluster);
static bool converts_back_to_same_numeral(int value, const char *expected_numeral);

int roman_convert_to_int(const char *numeral)
{
	if (!numeral) return ERROR;

	const int value = sum_of_cluster_values(numeral);
	const bool valid_input = converts_back_to_same_numeral(value, numeral);

	return valid_input ? value : ERROR;
}

static int sum_of_cluster_values(const char *numeral)
{
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
	return total;
}

static bool starts_with(const char *str, RomanCluster cluster)
{
	return strncmp(str, cluster.letters, cluster.length) == 0;
}

static bool converts_back_to_same_numeral(int value, const char *expected_numeral)
{
	char *converted_numeral = roman_convert_from_int(value);
	bool result = strcmp(converted_numeral, expected_numeral) == 0;
	free(converted_numeral);
	return result;
}
