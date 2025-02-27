package POO.UND1.LISTA.Q7;

import java.util.Scanner;

public class Contador {
	private int valor;

	public Contador() {
		this.valor = 0;
	}

	public void incrementaUm() {
		this.valor++;
	}

	public void incrementaValorN(int valorN) {
		this.valor += valorN;
	}

	public void decrementaUm() {
		this.valor--;
	}

	public void decrementaValorN(int valorN) {
		this.valor -= valorN;
	}

	public int getValor() {
		return this.valor;
	}

	public void menu() {
		Scanner scanner = new Scanner(System.in);
		int opcao = 0;
		System.out.println("####");
		System.out.println("Digite uma opção:");
		System.out.println("1 - Incrementar 1");
		System.out.println("2 - Incrementar N");
		System.out.println("3 - Decrementar 1");
		System.out.println("4 - Decrementar N");
		System.out.println("5 - Mostrar valor");
		System.out.println("6 - Sair");
		System.out.print("#### Opção: ");
		opcao = scanner.nextInt();

		// Eu poderia ter feito um switch.
		if (opcao == 1) {
			incrementaUm();
		} else if (opcao == 2) {
			System.out.print("Digite o valor de N:");
			int valorN = scanner.nextInt();
			incrementaValorN(valorN);
		} else if (opcao == 3) {
			decrementaUm();
		} else if (opcao == 4) {
			System.out.print("Digite o valor de N:");
			int valorN = scanner.nextInt();
			decrementaValorN(valorN);
		} else if (opcao == 5) {
			System.out.println("|\nValor: " + this.valor);
		} else if (opcao == 6) {
			System.out.println("Saindo...");
			scanner.close();
			System.exit(0);
		} else {
			System.out.println("Opção inválida.");
		}
		System.out.println();
	}
}
