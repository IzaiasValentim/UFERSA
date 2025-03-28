package POO.UND3.LISTA.Q60;

import java.util.Arrays;
import java.util.LinkedList;

public class Demo2LinkedList {
	public static void main(String[] Args) {
		LinkedList<Character> listaUm = new LinkedList<>(
				Arrays.asList('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'));

		LinkedList<Character> listaDois = new LinkedList<>();
		for (int c = listaUm.size() - 1; c >= 0; c--) {
			listaDois.add(listaUm.get(c));
		}
		System.out.println("Lista original: ");
		System.out.println(listaUm);
		System.out.println("\n Lista inversa: ");
		System.out.println(listaDois);
	}
}
