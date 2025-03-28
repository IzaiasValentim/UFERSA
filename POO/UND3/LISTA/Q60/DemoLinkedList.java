package POO.UND3.LISTA.Q60;

import java.util.Arrays;
import java.util.LinkedList;

public class DemoLinkedList {
	public static void main(String[] args) {
		LinkedList<Character> listaUm = new LinkedList<>(
				Arrays.asList('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'));
		LinkedList<Character> listaUmInversa = new LinkedList<>();

		for (int c = listaUm.size() - 1; c >= 0; c--) {
			listaUmInversa.add(listaUm.get(c));
		}

		System.out.println("Lista original: ");
		System.out.println(listaUm + "\n");
		System.out.println("Lista inversa: ");
		System.out.println(listaUmInversa);
	}
}
