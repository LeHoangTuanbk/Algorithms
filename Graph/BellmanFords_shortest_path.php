<?php
    /**
     * @Desciption: Bellman ford algorithms with adjacency edges list representation
     */

    $INT_MAX = 0x7FFFFFFF;

    class Edge
    {
        public $source;
        public $destination;
        public $weight;
    }

    class Graph
    {
        public $vertices_number;
        public $edges_number;
        public $edge;
        public function Print_adjacency_list_representation()
        {
            echo "The adjacency edges list: <br>";
            foreach($this->edge as $e)
            {
                echo "($e->source , $e->destination) "," == " ," $e->weight ";
                echo "<br>";
            }
            echo "<br>";
        }
    }

    function Create_graph($vertices_number, $edges_number)
    {
        $graph = new Graph();
        $graph->vertices_number = $vertices_number;
        $graph->edges_number = $edges_number;
        $graph->edge = array();
        
        for ($i = 0; $i < $graph->edges_number; ++$i)
            $graph->edge[$i] = new Edge();

        return $graph;
    }

    function Print_result($distance, $count, $source, $pre)
    {
        echo "<br>";
        echo "Min distance from vertex :$source";

        for ($i = 0; $i < $count; ++$i)
        {
            echo "<br>Vertex " . $i . "\t :  " . $distance[$i];
            $temp = $i;
            echo "\t, Path:";
            while( $temp != $source)
            {
                echo "$temp <--";
                $temp = $pre[$temp];
            }
            echo " $source";
        }
    }

    function Print_pre_vertice($pre)
    {
        echo "The pre_vertice of each vertice:<br>";
        foreach($pre as $key=>$item)
        {
            echo $key,"-->",$item,"<br>";
        }
    }

    function BellmanFord($graph, $source)
    {
        global $INT_MAX;
        $vertices_number = $graph->vertices_number;
        $edges_number = $graph->edges_number;
        $distance = array();
        $pre = array();
        $pre[$source] = $source;

        for ($i = 0; $i < $vertices_number; ++$i)
            $distance[$i] = $INT_MAX;

        $distance[$source] = 0;

        for ($i = 1; $i <= $vertices_number - 1; ++$i)
        {
            for ($j = 0; $j < $edges_number; ++$j)
            {
                $u = $graph->edge[$j]->source;
                $v = $graph->edge[$j]->destination;
                $weight = $graph->edge[$j]->weight;

                if ($distance[$u] != $INT_MAX && $distance[$u] + $weight < $distance[$v])
                {
                    $distance[$v] = $distance[$u] + $weight;
                    $pre[$v] = $u;
                }
            }
        }

        for ($i = 0; $i < $edges_number; ++$i)
        {
            $u = $graph->edge[$i]->source;
            $v = $graph->edge[$i]->destination;
            $weight = $graph->edge[$i]->weight;

            if ($distance[$u] != $INT_MAX && $distance[$u] + $weight < $distance[$v])
                echo "Graph contains negative weight cycle.";
        }

        Print_pre_vertice($pre);

        Print_result($distance, $vertices_number,$source,$pre);
    }

    $vertices_number = 5;
    $edges_number = 8;
    $graph = Create_graph($vertices_number, $edges_number);

    // Edge 0-1
    $graph->edge[0]->source = 0;
    $graph->edge[0]->destination = 1;
    $graph->edge[0]->weight = -1;

    // Edge 0-2
    $graph->edge[1]->source = 0;
    $graph->edge[1]->destination = 2;
    $graph->edge[1]->weight = 4;

    // Edge 1-2
    $graph->edge[2]->source = 1;
    $graph->edge[2]->destination = 2;
    $graph->edge[2]->weight = 3;

    // Edge 1-3
    $graph->edge[3]->source = 1;
    $graph->edge[3]->destination = 3;
    $graph->edge[3]->weight = 2;

    // Edge 1-4
    $graph->edge[4]->source = 1;
    $graph->edge[4]->destination = 4;
    $graph->edge[4]->weight = 2;

    // Edge 3-2
    $graph->edge[5]->source = 3;
    $graph->edge[5]->destination = 2;
    $graph->edge[5]->weight = 5;

    // Edge 3-1
    $graph->edge[6]->source = 3;
    $graph->edge[6]->destination = 1;
    $graph->edge[6]->weight = 1;

    // Edge 4-3
    $graph->edge[7]->source = 4;
    $graph->edge[7]->destination = 3;
    $graph->edge[7]->weight = -3;

    $graph->Print_adjacency_list_representation();

    //Find all the min path from vertex 0.
    BellmanFord($graph, 0);

?>