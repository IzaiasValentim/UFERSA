package POO.UND3.LISTA.Q61;

import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;

public class DemoMap {
	public static void main(String[] Args) {
		// Obtendo o texto
		Scanner sc = new Scanner(System.in);
		System.out.println("Informe o texto para contagem de caracteres: ");
		String frase = sc.nextLine();

		// TreeMap constroi e mantém a ordenação para as chaves.
		Map<Character, Integer> ocorrencias = new TreeMap<>();

		// Alimentando o map com o indentificador (letra) e o total de ocorrências.
		// O Map não aceitará entradas duplicadas e só adicionará a primeira ocorrência
		// e contagem.
		for (int c = 0; c < frase.length(); c++) {
			if (frase.charAt(c) != ' ') {
				ocorrencias.put(frase.charAt(c), ocorrencias.getOrDefault(frase.charAt(c), 0) + 1);
			}
		}

		// Imprimindo o resultado.
		for (Character s : ocorrencias.keySet()) {
			System.out.println("Contém: " + ocorrencias.get(s) + "" + s + "'s");
		}

		sc.close();
	}
}
