package POO.UND2.LISTA.Q21;

import java.util.Random;

public class Main {
	public static final int TOTAL_POSSIBILIDADES = 11;

	public static int lancaDado() {
		Random num = new Random();
		return num.nextInt(6) + 1;
	}

	public static void main(String[] args) {

		int possibilidades[] = new int[TOTAL_POSSIBILIDADES];

		int valorUm, valorDois, soma;
		for (int i = 0; i < 36000000; i++) {

			valorUm = lancaDado();
			valorDois = lancaDado();
			soma = valorUm + valorDois;
			possibilidades[soma - 2] = ++possibilidades[soma - 2];
		}
		// a parte da porcentagem não precisava. Adicionei por curiosidade mesmo.
		for (int t = 0; t < TOTAL_POSSIBILIDADES; t++) {
			System.out.printf("\nSoma: %d - vezes: %d - %.2f", t + 2, possibilidades[t],
					(float) possibilidades[t] / 36000000 * 100);
		}
	}
}
