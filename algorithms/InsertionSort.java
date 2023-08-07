package algorithms;
class Node {
    int data;
    Node left, right;
 
    Node(int item)
    {
        data = item;
        left = right = null;
    }
}
 
class  BinaryTree {
    Node root;
 
    /* Compute the "maxDepth" of a tree -- the number of
       nodes along the longest path from the root node
       down to the farthest leaf node.*/
    int maxDepth(Node node)
    {
        if (node == null)
            return 0;
        else {
            /* compute the depth of each subtree */
            int lDepth = maxDepth(node.left);
            System.out.println("Left: " + lDepth);
            int rDepth = maxDepth(node.right);
            System.out.println("Rightt: " + rDepth);
 
            /* use the larger one */
            if (lDepth > rDepth)
                return (lDepth + 1);
            else
                return (rDepth + 1);
        }
    }
 
    /* Driver program to test above functions */
    public static void main(String[] args)
    {
        BinaryTree tree = new BinaryTree();
 
        tree.root = new Node(1);
        tree.root.left = new Node(2);
        tree.root.right = new Node(3);
        tree.root.left.left = new Node(4);
        tree.root.left.right = new Node(5);
 
        System.out.println("Height of tree is "
                           + tree.maxDepth(tree.root));
    }
}
 
// package algorithms;

// import java.util.Arrays;

// public class InsertionSort
// {
//     void insertionSort(int arr[])
//     {
//         int size = arr.length;

//         for(int i = 1; i < size; i++)
//         {
//             int temp = arr[i];
//             int j = i - 1;
//             while(j >= 0 && arr[j] > temp)
//             {
//                 arr[j + 1] = arr[j];
//                 j = j - 1;
//             }
//             arr[j + 1] = temp;
//         }
//     }
 

//     public static void main(String args[])
//     {
//         int arr[] = { 44, 1, 13, 9, 6 };
        
//         InsertionSort ob = new InsertionSort();
//         ob.insertionSort(arr);
        
//         System.out.println(Arrays.toString(arr));
//     }
// };