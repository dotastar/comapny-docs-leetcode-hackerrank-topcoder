Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.


OJ's undirected graph serialization:
Nodes are labeled uniquely.

We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
Second node is labeled as 1. Connect node 1 to node 2.
Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/
         
         
         
         

这题和链表拷贝类似：http://fisherlei.blogspot.com/2013/11/leetcode-copy-list-with-random-pointer.html


所不同的是，在链表拷贝中，没有借助额外空间，通过多次链表遍历来拷贝、链接及拆分。


而这里图的拷贝，也可以通过多次遍历来插入拷贝节点，链接拷贝节点以及将拷贝节点拆分出来。但是同样的问题是，需要对图进行多次遍历。如果想在一次遍历中，完成拷贝的话，那就需要使用额外的内存来使用map存储源节点和拷贝节点之间的对应关系。有了这个关系之后，在遍历图的过程中，就可以同时处理访问节点及访问节点的拷贝节点，一次完成。详细看下面代码。


 


[Code]


 1 /**
 2  * Definition for undirected graph.
 3  * struct UndirectedGraphNode {
 4  *     int label;
 5  *     vector<UndirectedGraphNode *> neighbors;
 6  *     UndirectedGraphNode(int x) : label(x) {};
 7  * };
 8  */
 9 class Solution {
10 public:
11     UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {	O(N*N*logN)
12         if(node == NULL) return NULL;
13         unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> nodeMap;
14         queue<UndirectedGraphNode *> visit;
15         visit.push(node);
16         UndirectedGraphNode * nodeCopy = new UndirectedGraphNode(node->label);
17         nodeMap[node] = nodeCopy;
18         while (visit.size()>0)	//O(N)
19         {
20             UndirectedGraphNode * cur = visit.front();
21             visit.pop();
22             for (int i = 0; i< cur->neighbors.size(); ++i)	//O(N)
23             {
24                 UndirectedGraphNode * neighb = cur->neighbors[i];
25                 if (nodeMap.find(neighb) == nodeMap.end())	//O(N)
26                 {
27                     // no copy of neighbor node yet. create one and associate with the copy of cur
28                     UndirectedGraphNode* neighbCopy = new UndirectedGraphNode(neighb->label);
29                     nodeMap[cur]->neighbors.push_back(neighbCopy);
30                     nodeMap[neighb] = neighbCopy;
31                     visit.push(neighb);
32                 }
33                 else
34                 {
35                     // already a copy there. Associate it with the copy of cur
36                     nodeMap[cur]->neighbors.push_back(nodeMap[neighb]);
37                 }
38             }
39         }
40     
41         return nodeCopy;
42     }
43 };