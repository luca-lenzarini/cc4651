package com.united;

import classes.LinkedList.LinkedListNode;
import classes.LinkedList.LinkedList;

public class Main {

    public static void main(String[] args) {
        LinkedList<Integer> lista = new LinkedList<Integer>();

        lista.add(1);
        lista.add(2);
        lista.add(3);
        lista.add(4);
        lista.remove(0);
        lista.add(8);
        lista.remove(3);

        lista.printList();

        System.out.println(lista.size());
    }
}
