#include <assert.h>
#include <stdlib.h>
#include <math.h>

#include "cost.h"
#include "graph.h"
#include "set.h"

static type_elem min_item(set s, cost_t *array_cost) {
	cost_t min_cost = cost_inf();
	type_elem d;
	type_elem result = 0;
	set saux = set_copy(s);
	
	while(!set_is_empty(saux)){
		d = set_get(saux);
		if(cost_le(array_cost[d], min_cost)){
			min_cost = array_cost[d];
			result = d;
		}
		saux = set_elim(saux, d);
	}
	saux = set_destroy(saux);
	return result;
}

cost_t *dijkstra(graph_t graph, vertex_t init) {
	assert(graph_max_size(graph) > 0);
	unsigned int size = graph_max_size(graph);
	cost_t *array_cost = (cost_t*) calloc(size, sizeof(cost_t));
	if(!array_cost) return NULL;
	type_elem c = 0;
	set s = set_empty();

	for(vertex_t i = 0; i < size; i++){
		s = set_add(s, i);
	}

	s = set_elim(s, init);

	for(vertex_t j = 0; j < size; j++){
		array_cost[j] = graph_get_cost(graph, init, j);
	}

	while(!set_is_empty(s)){
		c = min_item(s, array_cost);
		s = set_elim(s, c);
		for(vertex_t j = 0; j < size; j++){
			array_cost[j] = fmin(array_cost[j], cost_sum(array_cost[c], graph_get_cost(graph, c, j)));
		}
	}
	s = set_destroy(s);
	return array_cost;
}
