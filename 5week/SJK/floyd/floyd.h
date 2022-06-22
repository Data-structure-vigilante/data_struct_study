#ifndef FLOYD_H
# include "../arrayGraph/arraygraph.h"

# define INF 100000

int		**getShortestPath(ArrayGraph *graph);

void	switchZeroToInf(ArrayGraph *graph);

int		**floyd(ArrayGraph graph);


#endif