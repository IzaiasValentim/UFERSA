package POO.UND3.PRATICAS.P_PILHAS;

import java.util.Stack;

public class Main {
	public static void main(String[] Args) {
		Stack<Integer> numeros = new Stack<>();
		System.out.println("Operações de adição à pilha: ");
		numeros.push(3);
		System.out.println(numeros);
		numeros.push(1);
		System.out.println(numeros);
		numeros.push(10);
		System.out.println(numeros + "\n");

		System.out.println("Operaçõs de remoção da pilha:");
		numeros.pop();
		System.out.println(numeros);
		numeros.pop();
		System.out.println(numeros);
		numeros.pop();
		System.out.println(numeros);
	}
}
