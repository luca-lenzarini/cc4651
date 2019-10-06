package classes.LinkedList;

import org.jetbrains.annotations.Contract;
import org.jetbrains.annotations.NotNull;

public class LinkedListNode<T extends Comparable<T>> implements Comparable<T>{
    private LinkedListNode<T> nextNode;
    private T value;

    public LinkedListNode() {
        this.nextNode = null;
        value = null;
    }

    public LinkedListNode(LinkedListNode<T> nextNode, T value){
        this.nextNode = nextNode;
        this.value = value;
    }

    LinkedListNode(T value){
        this.nextNode = null;
        this.value = value;
    }

    LinkedListNode<T> getNext(){
        return this.nextNode;
    }

    void setNext(LinkedListNode<T> nextNode){
        this.nextNode = nextNode;
    }

    T getValue(){
        return this.value;
    }

    @Override
    public int compareTo(@NotNull T objectToCompare) {
        return this.value.compareTo(objectToCompare);
    }
}
