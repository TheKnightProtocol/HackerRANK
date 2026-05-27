import java.io.*;
import java.util.*;

abstract class Tree {
    private int value;
    private int color;
    private int depth;
    
    public Tree(int value, int color, int depth) {
        this.value = value;
        this.color = color;
        this.depth = depth;
    }
    
    public int getValue() {
        return value;
    }
    
    public int getColor() {
        return color;
    }
    
    public int getDepth() {
        return depth;
    }
    
    public abstract void accept(TreeVis visitor);
}

class TreeNode extends Tree {
    private ArrayList<Tree> children = new ArrayList<>();
    
    public TreeNode(int value, int color, int depth) {
        super(value, color, depth);
    }
    
    public void accept(TreeVis visitor) {
        visitor.visitNode(this);
        for (Tree child : children) {
            child.accept(visitor);
        }
    }
    
    public void addChild(Tree child) {
        children.add(child);
    }
}

class TreeLeaf extends Tree {
    public TreeLeaf(int value, int color, int depth) {
        super(value, color, depth);
    }
    
    public void accept(TreeVis visitor) {
        visitor.visitLeaf(this);
    }
}

abstract class TreeVis {
    public abstract int getResult();
    public abstract void visitNode(TreeNode node);
    public abstract void visitLeaf(TreeLeaf leaf);
}

class SumInLeavesVisitor extends TreeVis {
    private int sum = 0;
    
    public int getResult() {
        return sum;
    }
    
    public void visitNode(TreeNode node) {
        // Do nothing for non-leaf nodes
    }
    
    public void visitLeaf(TreeLeaf leaf) {
        sum += leaf.getValue();
    }
}

class ProductRedNodesVisitor extends TreeVis {
    private long product = 1;
    private final int MOD = 1000000007;
    
    public int getResult() {
        return (int) product;
    }
    
    public void visitNode(TreeNode node) {
        if (node.getColor() == 0) { // Red node
            product = (product * node.getValue()) % MOD;
        }
    }
    
    public void visitLeaf(TreeLeaf leaf) {
        if (leaf.getColor() == 0) { // Red node
            product = (product * leaf.getValue()) % MOD;
        }
    }
}

class FancyVisitor extends TreeVis {
    private int sumNonLeafEvenDepth = 0;
    private int sumGreenLeaf = 0;
    
    public int getResult() {
        return Math.abs(sumNonLeafEvenDepth - sumGreenLeaf);
    }
    
    public void visitNode(TreeNode node) {
        if (node.getDepth() % 2 == 0) {
            sumNonLeafEvenDepth += node.getValue();
        }
    }
    
    public void visitLeaf(TreeLeaf leaf) {
        if (leaf.getColor() == 1) { // Green node
            sumGreenLeaf += leaf.getValue();
        }
    }
}

public class Solution {
    private static int[] values;
    private static int[] colors;
    private static List<Integer>[] graph;
    private static boolean[] visited;
    
    public static Tree solve() {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        
        values = new int[n + 1];
        colors = new int[n + 1];
        
        for (int i = 1; i <= n; i++) {
            values[i] = scanner.nextInt();
        }
        
        for (int i = 1; i <= n; i++) {
            colors[i] = scanner.nextInt();
        }
        
        graph = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++) {
            graph[i] = new ArrayList<>();
        }
        
        for (int i = 0; i < n - 1; i++) {
            int u = scanner.nextInt();
            int v = scanner.nextInt();
            graph[u].add(v);
            graph[v].add(u);
        }
        
        visited = new boolean[n + 1];
        return buildTree(1, 0);
    }
    
    private static Tree buildTree(int node, int depth) {
        visited[node] = true;
        
        // Find children (neighbors that are not parent)
        List<Integer> children = new ArrayList<>();
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                children.add(neighbor);
            }
        }
        
        // If leaf node (no children)
        if (children.isEmpty()) {
            return new TreeLeaf(values[node], colors[node], depth);
        }
        
        // Internal node
        TreeNode treeNode = new TreeNode(values[node], colors[node], depth);
        for (int child : children) {
            treeNode.addChild(buildTree(child, depth + 1));
        }
        return treeNode;
    }

    public static void main(String[] args) {
        Tree root = solve();
        
        SumInLeavesVisitor vis1 = new SumInLeavesVisitor();
        ProductRedNodesVisitor vis2 = new ProductRedNodesVisitor();
        FancyVisitor vis3 = new FancyVisitor();
        
        root.accept(vis1);
        root.accept(vis2);
        root.accept(vis3);
        
        int res1 = vis1.getResult();
        int res2 = vis2.getResult();
        int res3 = vis3.getResult();
        
        System.out.println(res1);
        System.out.println(res2);
        System.out.println(res3);
    }
}
