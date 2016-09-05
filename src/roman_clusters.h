#ifndef ROMAN_CLUSTERS_H
#define ROMAN_CLUSTERS_H

typedef struct RomanCluster {
	int value;
	char letters[3];
	int length;
} RomanCluster;

extern const RomanCluster *roman_cluster_largest(void);
extern const RomanCluster *roman_cluster_next_smaller(const RomanCluster *cluster);

#endif
