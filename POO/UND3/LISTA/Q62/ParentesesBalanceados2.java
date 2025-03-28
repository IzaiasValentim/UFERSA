package POO.UND3.LISTA.Q62;

import java.util.Scanner;
import java.util.Stack;

public class ParentesesBalanceados2 {
	public static void main(String[] Args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Informe a sequência de parênteses: ");
		String parenteses = sc.next();

		Stack<Character> pilhaParenteses = new Stack<>();

		for (Character c : parenteses.toCharArray()) {
			if (c.equals('(')) {
				pilhaParenteses.push(c);
			} else if (c.equals(')')) {

				// Se c for ')' e não houver nenhum '(' no topo para eliminar, logo não poderá ser
				// balanceada.
				if (pilhaParenteses.isEmpty()) {
					pilhaParenteses.push(c);
					break;
				}
				pilhaParenteses.pop();
			}
		}
		String ehBalanceada = pilhaParenteses.isEmpty() ? "É balanceada" : "Não balanceada";

		System.out.println(parenteses + " " + ehBalanceada);
		sc.close();
	}
}
