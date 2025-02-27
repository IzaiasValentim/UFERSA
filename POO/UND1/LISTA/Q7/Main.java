package POO.UND1.LISTA.Q7;

public class Main {
	public static void main(String args[]) {
		Contador contador = new Contador();
		
		boolean executar = true;

		// Irá executar o menu até que o usuário escolha a opção 6 - System.exit(0).
		while (executar) {
			contador.menu();
		}
	}
}
