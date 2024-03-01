
/** Pseudocode:

    for loop going throug all nodes
      set all distances to infinity
      set all parents to null

    set source distance to 0

    create bool updated

    do while updated is true

      set updated to false

      for loop of v to all nodes
        const int dv = dist[v]
        for loop of j for v + 1
          set const n to nlist v
          set const d to dv + node i's weight

          if d is less than the distance of n
            dist of n is equal to d
            parent of n equals v
            updated = true

**/

static void BellmanFord(const int src, const ECLgraph& g, int* const dist,int* const parent)
{
  for (int i = 0; i < g.nodes; i++) {
    dist[i] = INT_MAX;
    parent[i] = 0;
  }
  dist[src] = 0;

  bool updated;
  do {
    updated = false;

    for {int v = 0; v < g.nodes; v++} {
      const int dv = dist[v];
      for (int j = g.nindex[v]; j < g.nindex[v + 1]; j++) {
        const int n = g.nlist[j];
        const int d = dv + g.eweight[i];

        if (d < dist[n]) {
          dist[n] = d;
          parent[n] = v;
          updated = true;
        }
      }
    }
  } while (updated);
}

/** Pseudocode:

  for loop going throug all nodes
     set all distances to infinity
     set all color to 0
     set prev to 0

  set source distance to 0

  make a priority queue of pairs of ints
  push 0 and src to pq

  while loop that goes through all of queue
    const int v = top of second pair of queue
    pop
    set color of v to 1

    for loop of i = nindex v to nindex v + 1
      const int n = nlist of i
      const int w = weight of n

      if color is 1 and distance of n is larger than w
        dist of n = w
        prev of n is v
        push distance of n and n as a pair

**/

static void MST_prim(const int src, const ECLgraph& g, int* const dist, int* const prev, int* const color)
{
  for (int i = 0; i < g.nodes; i++) {
    dist[i] = INT_MAX;
    color[i] = 0;
    prev[i] = 0;
  }
  dist[src] = 0;

  std::priority_queue< std::pair<int, int> >pq;
  pq.push(std::make_pair(0, src));

  while(pq.size() > 0){
    const int v = pq.top().second;
    pq.pop();
    color[v] = 1;
    for (int i=g.nindex[v];i<g.nindex[v+1];i++){
      const int n = g.nlist[i];
      const int  w = g.eweight[n];
    
      if(color[n] == 1 && dist[n] > w){
        dist[n] = w;
        prev[n] = v;
        pq.push(std::make_pair(dist[n],n));
      }
    }
  }
}