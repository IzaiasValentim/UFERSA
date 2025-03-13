package POO.UND2.LISTA.Q18;

public class Main {
	public static void main(String[] args) {
		float m1[][] = {
				{ 14.3F, 2F },
				{ 6.3F, 1.2F }
		};

		float m2[][] = {
				{ 3F, 5F },
				{ 23.4F, 32F }
		};

		Matriz mM1 = new Matriz(m1);
		Matriz mM2 = new Matriz(m2);

		System.out.println("Operações em m1: ");
		System.out.println("Determinante: " + mM1.calcularDeterminante());
		System.out.println("Formato de m1:");
		System.out.println(mM1);

		System.out.println("Operações em m2: ");
		System.out.println("Determinante: " + mM2.calcularDeterminante());
		System.out.println("Formato de m2:");
		System.out.println(mM2);
	}
}
