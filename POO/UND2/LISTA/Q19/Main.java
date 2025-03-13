package POO.UND2.LISTA.Q19;

import java.util.ArrayList;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		ArrayList<Cliente> clientes = new ArrayList<>();

		int id = 0, idade;
		String nome, telefone;
		Scanner sc = new Scanner(System.in);

		do {

			System.out.println("Informe o id do cliente:");
			id = sc.nextInt();

			if (id < 0) {
				System.out.println("Cadastro de clientes encerrado.");
				break;
			}

			System.out.println("Informe o nome do cliente: ");
			nome = sc.next();

			System.out.println("Informe a idade do cliente: ");
			idade = sc.nextInt();

			System.out.println("Informe o telefone do cliente: ");
			telefone = sc.next();

			clientes.add(new Cliente(id, nome, idade, telefone));
		} while (id >= 0);

		System.out.println("\nClientes cadastrados: ");
		for (int c = 0; c < clientes.size(); c++) {
			System.out.println(clientes.get(c));
		}

		sc.close();
	}
}
