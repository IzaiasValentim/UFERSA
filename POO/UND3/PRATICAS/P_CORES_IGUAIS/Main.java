package POO.UND3.PRATICAS.P_CORES_IGUAIS;

import java.util.Arrays;
import java.util.Iterator;
import java.util.LinkedList;

public class Main {

	public static void comparaListas(LinkedList<String> l1, LinkedList<String> l2) {
		Iterator<String> iL1 = l1.iterator();

		while (iL1.hasNext()) {
			if (l2.contains(iL1.next())) {
				iL1.remove();
			}
		}
	}

	public static void main(String[] Args) {

		LinkedList<String> listaUm = new LinkedList<>(
				Arrays.asList("Azul", "Vermelho", "Ciano", "Branco", "Laranja", "Preto", "Amarelo", "Verde",
						"Amarelo"));

		LinkedList<String> listaDois = new LinkedList<>(
				Arrays.asList("Azul", "Verde", "Rosa", "Azul Marinho", "Amarelo", "Verde"));

		System.out.println("Lista 01 - Original:");
		System.out.println(listaUm + "\n");

		System.out.println("Lista 02 - Original: ");
		System.out.println(listaDois + "\n");

		comparaListas(listaUm, listaDois);

		System.out.println("Lista 01 - Filtrada: ");
		System.out.println(listaUm);

	}
}
