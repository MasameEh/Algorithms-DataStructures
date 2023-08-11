package datastructures.LinkedList;
import java.io.*;

// Java program to implement a Singly Linked List
public class LinkedList
{
    LinkedListNode head;

    // Node structure for LinkedList
    static class LinkedListNode
    {
        int data;
        LinkedListNode next;

        public LinkedListNode(int nodeData)
        {
            this.data = nodeData;
            this.next = null;
        }
    }

    // Method to insert an element at the end of the LinkedList
    public static LinkedList insertNode(LinkedList list, int data)
    {
        LinkedListNode newNode = new LinkedListNode(data);
        newNode.next = null;
        LinkedListNode lastNode = list.head;

        // If the list is empty, set the new node as the head
        if(list.head == null)
        {
            list.head = newNode;
        } 
        else 
        {
            // Traverse to the last node and append the new node
            while(lastNode.next != null)
            {
                lastNode = lastNode.next;
            }
            lastNode.next = newNode;
        }
        return list;
    }

    // Method to insert an element at the beginning of the LinkedList
    public static LinkedList insertNodeAtFirst(LinkedList list, int data)
    {
        LinkedListNode newNode = new LinkedListNode(data);
        
        // If the list is empty, set the new node as the head
        if(list.head == null)
        {
            list.head = newNode;
        } 
        else
        {
            // Set the new node's next to the current head and update the head
            newNode.next = list.head;
            list.head = newNode;
        }
        return list;
    }

    // Method to delete an element at a specific position
    public static LinkedList deleteNode(LinkedList list, int pos)
    {
        LinkedListNode currNode = list.head;
        LinkedListNode prev = null;

        // If the position is 0 and the list is not empty, delete the head node
        if(pos == 0 && currNode != null)
        {
            list.head = currNode.next;
            System.out.println("Element at position " + pos + " deleted");
            return list;
        }
        
        int counter = 0;
        
        // Traverse to the specified position
        while(currNode != null)
        {
            if(counter == pos)
            {
                // Delete the node at the specified position by updating the previous node's next
                prev.next = currNode.next;
                System.out.println("Element at position " + pos + " deleted");
                break;
            }
            else
            {
                counter++;
                prev = currNode;
                currNode = currNode.next;
            }
        }
        
        // If the specified position is not found
        if(currNode == null)
        {
            System.out.println("Element at position " + pos + " not found");
        }
        return list;
    }

    // Method to print the LinkedList
    public static void printList(LinkedList list)
    {
        LinkedListNode currNode = list.head;

        while(currNode != null)
        {
            System.out.print(currNode.data + " ");
            currNode = currNode.next;
        }
    }

    public static void main(String[] args) 
    {
        LinkedList list = new LinkedList();

        // Insert nodes into the LinkedList
        insertNode(list, 0);
        insertNode(list, 2);
        insertNodeAtFirst(list, 4);
        insertNode(list, 5);
        insertNodeAtFirst(list, 8);

        // Print the LinkedList
        printList(list);
    }
}
