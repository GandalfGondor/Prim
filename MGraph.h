typedef char VertexType;
typedef int EdgeType;
#define MAXVEX 100
#define INF 65535

typedef struct
{
	VertexType vexs[MAXVEX];
	EdgeType arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;