import java.util.*;

public class Graph {

    class VertexCover {
        private Vertex v;
        private int row, col;

        VertexCover(Vertex v, int row, int col) {
            this.v = v;
            this.row = row;
            this.col = col;
        }

        Vertex getVertex() {
            return v;
        }

        int getRow() {
            return row;
        }

        int getColumn() {
            return col;
        }
    }
    class Vertex {
        private int weight;
        private boolean bidirectional;

        Vertex() {
            weight = 0;
            bidirectional = false;
        }

        int getWeight () {
            return weight;
        }

        boolean isBidirectional() {
            return bidirectional;
        }

        void setWeight(int weight) {
            this.weight = weight;
        }

        void setBidirectional(boolean bidirectional) {
            this.bidirectional = bidirectional;
        }
    }

    private int n;
    private Vertex[][] inputGraph;
    private  int[][] outputGraph, transposeOutputGraph;
    private boolean[] visited;
    private int[] labels;
    private boolean hasBridge;

    Graph(int n) {
        this.n = n;
        inputGraph = new Vertex[n][n];
        outputGraph = new int[n][n];
        transposeOutputGraph = new int[n][n];
        visited = new boolean[n];
        labels = new int[n];
        hasBridge = false;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++)
            {
                inputGraph[i][j] = new Vertex();
            }
            visited[i] = false;
            labels[i] = -1;
        }
    }


    public void addEdge(int x, int y) {
        if(x >= n || y >= n || x < 0 || y < 0) return;

        inputGraph[x][y].setWeight(1);
        inputGraph[y][x].setWeight(1);
    }

    public void displayInputGraph() {
        for(int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(inputGraph[i][j].getWeight() + " ");
            }
            System.out.println("");
        }

        System.out.println("");
    }

    public void displayOutputGraph() {
        for(int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(outputGraph[i][j] + " ");
            }
            System.out.println("");
        }

        System.out.println("");
    }

    public void displayTransposeOutputGraph() {
        for(int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(transposeOutputGraph[i][j] + " ");
            }
            System.out.println("");
        }

        System.out.println("");
    }

    public void transposeOutput() {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                transposeOutputGraph[i][j] = outputGraph[j][i];
    }

    private void orientUtil(int v, int count) {
        if(visited[v]) return;

        visited[v] = true;

        labels[v] = count;

//---------------------Greedy choice using priority queue------------
        PriorityQueue<VertexCover> q = new PriorityQueue<>(new Comparator<VertexCover>() {
            @Override
            public int compare(VertexCover o1, VertexCover o2) {
                return o1.getVertex().getWeight() > o2.getVertex().getWeight() ? 1 : (o1.getVertex().getWeight() == o2.getVertex().getWeight() ? 0 : -1);
            }
        });

        for(int i = 0; i < n; i++) {
            if(inputGraph[v][i].getWeight() > 0 && !visited[i]) {
                if(!visited[i] || labels[v] < labels[i]) {
                    q.add(new VertexCover(inputGraph[v][i], v, i));
                }
            }
        }

        while(!q.isEmpty()) {
            VertexCover vCover = q.poll();
            int row = vCover.getRow();
            int col = vCover.getColumn();
            outputGraph[row][col] = 1;
            if(inputGraph[row][col].isBidirectional()) // If the edge is bidirectional, mark both ways (Case 2)
                outputGraph[col][row] = 1;
            inputGraph[row][col].setWeight(0);
            inputGraph[col][row].setWeight(0);
            orientUtil(col, count+1);

        }
//-------------------------------------------------------------------

//--------------------No greedy choice, unweighted graph-------------
//        for(int i = 0; i < n; i++) {

//            if(inputGraph[v][i].getWeight() == 1 && !visited[i])
//            {
//                if(!visited[i] || labels[v] < labels[i]) {
//                    outputGraph[v][i] = 1;
//                    inputGraph[v][i].setWeight(0);
//                    inputGraph[i][v].setWeight(0);
//                    orientUtil(i, count+1);
//                }
//            }
//        }
//-------------------------------------------------------------------


        for(int i = 0; i < n; i++) {
            if(inputGraph[v][i].getWeight() == 1) {
                if(labels[v] > labels[i]) {
                    outputGraph[v][i] = 1;
                    if(inputGraph[v][i].isBidirectional()) // If the edge is bidirectional, mark both ways (Case 2)
                        outputGraph[i][v] = 1;
                }
            }
        }
    }

    public void orient(int start) {
        if(start >= n || start < 0) return;

        orientUtil(start, 1);
    }

    public boolean checkForBridges(){

        boolean visited[] = new boolean[n];
        int timer = 0;
        int []timeStampAtThatNode = new int[n];

        bridgeUtil(0, -1, timer, visited, timeStampAtThatNode);


        return hasBridge;
    }

    public void bridgeUtil(int u, int parent, int timer, boolean visited[], int timeStampAtThatNode[])
    {

        // Mark the current node as visited
        visited[u] = true;
        timeStampAtThatNode[u] = timer++;
        int currTime = timeStampAtThatNode[u];

        for(int i =0; i < n; i++){
            if(i == parent){
                continue;
            }
            if(inputGraph[u][i].getWeight() > 0){
                if(!visited[i]){
                    bridgeUtil(i, u, timer, visited, timeStampAtThatNode);
                }

                timeStampAtThatNode[u] = Math.min(timeStampAtThatNode[u], timeStampAtThatNode[i]);

                if(currTime < timeStampAtThatNode[i]){
                    hasBridge = true;
                }
            }

        }
    }

    public static void main(String[] args) {
        Graph g = new Graph(13);

        g.addEdge(0,1);
        g.addEdge(0,3);
        g.addEdge(1,2);
        g.addEdge(2,5);
        g.addEdge(3,4);
        g.addEdge(4,7);
        g.addEdge(3,6);
        g.addEdge(6,7);
        g.addEdge(7,8);
        g.addEdge(8,10);
        g.addEdge(8,5);
        g.addEdge(9,6);
        g.addEdge(9,12);
        g.addEdge(12,11);
        g.addEdge(11,7);
        g.addEdge(11,10);

        System.out.println("Input Graph: ");
        g.displayInputGraph();

        System.out.println("Graph contains bridge: "+g.checkForBridges());

        if(!g.checkForBridges()){
            g.orient(5);
        }
        else{
            System.out.println("One way orientation not possible");
        }


        System.out.println("Output Graph: ");
        g.displayOutputGraph();

        System.out.println("Transpose Graph: ");
        g.transposeOutput();
        g.displayTransposeOutputGraph();

        //test for bridge - should output true

        Graph g1 = new Graph(5);
        g1.addEdge(1, 0);
        g1.addEdge(0, 2);
        g1.addEdge(2, 1);
        g1.addEdge(0, 3);
        g1.addEdge(3, 4);

        g1.addEdge(0, 1);
        g1.addEdge(2, 0);
        g1.addEdge(1, 2);
        g1.addEdge(3, 0);
        g1.addEdge(4, 3);

        System.out.println("Graph contains bridge: (should output true)"+g.checkForBridges());
    }
}
