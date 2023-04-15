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
    //Method to insert an element at last of the LinkedList 
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

    //Method to insert an element at first the LinkedList
    public static LinkedList insertNodeAtFirst(LinkedList list, int data)
    {
        LinkedListNode newNode = new LinkedListNode(data);
        if(list.head == null)
        {
            list.head = newNode;
        } 
        else
        {
             newNode.next = list.head;
             list.head = newNode;
        }
        return list;
    }

    //Method to delete element at specific position
    public static LinkedList deleteNode(LinkedList list, int pos)
    {
        LinkedListNode currNode = list.head;
        LinkedListNode prev = null;

        if(pos == 0 && currNode != null)
        {
            list.head = currNode.next;
            System.out.println("element at postion " + pos + " deleted");
            return list;
        }
        
        int counter = 0;
        
        while(currNode != null)
        {
            if(counter == pos)
            {
                prev.next = currNode.next;
                System.out.println("element at postion " + pos + " deleted");
                break;
            }
            else
            {
                counter++;
                prev = currNode;
                currNode = currNode.next;
            }
        }
        if(currNode == null)
        {
            System.out.println("element at postion " + pos + " not found");
        }
        return list;
    }

    //Method to print the LinkedList.
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
        insertNodeAtFirst(list, 4);
        insertNode(list, 5);
        insertNodeAtFirst(list, 8);
        
        
        printList(list);
    }
};

