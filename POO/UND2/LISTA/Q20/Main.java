package POO.UND2.LISTA.Q20;

import java.util.ArrayList;

public class Main {
	public static void main(String[] args) {
		ArrayList<Integer> l1 = new ArrayList<>();
		l1.add(1);
		l1.add(5);
		l1.add(10);
		l1.add(3);
		l1.add(2);

		ArrayList<Integer> l2 = new ArrayList<>();
		l2.add(44);
		l2.add(-2);
		l2.add(1);

		System.out.println("Produto de l1: " + Produto.calculaProduto(l1));
		System.out.println("Produto de l2: " + Produto.calculaProduto(l2));
	}
}
