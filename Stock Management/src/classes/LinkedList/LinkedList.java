package classes.LinkedList;

import org.jetbrains.annotations.NotNull;

public class LinkedList<T extends Comparable<T>> implements Comparable<T>{

    private LinkedListNode<T> firstNode;
    private Integer listSize;

    public LinkedList(){
        this.firstNode = null;
        listSize = 0;
    }

    public LinkedList(LinkedListNode<T> node){
        this.firstNode = node;
        this.listSize = 1;
    }

    public Boolean add(T value){
        LinkedListNode<T> newNode = new LinkedListNode<T>(value);

        LinkedListNode<T> lastNode = this.firstNode;

        if(lastNode == null){
            this.firstNode = newNode;
            listSize++;
            return true;
        }

        LinkedListNode<T> lastNodeTemp = null;
        while(lastNode != null){
            lastNodeTemp = lastNode;
            lastNode = lastNode.getNext();
        }
        listSize++;
        lastNodeTemp.setNext(newNode);
        return true;
    }

    public void printList(){
        LinkedListNode<T> lastNode = this.firstNode;

        while(lastNode != null){
            System.out.println(lastNode.getValue());
            lastNode = lastNode.getNext();
        }
    }

    public T remove(Integer index){
        LinkedListNode<T> lastNode = this.firstNode;
        LinkedListNode<T> lastNodeTemp = null;
        Integer loops = 0;

        if(loops > this.listSize){
            return null;
        }

        while(lastNode != null && !index.equals(loops)){
            lastNodeTemp = lastNode;
            lastNode = lastNode.getNext();
            loops++;
        }

        if(lastNode == null){
            return null;
        }

        if(lastNodeTemp == null){
            this.firstNode = lastNode.getNext();
        }else {
            lastNodeTemp.setNext(lastNode.getNext());
        }

        this.listSize--;
        return lastNode.getValue();
    }

    public T get(Integer index){
        LinkedListNode<T> lastNode = this.firstNode;
        Integer loops = 0;

        while(lastNode != null && !index.equals(loops)){
            lastNode = lastNode.getNext();
            loops++;
        }

        if(lastNode == null){
            return null;
        }

        return lastNode.getValue();
    }

    public void sort(){
        LinkedListNode<T> lastNode = this.firstNode;
        LinkedListNode<T> lastNodeTemp = null;

        while(lastNode != null){
            lastNodeTemp = lastNode;
            lastNode = lastNode.getNext();
        }
    }

    public Integer size(){
        return this.listSize;
    }

    @Override
    public int compareTo(@NotNull T o) {
        return 0;
    }
}
