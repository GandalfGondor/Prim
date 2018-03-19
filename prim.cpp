#include<iostream>
#include"MGraph.h"

using namespace std;

void MiniSpanTree_Prim(MGraph G)
{
	int min, i, j, k;
	int adjvex[MAXVEX];
	int lowcost[MAXVEX];
	lowcost[0] = 0;
	adjvex[0] = 0;
	for (i = 1; i < G.numVertexes; i++)
	{
		lowcost[i] = G.arc[0][i];
		adjvex[i] = 0;
	}
	for (i = 1; i < G.numVertexes; i++)
	{
		min = INF;
		j = 1;
		k = 0;
		while (j < G.numVertexes)
		{
			if (lowcost[j] != 0 && lowcost[j] < min)
			{
				min = lowcost[j];
				k = j;
			}
			j++;
		}
		cout << adjvex[k] << "-" << k << ", " << endl;
		lowcost[k] = 0;
		for (j = 1; j < G.numVertexes; j++)
		{
			if (lowcost[j] != 0 && G.arc[i][j] < lowcost[j])
			{
				lowcost[j] = G.arc[i][j];
				adjvex[j] = k;
			}
		}

	}
}

int main()
{
	MGraph *G = new MGraph;;
	int i, j, k, w;
	cout << "please input vertex and edge : " << endl;
	cin>>G->numVertexes >> G->numEdges ;
	for (i = 0; i < G->numVertexes; i++)
		cin >> G->vexs[i];
	for(i=0;i<G->numVertexes;i++)
		for (j = 0; j < G->numVertexes; j++)
		{
			G->arc[i][j] = INF;
		}

	for (k = 0; k < G->numEdges; k++)
	{
		cout << "please input i ,j and w" << endl;
		cin >> i >> j;
		i = i - 1; j = j - 1;
		cin >> G->arc[i][j];
		G->arc[j][i] = G->arc[i][j];
	}
	MiniSpanTree_Prim(*G);
	system("pause");
	return 0;
}