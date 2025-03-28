package POO.UND3.LISTA.Q61;

import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;

public class DemoMapa2 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Informa a frase: ");
		String frase = sc.nextLine();

		// É instânciado um TreeMap pois essa estrutura mantem a ordenação pelas chaves.
		Map<Character, Integer> ocorrencias = new TreeMap<>();

		for (Character c : frase.toCharArray()) {
			// Desconsiderando os espaços.
			if (c != ' ') {
				ocorrencias.put(c, ocorrencias.getOrDefault(c, 0) + 1);
			}
		}

		System.out.println(ocorrencias);
		sc.close();
	}
}
