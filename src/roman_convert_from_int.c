#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "roman_convert_from_int.h"
#include "roman_clusters.c"

static const int MAX_POSSIBLE_LENGTH_OF_NUMERAL = 16;

static void build_result_from_component_clusters(const int number, char *result);

static int append_cluster_to_reduce_remainder(RomanCluster cluster, int remainder, char *result);

char *roman_convert_from_int(const int number)
{
	char *result = calloc(MAX_POSSIBLE_LENGTH_OF_NUMERAL, sizeof(char));
	if (number < 1) return strcat(result, "underflow error");
	if (3999 < number) return strcat(result, "overflow error");

	build_result_from_component_clusters(number, result);
	return result;
}

static void build_result_from_component_clusters(const int number, char *result)
{
	int remainder = number;
	for (int i = 0; i < ROMAN_CLUSTERS_LENGTH; i++)
	{
		const RomanCluster cluster = ROMAN_CLUSTERS[i];
		remainder = append_cluster_to_reduce_remainder(cluster, remainder, result);
	}
}

static int append_cluster_to_reduce_remainder(RomanCluster entry, int remainder, char *result)
{
	while (remainder >= entry.value)
	{
		strcat(result, entry.letters);
		remainder -= entry.value;
	}
	return remainder;
}
