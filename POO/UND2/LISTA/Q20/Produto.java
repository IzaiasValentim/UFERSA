package POO.UND2.LISTA.Q20;

import java.util.ArrayList;

public class Produto {

	public static int calculaProduto(ArrayList<Integer> num) {
		int produto = num.get(0);

		for (int i = 1; i < num.size(); i++) {
			produto *= num.get(i);
		}
		return produto;
	}

	public static int calculaPorLista(int... numeros) {
		int produto = numeros[0];

		for (int i = 1; i < numeros.length; i++) {
			produto *= numeros[i];
		}
		return produto;
	}
}
