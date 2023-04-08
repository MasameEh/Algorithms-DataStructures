package datastructures;
import java.io.*;

//Java program to implement a Singly Linked List
public class LinkedList
{
    LinkedListNode head;
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

    public static LinkedList insertNode(LinkedList list, int data)
    {
        LinkedListNode newNode = new LinkedListNode(data);
        newNode.next = null;
        LinkedListNode lastNode = list.head;

        if(list.head == null)
        {
            list.head = newNode;
        } 
        else 
        {
            
            while(lastNode.next != null)
            {
                lastNode = lastNode.next;
            }
            lastNode.next = newNode;
        }
        return list;
    }

    public static LinkedList deleteNode(LinkedList list, int pos)
    {
        LinkedListNode currNode = list.head;
        LinkedListNode prev = null;

        if(pos == 0 && currNode != null)
        {
            list.head = currNode.next;
            System.out.println( pos + "  position element deleted");
            return list;
        }

        for(int i = 0; i < pos; i++)
        {
            prev = currNode;
            currNode = currNode.next;
            if(currNode == null)
            {
                System.out.println(pos + " position element not found");
            }
            
        }

        prev.next = currNode.next;
        System.out.println(pos + " position element deleted");
        
        return list;
    }

    //to print the LinkedList.
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

        insertNode(list, 0);
        insertNode(list, 2);
        insertNode(list, 3);
        insertNode(list, 5);
        
        
        printList(list);
    }
}

