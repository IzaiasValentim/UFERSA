package POO.UND3.LISTA.Q62;

import java.util.Stack;

public class ParentesesBalanceados {
	public static void main(String[] args) {
		String parenteses = "(()((())()))";

		Stack<Character> pilha = new Stack<>();

		char chars[] = parenteses.toCharArray();

		for (char c : chars) {
			if (c == '(') {
				pilha.add(c);
			}
			if (c == ')') {
				if (pilha.isEmpty()) {
					pilha.add(c);
					break;
				}

				pilha.pop();
			}
		}
		String balanceada = pilha.isEmpty() ? "Sim" : "Não";

		System.out.println("A sequência de parenteses é balanceada: " + balanceada);
	}
}
