package POO.UND3.PRATICAS.P_Arrays;


import java.util.ArrayList;
import java.util.Collections;


public class Main {
	public static void myFindFrist(ArrayList<String> palavras, String alvo) {

		System.out.println("Procurando por '" + alvo + "' no array: ");

		int posicao = Collections.binarySearch(palavras, alvo);

		String achado = posicao >= 0 ? String.format("Arr[%d] : %s", posicao, palavras.get(posicao))
				: "Nenhuma ocorrência";

		System.out.println(achado);
		System.out.println(achado);
	}

	public static void main(String[] Args) {

		ArrayList<String> pNaoOrder = new ArrayList<>();
		pNaoOrder.add("Branco");
		pNaoOrder.add("Marrom");
		pNaoOrder.add("Azul");
		pNaoOrder.add("Verde");
		pNaoOrder.add("Roxo");
		pNaoOrder.add("Amarelo");
		pNaoOrder.add("Marrom");

		System.out.println("Array original: ");
		System.out.println(pNaoOrder);

		System.out.println("\n Array ordenado com Collections.sort(arr): ");
		// Ordenação asc por meio de Collections.sort(arr);
		Collections.sort(pNaoOrder);
		System.out.println(pNaoOrder+"\n");

		String procurar = "Branco";
		myFindFrist(pNaoOrder, procurar);
		procurar = "Rosa";
		myFindFrist(pNaoOrder, procurar);
		procurar = "Roxo";
		myFindFrist(pNaoOrder, procurar);
	}
}
