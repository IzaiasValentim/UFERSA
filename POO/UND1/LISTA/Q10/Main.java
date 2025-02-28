package POO.UND1.LISTA.Q10;

public class Main {
	public static void main(String args[]) {
		System.out.println("O maior valor entre -10 e -3 é: " + MaiorValor.maiorEntreDois(-10, -3));
		System.out.println("O maior valor entre 5, 10 e 2 é: " + MaiorValor.maiorEntreTres(5, 10, 2));
		System.out.println("O maior valor entre 7, 2, 1, 0 é: " + MaiorValor.maiorEntreQuatro(7, 2, 1, 0));
		System.out.println(
				"O maior valor entre -100, 34, 200, 10, 1 é: " + MaiorValor.maiorEntreCinco(-100, 34, 200, 10, 1));
	}
}
